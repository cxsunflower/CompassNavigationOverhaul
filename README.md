# Compass Navigation Overhaul VR

**English** · [简体中文](README.zh-CN.md)

## First build

1. Install Visual Studio (Desktop C++), CMake 3.21+, Ninja and Git, and bootstrap [vcpkg](https://github.com/microsoft/vcpkg).
2. Get the source (replace `<repository-url>` with the repository URL):

   ```bat
   git clone --recurse-submodules <repository-url> CompassNavigationOverhaul
   cd CompassNavigationOverhaul
   ```

3. Set `VS_VCVARS` and `VCPKG_ROOT_CFG` at the top of `build.bat` ([other settings](#buildbat-values)), then run:

   ```bat
   build.bat
   ```

The first build downloads and compiles dependencies. Packages land in `build\package`; archives land in `dist` (requires 7-Zip). Nothing is deployed to MO2 automatically.

## Project layout

```text
CompassNavigationOverhaul/
├── assets/
│   ├── main/                       English main package in game Data layout
│   ├── localization/zh-CN/         Chinese overlay in the same Data layout
│   ├── source/questlist/           Immutable SWF baselines and SVG artwork
│   └── generated/                  QuestList and pre-embedding Compass movies
├── cmake/                          vcpkg toolchain overlays and the CommonLibSSE-NG port
├── decompiled/                     Decompiled reference sources from the original mod
├── manager/                        Project context, feature docs, history and user manuals
├── include/                        RE type stubs, IUI/NND API headers, utilities
├── source/                         SKSE implementation: hooks / hud / questlist / settings / ui
├── swf/                            ActionScript 2 sources and .fla projects for the HUD movies
├── tools/                          Python packaging, patching, and verification scripts
├── AGENTS.md                       AI agent instructions (Git rules)
├── build.bat                       Build and package script
├── CMakeLists.txt
├── CMakePresets.json               build-relwithdebinfo-vr-only preset
├── CommonLibSSE.natvis             Visual Studio debugger visualizers
├── vcpkg.json                      Dependency manifest for vcpkg
└── LICENSE
```

Build outputs land in `build\relwithdebinfo-vr-only\CompassNavigationOverhaulVR.dll` (compiled DLL), `build\package` (staged package folders), and `dist` (release archives). The `build` and `dist` directories are generated and can be deleted at any time. The DLL, SKSE plugin name, and version resource are all derived from the CMake project name `CompassNavigationOverhaulVR`.

Module responsibilities: [C++ navigation](source/README.md). Release inputs and artwork: [resource layout](assets/README.md).

## build.bat values

Edit the machine-specific block at the top of `build.bat`:

- `VS_VCVARS`: Visual Studio's `vcvars64.bat`. Required for `build.bat` and `build.bat clean`; not used by `nobuild`.
- `SDK_ROOT`, `SDK_VER`: Windows SDK location and version. Optional — leave `SDK_ROOT` empty when the default SDK layout works.
- `VS_CMAKE_BIN`, `VS_NINJA_BIN`: CMake and Ninja directories. Optional — leave empty when already on `PATH`.
- `VCPKG_ROOT_CFG`: bootstrapped vcpkg root. Required for the configure and build steps; the vcpkg bundled with Visual Studio works too.
- `SEVENZIP`: `7z.exe`. Optional — the script also looks it up on `PATH`; when 7-Zip is unavailable, archive generation is skipped and the staged folders under `build\package` are kept.
- `MAKE_CHS`: Chinese package switch. Optional — `1` (default) also generates the `-CHS` overlay archive; `0` builds only the main package.

All other values in the script are derived from the script's own location and need no editing.

## Commands

```bat
build.bat           incremental configure, build, and package
build.bat nobuild   package the existing build\relwithdebinfo-vr-only\CompassNavigationOverhaulVR.dll
build.bat clean     delete build\, then full configure, build, and package
```


## Documentation and SWF workflow

- [Documentation index](manager/CONTEXT.md) · [Current QuestList behavior](manager/docs/quest-list.md) · [Historical notes](manager/docs/quest-list-history.md) (Chinese).
- [Tool reference](tools/README.md): rebuilding SWFs also needs Python 3, Java and JPEXS `ffdec-cli.jar`; decompiled regression tests use Node.js.
- After ActionScript changes, rebuild the affected SWF/Compass baseline, embed both Compass movies, verify, then package. `build.bat` checks hashes but does not compile ActionScript automatically.
- `vcpkg.json` (`version-string`) is the single version source. Packaging does not deploy to MO2; VR acceptance is a separate step.

## Version-control boundaries

Ignore `build/`, `out/`, `dist/`, `cache/`, installed dependencies and local IDE/temporary files. Keep release inputs under `assets/`, AS2/FLA/SWF files, original and Compass baselines, SVG artwork, hash manifests and tests eligible for version control. Do not blanket-ignore binaries needed by the rebuild chain; review generated SWFs and manifests with their source changes.

## Project-manager entry point

Agents start with root AGENTS.md, then [CONTEXT](manager/CONTEXT.md) and [project conventions](manager/agents.md), loading details only as needed. See the [user manual](manager/user-manual/README.md) for player and developer workflows (Chinese). Project documentation is consolidated under manager/; the former root docs/ directory has been removed.
