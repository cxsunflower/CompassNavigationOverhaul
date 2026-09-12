"""CI package tests use temporary synthetic inputs, never local release outputs."""
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('ci_tools', ROOT / 'tools/ci.py')
ci = importlib.util.module_from_spec(spec)
spec.loader.exec_module(ci)

class CITests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.sha = 'a' * 40
        files = {
            'vcpkg.json': '{"version-string":"1.2.3"}',
            'LICENSE': 'test license',
            'build/relwithdebinfo-vr-only/CompassNavigationOverhaulVR.dll': 'dll',
            'assets/main/SKSE/Plugins/CompassNavigationOverhaulVR.ini': '[Debug]\nuLogLevel=2',
            f'assets/main/MCM/Config/{ci.MOD}/config.json': '{"language":"en"}',
            f'assets/localization/zh-CN/MCM/Config/{ci.MOD}/config.json': '{"language":"zh"}',
        }
        for name, data in files.items():
            p = self.root / name
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_text(data, encoding='utf-8')

    def test_package_and_verify_provenance(self):
        ci.package(self.root, self.sha)
        ci.verify_release(self.root / 'dist', self.sha, '1.2.3')
        self.assertEqual((self.root / f'build/package/chs/MCM/Config/{ci.MOD}/config.json').read_text(), '{"language":"zh"}')
        self.assertEqual(len(list((self.root / 'dist').glob('*.zip'))), 2)

    def test_reject_changed_archive(self):
        ci.package(self.root, self.sha)
        p = next((self.root / 'dist').glob('*.zip'))
        p.write_bytes(p.read_bytes() + b'tampering')
        with self.assertRaisesRegex(ValueError, 'hash mismatch'):
            ci.verify_release(self.root / 'dist', self.sha, '1.2.3')

    def test_reject_wrong_source_or_version(self):
        ci.package(self.root, self.sha)
        for sha, ver in [('b' * 40, '1.2.3'), (self.sha, '1.2.4')]:
            with self.assertRaises(ValueError):
                ci.verify_release(self.root / 'dist', sha, ver)

    def test_reject_extra_or_missing_archives(self):
        ci.package(self.root, self.sha)
        extra = self.root / 'dist/extra.zip'
        extra.write_bytes(b'extra')
        with self.assertRaises(ValueError):
            ci.verify_release(self.root / 'dist', self.sha, '1.2.3')
        extra.unlink()
        next((self.root / 'dist').glob('*.zip')).unlink()
        with self.assertRaises(ValueError):
            ci.verify_release(self.root / 'dist', self.sha, '1.2.3')

    def test_version_cannot_escape_output_directory(self):
        (self.root / 'vcpkg.json').write_text(json.dumps({'version-string': '../bad'}))
        with self.assertRaises(ValueError):
            ci.package(self.root, self.sha)
        with self.assertRaises(ValueError):
            ci.package(self.root, 'not-a-sha')

    def test_workflows_use_current_inputs_and_manual_release(self):
        workflows = ROOT / '.github/workflows'
        build = (workflows / 'build.yml').read_text(encoding='utf-8')
        release = (workflows / 'release.yml').read_text(encoding='utf-8')
        combined = (workflows / 'build-release.yml').read_text(encoding='utf-8')
        self.assertIn('submodules: recursive', build)
        self.assertIn('verify_package.py', (ROOT / 'tools/ci.py').read_text(encoding='utf-8'))
        for name in ('questlist_layout.test.cjs', 'compass_debug.test.cjs', 'compass_marker_scale.test.cjs'):
            self.assertIn(name, build)
        self.assertIn('uses: ./.github/workflows/build.yml', combined)
        self.assertIn('default: false', combined)
        self.assertIn('target_commitish: ${{ steps.source.outputs.sha }}', release)
        self.assertIn("r['event'] == 'workflow_dispatch'", release)
        for path in workflows.glob('*.yml'):
            self.assertNotIn('Get-Content VERSION', path.read_text(encoding='utf-8'))

if __name__ == '__main__':
    unittest.main()
