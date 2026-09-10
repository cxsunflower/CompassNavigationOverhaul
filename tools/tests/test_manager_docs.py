"""Structural documentation guard regression; does not inspect private mappings."""
from pathlib import Path
import sys
import tempfile
import unittest
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import check_manager_docs as docs

class ManagerDocsTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        for p in ['AGENTS.md','manager/CONTEXT.md','manager/agents.md','manager/SKILL.md',
                  'manager/docs/experience.md','manager/user-manual/README.md']:
            self.write(p,'<!-- 定位：测试 -->\n# 标题\n')
    def write(self,p,s):
        path=self.root/p;path.parent.mkdir(parents=True,exist_ok=True);path.write_text(s,encoding='utf-8')
    def test_valid_structure(self):
        self.assertEqual(docs.check(self.root)[1],[])
    def test_missing_link(self):
        self.write('manager/CONTEXT.md','<!-- 定位：测试 -->\n# 标题\n[坏链接](missing.md)')
        self.assertTrue(any('missing link target' in e for e in docs.check(self.root)[1]))
    def test_heading_anchor(self):
        self.write('manager/CONTEXT.md','<!-- 定位：测试 -->\n# 标题\n[正确](#标题)\n[错误](#不存在)')
        self.assertEqual(len(docs.check(self.root)[1]),1)
    def test_header_and_index_limit(self):
        self.write('manager/CONTEXT.md','# 标题\n'+'过长\n'*81)
        errors=docs.check(self.root)[1]
        self.assertTrue(any('positioning' in e for e in errors))
        self.assertTrue(any('L1 limit' in e for e in errors))
    def test_private_and_skill_body_not_validated(self):
        for p in ['manager/privacy.md','manager/SKILL.md']:
            self.write(p,'<!-- 定位：元数据 -->\n[不是公开文档](missing-private.md)\n')
        self.assertEqual(docs.check(self.root)[1],[])
    def test_current_project(self):
        self.assertEqual(docs.check(ROOT)[1],[])

if __name__ == '__main__':unittest.main()
