<!-- 定位：安装及开发环境指引，区分配置文件、安装包和实际部署。 -->

# 安装与环境

## 玩家安装
1. 确认使用 Skyrim VR 对应的 SKSEVR、SkyUI VR，以及兼容的 MCM Helper 和 Infinity UI。不要只按“最新版”推断兼容性，应核对各安装包说明。
2. 在 MO2 安装主包；中文用户再安装 CHS 覆盖包，让其同路径 config.json 覆盖主包。
3. 检查当前配置中的 `Compass Navigation Overhaul VR.esp`、`MCMHelper.esp` 与依赖启用状态。
4. 完全退出并通过 SKSEVR 启动游戏。检查日志确认 DLL 成功加载后再验收菜单。

只使用项目发布包中的嵌入 Compass 资源，不单独部署 QuestItemList.swf，不应用已撤回的 Palm 网格补偿。当前项目记录已有 MCM Helper 成功注册证据；若菜单仍异常，以本次启动的最新日志为准，见 [调试](debugging.md)。

## 开发环境
- Visual Studio C++、CMake/Ninja、Git 与已初始化的 vcpkg。
- SWF：Python 3、Java、JPEXS 的 ffdec-cli.jar；脚本回归另需 Node.js。
- 本机路径配置见根目录 [中文 README](../../README.zh-CN.md) / [English](../../README.md) 的 build.bat 配置段。
- 源码和生成清单需配套；修改后按 [开发流程](development.md) 验证。

## 配置与产物
默认值、插件 INI、用户保存设置有覆盖优先级，见 [MCM 配置来源](../docs/mcm.md)。发布 ZIP 位于 dist，暂存目录位于 build/package。生成 ZIP 不会自动更新 MO2，既有用户值也不会被默认值自动重置。
