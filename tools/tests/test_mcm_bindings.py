"""Regression tests for MCM INI bindings; never mutate release files."""
import copy
import configparser
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location("validator", ROOT / "tools/verify_mcm_config_zhcn.py")
v = importlib.util.module_from_spec(spec)
spec.loader.exec_module(v)

class BindingsTests(unittest.TestCase):
    def setUp(self):
        self.en = json.loads(v.EN.read_text(encoding="utf-8"))
        self.zh = json.loads(v.ZH.read_text(encoding="utf-8"))
        self.ini = (v.MCM_ASSET_DIR / "settings.ini").read_text(encoding="utf-8")
        v.errors.clear()

    def check(self, ini=None, en=None, zh=None, source=None):
        with tempfile.TemporaryDirectory() as directory:
            p = Path(directory) / "settings.ini"
            p.write_text(self.ini if ini is None else ini, encoding="utf-8")
            src = None
            if source is not None:
                src = Path(directory) / "Settings.cpp"
                src.write_text(source, encoding="utf-8")
            v.check_bindings(self.en if en is None else en, self.zh if zh is None else zh, p, src)

    def test_current_configuration(self):
        self.check()
        self.assertEqual(v.errors, [])

    def test_quest_list_columns(self):
        for language, doc in (("en", self.en), ("zh", self.zh)):
            with self.subTest(language=language):
                page = doc["pages"][1]
                self.assertEqual(page["cursorFillMode"], "topToBottom")
                content = page["content"]
                headers = [(i, item) for i, item in enumerate(content) if item["type"] == "header"]
                self.assertEqual(len(headers), 2)
                self.assertEqual([item.get("position") for _, item in headers], [0, 1])
                left = content[headers[0][0] + 1:headers[1][0]]
                right = content[headers[1][0] + 1:]
                self.assertEqual([item["id"] for item in left], [
                    "fOffsetX:QuestList", "fTextScale:QuestList",
                    "bShowInExteriors:QuestList", "bShowInInteriors:QuestList", "bHideInCombat:QuestList",
                ])
                self.assertEqual([item["id"] for item in right], [
                    "bRequireLookingAtCompass:QuestList", "bRequireCompassVisible:QuestList",
                    "uCompassGazeMode:QuestList", "fCompassGazeAngleToShow:QuestList",
                    "fCompassGazeAngleToKeep:QuestList", "fCompassMaxDistance:QuestList",
                    "fCompassGazePitchToShow:QuestList", "fCompassGazePitchToKeep:QuestList",
                    "bCompassOnPalm:QuestList",
                ])

    def test_compass_gaze_default_enabled(self):
        key = "bRequireLookingAtCompass"
        for path in (v.MCM_ASSET_DIR / "settings.ini", ROOT / "assets/main/SKSE/Plugins/CompassNavigationOverhaulVR.ini"):
            with self.subTest(path=path):
                ini = configparser.ConfigParser(interpolation=None)
                ini.read(path, encoding="utf-8-sig")
                self.assertEqual(ini.getint("QuestList", key), 1)
        header = (ROOT / "include/Settings.h").read_text(encoding="utf-8-sig")
        self.assertRegex(header, r"\brequireLookingAtCompass\s*=\s*true\s*;")
        source = v.read_settings_bindings()
        self.assertIn('MakeSetting("bRequireLookingAtCompass:QuestList", requireLookingAtCompass)', source)
        self.assertRegex(source, r'if\s*\(name\s*==\s*"bRequireLookingAtCompass:QuestList"\)\s*\{\s*requireLookingAtCompass\s*=\s*a_setting->GetBool\(\)')
        for language, doc in (("en", self.en), ("zh", self.zh)):
            with self.subTest(language=language):
                item = next(i for p in doc["pages"] for i in p["content"] if i.get("id") == key + ":QuestList")
                self.assertEqual(item["type"], "toggle")
                self.assertEqual(item["valueOptions"]["sourceType"], "ModSettingBool")
                self.assertIn("Default: Enabled" if language == "en" else "默认：开启", item["help"])

    def test_all_hud_diagnostics_follow_mcm_log_level(self):
        for path in (v.MCM_ASSET_DIR / "settings.ini", ROOT / "assets/main/SKSE/Plugins/CompassNavigationOverhaulVR.ini"):
            ini = configparser.ConfigParser(interpolation=None)
            ini.read(path, encoding="utf-8-sig")
            self.assertEqual(ini.getint("Debug", "uLogLevel"), 2)
            self.assertNotIn("bdebugoverlay", ini["Debug"])
        source = v.read_settings_bindings()
        self.assertNotIn("bDebugOverlay", source)
        header = (ROOT / "include/Settings.h").read_text(encoding="utf-8-sig")
        self.assertIn("return logLevel <= logger::level::debug;", header)
        self.assertNotIn("inline bool overlay", header)
        lifecycle = (ROOT / "source/ui/SettingsLifecycle.cpp").read_text(encoding="utf-8-sig")
        self.assertIn('const bool enabled = settings::debug::IsDebugEnabled();', lifecycle)
        self.assertIn('compass->Invoke("SetDebugOverlay", enabled, settings::debug::calibrateQuestList, a_snapshot);', lifecycle)
        self.assertIn('PollDebugOverlay(true);', lifecycle)
        self.assertIn('milliseconds(100)', lifecycle)
        self.assertNotIn('SetLayoutDebug', lifecycle)
        debug = (ROOT / "swf/compass/Debug.as").read_text(encoding="utf-8-sig")
        self.assertIn('debugOverlay._visible = gate == "visible";', debug)
        self.assertIn('debugQueue.length >= 12', debug)
        self.assertNotIn('beginFill(', debug)

    def test_native_ini_reader_normalizes_bom_without_editing_saved_settings(self):
        helper = (ROOT / "source/utils/INIInput.cpp").read_text(encoding="utf-8-sig")
        reader = (ROOT / "source/utils/INISettingCollection.cpp").read_text(encoding="utf-8-sig")
        loading = (ROOT / "source/settings/Loading.cpp").read_text(encoding="utf-8-sig")
        self.assertIn("0xEF, 0xBB, 0xBF", helper)
        self.assertIn("GetTempFileNameW", helper)
        self.assertIn("std::filesystem::remove(temporaryPath, ec)", helper)
        self.assertIn("INIInput input(iniPath);", reader)
        self.assertIn("input.GetPath().string()", reader)
        self.assertIn("_this()->ReadAllSettings();", reader)
        self.assertIn("[Settings] effective logLevel=", loading)
        self.assertIn("[HUDDebug]", (ROOT / "source/ui/SettingsLifecycle.cpp").read_text(encoding="utf-8-sig"))

    def test_wrong_section_detected(self):
        bad = self.ini.replace("fMarkerNameScale=100\n", "")
        bad = bad.replace("[QuestList]", "[QuestList]\nfMarkerNameScale=100")
        self.check(ini=bad)
        self.assertTrue(any("fMarkerNameScale:Display missing" in x for x in v.errors))

    def test_both_languages_help_defaults(self):
        for language in ("en", "zh"):
            with self.subTest(language=language):
                v.errors.clear()
                doc = copy.deepcopy(getattr(self, language))
                item = next(i for p in doc["pages"] for i in p["content"] if i.get("id") == "fOffsetX:QuestList")
                label = "Default: 0" if language == "en" else "默认：0"
                replacement = "Default: 1" if language == "en" else "默认：1"
                item["help"] = item["help"].replace(label, replacement)
                self.check(**{language: doc})
                self.assertTrue(any("help default" in x for x in v.errors))

    def test_retired_positions_absent_horizontal_offset_preserved(self):
        paths = [ROOT / 'include/Settings.h', ROOT / 'source/settings/Registration.cpp',
                 ROOT / 'source/settings/Dispatch.cpp', v.MCM_ASSET_DIR / 'settings.ini',
                 ROOT / 'assets/main/SKSE/Plugins/CompassNavigationOverhaulVR.ini']
        for path in paths:
            text = path.read_text(encoding='utf-8-sig')
            for key in ('fPositionX', 'fPositionY', 'positionX', 'positionY', 'fOffsetY', 'offsetY'):
                self.assertNotIn(key, text, str(path))
        source = v.read_settings_bindings()
        for axis in ('X',):
            self.assertIn('MakeSetting("fOffset' + axis + ':QuestList", offset' + axis + ')', source)
            self.assertIn('fOffset' + axis + '=0', self.ini)
        for doc in (self.en, self.zh):
            ids = {i.get('id') for p in doc['pages'] for i in p['content'] if i.get('id')}
            self.assertTrue({'fOffsetX:QuestList'} <= ids)
            self.assertFalse({'fPositionX:QuestList', 'fPositionY:QuestList', 'fOffsetY:QuestList'} & ids)

    def test_horizontal_offset_range_and_bridge(self):
        for doc in (self.en, self.zh):
            item = next(i for p in doc['pages'] for i in p['content'] if i.get('id') == 'fOffsetX:QuestList')
            self.assertEqual((item['valueOptions']['min'], item['valueOptions']['max'], item['valueOptions']['step']), (-200, 200, 5))
        dispatch = (ROOT / 'source/settings/Dispatch.cpp').read_text(encoding='utf-8-sig')
        self.assertIn('offsetX = std::max(-200.0F, std::min(200.0F,', dispatch)
        bridge = (ROOT / 'source/questlist/Bridge.cpp').read_text(encoding='utf-8-sig')
        self.assertIn('Invoke("SetOffsetX", settings::questlist::offsetX);', bridge)
        self.assertNotIn('SetOffsets', bridge)

    def test_retired_height_setting_absent(self):
        self.assertNotIn("fMaxHeight", self.ini)
        for doc in (self.en, self.zh):
            ids = {i.get("id") for p in doc["pages"] for i in p["content"] if i.get("id")}
            self.assertNotIn("fMaxHeight:QuestList", ids)
        source = v.read_settings_bindings()
        self.assertNotIn("fMaxHeight:QuestList", source)
        self.assertNotIn("maxHeight", source)

    def test_missing_native_binding(self):
        self.check(source="")
        self.assertTrue(any("missing C++ registration" in x for x in v.errors))
        self.assertTrue(any("missing C++ change handler" in x for x in v.errors))

    def test_out_of_range_default(self):
        self.check(ini=self.ini.replace("fMarkerNameScale=100", "fMarkerNameScale=999"))
        self.assertTrue(any("invalid slider range" in x for x in v.errors))

    def test_duplicate_ini_key(self):
        self.check(ini=self.ini.replace("fMarkerNameScale=100", "fMarkerNameScale=100\nfMarkerNameScale=200"))
        self.assertTrue(any("Settings input" in x for x in v.errors))

if __name__ == "__main__":
    unittest.main()
