"""CI package tests use temporary synthetic inputs, never local release outputs."""
import importlib.util
import hashlib
import sys
import json
from pathlib import Path
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
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

        dll = self.root / 'build/relwithdebinfo-vr-only/CompassNavigationOverhaulVR.dll'
        Path(str(dll) + '.build-profile.json').write_text(json.dumps({
            'palmtest': False, 'sha256': hashlib.sha256(dll.read_bytes()).hexdigest()}))

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

    def test_excludes_palmtest_and_mo_metadata_at_any_depth(self):
        import zipfile
        bad = ['meta.ini', 'nested/META.INI', 'CNO_PalmTest_ThirdParty.txt',
               'meshes/CNO/PalmTest.nif', 'textures/CNO/PalmTest.dds',
               'SKSE/Plugins/CNO_PalmTest.ini', 'Interface/CNOQuestPanel/QuestItemListArt.swf']
        for name in bad:
            p = self.root / 'assets/main' / name
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_bytes(b'experimental or MO metadata')
        ci.package(self.root, self.sha)
        for p in (self.root / 'dist').glob('*.zip'):
            with zipfile.ZipFile(p) as z:
                self.assertFalse(any(ci.excluded(n) for n in z.namelist()))
        self.assertFalse(any(ci.excluded(p.relative_to(self.root / 'build/package').as_posix())
                             for p in (self.root / 'build/package').rglob('*')))
        self.assertTrue((self.root / 'assets/main/meta.ini').exists())

    def test_rejects_experimental_missing_or_stale_dll_profile(self):
        dll = self.root / 'build/relwithdebinfo-vr-only/CompassNavigationOverhaulVR.dll'
        profile = Path(str(dll) + '.build-profile.json')
        for data in [None, {'palmtest': True, 'sha256': ci.digest(dll)},
                     {'palmtest': False, 'sha256': '0' * 64}]:
            if data is None:
                profile.unlink()
            else:
                profile.write_text(json.dumps(data))
            with self.assertRaises(ValueError):
                ci.package(self.root, self.sha)

    def test_release_rejects_metadata_even_with_matching_archive_hash(self):
        import zipfile
        for member in ['meta.ini', 'nested/META.INI', 'SKSE/Plugins/CNO_PalmTest.ini']:
            ci.package(self.root, self.sha)
            archive = self.root / 'dist' / f'{ci.MOD} 1.2.3.zip'
            with zipfile.ZipFile(archive, 'a') as z:
                z.writestr(member, 'bad')
            meta = self.root / 'dist/build-metadata.json'
            data = json.loads(meta.read_text())
            data['archives'][archive.name] = ci.digest(archive)
            meta.write_text(json.dumps(data))
            with self.assertRaisesRegex(ValueError, 'Non-production file'):
                ci.verify_release(self.root / 'dist', self.sha, '1.2.3')

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
