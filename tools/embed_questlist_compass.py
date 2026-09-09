"""Embed QuestList as a native sprite of Compass, without a loadMovie boundary."""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile
import xml.etree.ElementTree as ET

from build_questlist_art import check_xml, definition_id
from compass_passenger import load_config, placement_matrix

ROOT = Path(__file__).resolve().parents[1]
INPUTS = ['assets/generated/Compass.before-embedded.swf', 'assets/generated/QuestItemList.swf', 'tools/embed_questlist_compass.py', 'tools/compass_passenger.py', 'swf/QuestItemList.as']
OUTPUTS = ['assets/main/Interface/InfinityUI/' + tree + '/HUDMovieBaseInstance/CompassShoutMeterHolder/Compass.swf' for tree in ['HUDMenu', 'VR_HMD_info']]
MANIFEST = ROOT / 'tools/compass-embedded.json'

def hashes():
    return {p: hashlib.sha256((ROOT / p).read_bytes()).hexdigest() for p in INPUTS + OUTPUTS}

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ffdec')
    parser.add_argument('--check', action='store_true')
    parser.add_argument('--output', type=Path, help='Preflight output; do not replace release movies or the hash manifest')
    args = parser.parse_args()
    load_config(ROOT)
    if args.check:
        if args.output:
            parser.error('--check and --output cannot be combined')
        assert json.loads(MANIFEST.read_text()) == hashes(), 'Embedded Compass is stale'
        print('Embedded Compass inputs and outputs verified.')
        return
    if not args.ffdec or not Path(args.ffdec).is_file():
        parser.error('--ffdec must name an existing JPEXS ffdec-cli.jar')
    cmd = ['java', '-jar', args.ffdec]
    with tempfile.TemporaryDirectory(prefix='cno-embed-') as temp:
        work = Path(temp)
        for name, source in zip(['compass', 'quest'], INPUTS[:2]):
            subprocess.run(cmd + ['-swf2xml', str(ROOT/source), str(work/(name+'.xml'))], check=True)
        compass = ET.parse(work/'compass.xml')
        quest = ET.parse(work/'quest.xml')
        tags = compass.getroot().find('tags')
        base_ids = {definition_id(t) for t in tags if t.get('type', '').startswith('Define')}
        base_ids.discard(None)
        quest_tags = quest.getroot().find('tags')
        quest_ids = {definition_id(t) for t in quest_tags if t.get('type', '').startswith('Define')}
        quest_ids.discard(None)
        remapped_ids = {identifier + 500 for identifier in quest_ids}
        assert not base_ids.intersection(remapped_ids), 'Compass/QuestList resource ID collision'
        assert 511 not in base_ids and 511 not in remapped_ids, 'Embedded wrapper sprite ID collision'
        target = next(t for t in tags if t.get('type') == 'DefineSpriteTag' and t.get('spriteId') == '133')
        assert any(t.get('name') == 'TextFieldInstance' for t in target.find('subTags'))
        assert not any(t.get('spriteId') == '511' for t in tags)
        # Remap all QuestList resource definitions, placements and linkage IDs.
        resources = []
        timeline = []
        id_attrs = {'characterID', 'characterId', 'spriteId', 'shapeId', 'fontId', 'bitmapId'}
        for original in quest.getroot().find('tags'):
            kind = original.get('type')
            if kind in ('FileAttributesTag', 'MetadataTag', 'SetBackgroundColorTag'):
                continue
            t = copy.deepcopy(original)
            for node in t.iter():
                for key in id_attrs.intersection(node.attrib):
                    value = int(node.get(key))
                    if value > 0:
                        node.set(key, str(value + 500))
            if kind in ('ImportAssets2Tag', 'ExportAssetsTag'):
                for number in t.find('tags'):
                    number.text = str(int(number.text) + 500)
            if kind in ('DoActionTag', 'ShowFrameTag', 'PlaceObject2Tag'):
                timeline.append(t)
            else:
                resources.append(t)
        sprite = ET.Element('item', type='DefineSpriteTag', spriteId='511', frameCount='1', hasEndTag='true', forceWriteAsLong='true')
        sub = ET.SubElement(sprite, 'subTags')
        sub.extend(timeline)
        resources.append(sprite)
        for i, resource in enumerate(resources):
            tags.insert(i, resource)
        placement = ET.Element('item', type='PlaceObject2Tag', characterId='511', depth='100', name='QuestItemList', forceWriteAsLong='true', placeFlagHasCharacter='true', placeFlagHasMatrix='true', placeFlagHasName='true', placeFlagMove='false', placeFlagHasClipActions='false', placeFlagHasClipDepth='false', placeFlagHasColorTransform='false', placeFlagHasRatio='false')
        # Position and scale are set once by the runtime solver. JPEXS matrix
        # scales are fractions, and translations are twips, not HUD pixels.
        ET.SubElement(placement, 'matrix', **placement_matrix())
        target.find('subTags').insert(0, placement)
        compass.write(work/'embedded.xml', encoding='utf-8', xml_declaration=True)
        subprocess.run(cmd + ['-xml2swf', str(work/'embedded.xml'), str(work/'embedded.swf')], check=True)
        subprocess.run(cmd + ['-swf2xml', str(work/'embedded.swf'), str(work/'verify.xml')], check=True)
        verify = ET.parse(work/'verify.xml')
        check_xml(verify.getroot(), offset=500)
        assert any(t.get('name') == 'QuestItemList' and t.get('characterId') == '511' for t in verify.iter('item'))
        embedded = next(t for t in verify.iter('item') if t.get('name') == 'QuestItemList' and t.get('characterId') == '511')
        matrix = embedded.find('matrix')
        assert matrix.get('hasScale') == 'false' and float(matrix.get('translateX')) == 0 and float(matrix.get('translateY')) == 0
        assert sum(t.get('type') == 'DoInitActionTag' for t in verify.iter('item')) == 4
        if args.output:
            args.output.resolve().parent.mkdir(parents=True, exist_ok=True)
            args.output.resolve().write_bytes((work/'embedded.swf').read_bytes())
        else:
            for output in OUTPUTS:
                (ROOT/output).write_bytes((work/'embedded.swf').read_bytes())
    if not args.output:
        MANIFEST.write_text(json.dumps(hashes(), indent=2)+'\n')
    print('QuestList embedded in Compass Target; class initializers and sprite placement verified.')

if __name__ == '__main__':
    main()
