"""Regression tests for the source-module assembler and preserved SWF entrypoints."""

import hashlib
from pathlib import Path
import re
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))

import build_questlist_swf as builder
from questlist_source import ENTRYPOINTS, compose, compose_all


class SourceModulesTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.write("swf/QuestItem.as", 'class QuestItem extends MovieClip {\n// @include "item/A.as"\n}\n')
        self.write("swf/QuestItemList.as", '// @include "list/A.as"\nstop();\n')
        self.write("swf/questlist/item/A.as", "function QuestItem() {}\n")
        self.write("swf/questlist/list/A.as", "function QuestItemList() {}\n")

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text, encoding="utf-8")
        return path

    def test_real_source_inventory_and_public_contract(self):
        sources = compose_all(ROOT)
        self.assertEqual(tuple(sources), ENTRYPOINTS)
        self.assertEqual(sum(len(deps) - 1 for _, deps in sources.values()), 13)
        timeline = sources["swf/QuestItemList.as"][0]
        item = sources["swf/QuestItem.as"][0]
        # Includes the Passenger geometry and bounded diagnostic helpers.
        self.assertEqual(len(re.findall(r"(?m)^\s*(?:(?:public|private|static)\s+)*function\s+\w+\s*\(", timeline)), 61)
        self.assertEqual(len(re.findall(r"(?m)^\s*(?:(?:public|private|static)\s+)*function\s+\w+\s*\(", item)), 31)
        self.assertRegex(timeline, r"stop\(\);\s*$")
        self.assertEqual(timeline.count("_global.gfxExtensions = true;"), 1)
        self.assertEqual(item.count("class QuestItem extends MovieClip"), 1)
        self.assertIn("function AddQuest(a_type:Number, a_title:String, a_description:String, a_isInSameLocation:Boolean, a_objectives:Array, a_ageIndex:Number)", timeline)
        self.assertIn("function SetQuestInfo(a_type:Number, a_title:String, a_description:String, a_isInSameLocation:Boolean, a_objectives:Array, a_ageIndex:Number)", item)
        for name in ("SetPanelSurface", "SetAnchor", "UpdateAnchor", "SetOffsets", "SetTextScale", "SyncQuests", "GetLayoutSnapshot", "SetLayoutDebug", "GetLayoutDebugVisibility", "GetLayoutDebugState", "Update", "onEnterFrame", "onUnload"):
            self.assertIn("function " + name + "(", timeline)
        for name in ("GetContentBounds", "ApplyHeightLimit", "ReflowWidth", "GetLayoutDebugRegions", "SetSide", "Show", "Remove"):
            self.assertIn("function " + name + "(", item)
        self.assertNotIn("SetMaxHeight", timeline + item)

    def test_nested_includes_keep_the_original_scope(self):
        self.write("swf/questlist/item/A.as", '// @include "item/B.as"\nfunction QuestItem() {}\n')
        self.write("swf/questlist/item/B.as", "function Helper():Void { return; }\n")
        source, dependencies = compose("swf/QuestItem.as", self.root)
        self.assertIn("function Helper():Void", source)
        self.assertEqual(dependencies, ["swf/QuestItem.as", "swf/questlist/item/A.as", "swf/questlist/item/B.as"])

    def test_missing_module_is_rejected(self):
        (self.root / "swf/questlist/item/A.as").unlink()
        with self.assertRaisesRegex(ValueError, "Missing or unsafe"):
            compose_all(self.root)

    def test_duplicate_include_is_rejected(self):
        self.write("swf/QuestItem.as", 'class QuestItem extends MovieClip {\n// @include "item/A.as"\n// @include "item/A.as"\n}\n')
        with self.assertRaisesRegex(ValueError, "Duplicate QuestList include"):
            compose_all(self.root)

    def test_circular_include_is_rejected(self):
        self.write("swf/questlist/item/A.as", '// @include "item/B.as"\n')
        self.write("swf/questlist/item/B.as", '// @include "item/A.as"\n')
        with self.assertRaisesRegex(ValueError, "Circular QuestList include"):
            compose_all(self.root)

    def test_path_escape_and_malformed_directive_are_rejected(self):
        for directive in ('// @include "../private.as"', '// @include "/private.as"', '// @include "item/A.txt"'):
            with self.subTest(directive=directive):
                self.write("swf/QuestItemList.as", directive + "\n")
                with self.assertRaises(ValueError):
                    compose("swf/QuestItemList.as", self.root)

    def test_orphan_and_cross_entrypoint_modules_are_rejected(self):
        extra = self.write("swf/questlist/item/Unused.as", "function Unused() {}\n")
        with self.assertRaisesRegex(ValueError, "inventory mismatch"):
            compose_all(self.root)
        extra.unlink()
        self.write("swf/QuestItemList.as", '// @include "item/A.as"\nstop();\n')
        with self.assertRaisesRegex(ValueError, "multiple entrypoints"):
            compose_all(self.root)

    def test_duplicate_methods_and_extra_classes_are_rejected(self):
        self.write("swf/questlist/item/A.as", "function QuestItem() {}\nfunction QuestItem() {}\n")
        with self.assertRaisesRegex(ValueError, "Duplicate QuestList functions"):
            compose_all(self.root)
        self.write("swf/questlist/item/A.as", "function QuestItem() {}\nclass Extra {}\n")
        with self.assertRaisesRegex(ValueError, "original MovieClip class"):
            compose_all(self.root)

    def test_unknown_entrypoint_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "Unknown QuestList entrypoint"):
            compose("swf/questlist/item/A.as", self.root)

    def test_hash_manifest_tracks_every_module(self):
        self.write("artifact.swf", "artifact")
        with patch.object(builder, "ROOT", self.root), patch.object(builder, "INPUTS", list(ENTRYPOINTS)), patch.object(builder, "TARGETS", ["artifact.swf"]):
            first = builder.hashes()
            self.assertIn("swf/questlist/item/A.as", first)
            self.assertIn("swf/questlist/list/A.as", first)
            self.write("swf/questlist/item/A.as", "function QuestItem() { var changed:Number = 1; }\n")
            second = builder.hashes()
            self.assertNotEqual(first["swf/questlist/item/A.as"], second["swf/questlist/item/A.as"])
            self.assertEqual(second["swf/questlist/item/A.as"], hashlib.sha256((self.root / "swf/questlist/item/A.as").read_bytes()).hexdigest())


if __name__ == "__main__":
    unittest.main()
