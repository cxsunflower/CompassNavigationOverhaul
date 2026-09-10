"""Rebuild QuestList scripts and the three supplied objective-art symbols.

Usage: python tools/build_questlist_swf.py --ffdec <ffdec-cli.jar>
       python tools/build_questlist_swf.py --ffdec <ffdec-cli.jar> --output <temporary.swf>
       python tools/build_questlist_swf.py --check
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tempfile
import zlib
import struct
import xml.etree.ElementTree as ET

from build_questlist_art import ART, SOURCE_FILES as ART_SOURCE_FILES, TITLE_TARGETS, build_title_art, build_art, check_xml
from questlist_header_layout import wrap_header, check_header_layout
from questlist_source import ENTRYPOINTS, compose_all

ROOT = Path(__file__).resolve().parents[1]
SOURCES = list(ENTRYPOINTS)
TARGETS = ['assets/generated/QuestItemList.swf'] + [p.relative_to(ROOT).as_posix() for p in TITLE_TARGETS]
MANIFEST = ROOT / 'tools/questlist-swf.json'
INPUTS = SOURCES + [p.relative_to(ROOT).as_posix() for p in ART_SOURCE_FILES] + ['tools/build_questlist_swf.py', 'tools/questlist_header_layout.py', 'tools/questlist_source.py']

TYPE_NAMES = r'(?:Number|String|Boolean|Void|MovieClip|TextField|TextFormat|Array|Object|QuestItem|CompassMarkerInfo)'


def strip_as2_types(text):
    """Remove declarations' type annotations, not colons in expressions.

    In particular, a broad ': String' substitution corrupts ternary expressions
    such as `typeof(value) == "string" ? String(value) : String(value.text)`.
    """
    text = re.sub(r'(\bvar\s+[A-Za-z_$][\w$]*)\s*:\s*' + TYPE_NAMES + r'\b', r'\1', text)

    def function_signature(match):
        params = re.sub(r'([A-Za-z_$][\w$]*)\s*:\s*' + TYPE_NAMES + r'\b', r'\1', match.group(2))
        return match.group(1) + params + match.group(3)

    return re.sub(
        r'(\bfunction\s+[A-Za-z_$][\w$]*\s*\()([^)]*)(\)\s*)(?::\s*' + TYPE_NAMES + r'\b)?',
        function_signature, text)


def hashes():
    sources = compose_all(ROOT)
    modules = sorted({p for _, deps in sources.values() for p in deps if p not in SOURCES})
    return {p: hashlib.sha256((ROOT / p).read_bytes()).hexdigest() for p in INPUTS + modules + TARGETS}


def artwork(path):
    raw = path.read_bytes()
    body = zlib.decompress(raw[8:]) if raw[:3] == b'CWS' else raw[8:]
    assert len(body) + 8 == struct.unpack_from('<I', raw, 4)[0]
    pos = (5 + (body[0] >> 3) * 4 + 7) // 8 + 4
    kept = [body[:pos]]
    while pos < len(body):
        start = pos
        tag = struct.unpack_from('<H', body, pos)[0]
        pos += 2
        size = tag & 63
        if size == 63:
            size = struct.unpack_from('<I', body, pos)[0]
            pos += 4
        pos += size
        if tag >> 6 not in (12, 59):  # Main actions and class initialization only.
            kept.append(body[start:pos])
    return kept


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ffdec', type=Path)
    parser.add_argument('--check', action='store_true')
    parser.add_argument('--output', type=Path, help='Preflight output; leave release SWFs and hash manifests unchanged')
    args = parser.parse_args()
    sources = compose_all(ROOT)
    if args.check:
        if args.output:
            parser.error('--check and --output cannot be combined')
        if not MANIFEST.exists() or json.loads(MANIFEST.read_text()) != hashes():
            raise SystemExit('QuestList SWF/source mismatch; run tools/build_questlist_swf.py --ffdec <jar>')
        print('QuestList source and both SWF hashes verified.')
        return
    if not args.ffdec or not args.ffdec.is_file():
        parser.error('--ffdec must name an existing JPEXS ffdec-cli.jar')
    command = ['java', '-jar', str(args.ffdec.resolve())]
    with tempfile.TemporaryDirectory(prefix='cno-questlist-') as temp:
        work = Path(temp)
        scripts = work / 'scripts'
        for src, dst in zip(SOURCES, ['frame_1/DoAction.as', '__Packages/QuestItem.as']):
            target = scripts / dst
            target.parent.mkdir(parents=True, exist_ok=True)
            text = sources[src][0]
            # JPEXS AS2 importer accepts untyped declarations, unlike Adobe's compiler.
            text = strip_as2_types(text)
            target.write_text(text, encoding='utf-8')
        # Start from the immutable original, never from yesterday's generated
        # movie. Recreate the artwork first so rebuilding cannot duplicate IDs.
        art_base = work / 'quest-art-base.swf'
        art_work = work / 'art'
        art_work.mkdir()
        build_art(args.ffdec.resolve(), art_base, art_work)
        # Insert the actual layout parent at the original Title placement.
        # This preserves the imported Header and all 18 animation frames.
        base_xml = work / 'quest-layout.xml'
        subprocess.run(command + ['-swf2xml', str(art_base), str(base_xml)], check=True)
        original_tree = ET.parse(base_xml)
        tree = ET.parse(base_xml)
        wrap_header(tree.getroot())
        tree.write(base_xml, encoding='utf-8', xml_declaration=True)
        original = work / 'quest-layout-base.swf'
        subprocess.run(command + ['-xml2swf', str(base_xml), str(original)], check=True)
        output = work / 'QuestItemList.swf'
        subprocess.run(command + ['-onerror', 'abort', '-importScript', str(original), str(output), str(scripts)], check=True)
        assert artwork(original) == artwork(output), 'Artwork, imports or animation tags changed'
        export = work / 'export'
        subprocess.run(command + ['-export', 'script', str(export), str(output)], check=True, stdout=subprocess.DEVNULL)
        # Verify actual SWF definitions and linkage, not just AS2 strings.
        verified_xml = work / 'quest-verified.xml'
        subprocess.run(command + ['-swf2xml', str(output), str(verified_xml)], check=True)
        verified_root = ET.parse(verified_xml).getroot()
        check_xml(verified_root)
        check_header_layout(verified_root, original_tree.getroot())
        timeline = (export / 'scripts/frame_1/DoAction.as').read_text(encoding='utf-8')
        item = (export / 'scripts/__Packages/QuestItem.as').read_text(encoding='utf-8')
        params = r'\(a_type, a_title, a_description, a_isInSameLocation, a_objectives, a_ageIndex\)'
        assert re.search('function AddQuest' + params, timeline)
        assert re.search('function SetQuestInfo' + params, item)
        assert 'function SetTextScale(' in timeline
        assert 'function SetMaxHeight(' not in timeline
        assert 'HudElements.push' not in timeline
        assert '_parent.TextFieldInstance' in timeline
        assert 'function GetAnchorState(' in timeline
        assert 'function GetLayoutSnapshot(' in timeline
        assert 'function GetDebugObservation(' in timeline
        assert 'function GetDebugDetails(' in timeline
        assert 'function SetCalibration(' in timeline
        assert 'SetLayoutDebug' not in timeline
        assert 'QuestListLayoutDebugOverlay' not in timeline
        assert 'function GetFullBoundsInRoot(' in timeline
        assert 'function GetFitGeometry(' in timeline
        assert 'function GetVisibleBottomInRoot(' in timeline
        assert 'function SetAnchor(' in timeline and 'function UpdateAnchor(' in timeline
        assert re.search(r'function onEnterFrame\(\)\s*\{\s*Update\(\);', timeline)
        assert 'function FitLayout(' in timeline and 'function FitsViewport(' in timeline
        assert 'function ReflowWidth(' in item
        assert 'this.DescriptionTextField.setTextFormat' in item
        assert 'QuestItem.miscQuestFrame = ' in item
        assert 'a_objectives.join' not in item, 'Journal details must not replace objectives'
        assert 'this.TitleTextField._visible = ' in item
        assert 'a_type == 6' in item
        assert 'function GetContentBounds(' in item
        assert 'function MeasureTextHeight(' in item
        assert 'function GetDetailContentBounds(' in item
        assert 'function UpdateDetailMask(' in item
        assert 'function ResizeObjectivesHeader(' in item
        assert 'function LayoutDetailBox(' in item
        assert 'function GetDetailBoxBounds(' in item
        assert 'function GetDiagnosticRegions(' in item
        assert 'function GetRenderedBottomInSpace(' in item
        assert 'function GetHeaderBottomInSpace(' in item
        assert 'function GetVisibleContentBottom(' in item
        assert 'function HasOmittedContent(' in item
        assert 'this.DetailBody.setMask(this.DetailContentMask)' in item
        assert 'this.DetailBox.Header' in item
        assert 'this.DetailBox.layoutWidth' in item and 'this.DetailBox.layoutHeight' in item
        assert 'this.DetailBody.layoutWidth' in item and 'this.DetailBody.layoutHeight' in item
        assert 'this.DetailBox._width =' not in item and 'this.DetailBox._height =' not in item
        assert 'function ApplyHeightLimit(' in item
        assert 'this.ObjectiveItemList.push(' in item
        # JPEXS renames local variables during decompilation. Match the
        # completed/failed object construction instead of a source-local name.
        assert re.search(
            r'completed:(?P<row>[A-Za-z_$][\w$]*)\.completed\s*==\s*true\s*&&\s*'
            r'(?P=row)\.failed\s*!=\s*true\s*,\s*failed:(?P=row)\.failed\s*==\s*true',
            item), 'Objective completion/failed state mapping was not preserved'
        assert 'function DrawDividerFallback(' in item
        assert 'function DrawObjectiveIconFallback(' in item
        assert 'QuestObjectivesDivider' in item
        assert 'QuestObjectiveCompleted' in item and 'QuestObjectivePending' in item
        for _, _, linkage, _ in ART:
            assert linkage in item, f'Artwork linkage {linkage} is not referenced by QuestItem'
        assert 'function SyncQuests(' in timeline
        if args.output:
            args.output.resolve().parent.mkdir(parents=True, exist_ok=True)
            args.output.resolve().write_bytes(output.read_bytes())
        else:
            title_art = build_title_art(args.ffdec.resolve(), work)
            (ROOT / TARGETS[0]).write_bytes(output.read_bytes())
            for target in TITLE_TARGETS:
                target.write_bytes(title_art)
    if not args.output:
        MANIFEST.write_text(json.dumps(hashes(), indent=2) + '\n', encoding='utf-8')
    print('QuestList compiled; six-argument ABI, separate objectives, text layout and artwork verified.')


if __name__ == '__main__':
    main()
