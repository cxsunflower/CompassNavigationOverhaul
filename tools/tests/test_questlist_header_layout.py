"""Structural regression tests for the native QuestItem layout wrapper."""

from copy import deepcopy
from pathlib import Path
import sys
import unittest
import xml.etree.ElementTree as ET

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from questlist_header_layout import WRAPPER_ID, check_header_layout, wrap_header


def fixture():
    root = ET.Element('swf')
    tags = ET.SubElement(root, 'tags')
    title = ET.SubElement(tags, 'item', type='DefineSpriteTag', spriteId='5', frameCount='1')
    sub = ET.SubElement(title, 'subTags')
    for name in ('EndPiece', 'TitleTextField', 'Bracket'):
        ET.SubElement(sub, 'item', type='PlaceObject2Tag', name=name)
    ET.SubElement(sub, 'item', type='ShowFrameTag')
    quest = ET.SubElement(tags, 'item', type='DefineSpriteTag', spriteId='6', frameCount='18')
    sub = ET.SubElement(quest, 'subTags')
    place = ET.SubElement(sub, 'item', type='PlaceObject3Tag', name='Title', characterId='5', depth='1',
                          placeFlagHasColorTransform='true', blendMode='2')
    ET.SubElement(place, 'matrix', hasScale='false', hasRotate='false', translateX='0', translateY='0')
    ET.SubElement(place, 'colorTransform', hasAddTerms='false', redMultTerm='256', greenMultTerm='256',
                  blueMultTerm='256', alphaMultTerm='0')
    for i in range(18):
        ET.SubElement(sub, 'item', type='FrameLabelTag', name='Frame' + str(i))
        ET.SubElement(sub, 'item', type='ShowFrameTag')
    return root


class HeaderLayoutTests(unittest.TestCase):
    def test_wrapper_preserves_original_art_and_animation(self):
        root = fixture()
        original = deepcopy(root)
        wrap_header(root)
        self.assertTrue(check_header_layout(root, original))
        self.assertEqual(len([t for t in root.findall('./tags/item') if t.get('spriteId') == '5']), 1)

    def test_reserved_id_collision_is_rejected(self):
        root = fixture()
        ET.SubElement(root.find('tags'), 'item', type='DefineShapeTag', shapeId=str(WRAPPER_ID))
        with self.assertRaises(AssertionError):
            wrap_header(root)

    def test_changed_animation_and_header_are_rejected(self):
        root = fixture()
        original = deepcopy(root)
        wrap_header(root)
        quest = next(t for t in root.findall('./tags/item') if t.get('spriteId') == '6')
        quest.findall('./subTags/item')[0].find('matrix').set('translateX', '20')
        with self.assertRaisesRegex(AssertionError, 'animation changed'):
            check_header_layout(root, original)
        quest.findall('./subTags/item')[0].find('matrix').set('translateX', '0')
        title = next(t for t in root.findall('./tags/item') if t.get('spriteId') == '5')
        title.find('./subTags/item').set('name', 'Changed')
        with self.assertRaises(AssertionError):
            check_header_layout(root, original)


if __name__ == '__main__':
    unittest.main()
