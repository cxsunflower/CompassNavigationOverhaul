#!/usr/bin/env python3
"""Build the supplied objective artwork into native AS2 SWF symbols.

The checked-in SVGs are vector traces of the user-provided PNGs. This module
uses only the standard library and JPEXS; no runtime loadMovie is introduced.
"""

import argparse
from pathlib import Path
import re
import subprocess
import tempfile
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / 'assets/source/questlist/QuestItemList.HUDMenu-original.swf'
ART = (
    (300, 303, 'QuestObjectivesDivider', 'divider.svg'),
    (301, 304, 'QuestObjectiveCompleted', 'completed.svg'),
    (302, 305, 'QuestObjectivePending', 'pending.svg'),
)
SOURCE_FILES = [BASE, Path(__file__), *[ROOT / 'assets/source/questlist/art' / row[3] for row in ART]]
TITLE_SOURCE = ROOT / 'assets/source/questlist/art/QuestItemListArt.original.swf'
TITLE_TARGETS = [ROOT / ('assets/main/Interface/InfinityUI/' + tree +
    '/HUDMovieBaseInstance/CompassShoutMeterHolder/!assets/QuestItemListArt.swf')
    for tree in ('HUDMenu', 'VR_HMD_info')]
SOURCE_FILES.append(TITLE_SOURCE)


def build_title_art(ffdec, work):
    """Preserve original artwork; the reported dark area came from scaled name text."""
    return TITLE_SOURCE.read_bytes()


def run(ffdec, *args):
    subprocess.run(['java', '-jar', str(ffdec), *map(str, args)], check=True)


def signed_bits(value):
    bits = 2
    while not (-(1 << (bits - 1)) <= value < (1 << (bits - 1))):
        bits += 1
    return bits


def rect(parent, name, width, height):
    return ET.SubElement(parent, name, type='RECT', Xmin='0', Ymin='0',
                         Xmax=str(width * 20), Ymax=str(height * 20),
                         nbits=str(signed_bits(max(width, height) * 20)))


def vector_shape(path, shape_id):
    svg = ET.parse(path).getroot()
    width, height = int(svg.get('width')), int(svg.get('height'))
    shape = ET.Element('item', type='DefineShape4Tag', shapeId=str(shape_id),
                       forceWriteAsLong='true', reserved='0',
                       usesFillWindingRule='false', usesNonScalingStrokes='false',
                       usesScalingStrokes='true')
    rect(shape, 'shapeBounds', width, height)
    rect(shape, 'edgeBounds', width, height)
    layers = list(svg.findall('{http://www.w3.org/2000/svg}path'))
    assert layers and len(layers) < 8
    styles = ET.SubElement(shape, 'shapes', type='SHAPEWITHSTYLE',
                           numFillBits=str(len(layers).bit_length()), numLineBits='0')
    fills = ET.SubElement(ET.SubElement(styles, 'fillStyles', type='FILLSTYLEARRAY'), 'fillStyles')
    for layer in layers:
        color = layer.get('fill').lstrip('#')
        assert re.fullmatch(r'[0-9a-fA-F]{6}', color)
        fill = ET.SubElement(fills, 'item', type='FILLSTYLE', fillStyleType='0', bitmapId='0')
        ET.SubElement(fill, 'color', type='RGBA', alpha='255',
                      red=str(int(color[0:2], 16)), green=str(int(color[2:4], 16)),
                      blue=str(int(color[4:6], 16)))
    lines = ET.SubElement(styles, 'lineStyles', type='LINESTYLEARRAY')
    ET.SubElement(lines, 'lineStyles')
    records = ET.SubElement(styles, 'shapeRecords')
    for style, layer in enumerate(layers, 1):
        # These source-derived SVGs deliberately contain only absolute M/L/Z.
        tokens = re.findall(r'[MLZ]|-?\d+(?:\.\d+)?', layer.get('d'))
        assert ''.join(re.findall(r'[A-Za-z]', layer.get('d'))) == ''.join(t for t in tokens if t in 'MLZ')
        contours, points = [], []
        i = 0
        while i < len(tokens):
            op = tokens[i]
            if op == 'Z':
                assert len(points) >= 3
                contours.append(points)
                points = []
                i += 1
            else:
                assert op in ('M', 'L') and i + 2 < len(tokens)
                points.append((int(float(tokens[i + 1]) * 20), int(float(tokens[i + 2]) * 20)))
                i += 3
        assert not points and contours
        for contour in contours:
            x, y = contour[0]
            ET.SubElement(records, 'item', type='StyleChangeRecord',
                          fillStyle0='0', fillStyle1=str(style), lineStyle='0',
                          moveBits=str(signed_bits(max(abs(x), abs(y)))),
                          moveDeltaX=str(x), moveDeltaY=str(y),
                          numFillBits='0', numLineBits='0', stateFillStyle0='false',
                          stateFillStyle1='true', stateLineStyle='false',
                          stateMoveTo='true', stateNewStyles='false')
            for nx, ny in contour[1:] + contour[:1]:
                dx, dy = nx - x, ny - y
                if dx == 0 and dy == 0:
                    continue
                ET.SubElement(records, 'item', type='StraightEdgeRecord',
                              deltaX=str(dx), deltaY=str(dy), generalLineFlag='true',
                              vertLineFlag='false', numBits=str(signed_bits(max(abs(dx), abs(dy))) - 2))
                x, y = nx, ny
    ET.SubElement(records, 'item', type='EndShapeRecord', endOfShape='0')
    return shape


