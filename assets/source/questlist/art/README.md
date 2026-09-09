# QuestList objective artwork

These SVGs are vector traces of the three PNG assets supplied for this project. They preserve the original silhouettes and colors; the small antialiasing differences are intentional consequences of vectorization, not a redesign.

| Source PNG | SVG | Original SHA256 |
| --- | --- | --- |
| `Journal Basic.png` | `divider.svg` | `89a13a70fbda4f514fa09e1cef1c8a25008eea4ace4b7ea524e9a85faa9f6185` |
| `Quest Active Hover.png` | `completed.svg` | `f99fc2c6cd2f54962a1eb6b00b91574abf68718fa9bfbc097774c08fb814dc7b` |
| `Quest.png` | `pending.svg` | `f765210004a0f0965a4bebabf8299d7575acb31dd675daba4d2493b2a03c42da` |

The divider has a blank middle and no lettering. The HUD adds a localized `OBJECTIVES` label in that space. Pending objectives use the hollow diamond; completed objectives use the filled diamond. Failed objectives use the hollow diamond at reduced opacity.

`tools/build_questlist_art.py` converts these SVGs into native DefineShape4 resources and one-frame exported sprites. The source artwork is reconstructed from the immutable `assets/source/questlist/QuestItemList.HUDMenu-original.swf`, rather than appended to a previously generated movie. The normal `tools/build_questlist_swf.py` workflow now generates the artwork and imports the AS2 scripts together, checking that non-action tags are unchanged by script compilation.

| Resource | Shape ID | Sprite ID | Embedded Shape / Sprite |
| --- | ---: | ---: | --- |
| `QuestObjectivesDivider` | 300 | 303 | 800 / 803 |
| `QuestObjectiveCompleted` | 301 | 304 | 801 / 804 |
| `QuestObjectivePending` | 302 | 305 | 802 / 805 |

The embedded ID offset is 500; the QuestList container remains Sprite 511. The build manifest includes the original SWF, artwork sources, build scripts and generated movie. Use `python tools/build_questlist_swf.py --ffdec <jar>` to rebuild and `--check` to verify the hashes. For a non-deploying Compass check, use `python tools/embed_questlist_compass.py --ffdec <jar> --output build/compass-step3-preflight.swf`.

The original title artwork and animations are preserved. Do not deploy a separate QuestItemList movie or re-enable the abandoned Palm UV/mesh modifications. Actual VR appearance must still be tested in game.
