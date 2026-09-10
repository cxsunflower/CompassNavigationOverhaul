# QuestList Journal-vector skin

The default objective skin now uses four original vector shapes extracted from a locally installed SkyUI VR `quest_journal.swf`. It does not trace PNGs, load the Journal menu, instantiate `QuestsPage`, or import Journal fonts/scripts.

## Source and provenance

`journal-shapes.xml` records the source SWF SHA256, descriptive source label and original character IDs. It contains only the four selected shape definitions. The default shapes were also compared with the installed translated Journal and its active-quest fix: their geometry and colors match. Original IDs are evidence for this extraction, not a universal interface for other UI mods.

`tools/extract_journal_art.py` resolves exported `ObjectiveListItem` states (`Normal`, `Completed`, `Failed`) and the named `QuestsPage.objectivesHeader` child. It rejects ambiguous or bitmap-backed art instead of guessing. This is an explicit authoring operation, not a normal-build scan of the player's installation. To extract another compatible source:

```powershell
python tools/extract_journal_art.py --ffdec <ffdec-cli.jar> --source-journal <quest_journal.swf> --source-label "Source description"
```

Original game/SkyUI artwork remains subject to its original rights. Extraction and this project's code license do not grant new redistribution rights to those assets; check permissions before publishing a derivative skin. No complete third-party Journal SWF is included.

The retired `divider.svg`, `completed.svg` and `pending.svg` traces have been removed from the working source tree. Their history remains in Git; they are not build inputs or runtime artwork.

## Independent skin contract

The required library is `!assets/QuestItemListSkin.swf`, next to each of the two release Compass movies:

```text
Interface/InfinityUI/HUDMenu/HUDMovieBaseInstance/CompassShoutMeterHolder/!assets/QuestItemListSkin.swf
Interface/InfinityUI/VR_HMD_info/HUDMovieBaseInstance/CompassShoutMeterHolder/!assets/QuestItemListSkin.swf
```

| Export name | Canvas and behavior |
| --- | --- |
| `QuestObjectivesDivider` | 481.25 x 14.85; origin 0,0; left wing x=0..172.75, blank center x=172.75..308.5, right wing x=308.5..481.25; no baked-in text |
| `QuestObjectivePending` | 18 x 27 transparent slot; original hollow diamond fitted uniformly |
| `QuestObjectiveCompleted` | 18 x 27 transparent slot; original filled diamond fitted uniformly |
| `QuestObjectiveFailed` | 18 x 27 transparent slot; original square-aspect failed cross fitted uniformly |

The icon wrapper includes transparent bounds to keep layout stable. Source colors and vector records remain unchanged. No extra diamond thickening is introduced; the existing runtime 4/4/4 black filter and 18 x 27 row slot stay in place. The native failed cross uses its original subdued color at full clip opacity, rather than dimming it twice. Existing primitives remain only as attachment-failure fallbacks; a missing library is an installation error, not a supported skin.

A compatible cosmetic patch can override these two small SWFs through MO2, without rebuilding the DLL or modifying layout scripts. Preserve export names, canvas/origin, blank-center geometry and script-free single-frame symbols. Character IDs inside the replacement library are not an external API. Normal Journal UI replacers do not automatically change this independent skin. Adapting artwork of different dimensions requires fitting it to this contract, not blindly substituting a source file.

The build imports the four symbols as local IDs 303/304/305/307, remapped by +500 when embedding QuestList in Compass. The skin's own internal IDs are separate. `build_questlist_art.py` verifies original shape geometry/colors after SWF round-trip and rejects menu scripts, imports and fonts. `build_questlist_swf.py` tracks the extraction and both skin outputs in its manifest.

## Existing upper detail artwork versus the new skin

The existing upper detail library is `QuestItemListArt.swf`, with the authoring project at `swf/_assets/QuestItemListArt.fla`. Git traces that project to `0aa7c98` (moving artwork to an external SWF); the immutable SWF matches both original checked-in copies from `e683dfd` byte-for-byte. Its exported `QuestTitleEndPiece` contains 11 quest-type frames and `QuestTitleBracket` contains 193 frames. This establishes the project's retained source, not the ultimate authorship of every vector; direct origin from vanilla game art has not been proven.

Both libraries use `ImportAssets2` and the existing `!assets` resource mechanism. The upper detail symbols are placed on the original timeline and selected by frame; objective symbols are created dynamically with `attachMovie`. Neither library reads the player's current Journal at runtime. Replacing one library does not replace the other, and UI adapters must preserve the respective export and animation/canvas contracts.

## Boundaries and verification

The original upper title artwork `QuestItemListArt.original.swf` and both published `QuestItemListArt.swf` files remain byte-for-byte unchanged. QuestList stays embedded in Compass; the new library contains only graphics, not a second runtime list or `loadMovie` boundary. Do not deploy standalone `QuestItemList.swf` or restore withdrawn Palm UV/mesh changes.

Run the normal [build workflow](../../../../tools/README.md) and `python -m unittest discover -s tools/tests -p 'test_*.py'`, then export the final Compass for the layout, observer and distance regressions. A composed preview using exported skin SVGs confirms asset selection only, not game font rendering, filters, MO2 resolution or VR behavior. This change is built but not deployed; in-game verification is still required.
