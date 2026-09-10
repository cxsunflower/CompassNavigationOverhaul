"""Pure-vector provenance, skin isolation, imports and geometry regression tests."""
import copy
from pathlib import Path
import sys
import unittest
import xml.etree.ElementTree as E

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import build_questlist_art as art
import build_questlist_swf as builder
from extract_journal_art import extract


def empty_movie():
    return E.fromstring('<swf frameCount="1"><tags/></swf>')


def journal_fixture():
    r = empty_movie()
    tags = r.find('tags')
    for i, name in enumerate(('pending', 'completed', 'failed', 'divider'), 91):
        s = copy.deepcopy(art.sources()[name]); s.set('shapeId', str(i)); tags.append(s)
    def sprite(i):
        return E.SubElement(E.SubElement(tags, 'item', type='DefineSpriteTag', spriteId=str(i)), 'subTags')
    sub = sprite(40)
    for name, i in [('Normal', 91), ('Completed', 92), ('Failed', 93)]:
        E.SubElement(sub, 'item', type='FrameLabelTag', name=name)
        E.SubElement(sub, 'item', type='PlaceObject2Tag', characterId=str(i), depth='4')
        E.SubElement(sub, 'item', type='ShowFrameTag')
    E.SubElement(sprite(41), 'item', type='PlaceObject2Tag', characterId='94', depth='1')
    E.SubElement(sprite(42), 'item', type='PlaceObject2Tag', characterId='41', depth='1', name='objectivesHeader')
    export = E.SubElement(tags, 'item', type='ExportAssetsTag')
    ids, names = E.SubElement(export, 'tags'), E.SubElement(export, 'names')
    for i, n in [(40, 'ObjectiveListItem'), (42, 'QuestsPage')]:
        E.SubElement(ids, 'item').text = str(i); E.SubElement(names, 'item').text = n
    return r


class QuestListSkinTests(unittest.TestCase):
    def test_original_records_and_colors_are_preserved(self):
        root = art.make_skin(empty_movie())
        defs = art.check_skin(root)
        for i, _, _, name in art.ART:
            self.assertEqual(art.shape_signature(defs[i]), art.shape_signature(art.sources()[name]))
        edge = next(t for t in defs[300].iter('item') if t.get('type') == 'StraightEdgeRecord' and t.get('deltaX'))
        edge.set('deltaX', str(int(edge.get('deltaX')) + 1))
        with self.assertRaisesRegex(AssertionError, 'geometry/colors'):
            art.check_skin(root)

    def test_skin_rejects_menu_actions_and_external_dependencies(self):
        for kind in ('DoActionTag', 'DoInitActionTag', 'ImportAssets2Tag', 'DefineEditTextTag'):
            root = art.make_skin(empty_movie())
            E.SubElement(root.find('tags'), 'item', type=kind)
            with self.assertRaisesRegex(AssertionError, 'scripts or fonts'):
                art.check_skin(root)

    def test_all_icons_fit_fixed_slot_without_anisotropic_scaling(self):
        defs = art.check_skin(art.make_skin(empty_movie()))
        for shape, sprite, _, name in art.ART:
            if name == 'divider':
                continue
            m = next(t.find('matrix') for t in defs[sprite].findall('subTags/item') if t.get('characterId') == str(shape))
            sx, sy = float(m.get('scaleX')), float(m.get('scaleY'))
            self.assertEqual(sx, sy)
            b = defs[shape].find('shapeBounds')
            for lo, hi, axis, scale, limit in [('Xmin','Xmax','X',sx,360), ('Ymin','Ymax','Y',sy,540)]:
                translation = int(m.get('translate' + axis))
                self.assertGreaterEqual(int(b.get(lo)) * scale + translation, 0)
                self.assertLessEqual(int(b.get(hi)) * scale + translation, limit)
        bounds = defs[309]
        self.assertEqual(bounds.find('.//color').get('alpha'), '0')
        self.assertEqual(bounds.find('shapeBounds').get('Xmax'), '360')
        self.assertEqual(bounds.find('shapeBounds').get('Ymax'), '540')

    def test_local_and_embedded_import_contract(self):
        for offset in (0, 500):
            root = empty_movie(); art.add_art(root)
            for n in root.findall('tags/item/tags/item'):
                n.text = str(int(n.text) + offset)
            art.check_xml(root, offset)
            imp = root.find('tags/item')
            self.assertEqual(imp.get('url'), '!assets/QuestItemListSkin.swf')
            self.assertEqual(len(imp.findall('names/item')), 4)

    def test_import_id_collision_and_journal_reference_are_rejected(self):
        root = empty_movie(); art.add_art(root)
        E.SubElement(root.find('tags'), 'item', type='DefineSpriteTag', spriteId='303')
        with self.assertRaisesRegex(AssertionError, 'collide'):
            art.check_xml(root)
        root = empty_movie(); art.add_art(root)
        E.SubElement(root.find('tags'), 'item', type='ImportAssets2Tag', url='quest_journal.swf')
        with self.assertRaisesRegex(AssertionError, 'Journal menu'):
            art.check_xml(root)

    def test_extractor_resolves_names_and_states_not_fixed_character_ids(self):
        result = extract(journal_fixture(), 'a' * 64, 'test source')
        self.assertEqual(result.get('sourceSHA256'), 'a' * 64)
        self.assertEqual({r.get('name') for r in result}, {'pending','completed','failed','divider'})
        for row in result:
            self.assertEqual(art.shape_signature(row.find('item')), art.shape_signature(art.sources()[row.get('name')]))

    def test_ambiguous_header_fails_closed(self):
        root = journal_fixture()
        header = next(t for t in root.find('tags') if t.get('spriteId') == '41')
        E.SubElement(header.find('subTags'), 'item', type='PlaceObject2Tag', characterId='91', depth='2')
        with self.assertRaisesRegex(ValueError, 'one pure shape'):
            extract(root, '', '')

    def test_default_skin_is_tracked_and_old_traces_are_not_build_inputs(self):
        self.assertIn('assets/source/questlist/art/journal-shapes.xml', builder.INPUTS)
        self.assertFalse(any(p.endswith('.svg') for p in builder.INPUTS))
        self.assertEqual(sum(p.endswith('/QuestItemListSkin.swf') for p in builder.TARGETS), 2)


if __name__ == '__main__':
    unittest.main()
