<!-- 定位：L2 当前 QuestList 行为、源码职责、构建链及验收限制，不混入旧部署指引。 -->

# QuestList 当前实现

## 显示路径与迁移边界
QuestList 静态嵌入 `Compass.FocusedMarkerInfo.Target.QuestItemList`，继续跟随罗盘。掌上独立面板目前是另一条静态测试路径，不替换此实现，不修改第三方 Palm。禁止恢复已撤回的 UV／网格补偿，也禁止独立部署 QuestItemList.swf。

## 内容与排序
- 内容为原标题装饰、日志详情、目标分隔装饰和目标；仅杂项任务显示任务名，空区不占正文高度。
- `SyncQuests` 按任务键／内容签名更新，避免未变化内容反复重建与重启动画。
- 进行中目标在前、已完成组按原目标序号倒序、失败组在后。**没有完成时间戳，尚不能保证“更早完成的目标始终在底部”**；这是已有需求缺口，不是本次 Debug 修复范围。

## 字体、装饰与布局
- 正文使用 `$EverywhereMediumFont`，Normal、非斜体；目标文字按状态区分明暗。
- 层级为 `QuestItem → DetailBox → Header + DetailBody + DetailContentMask`。Header 保留原 Title 引用；Body 放生成内容；局部遮罩只保护 Body。
- 原装饰决定自然内容宽度，逻辑 Box 尺寸由排版函数拥有，不从未裁切素材或 Debug 绘制反向测量。
- **当前顺序是自然宽度 → 必要时缩小面板 → 完整段／行省略**。不再使用历史的“先扩宽正文”方案，不能把文字扩到固定装饰之外。
- 省略标记为 `. . .`，跟随实际条目比例；不能挤掉最后一条原本可读的目标。没有足够空间时标记本身也可省略。
- 目标图标与分隔装饰改用任务日志原始矢量；独立 `QuestItemListSkin.swf` 只含图形，不运行日志页面。**菱形不额外加粗**，保留 4/4/4 滤镜及 18×27 槽位；失败目标使用原生日志叉号，保持原比例与颜色。上方任务详情装饰字节不变。[皮肤接口与素材来源](../../assets/source/questlist/art/README.md)。
- 皮肤适配包可覆盖 HUDMenu／VR_HMD_info 两个 `!assets/QuestItemListSkin.swf`，无需改 DLL 或布局；普通日志美化包不会自动同步，须提供符合固定导出名和画布尺寸的适配。

## 显示、定位与缩放
- 当前名称／距离设置范围 25～150%；面板期望范围 25～110%，自动缩小下限为 `min(90,期望值)`。实际默认值以发布 INI 为准。
- 相对偏移 X/Y 为 -100～100、步长 5、默认 0。最大高度设置已退役；旧整体文字缩放键保留解析但不应用。
- Passenger 布局使用 Target 局部空间；调试绘制统一转为 SWF 根空间。两者不能混用。
- 760～960 是当前共享 HUD 的候选连续显示带，不是全宽或所有姿态的实测 UV 保证；独立校准／专用面板不据此宣称自身边界。
- 门控包括焦点、罗盘可见性、注视与对应设置；物理手掌跟随不能由 Flash 父子关系单独保证。
- 已部署的距离修复保持文字／箭头原底边向上放大；不等于整个父级动画期间都没有遮挡。

## 当前 HUD Debug
MCM Debug／Trace 开启全部普通诊断；Info 及以上关闭。独立校准仍手动控制。
D/H/M/N/Q/F/V 空心边框、短 ID 与最多两行中文替代旧坐标表和逐行红框；详细内容写日志。
Q 仅合并可见条目和省略标记，F 表示完整内容，V 为逻辑视口。空列表保留实例存在性和 V，不伪造 Q/F 的零尺寸内容。详见 [HUD Debug](hud-debug.md)。
**新 Debug 及本次三项修复尚未部署，VR 未验收。**

## 源码结构与编辑入口
`swf/QuestItem.as`、`swf/QuestItemList.as` 保留原两个入口；`swf/questlist/item/` 七个模块、`list/` 七个模块共 14 个。列表 Debug 只提供数据，Calibration 独立保留校准；唯一普通观察器在 `swf/compass/Debug.as`。
组合器检查显式 include、依赖哈希、缺失／重复／循环／越界／孤立模块和重复函数。[模块导航](../../swf/questlist/README.md)。不要维护第二份完整 AS2 或另载运行时列表。独立皮肤 SWF 是获准的纯图形库，通过现有 `!assets` 导入机制使用，不含脚本、字体或任务日志引用。

## SWF 构建与校验
在项目根目录逐条执行，任何一步失败就停止。`build.bat` 不会自动重编 ActionScript。

```powershell
$ff = '完整路径\ffdec-cli.jar'
python -X utf8 tools/questlist_source.py --output build/questlist-sources
python -X utf8 tools/build_questlist_swf.py --ffdec $ff
python -X utf8 tools/build_compass_swf.py --ffdec $ff
python -X utf8 tools/embed_questlist_compass.py --ffdec $ff
python -X utf8 tools/build_questlist_swf.py --check
python -X utf8 tools/build_compass_swf.py --check
python -X utf8 tools/embed_questlist_compass.py --check
python -X utf8 -m unittest discover -s tools/tests -p 'test_*.py'
```

随后从最终内嵌 Compass 导出脚本，运行 `questlist_layout.test.cjs`、`compass_debug.test.cjs` 和 `compass_marker_scale.test.cjs`。观察器测试三个参数为 QuestItem 类、sprite 511 的列表时间轴、Compass 主时间轴；距离测试参数为 scripts 目录。[工具说明](../../tools/README.md)。
只改 AS2 且 DLL 已对应当前原生源码时可用 `build.bat nobuild` 打包；C++ 改动须完整编译。发布两份内嵌 Compass 及配套的两份独立皮肤，不能漏装皮肤文件；生成基底只作构建输入。

## 原生素材皮肤验收
已从最终皮肤 SWF 导出矢量制作静态合成预览；不是游戏截图，不证明字体、滤镜、MO2 导入解析或 VR 渲染通过。目标行／排序、换行、缩放、省略、淡入及跟随逻辑不变。新皮肤和本轮 Compass 尚未部署；用户已授权整理并本地提交，提交记录以 Git 为准。

## 验收与历史
本次三项 Debug 修复由最终 SWF 的新增边界用例验证；正常布局、距离动画和设置链路另跑既有回归。构建、打包、安装与 VR 必须分别记录。
历史实验／部署证据见 [S2](../stages/s2-mcm.md)、[历史记录](quest-list-history.md)、[整理前指南存档](guidance-history.md)。本页是当前实现，不从旧记录推断“新包已安装”。

