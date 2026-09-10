"""Extract pure Journal vector shapes without copying its page, scripts or fonts.

Run explicitly when changing the default skin source. Normal builds use the
checked-in extraction and do not inspect the player's installation.
"""
import argparse
import copy
import hashlib
from pathlib import Path
import subprocess
import tempfile
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[1]
SHAPE_TYPES = {'DefineShapeTag', 'DefineShape2Tag', 'DefineShape3Tag', 'DefineShape4Tag'}


def extract(root, source_hash, label):
    tags = root.find('tags')
    definitions = {}
    exports = {}
    for t in tags:
        if t.get('type') in SHAPE_TYPES:
            definitions[int(t.get('shapeId'))] = t
        elif t.get('type') == 'DefineSpriteTag':
            definitions[int(t.get('spriteId'))] = t
        elif t.get('type') == 'ExportAssetsTag':
            exports.update({n.text: int(i.text) for i, n in zip(t.findall('tags/item'), t.findall('names/item'))})
    objective = definitions[exports['ObjectiveListItem']]
    placements, states = {}, {}
    label_now = None
    for t in objective.find('subTags'):
        kind = t.get('type')
        if kind == 'FrameLabelTag':
            label_now = t.get('name')
        elif kind in ('RemoveObjectTag', 'RemoveObject2Tag'):
            placements.pop(int(t.get('depth')), None)
        elif kind.startswith('PlaceObject') and t.get('characterId'):
            placements[int(t.get('depth'))] = int(t.get('characterId'))
        elif kind == 'ShowFrameTag' and label_now in ('Normal', 'Completed', 'Failed'):
            shapes = [definitions[i] for i in placements.values()
                      if i in definitions and definitions[i].get('type') in SHAPE_TYPES]
            if len(shapes) != 1:
                raise ValueError(f'Unsupported {label_now} artwork: expected one pure shape, got {len(shapes)}')
            states[label_now] = shapes[0]
    page = definitions[exports['QuestsPage']]
    headers = [t for t in page.findall('subTags/item') if t.get('name') == 'objectivesHeader']
    if len(headers) != 1:
        raise ValueError('Unsupported Journal: objectivesHeader must be unambiguous')
    header = definitions[int(headers[0].get('characterId'))]
    graphics = [definitions[int(t.get('characterId'))] for t in header.findall('subTags/item')
                if t.get('characterId') and int(t.get('characterId')) in definitions
                and definitions[int(t.get('characterId'))].get('type') in SHAPE_TYPES]
    if len(graphics) != 1:
        raise ValueError('Unsupported header: expected one pure shape; inspect this skin manually')
    result = ET.Element('JournalArtwork', sourceFile='quest_journal.swf',
                        sourceSHA256=source_hash, sourceLabel=label)
    for name, shape in [('divider', graphics[0]), ('completed', states['Completed']),
                        ('pending', states['Normal']), ('failed', states['Failed'])]:
        # No bitmap dependencies, font references, scripts or menu containers.
        for fill in shape.iter('item'):
            if fill.get('type') == 'FILLSTYLE' and int(fill.get('fillStyleType', '0')) >= 64:
                raise ValueError('Bitmap-backed Journal artwork needs a separate adapter')
        row = ET.SubElement(result, 'asset', name=name, sourceShapeId=shape.get('shapeId'))
        row.append(copy.deepcopy(shape))
    return result


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--ffdec', type=Path, required=True)
    p.add_argument('--source-journal', type=Path, required=True)
    p.add_argument('--source-label', default='Locally installed Journal artwork')
    p.add_argument('--output', type=Path, default=ROOT / 'assets/source/questlist/art/journal-shapes.xml')
    a = p.parse_args()
    source = a.source_journal.resolve()
    before = hashlib.sha256(source.read_bytes()).hexdigest()
    with tempfile.TemporaryDirectory(prefix='cno-journal-extract-') as tmp:
        xml = Path(tmp) / 'journal.xml'
        subprocess.run(['java', '-jar', str(a.ffdec.resolve()), '-swf2xml', str(source), str(xml)], check=True)
        result = extract(ET.parse(xml).getroot(), before, a.source_label)
    assert hashlib.sha256(source.read_bytes()).hexdigest() == before
    ET.indent(result)
    a.output.parent.mkdir(parents=True, exist_ok=True)
    ET.ElementTree(result).write(a.output, encoding='utf-8', xml_declaration=True)
    print('Extracted four original vector shapes; source Journal unchanged.')


if __name__ == '__main__':
    main()
