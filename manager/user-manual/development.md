<!-- 定位：开发者按修改类型选择构建和验证步骤。 -->

# 开发流程

先读 [项目约定](../agents.md)，保留用户已有修改与暂存内容。以下命令在项目根目录运行；任一步失败先停止排查，不继续发布。

| 修改类型 | 流程与验收 |
|---|---|
| C++ | build.bat 编译并打包；另跑相关回归，检查日志和 VR 行为 |
| AS2 / SVG / SWF | 重编译→嵌入→反编译回归→哈希检查→打包；[完整步骤](../docs/quest-list.md) |
| QuestList源码模块 | 在`swf/questlist/item/`或`list/`按职责修改；原两个入口负责组合。先检查模块清单与组合源码，再执行完整SWF回归；[目录说明](../../swf/questlist/README.md) |
| MCM 文案/默认值 | 更新英文与翻译规则→生成中文→绑定测试→打包→完整校验；[完整步骤](../docs/mcm.md) |
| 文档 | 运行 tools/check_manager_docs.py；检查当前语义与历史隔离，不需要重新打包 |

```powershell
python -X utf8 tools/check_manager_docs.py
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

## 原生可见性与 VR 节点回归
在已加载 Visual Studio x64 开发环境的终端、项目根目录执行：

```powershell
python -X utf8 -m unittest discover -s tools/tests -p "test_*.py"
```

重点入口为 `tools/tests/test_compass_visibility.py` 与 `tools/tests/test_vr_scene.py`：提取生产方法编译运行，分别覆盖独立可见性／注视要求、VR 根搜索、路径核验、重复根与缓存归属。缺少编译器时可能显示 skipped；这不是原生回归通过，需在正确开发环境重新运行。测试替身不证明运行时已选中 Palm 的实际节点，仍须核对日志。

若出现 PCH 编译器版本不匹配，重编本项目和 CommonLib，不能沿用旧 DLL 宣称通过。依赖工具下载或系统工具不可用属于构建环境问题；若临时复用已安装依赖，须确认依赖未改并记录边界，结束后恢复常规依赖安装，不把临时绕过写入项目默认配置。本次环境处理历史见 [S1](../stages/s1-questlist.md)。

## 文档任务自检
依指定 project-manager Skill 更新索引、相关阶段、专项与使用手册，再同步有复用价值的经验。结构检查之外，人工核对“已构建／已部署／VR 已通过”的语义，并同步 [审查报告](../docs/documentation-review.md)，不能只在旧指南末尾追加相反结论。已同步内容不重复追加；文档任务无需重新编译、打包或部署。

完成后更新 CONTEXT 当前状态、相关阶段及专项文档；只把可复用的经验写入 experience。Git 提交须得到用户授权，当前仍是暂不提交。

## GitHub Actions
三个手动入口已对齐当前目录与验证链，不新增push／PR自动触发：

| 工作流 | 用途 | 发布限制 |
|---|---|---|
| `Build` | Windows VR构建、源码／资源／文档检查、测试、主包和CHS打包；同时可被其他工作流复用 | 只上传`dist`产物，不发布 |
| `Build + Release` | 调用同一Build；`publish`默认false | 手动勾选后才发布当前构建 |
| `Release` | 发布指定成功的手动Build运行；必须提供run ID | 不再猜测“最近一次”，旧的无元数据产物必须重新构建 |

版本唯一读取`vcpkg.json`的`version-string`，不恢复VERSION文件。英文静态资源来自`assets/main`，汉化来自`assets/localization/zh-CN`；递归检出CommonLibSSE-NG子模块。使用Python、Node、Java、MSVC及VR CMake preset，不调用带本机绝对路径的build.bat。

构建先检查三份SWF源码／生成清单、文档及Python测试，再用固定版本且校验SHA256的JPEXS分别导出HUDMenu和VR_HMD_info最终Compass，运行布局、观察器和距离回归。CI不自动重新生成不匹配的SWF来掩盖未提交资源；发现失配应在开发环境重新编译成套提交。`.gitattributes`保护ActionScript及日志矢量XML的字节级构建输入，避免Windows检出换行转换破坏清单。

`tools/ci.py package --sha <完整提交SHA>`只操作仓库生成目录`build/package`和`dist`，会清理这两个输出目录；不要把它当作游戏部署命令。它生成两份ZIP及`build-metadata.json`，随后调用`verify_package.py --archives`校验文件集合和字节内容。元数据包含版本、来源提交和两份ZIP的SHA256；产物保留14天。

发布仅接受本仓库指定的手动构建运行；独立Release要求运行成功，组合流程只允许消费当前运行中已通过needs依赖的Build。下载后按来源提交检出，核对版本／SHA／ZIP哈希与完整性，标签显式指向构建提交。已有版本标签若指向不同提交则失败，需先按发布策略更新唯一版本来源，而不是移动已有标签。发布权限仅在Release作业开启；工作流不接受PR来源产物发布。

本轮本地验证：actionlint语法通过；55项Python（含6项CI正反例）通过；固定JPEXS对两份Compass分别通过60项布局、16组观察器及84项距离回归；真实主包20文件／CHS1文件在临时目录完成打包及ZIP校验，没有替换现有发布目录或安装。GitHub托管runner、缓存命中和实际Release仍未执行，不能将本地通过写成远程运行成功。

### Release附件与标题
- 主包：`Compass Navigation Overhaul VR <版本号>.zip`。
- 汉化包：`Compass Navigation Overhaul VR <版本号>-CHS.zip`。
- Release标题：`Compass Navigation Overhaul VR <版本号>`；Git标签：`v<版本号>`。
- 版本来自vcpkg.json的version-string；build-metadata.json仅随Actions构建产物保存校验，不作为Release附件发布。

### 全新检出的SWF字节校验
哈希清单校验的是原始字节。为已跟踪输入补充`-text`不会自动重写Git中的旧blob；工作区通过和Git过滤结果正确，都不能代替仓库快照验证。提交前应确认相关输入进入差异，并用隔离暂存索引生成候选树、导出到临时目录后运行三份SWF脚本的`--check`。不要关闭检查、修改清单掩盖差异，或在CI中悄悄重建资源。
