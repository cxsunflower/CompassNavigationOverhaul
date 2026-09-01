# Compass Navigation Overhaul VR

[English](README.md) · **简体中文**

## 项目目录结构

```text
CompassNavigationOverhaul/
├── assets/
│   └── main/                       原样复制进发布包的文件
│       ├── Interface/InfinityUI/   HUD 影片：HUDMenu（平面）与 VR_HMD_info（VR）
│       ├── MCM/Config/...          MCM Helper 配置：config.json、config.zh-CN.json、settings.ini
│       ├── SKSE/Plugins/           CompassNavigationOverhaulVR.ini 默认用户设置
│       └── Compass Navigation Overhaul VR.esp   MCM 空壳插件
├── cmake/                          vcpkg 工具链覆盖与 CommonLibSSE-NG 端口
├── decompiled/                     原版 Mod 的反编译参考源码
├── include/                        RE 类型桩、IUI/NND API 与工具头文件
├── source/                         SKSE 插件实现
├── swf/                            HUD 影片的 ActionScript 2 源码与 .fla 工程
├── tools/                          Python 打包、补丁与校验脚本
├── build.bat                       编译打包脚本
├── CMakeLists.txt
├── CMakePresets.json               build-relwithdebinfo-vr-only 预设
├── vcpkg.json                      vcpkg 依赖清单
├── VERSION                         build.bat 读取的版本号
└── LICENSE
```

编译产物位于 `build\relwithdebinfo-vr-only\CompassNavigationOverhaulVR.dll`（编译出的 DLL）、`build\package`（打包暂存目录）和 `dist`（发布压缩包）。`build` 与 `dist` 为生成目录，可随时删除。DLL 文件名、SKSE 插件名和版本资源均由 CMake 工程名 `CompassNavigationOverhaulVR` 决定。

## build.bat 配置值

编辑 `build.bat` 顶部的本机配置：

- `VS_VCVARS`：Visual Studio 的 `vcvars64.bat`。编译时必填；`nobuild` 不使用。
- `SDK_ROOT`、`SDK_VER`：Windows SDK 路径和版本。可选——默认 SDK 布局可用时 `SDK_ROOT` 留空。
- `VS_CMAKE_BIN`、`VS_NINJA_BIN`：CMake 与 Ninja 目录。可选——已在 `PATH` 中时留空。
- `VCPKG_ROOT_CFG`：初始化后的 vcpkg 根目录，配置与编译步骤必填；使用 Visual Studio 自带的 vcpkg 也可以。
- `SEVENZIP`：`7z.exe` 路径。可选——脚本也会在 `PATH` 中查找；完全找不到时跳过压缩包生成，仅保留 `build\package` 下的打包目录。
- `MAKE_CHS`：中文包开关。可选——`1`（默认）同时生成 `-CHS` 覆盖包；`0` 只生成英文主包。

脚本中其余变量均由脚本所在位置自动推导，无需修改。

## 命令

```bat
build.bat           增量配置、编译并打包
build.bat nobuild   不编译，直接打包已有的 build\relwithdebinfo-vr-only\CompassNavigationOverhaulVR.dll
build.bat clean     删除 build\ 后完整配置、编译并打包
```

环境要求：Visual Studio（“使用 C++ 的桌面开发”工作负载）、CMake 3.21+ 与 Ninja（可直接使用 Visual Studio 自带版本）、Git，以及完成 bootstrap 的 [vcpkg](https://github.com/microsoft/vcpkg)。首次配置会下载并编译 `vcpkg.json` 锁定的依赖。
