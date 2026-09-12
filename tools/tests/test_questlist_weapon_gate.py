"""Keep the legacy key and weapon-drawn behavior with an accurate MCM label."""
from pathlib import Path
import itertools
import json
import re
import unittest

ROOT = Path(__file__).resolve().parents[2]


class QuestListWeaponGateTests(unittest.TestCase):
    def test_presentation_uses_weapon_state_not_combat_state(self):
        s = (ROOT / 'source/hud/QuestPresentation.cpp').read_text(encoding='utf-8-sig')
        self.assertIn('const bool weaponDrawn = playerState->IsWeaponDrawn();', s)
        self.assertIn('CanBeDisplayed(player->GetParentCell(), weaponDrawn)', s)
        self.assertNotIn('player->IsInCombat()', s)

    def test_weapon_gate_truth_table_ignores_combat(self):
        s = (ROOT / 'source/questlist/Bridge.cpp').read_text(encoding='utf-8-sig')
        expr = re.search(r'CanBeDisplayed\([^{}]+\) const\s*\{\s*if\s*\(([^)]+)\)', s).group(1)
        self.assertIn('a_isPlayerWeaponDrawn', expr)
        expr = expr.replace('settings::questlist::hideInCombat', 'enabled').replace('a_isPlayerWeaponDrawn', 'drawn')
        expr = expr.replace('||', 'or').replace('!', 'not ').strip()
        for enabled, drawn, combat in itertools.product((False, True), repeat=3):
            with self.subTest(enabled=enabled, drawn=drawn, combat=combat):
                result = eval(expr, {'__builtins__': {}}, {'enabled': enabled, 'drawn': drawn})
                self.assertEqual(result, not (enabled and drawn))

    def test_mcm_retains_saved_key_and_explains_weapon_state(self):
        cases = [
            ('assets/main/MCM/Config/Compass Navigation Overhaul VR/config.json', 'Hide With Weapon Drawn', 'whether or not you are in combat'),
            ('assets/localization/zh-CN/MCM/Config/Compass Navigation Overhaul VR/config.json', '拔出武器时隐藏', '与是否处于战斗无关'),
        ]
        for name, title, help_text in cases:
            doc = json.loads((ROOT / name).read_text(encoding='utf-8-sig'))
            rows = [c for page in doc['pages'] for c in page['content'] if c.get('id') == 'bHideInCombat:QuestList']
            self.assertEqual(len(rows), 1)
            self.assertEqual(rows[0]['text'], title)
            self.assertIn(help_text, rows[0]['help'])


if __name__ == '__main__':
    unittest.main()
