# Compass Navigation Overhaul VR

**English** · [简体中文](README.zh-CN.md)

## Project layout

```text
CompassNavigationOverhaul/
├── assets/
│   └── main/                       Files copied verbatim into the release archives
│       ├── Interface/InfinityUI/   HUD movies: HUDMenu (flat) and VR_HMD_info (VR)
│       ├── MCM/Config/...          MCM Helper config: config.json, config.zh-CN.json, settings.ini
│       ├── SKSE/Plugins/           CompassNavigationOverhaulVR.ini default user settings
│       └── Compass Navigation Overhaul VR.esp   MCM shell plugin
├── cmake/                          vcpkg toolchain overlays and the CommonLibSSE-NG port
├── decompiled/                     Decompiled reference sources from the original mod
├── include/                        RE type stubs, IUI/NND API headers, utilities
├── source/                         SKSE plugin implementation
├── swf/                            ActionScript 2 sources and .fla projects for the HUD movies
├── tools/                          Python packaging, patching, and verification scripts
├── build.bat                       Build and package script
├── CMakeLists.txt
├── CMakePresets.json               build-relwithdebinfo-vr-only preset
├── vcpkg.json                      Dependency manifest for vcpkg
├── VERSION                         Version string read by build.bat
└── LICENSE
```

Build outputs land in `build\relwithdebinfo-vr-only\CompassNavigationOverhaulVR.dll` (compiled DLL), `build\package` (staged package folders), and `dist` (release archives). The `build` and `dist` directories are generated and can be deleted at any time. The DLL, SKSE plugin name, and version resource are all derived from the CMake project name `CompassNavigationOverhaulVR`.

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

Prerequisites: Visual Studio with the Desktop C++ workload, CMake 3.21+ and Ninja (the Visual Studio-bundled copies work), Git, and a bootstrapped [vcpkg](https://github.com/microsoft/vcpkg). The first configure downloads and builds the dependencies locked by `vcpkg.json`.
