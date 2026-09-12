"""Keep fixed plugin diagnostics English; do not translate gameplay data."""
from pathlib import Path
import re
import unittest

ROOT = Path(__file__).resolve().parents[2]


class DiagnosticLanguageTests(unittest.TestCase):
    def check_literals(self, name):
        source = (ROOT / name).read_text(encoding='utf-8-sig')
        source = re.sub(r'//[^\n]*|/\*.*?\*/', '', source, flags=re.S)
        for literal in re.findall(r'"(?:\\.|[^"\\])*"', source):
            self.assertIsNone(re.search('[\u4e00-\u9fff]', literal), (name, literal))

    def test_native_hook_diagnostics_are_english(self):
        self.check_literals('source/hooks/Install.cpp')

    def test_hud_diagnostic_literals_are_english(self):
        self.check_literals('swf/compass/Debug.as')


if __name__ == '__main__':
    unittest.main()
