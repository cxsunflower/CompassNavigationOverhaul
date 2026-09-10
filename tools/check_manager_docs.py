"""Check project-manager structure and links; no private contents or Skill edits.

This is a structural guard, not proof of semantic accuracy or VR acceptance.
Run from any directory: python tools/check_manager_docs.py
"""
from pathlib import Path
from urllib.parse import unquote
import re
import sys

ROOT = Path(__file__).resolve().parents[1]


def visible_markdown(text):
    return re.sub(r"(?ms)^\s*(```|~~~).*?^\s*\1[^\n]*$", "", text)


def anchors(text):
    found = set()
    seen = {}
    for title in re.findall(r"(?m)^#{1,6}\s+(.+?)\s*#*\s*$", visible_markdown(text)):
        slug = re.sub(r"[^\w\- ]", "", title.lower()).replace(" ", "-")
        n = seen.get(slug, 0)
        seen[slug] = n + 1
        found.add(slug if n == 0 else f"{slug}-{n}")
    found.update(re.findall(r'<a\s+(?:id|name)=[\'"]([^\'"]+)', text))
    return found


def check(root=ROOT):
    root = Path(root)
    manager = root / "manager"
    errors = []
    count = 0
    for required in ["AGENTS.md", "manager/CONTEXT.md", "manager/agents.md", "manager/SKILL.md",
                     "manager/docs/experience.md", "manager/user-manual/README.md"]:
        if not (root / required).is_file():
            errors.append(f"missing entry: {required}")
    paths = set(manager.rglob("*.md"))
    for name in ("README.md", "README.zh-CN.md", "AGENTS.md"):
        if (root / name).is_file(): paths.add(root / name)
    for folder in ("tools", "source", "include", "swf", "assets"):
        paths.update(p for p in (root / folder).rglob("*.md") if "decompiled" not in p.parts)
    for path in sorted(paths):
        relative = path.relative_to(root).as_posix()
        # Metadata only: never load privacy mappings or reinterpret the read-only Skill.
        if path.name in ("privacy.md", "SKILL.md"):
            with path.open(encoding="utf-8-sig") as stream:
                first = stream.readline()
            if not first.startswith("<!-- 定位："):
                errors.append(f"{relative}: missing positioning header (read-only/metadata check)")
            continue
        count += 1
        text = path.read_text(encoding="utf-8-sig")
        lines = text.splitlines()
        if manager in path.parents and (not lines or not lines[0].startswith("<!-- 定位：")):
            errors.append(f"{relative}: missing positioning header")
        if manager in path.parents and not re.search(r"(?m)^# ", text):
            errors.append(f"{relative}: missing document title")
        if path.name == "CONTEXT.md" and len(lines) > 80:
            errors.append(f"{relative}: {len(lines)} lines exceeds L1 limit")
        if re.search(r"(?<!\d)2\.(?:10|12)\.\d+(?!\d)", text):
            errors.append(f"{relative}: duplicated project version")
        for link in re.findall(r"\]\(([^)]+)\)", visible_markdown(text)):
            if re.match(r"[a-zA-Z][\w+.-]*:", link):
                continue
            file_part, _, fragment = unquote(link).partition("#")
            target = (path.parent / file_part).resolve() if file_part else path
            if not target.exists():
                errors.append(f"{relative}: missing link target: {link}")
            elif fragment and target.suffix == ".md" and target.name not in ("privacy.md", "SKILL.md"):
                if fragment not in anchors(target.read_text(encoding="utf-8-sig")):
                    errors.append(f"{relative}: missing heading anchor: {link}")
    return count, errors


if __name__ == "__main__":
    count, errors = check()
    for error in errors:
        print(error)
    print(f"Project docs: {count} public Markdown files checked, {len(errors)} errors; Skill/privacy metadata only.")
    sys.exit(bool(errors))
