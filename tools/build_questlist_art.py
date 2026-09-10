"""Build a script-free, independently replaceable skin from Journal vectors.

Original shape records/colors are copied, never traced from PNG/SVG. QuestList
imports this small library through the same !assets mechanism as its title art;
it never loads quest_journal.swf, a menu page, fonts or Journal scripts.
"""
import argparse
import copy
from pathlib import Path
import subprocess
import tempfile
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / 'assets/source/questlist/QuestItemList.HUDMenu-original.swf'
JOURNAL_SOURCE = ROOT / 'assets/source/questlist/art/journal-shapes.xml'
SKIN_URL = '!assets/QuestItemListSkin.swf'
ART = (
    (300, 303, 'QuestObjectivesDivider', 'divider'),
    (301, 304, 'QuestObjectiveCompleted', 'completed'),
    (302, 305, 'QuestObjectivePending', 'pending'),
    (308, 307, 'QuestObjectiveFailed', 'failed'),
)
TITLE_SOURCE = ROOT / 'assets/source/questlist/art/QuestItemListArt.original.swf'
TITLE_TARGETS = [ROOT / ('assets/main/Interface/InfinityUI/' + tree +
    '/HUDMovieBaseInstance/CompassShoutMeterHolder/!assets/QuestItemListArt.swf')
    for tree in ('HUDMenu', 'VR_HMD_info')]
SKIN_TARGETS = [p.with_name('QuestItemListSkin.swf') for p in TITLE_TARGETS]
SOURCE_FILES = [BASE, Path(__file__), JOURNAL_SOURCE, TITLE_SOURCE,
                ROOT / 'tools/extract_journal_art.py']


def build_title_art(ffdec, work):
    """Keep the existing upper quest-detail artwork byte-for-byte."""
    return TITLE_SOURCE.read_bytes()


def run(ffdec, *args):
    subprocess.run(['java', '-jar', str(ffdec), *map(str, args)], check=True)


def definition_id(tag):
    for key in ('shapeId', 'spriteId', 'characterID', 'characterId', 'bitmapId',
                'buttonId', 'soundId', 'fontId'):
        if key in tag.attrib:
            return int(tag.get(key))
    return None


def shape_signature(shape):
    # Ignore serialization widths/IDs, not edges, colors or geometric bounds.
    def visit(node):
        attributes = tuple(sorted((k, v) for k, v in node.attrib.items()
            if k not in ('shapeId', 'forceWriteAsLong', 'nbits', 'numBits', 'moveBits')))
        return node.tag, attributes, (node.text or '').strip(), tuple(visit(c) for c in node)
    return visit(shape)


def sources():
    root = ET.parse(JOURNAL_SOURCE).getroot()
    result = {row.get('name'): row.find('item') for row in root.findall('asset')}
    assert set(result) == {row[3] for row in ART}
    for shape in result.values():
        assert shape.get('type') in ('DefineShapeTag', 'DefineShape2Tag', 'DefineShape3Tag', 'DefineShape4Tag')
        for n in shape.iter('item'):
            if n.get('type') == 'FILLSTYLE':
                assert int(n.get('fillStyleType', '0')) < 64, 'No external bitmap dependencies allowed'
    return result


def placement(character, depth, x=0, y=0, scale=1):
    p = ET.Element('item', type='PlaceObject2Tag', characterId=str(character), depth=str(depth),
        forceWriteAsLong='true', placeFlagHasCharacter='true', placeFlagHasMatrix='true',
        placeFlagHasName='false', placeFlagMove='false', placeFlagHasClipActions='false',
        placeFlagHasClipDepth='false', placeFlagHasColorTransform='false', placeFlagHasRatio='false')
    ET.SubElement(p, 'matrix', type='MATRIX', hasRotate='false', hasScale=str(scale != 1).lower(),
        nRotateBits='0', nScaleBits='0', nTranslateBits='0', scaleX=str(scale), scaleY=str(scale),
        translateX=str(round(x)), translateY=str(round(y)))
    return p


