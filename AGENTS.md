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
