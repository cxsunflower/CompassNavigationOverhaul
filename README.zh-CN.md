# Compass Navigation Overhaul VR

[English](README.md) · **简体中文**

## 项目目录结构

```text
CompassNavigationOverhaul/
├── assets/
│   ├── main/                       英文主包，保持游戏 Data 安装目录
│   ├── localization/zh-CN/         中文覆盖包，保持同样的 Data 目录
│   ├── source/questlist/           不可变 SWF 基底与 SVG 素材
│   └── generated/                  QuestList 与嵌入前 Compass 中间件
├── cmake/                          vcpkg 工具链覆盖与 CommonLibSSE-NG 端口
├── decompiled/                     原版 Mod 的反编译参考源码
├── manager/                        项目上下文、专项文档、历史与使用手册
├── include/                        RE 类型桩、IUI/NND API 与工具头文件
├── source/                         SKSE 实现：hooks / hud / questlist / settings / ui
├── swf/                            HUD 影片的 ActionScript 2 源码与 .fla 工程
├── tools/                          Python 打包、补丁与校验脚本
├── AGENTS.md                       AI 协作规范（Git 提交信息）
├── build.bat                       编译打包脚本
├── CMakeLists.txt
├── CMakePresets.json               build-relwithdebinfo-vr-only 预设
├── CommonLibSSE.natvis             Visual Studio 调试可视化文件
├── vcpkg.json                      vcpkg 依赖清单
└── LICENSE
```

编译产物位于 `build\relwithdebinfo-vr-only\CompassNavigationOverhaulVR.dll`（编译出的 DLL）、`build\package`（打包暂存目录）和 `dist`（发布压缩包）。`build` 与 `dist` 为生成目录，可随时删除。DLL 文件名、SKSE 插件名和版本资源均由 CMake 工程名 `CompassNavigationOverhaulVR` 决定。

模块职责见 [C++ 导航](source/README.md)；发布输入与素材边界见 [资源说明](assets/README.md)。

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

## 文档与 SWF 工作流

- [文档索引](manager/CONTEXT.md) · [QuestList 当前说明](manager/docs/quest-list.md) · [历史记录](manager/docs/quest-list-history.md)
- [工具说明](tools/README.md)：SWF 重建还需 Python 3、Java、JPEXS 的 `ffdec-cli.jar`；反编译回归测试需 Node.js。
- 改 ActionScript 后，先重建受影响的 SWF/罗盘基底，再嵌入两份 Compass 并校验，最后打包。`build.bat` 不自动编译 ActionScript，只检查哈希一致性。
- 版本以 `vcpkg.json` 的 `version-string` 为准。打包不等于已部署到 MO2；VR 效果必须单独验收。

## Git 跟踪边界

忽略 `build/`、`out/`、`dist/`、`cache/`、依赖安装目录及本机 IDE/临时文件。保留发布输入 `assets/`、AS2/FLA/SWF、原始与罗盘基底、SVG 素材、构建清单和测试，避免忽略二进制通配符破坏重建链。生成的 SWF 与哈希清单应随对应源码一起审阅。

## 项目管家入口

AI 接手时先读根目录 AGENTS.md，再读 [项目索引](manager/CONTEXT.md) 与 [项目约定](manager/agents.md)，按任务加载专项文档。玩家与开发者均可从 [使用手册](manager/user-manual/README.md) 上手。项目文档统一维护于 manager/，根目录旧 docs/ 已移除。
