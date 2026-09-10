# QuestList AS2 source modules

This directory contains the editable implementation of the quest-detail UI. The original SWF linkage and timeline entrypoints remain `swf/QuestItem.as` and `swf/QuestItemList.as`. The files here are **source fragments**, not separately loaded SWF classes or movies.

## Source ownership

```text
swf/
├── QuestItem.as                Class declaration, fields and module list
├── QuestItemList.as            Timeline state, module list and stop()
└── questlist/
    ├── item/
    │   ├── Initialization.as   Original Header references and text defaults
    │   ├── Artwork.as          Divider, icon and label-art construction
    │   ├── Content.as          Quest data, objective creation and row content
    │   ├── Layout.as           Natural width, Box layout and reflow
    │   ├── Geometry.as         Coordinate conversion, bounds and row clipping
    │   ├── Debug.as            Read-only layout diagnostic regions
    │   └── Lifecycle.as        Side-art and original fade entrypoints
    └── list/
        ├── Core.as             Initialization, anchoring, settings and update
        ├── Entries.as          Quest synchronization, sorting and lifecycle
        ├── Layout.as           Viewport fitting, scale search and viewport mask
        ├── Overflow.as         Whole-section omission and ellipsis placement
        ├── Diagnostics.as      Root-space logging and on-demand snapshots
        ├── Debug.as            Read-only visible/full geometry and detailed observations
        └── Calibration.as      Independent boundary calibration and cleanup
```

`tools/questlist_source.py` expands the explicit `// @include "item/Content.as"` directives before the existing JPEXS import. Paths are relative to `swf/questlist/`, not to the including file. The assembler rejects missing, duplicate, circular, escaping and unreferenced modules, as well as duplicate functions or unexpected classes. Every dependency is included in the source/SWF hash manifest.

Keep member declarations and the class wrapper in `QuestItem.as`; keep timeline state declarations, the global initialization and `stop()` in `QuestItemList.as`. Move complete functions into the appropriate fragment. Do not add another class wrapper, independent timeline, runtime `loadMovie`, or manual copies of assembled source. A new source module must be added to an entrypoint and covered by tests. The current AS2 scope is intentionally unchanged so existing native calls, `registerClass` linkage and the original 18-frame animation continue to work.

## Editing and verification

Run these commands from the project root. The optional assembly output is for inspection only and is never a release artifact.

```powershell
python -X utf8 tools/questlist_source.py --output build/questlist-sources
python -X utf8 tools/tests/test_questlist_source.py

$ff = '完整路径\ffdec-cli.jar'
python -X utf8 tools/build_questlist_swf.py --ffdec $ff --output build/questlist-preflight.swf
java -jar $ff -export script build/questlist-preflight build/questlist-preflight.swf
node tools/tests/questlist_layout.test.cjs build/questlist-preflight/scripts/__Packages/QuestItem.as build/questlist-preflight/scripts/frame_1/DoAction.as
python -X utf8 tools/tests/test_questlist_header_layout.py
```

The Node runner in `tools/tests/questlist_layout.test.cjs` uses `questlist/harness.cjs` and three suites: `item.test.cjs`, `layout.test.cjs`, and `debug.test.cjs`. Tests run against the decompiled SWF, not merely the uncompiled fragments. The Python source tests cover module integrity and the preserved public entrypoints.

For a release, build QuestList without `--output`, rebuild the Compass baseline when its source/hash check requires it, embed into both Compass movies, run all three SWF hash checks, then package through `build.bat`. Do not install a standalone QuestItemList SWF. Include both required `!assets/QuestItemListSkin.swf` files when packaging. This script-free symbol library uses the existing asset-import mechanism, not a separately loaded list or Journal menu. Preserve user configurations, existing Git changes and the original upper detail artwork. See [the current build and acceptance guide](../../manager/docs/quest-list.md) for the complete workflow.
Ordinary HUD drawing belongs only to `swf/compass/Debug.as`, composed into Compass. QuestList has 14 source modules; no debug drawing contributes to layout. See [HUD Debug](../../manager/docs/hud-debug.md).