def icon_bounds():
    """Transparent 18x27 slot: failed cross stays square; all row bounds stay fixed."""
    return ET.fromstring('''<item type="DefineShape3Tag" shapeId="309" forceWriteAsLong="true">
      <shapeBounds type="RECT" Xmin="0" Ymin="0" Xmax="360" Ymax="540" nbits="11"/>
      <shapes type="SHAPEWITHSTYLE" numFillBits="1" numLineBits="0">
        <fillStyles type="FILLSTYLEARRAY"><fillStyles><item type="FILLSTYLE" fillStyleType="0">
          <color type="RGBA" red="0" green="0" blue="0" alpha="0"/>
        </item></fillStyles></fillStyles>
        <lineStyles type="LINESTYLEARRAY"><lineStyles/></lineStyles>
        <shapeRecords>
          <item type="StyleChangeRecord" stateMoveTo="true" moveDeltaX="0" moveDeltaY="0" moveBits="1" stateFillStyle0="false" stateFillStyle1="true" fillStyle1="1" stateLineStyle="false" stateNewStyles="false"/>
          <item type="StraightEdgeRecord" generalLineFlag="false" vertLineFlag="false" deltaX="360" numBits="8"/>
          <item type="StraightEdgeRecord" generalLineFlag="false" vertLineFlag="true" deltaY="540" numBits="9"/>
          <item type="StraightEdgeRecord" generalLineFlag="false" vertLineFlag="false" deltaX="-360" numBits="8"/>
          <item type="StraightEdgeRecord" generalLineFlag="false" vertLineFlag="true" deltaY="-540" numBits="9"/>
          <item type="EndShapeRecord" endOfShape="0"/>
        </shapeRecords>
      </shapes>
    </item>''')


def make_skin(base_root):
    root = copy.deepcopy(base_root)
    root.set('frameCount', '1')
    tags = root.find('tags')
    tags.clear()
    original = sources()
    tags.append(icon_bounds())
    exports = ET.Element('item', type='ExportAssetsTag', forceWriteAsLong='true')
    ids, names = ET.SubElement(exports, 'tags'), ET.SubElement(exports, 'names')
    for shape_id, sprite_id, linkage, name in ART:
        shape = copy.deepcopy(original[name])
        shape.set('shapeId', str(shape_id))
        tags.append(shape)
        sprite = ET.Element('item', type='DefineSpriteTag', spriteId=str(sprite_id),
            frameCount='1', hasEndTag='true', forceWriteAsLong='true')
        sub = ET.SubElement(sprite, 'subTags')
        b = shape.find('shapeBounds')
        x, y = int(b.get('Xmin')), int(b.get('Ymin'))
        w, h = int(b.get('Xmax')) - x, int(b.get('Ymax')) - y
        if name == 'divider':
            # Canonical skin contract: original 481.25x14.85 divider, blank center.
            assert (x, y, w, h) == (0, 184, 9625, 297), 'Adapt this divider to the documented skin canvas first'
            sub.append(placement(shape_id, 1, -x, -y))
        else:
            sub.append(placement(309, 1))
            scale = min(358 / w, 538 / h)
            # Fixed-point SWF matrices round down; keep painted bounds inside the slot.
            scale = int(scale * 65536) / 65536
            sub.append(placement(shape_id, 2, (360 - w * scale) / 2 - x * scale,
                                 (540 - h * scale) / 2 - y * scale, scale))
        ET.SubElement(sub, 'item', type='ShowFrameTag', forceWriteAsLong='false')
        tags.append(sprite)
        ET.SubElement(ids, 'item').text = str(sprite_id)
        ET.SubElement(names, 'item').text = linkage
    tags.append(exports)
    ET.SubElement(tags, 'item', type='ShowFrameTag', forceWriteAsLong='false')
    check_skin(root)
    return root


