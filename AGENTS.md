## Git Rules

### Commit Messages

Use Conventional Commits for all Git commit messages.

For every AI-generated commit, append the following lines to the end of the commit message:

🤖 Generated with {AI_TOOL_NAME}

Co-Authored-By: {CURRENT_MODEL_NAME}

Rules:

* Replace `{AI_TOOL_NAME}` with the actual AI coding tool currently being used.
* Replace `{CURRENT_MODEL_NAME}` with the exact name of the AI model currently being used.
* Never output `{AI_TOOL_NAME}` or `{CURRENT_MODEL_NAME}` literally.
* Do not omit these lines for AI-generated commits.

## Project pointers

- Human docs: `README.md` (EN) / `README.zh-CN.md` (中文) for layout and build; `manager/CONTEXT.md` for navigation and `manager/docs/` for feature docs and changelog; `decompiled/README.md` for the reverse-engineering reference.
- Build & package: `build.bat`, `build.bat nobuild`, `build.bat clean` (see README for required variables). Version comes from `vcpkg.json` (`version-string`); there is no `VERSION` file.
- QuestList SWF workflow: `manager/docs/quest-list.md` ("SWF 构建与校验") and `tools/README.md`. Never deploy a standalone `QuestItemList.swf`; never re-enable the withdrawn Palm UV/mesh compensation.

## 项目管理
<!-- project-manager 路由；既有规则保持不变 -->
- 启动读取 `manager/CONTEXT.md` 和 `manager/agents.md`，L2 按导航按需读取，禁止预加载全部文档。
- 不支持 Skill 的工具首次接手先读 `manager/SKILL.md` 获取完整规则；日常启动仅 L0+L1。
- 完成任务后更新 CONTEXT 当前状态、当前 stages 记录、相关文档及可复用经验。
- 新上下文、接手项目、阶段变化或用户要求更新记录/生成手册时使用本管理流程。
- 索引 ≤80 行；管理文档首行标明定位；项目规则写 agents.md，不改 Skill 副本正文。
- 私密数据以占位符表达，仅必要时写入已忽略的 manager/privacy.md，不预加载或外泄。
