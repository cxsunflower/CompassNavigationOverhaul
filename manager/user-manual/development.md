<!-- 定位：开发者按修改类型选择构建和验证步骤。 -->

# 开发流程

先读 [项目约定](../agents.md)，保留用户已有修改与暂存内容。以下命令在项目根目录运行；任一步失败先停止排查，不继续发布。

| 修改类型 | 流程与验收 |
|---|---|
| C++ | build.bat 编译并打包；另跑相关回归，检查日志和 VR 行为 |
| AS2 / SVG / SWF | 重编译→嵌入→反编译回归→哈希检查→打包；[完整步骤](../docs/quest-list.md) |
| QuestList源码模块 | 在`swf/questlist/item/`或`list/`按职责修改；原两个入口负责组合。先检查模块清单与组合源码，再执行完整SWF回归；[目录说明](../../swf/questlist/README.md) |
| MCM 文案/默认值 | 更新英文与翻译规则→生成中文→绑定测试→打包→完整校验；[完整步骤](../docs/mcm.md) |
| 文档 | 检查导航、相对链接、当前状态、L1 行数；不需要重新打包 |

```powershell
python -X utf8 tools/questlist_source.py --output build/questlist-sources
python -X utf8 tools/tests/test_questlist_source.py
python -X utf8 tools/tests/test_mcm_bindings.py
python -X utf8 tools/verify_mcm_config_zhcn.py
python tools/build_questlist_swf.py --check
python tools/build_compass_swf.py --check
python tools/embed_questlist_compass.py --check
python -X utf8 tools/verify_package.py --archives
```

完整 MCM 校验器会核对已存在的打包暂存配置，修改母本后旧暂存区报错应先重新打包。`build.bat nobuild` 沿用已有 DLL，不能用于交付未编译的 C++ 修改。

完成后更新 CONTEXT 当前状态、相关阶段及专项文档；只把可复用的经验写入 experience。Git 提交须得到用户授权，当前仍是暂不提交。
