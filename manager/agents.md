<!-- 定位：L1 项目约定，启动读取；具体操作步骤在 L2。 -->

# 项目约定
- 根目录 AGENTS.md 的既有规则保留；按用户授权范围修改和提交；未授权时不暂存、不提交、不重置索引。本轮用户已明确授权全部改动细分本地提交，未授权push。
- 运行环境：Windows、Skyrim VR、SKSEVR、SkyUI VR、MCM Helper 与 Infinity UI；依赖兼容性需按实际安装包核对。
- 构建：Visual Studio C++、CMake/Ninja、vcpkg；SWF 另需 Java/JPEXS，工具使用 Python 3，脚本回归使用 Node.js。
- 沿用现有格式：C++/AS2 命名和缩进不作无关重排；MCM 中英文 JSON 保持 UTF-8 无 BOM、配对结构和 CRLF。
- 修改前读取文件，用版本校验的小补丁；不覆盖用户已有修改。
- SWF、基底、SVG、哈希清单是配套发布输入，不应被通用忽略规则屏蔽。
- 禁止独立部署 QuestItemList.swf；禁止恢复已撤回的 Palm UV/网格补偿。
- 版本唯一来源 vcpkg.json；不要恢复 VERSION 文件。
- 资源分层：assets/main 为主包，assets/localization/zh-CN 为中文覆盖，assets/source 为原始素材，assets/generated 为配套中间SWF；后二者不直接部署。私有C++头文件随实现放在source对应模块。
- 源码模拟、反编译测试、打包校验、实际安装检查、VR 验收分别记录，不混称“通过”。
- MCM 静态通过不代表 Helper DLL 已加载或菜单已注册；未证实的根因必须标为待查。
- 启动只读 L0+L1，专项文档按 CONTEXT 导航加载；历史记录不是当前指南。
- 管理文档首行写定位说明；CONTEXT 不写操作步骤且不超过 80 行。
- SKILL.md 初始化时添加定位首行，后续正文与用户指定源保持一致且不在项目内编辑；同步须重新读取源。
- 本机路径、密钥等不进入公开文档；如确需保存，使用占位符并存入已忽略的 privacy.md。