def sprite(shape_id, sprite_id):
    result = ET.Element('item', type='DefineSpriteTag', spriteId=str(sprite_id),
                        frameCount='1', hasEndTag='true', forceWriteAsLong='true')
    sub = ET.SubElement(result, 'subTags')
    place = ET.SubElement(sub, 'item', type='PlaceObject2Tag', characterId=str(shape_id),
                          depth='1', forceWriteAsLong='true', placeFlagHasCharacter='true',
                          placeFlagHasMatrix='true', placeFlagHasName='false',
                          placeFlagMove='false', placeFlagHasClipActions='false',
                          placeFlagHasClipDepth='false', placeFlagHasColorTransform='false',
                          placeFlagHasRatio='false')
    ET.SubElement(place, 'matrix', type='MATRIX', hasRotate='false', hasScale='false',
                  nRotateBits='0', nScaleBits='0', nTranslateBits='0',
                  translateX='0', translateY='0')
    ET.SubElement(sub, 'item', type='ShowFrameTag', forceWriteAsLong='false')
    return result


def add_art(root):
    tags = root.find('tags')
    assert tags is not None
    existing = set()
    for tag in tags:
        if tag.get('type', '').startswith('Define'):
            identifier = definition_id(tag)
            if identifier is not None:
                existing.add(identifier)
    reserved = {value for row in ART for value in row[:2]}
    assert not existing.intersection(reserved), 'Objective artwork IDs already exist in the source SWF'
    resources = []
    exports = ET.Element('item', type='ExportAssetsTag', forceWriteAsLong='true')
    ids, names = ET.SubElement(exports, 'tags'), ET.SubElement(exports, 'names')
    for shape_id, sprite_id, name, filename in ART:
        resources.append(vector_shape(ROOT / 'assets/source/questlist/art' / filename, shape_id))
        resources.append(sprite(shape_id, sprite_id))
        ET.SubElement(ids, 'item').text = str(sprite_id)
        ET.SubElement(names, 'item').text = name
    resources.append(exports)
    for i, resource in enumerate(resources):
        tags.insert(i, resource)


def definition_id(tag):
    # A text tag's fontId is a reference, not another character definition.
    for key in ('shapeId', 'spriteId', 'characterID', 'characterId', 'bitmapId',
                'buttonId', 'soundId', 'fontId'):
        if key in tag.attrib:
            return int(tag.get(key))
    return None


def check_xml(root, offset=0):
    tags = root.find('tags')
    assert tags is not None
    definitions = {}
    for tag in tags:
        if tag.get('type', '').startswith('Define'):
            identifier = definition_id(tag)
            if identifier is not None:
                assert identifier not in definitions, f'Duplicate resource ID {identifier}'
                definitions[identifier] = tag
    exports = {}
    for tag in tags:
        if tag.get('type') == 'ExportAssetsTag':
            for identifier, name in zip(tag.findall('./tags/item'), tag.findall('./names/item')):
                assert name.text not in exports, f'Duplicate export {name.text}'
                exports[name.text] = int(identifier.text)
    for shape_id, sprite_id, name, filename in ART:
        shape = definitions[shape_id + offset]
        assert shape.get('type') == 'DefineShape4Tag'
        svg = ET.parse(ROOT / 'assets/source/questlist/art' / filename).getroot()
        assert int(shape.find('shapeBounds').get('Xmax')) == int(svg.get('width')) * 20
        assert int(shape.find('shapeBounds').get('Ymax')) == int(svg.get('height')) * 20
        assert sum(t.get('type') == 'StraightEdgeRecord' for t in shape.iter('item')) >= 4
        assert exports[name] == sprite_id + offset
        placements = definitions[sprite_id + offset].findall('./subTags/item')
        assert sum(t.get('characterId') == str(shape_id + offset) for t in placements) == 1
    return definitions


def build_art(ffdec, output, work):
    base_xml = work / 'quest-art.xml'
    run(ffdec, '-swf2xml', BASE, base_xml)
    tree = ET.parse(base_xml)
    add_art(tree.getroot())
    check_xml(tree.getroot())
    tree.write(base_xml, encoding='utf-8', xml_declaration=True)
    run(ffdec, '-xml2swf', base_xml, output)
    verify_xml = work / 'quest-art-verified.xml'
    run(ffdec, '-swf2xml', output, verify_xml)
    check_xml(ET.parse(verify_xml).getroot())


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ffdec', type=Path, required=True)
    parser.add_argument('--output', type=Path, default=ROOT / 'build/questlist-art.swf')
    args = parser.parse_args()
    with tempfile.TemporaryDirectory(prefix='cno-art-') as directory:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        build_art(args.ffdec.resolve(), args.output.resolve(), Path(directory))
    print('Objective artwork built: divider, completed and pending symbols verified.')
