"""Regression checks for shared CommonLib/plugin runtime selection."""
import json
from pathlib import Path
import unittest

ROOT = Path(__file__).resolve().parents[2]

class RuntimeConfigurationTests(unittest.TestCase):
    def setUp(self):
        self.presets = {p['name']: p for p in json.loads((ROOT / 'CMakePresets.json').read_text())['configurePresets']}
        self.cmake = (ROOT / 'CMakeLists.txt').read_text(encoding='utf-8')

    def resolve(self, name):
        p = self.presets[name]
        values = {}
        for parent in reversed(p.get('inherits', [])):
            values.update(self.resolve(parent))
        values.update(p.get('cacheVariables', {}))
        return values

    def test_all_six_presets_select_explicit_runtime_sets(self):
        for config in ['debug', 'relwithdebinfo']:
            for mode, expected in [('all', ('ON', 'ON', 'ON')), ('se-only', ('ON', 'ON', 'OFF')), ('vr-only', ('OFF', 'OFF', 'ON'))]:
                with self.subTest(config=config, mode=mode):
                    values = self.resolve(f'build-{config}-{mode}')
                    self.assertEqual(tuple(values['ENABLE_SKYRIM_' + key] for key in ['SE', 'AE', 'VR']), expected)

    def test_no_runtime_undefines_in_preset_flags(self):
        text = (ROOT / 'CMakePresets.json').read_text()
        self.assertNotIn('RUNTIME_DISABLE_FLAGS', text)
        self.assertNotIn('UENABLE_SKYRIM', text)
        self.assertNotIn('RUNTIME_DISABLE_FLAGS', self.cmake)

    def test_options_precede_commonlib_configuration(self):
        for runtime in ['SE', 'AE', 'VR']:
            self.assertLess(self.cmake.index('option(ENABLE_SKYRIM_' + runtime), self.cmake.index('add_subdirectory('))

    def test_restricted_bundle_and_package_guards(self):
        self.assertIn('if(NOT CNO_ALL_RUNTIMES AND COMMONLIB_PREBUILT_DIR)', self.cmake)
        self.assertIn('Restricted runtimes require CommonLib source', self.cmake)
        self.assertIn('Restricted runtimes require the CommonLibSSE-NG submodule', self.cmake)

    def test_palmtest_is_opt_in_and_message_entry_is_guarded(self):
        self.assertIn('option(CNO_BUILD_PALMTEST "Build the experimental independent PalmTest panel" OFF)', self.cmake)
        self.assertIn('list(FILTER sources EXCLUDE REGEX "/palmtest/")', self.cmake)
        self.assertIn('list(FILTER headers EXCLUDE REGEX "/palmtest/")', self.cmake)
        for config in ['debug', 'relwithdebinfo']:
            for mode in ['all', 'se-only', 'vr-only']:
                self.assertEqual(self.resolve(f'build-{config}-{mode}')['CNO_BUILD_PALMTEST'], 'OFF')
        source = (ROOT / 'source/MessageListeners.cpp').read_text(encoding='utf-8')
        self.assertIn('#ifdef CNO_BUILD_PALMTEST\n#include "palmtest/PalmTest.h"\n#endif', source)
        self.assertIn('#ifdef CNO_BUILD_PALMTEST\n\tCNO::PalmTest::OnMessage(a_msg->type);\n#endif', source)
        self.assertIn('write_build_profile.cmake', self.cmake)

    def test_deployment_uses_shared_options(self):
        self.assertIn('if(ENABLE_SKYRIM_SE OR ENABLE_SKYRIM_AE)', self.cmake)
        self.assertIn('set(COPY_VR ${ENABLE_SKYRIM_VR})', self.cmake)

if __name__ == '__main__':
    unittest.main()