def check_skin(root):
    tags = root.find('tags')
    allowed = {'DefineShapeTag', 'DefineShape2Tag', 'DefineShape3Tag', 'DefineShape4Tag',
               'DefineSpriteTag', 'ExportAssetsTag', 'ShowFrameTag', 'EndTag'}
    assert all(t.get('type') in allowed for t in tags), 'Skin must not contain imports, scripts or fonts'
    definitions = {definition_id(t): t for t in tags if t.get('type', '').startswith('Define')}
    assert len(definitions) == 9
    exports = {n.text: int(i.text) for t in tags if t.get('type') == 'ExportAssetsTag'
               for i, n in zip(t.findall('tags/item'), t.findall('names/item'))}
    assert exports == {link: sprite for _, sprite, link, _ in ART}
    original = sources()
    for shape_id, sprite_id, linkage, name in ART:
        assert shape_signature(definitions[shape_id]) == shape_signature(original[name]), 'Original vector geometry/colors changed'
        sprite = definitions[sprite_id]
        assert sprite.get('frameCount') == '1'
        children = sprite.findall('subTags/item')
        assert all(t.get('type') in ('PlaceObject2Tag', 'ShowFrameTag', 'EndTag') for t in children)
        assert any(t.get('characterId') == str(shape_id) for t in children)
        assert all(not t.get('characterId') or int(t.get('characterId')) in definitions for t in children)
        for t in children:
            m = t.find('matrix')
            if m is not None:
                assert m.get('hasRotate') == 'false'
                assert float(m.get('scaleX', '1')) == float(m.get('scaleY', '1')), 'Do not distort source icons'
    return definitions


def add_art(root):
    tags = root.find('tags')
    occupied = {definition_id(t) for t in tags if t.get('type', '').startswith('Define')}
    occupied.update(int(i.text) for t in tags if t.get('type', '').startswith('ImportAssets') for i in t.findall('tags/item'))
    assert not occupied.intersection({row[1] for row in ART})
    imported = ET.Element('item', type='ImportAssets2Tag', url=SKIN_URL,
        downloadNow='1', forceWriteAsLong='true', hasDigest='0')
    ids, names = ET.SubElement(imported, 'tags'), ET.SubElement(imported, 'names')
    for _, sprite_id, linkage, _ in ART:
        ET.SubElement(ids, 'item').text = str(sprite_id)
        ET.SubElement(names, 'item').text = linkage
    tags.insert(0, imported)


def check_xml(root, offset=0):
    """Verify the small skin import contract in standalone and embedded QuestList."""
    tags = root.find('tags')
    defs = {}
    for tag in tags:
        if tag.get('type', '').startswith('Define'):
            identifier = definition_id(tag)
            if identifier is not None:
                assert identifier not in defs, f'Duplicate resource ID {identifier}'
                defs[identifier] = tag
    imports = [t for t in tags if t.get('type') == 'ImportAssets2Tag' and t.get('url') == SKIN_URL]
    assert len(imports) == 1, 'Exactly one independent skin library is required'
    actual = {n.text: int(i.text) for i, n in zip(imports[0].findall('tags/item'), imports[0].findall('names/item'))}
    assert actual == {link: sprite + offset for _, sprite, link, _ in ART}
    assert not set(actual.values()).intersection(defs), 'Imported skin IDs collide with local definitions'
    assert not any('quest_journal' in t.get('url', '').lower() for t in tags), 'Never import the Journal menu'
    return defs


def build_art(ffdec, output, work):
    base_xml = work / 'quest-art.xml'
    run(ffdec, '-swf2xml', BASE, base_xml)
    tree = ET.parse(base_xml)
    skin = make_skin(tree.getroot())
    skin_xml = work / 'skin.xml'
    ET.ElementTree(skin).write(skin_xml, encoding='utf-8', xml_declaration=True)
    run(ffdec, '-xml2swf', skin_xml, work / 'QuestItemListSkin.swf')
    run(ffdec, '-swf2xml', work / 'QuestItemListSkin.swf', work / 'skin-verified.xml')
    check_skin(ET.parse(work / 'skin-verified.xml').getroot())
    add_art(tree.getroot())
    check_xml(tree.getroot())
    tree.write(base_xml, encoding='utf-8', xml_declaration=True)
    run(ffdec, '-xml2swf', base_xml, output)
    run(ffdec, '-swf2xml', output, work / 'quest-art-verified.xml')
    check_xml(ET.parse(work / 'quest-art-verified.xml').getroot())


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--ffdec', type=Path, required=True)
    p.add_argument('--output', type=Path, default=ROOT / 'build/questlist-art.swf')
    a = p.parse_args()
    with tempfile.TemporaryDirectory(prefix='cno-art-') as tmp:
        a.output.parent.mkdir(parents=True, exist_ok=True)
        build_art(a.ffdec.resolve(), a.output.resolve(), Path(tmp))
        a.output.with_name('QuestItemListSkin.swf').write_bytes((Path(tmp) / 'QuestItemListSkin.swf').read_bytes())
    print('QuestList skin imports and four original vector assets verified.')
