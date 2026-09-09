"""Compose QuestList's AS2 source modules without changing its runtime ABI.

The two public entrypoints remain the original timeline and QuestItem class.
Modules are source fragments, not new SWF classes or runtime loadMovie files.
"""

from pathlib import Path
from collections import Counter
import re

ROOT = Path(__file__).resolve().parents[1]
ENTRYPOINTS = (
    "swf/QuestItemList.as",
    "swf/QuestItem.as",
)
INCLUDE = re.compile(r'^[ \t]*// @include "([A-Za-z0-9_./-]+\.as)"[ \t]*$', re.MULTILINE)
IDENTIFIER = re.compile(r'(?m)^[ \t]*(?:(?:public|private|static)[ \t]+)*function[ \t]+([A-Za-z_$][\w$]*)[ \t]*\(')
CLASS = re.compile(r'(?m)^[ \t]*class[ \t]+([A-Za-z_$][\w$]*)\b')


def compose(entrypoint, root=ROOT):
    """Return expanded source and its dependencies, rejecting cycles/duplicates."""
    root = Path(root).resolve()
    module_root = root / "swf" / "questlist"
    entry = (root / entrypoint).resolve()
    if entrypoint not in ENTRYPOINTS or not entry.is_file():
        raise ValueError(f"Unknown QuestList entrypoint: {entrypoint}")
    visited = set()
    dependencies = [entry.relative_to(root).as_posix()]

    def expand(path, stack):
        text = path.read_text(encoding="utf-8-sig")

        def include(match):
            relative = Path(match.group(1))
            if relative.is_absolute() or ".." in relative.parts:
                raise ValueError(f"Invalid include: {relative}")
            child = (module_root / relative).resolve()
            if not child.is_relative_to(module_root.resolve()) or not child.is_file():
                raise ValueError(f"Missing or unsafe include: {relative}")
            if child in stack:
                raise ValueError(f"Circular QuestList include: {relative}")
            if child in visited:
                raise ValueError(f"Duplicate QuestList include: {relative}")
            visited.add(child)
            dependencies.append(child.relative_to(root).as_posix())
            return expand(child, stack + (child,)).rstrip("\r\n")

        return INCLUDE.sub(include, text)

    source = expand(entry, (entry,))
    if "@include" in source:
        raise ValueError("Unexpanded or malformed QuestList include")
    names = IDENTIFIER.findall(source)
    duplicates = sorted(name for name, count in Counter(names).items() if count > 1)
    if duplicates:
        raise ValueError(f"Duplicate QuestList functions: {duplicates}")
    classes = CLASS.findall(source)
    if entrypoint.endswith("QuestItem.as"):
        if classes != ["QuestItem"] or not re.search(r'\bclass\s+QuestItem\s+extends\s+MovieClip\b', source):
            raise ValueError("QuestItem must retain its original MovieClip class")
    elif classes:
        raise ValueError("The QuestList timeline must not declare new classes")
    return source, dependencies


def compose_all(root=ROOT):
    """Also reject orphaned modules, so every source file is tracked by builds."""
    root = Path(root).resolve()
    result = {name: compose(name, root) for name in ENTRYPOINTS}
    used = [dependency for _, dependencies in result.values() for dependency in dependencies]
    if len(used) != len(set(used)):
        raise ValueError("A QuestList module is included by multiple entrypoints")
    actual = {path.relative_to(root).as_posix() for path in (root / "swf" / "questlist").rglob("*.as")}
    expected = {path for path in used if path.startswith("swf/questlist/")}
    if actual != expected:
        raise ValueError(f"QuestList module inventory mismatch: missing={sorted(actual-expected)}, stale={sorted(expected-actual)}")
    return result


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, help="Optional directory for assembled, typed source")
    args = parser.parse_args()
    result = compose_all()
    if args.output:
        args.output.mkdir(parents=True, exist_ok=True)
        for name, (source, _) in result.items():
            (args.output / Path(name).name).write_text(source, encoding="utf-8")
    print("QuestList source modules verified:", sum(len(deps)-1 for _, deps in result.values()), "modules")
