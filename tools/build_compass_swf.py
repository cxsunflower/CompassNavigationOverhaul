"""Rebuild the Compass baseline movie from AS2 sources via ffdec importScript.

Source-of-truth chain for the Compass baseline (assets/generated/Compass.before-embedded.swf):
  swf/Compass.as + swf/CompassMarkerInfo.as (with swf/utils.as inlined)
      -- this script --> assets/generated/Compass.before-embedded.swf (2 scripts replaced, artwork untouched)
      -- embed_questlist_compass.py --> assets/.../Compass.swf (HUDMenu + VR_HMD_info)

Only the main-timeline script (frame_1/DoAction.as) and the marker class
(__Packages/CompassMarkerInfo.as) are recompiled; the other 7 decompiled
scripts (sprite 123/136 frame actions, registerClass stub) are preserved
by ffdec and asserted byte-identical after re-export.

Usage: python tools/build_compass_swf.py --ffdec <ffdec-cli.jar>
       python tools/build_compass_swf.py --ffdec <ffdec-cli.jar> --output <temporary.swf>
       python tools/build_compass_swf.py --check
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tempfile
import xml.etree.ElementTree as ET

from build_questlist_swf import artwork, strip_as2_types

ROOT = Path(__file__).resolve().parents[1]
SOURCES = ['swf/Compass.as', 'swf/CompassMarkerInfo.as', 'swf/compass/Debug.as']
TARGETS = ['assets/generated/Compass.before-embedded.swf']
MANIFEST = ROOT / 'tools/compass-swf.json'
INPUTS = SOURCES + ['swf/utils.as', 'tools/build_compass_swf.py', 'tools/build_questlist_swf.py']

# Decompiled scripts that importScript must leave untouched (sprite frame
# actions keep their names; the registerClass stub keeps the class linkage).
PRESERVED = [
    'CompassMarkerInfo.as',
    'DefineSprite_123_Compass Marker/frame_1/DoAction.as',
    'DefineSprite_123_Compass Marker/frame_2/DoAction.as',
    'DefineSprite_123_Compass Marker/frame_3/DoAction.as',
    'DefineSprite_123_Compass Marker/frame_4/DoAction.as',
    'DefineSprite_136_CompassMarkerInfo/frame_1/DoAction.as',
    'DefineSprite_136_CompassMarkerInfo/frame_12/DoAction.as',
]


def hashes():
    return {p: hashlib.sha256((ROOT / p).read_bytes()).hexdigest() for p in INPUTS + TARGETS}


def debug_timeline(command, baseline, work):
    """Read authored frame labels; never infer phases from frame-number guesses."""
    xml = work / 'debug-timeline.xml'
    subprocess.run(command + ['-swf2xml', str(baseline), str(xml)], check=True)
    sprite = next(t for t in ET.parse(xml).getroot().find('tags')
                  if t.get('type') == 'DefineSpriteTag' and t.get('spriteId') == '136')
    labels = []
    frame = 1
    for tag in sprite.find('subTags'):
        if tag.get('type') == 'FrameLabelTag':
            labels.append({'frame': frame, 'name': tag.get('name')})
        if tag.get('type') == 'ShowFrameTag':
            frame += 1
    assert labels and any(label['name'] == 'IdleShow' for label in labels)
    idle = next(label['frame'] for label in labels if label['name'] == 'IdleShow')
    depth = next(t.get('depth') for t in sprite.find('subTags') if t.get('name') == 'Distance')
    current = 1
    matrix = None
    for tag in sprite.find('subTags'):
        if tag.get('depth') == depth and tag.find('matrix') is not None:
            matrix = tag.find('matrix')
        if tag.get('type') == 'ShowFrameTag':
            if current == idle:
                break
            current += 1
    assert matrix is not None
    rest = {'x': float(matrix.get('translateX', '0'))/20,
            'y': float(matrix.get('translateY', '0'))/20,
            'sx': float(matrix.get('scaleX', '1')) if matrix.get('hasScale') == 'true' else 1,
            'sy': float(matrix.get('scaleY', '1')) if matrix.get('hasScale') == 'true' else 1,
            'r0': float(matrix.get('rotateSkew0', '0')) if matrix.get('hasRotate') == 'true' else 0,
            'r1': float(matrix.get('rotateSkew1', '0')) if matrix.get('hasRotate') == 'true' else 0}
    return {'labels': labels, 'distanceRest': rest, 'restFrame': idle}


def prepare_timeline(metadata=None):
    text = (ROOT / 'swf/Compass.as').read_text(encoding='utf-8')
    debug = (ROOT / 'swf/compass/Debug.as').read_text(encoding='utf-8')
    debug = debug.replace('__CNO_DEBUG_TIMELINE__', re.sub(r'"([A-Za-z0-9_]+)":', r'\1:', json.dumps(metadata or {'labels': []})))
    assert text.count('// @include "compass/Debug.as"') == 1
    text = text.replace('// @include "compass/Debug.as"', debug)
    utils = (ROOT / 'swf/utils.as').read_text(encoding='utf-8')
    assert text.count('#include "utils.as"') == 1
    text = text.replace('#include "utils.as"', utils)
    # Imports are compile-time only; ffdec takes a single translation unit.
    text = re.sub(r'(?m)^import\s+[A-Za-z_$][\w$]*\s*;\s*\n', '', text)
    assert not re.search(r'(?m)^import\s', text)
    # JPEXS AS2 importer accepts untyped declarations, unlike Adobe's compiler.
    return strip_as2_types(text)


def name_fade_only(command, output, work):
    """Keep Target at its IdleShow Y in every frame; retain authored alpha fades."""
    xml = work / 'name-fade.xml'
    subprocess.run(command + ['-swf2xml', str(output), str(xml)], check=True)
    tree = ET.parse(xml)
    sprite = next(t for t in tree.getroot().find('tags')
                  if t.get('type') == 'DefineSpriteTag' and t.get('spriteId') == '136')
    tags = list(sprite.find('subTags'))
    depth = next(t.get('depth') for t in tags if t.get('name') == 'Target')
    # Resolve the inherited matrix at IdleShow, not an arbitrary animation frame.
    rest_y = None
    for tag in tags:
        if tag.get('type') == 'FrameLabelTag' and tag.get('name') == 'IdleShow':
            break
        matrix = tag.find('matrix')
        if tag.get('depth') == depth and matrix is not None:
            rest_y = matrix.get('translateY')
    assert rest_y is not None
    alpha_before = [ET.tostring(t.find('colorTransform')) for t in tags
                    if t.find('colorTransform') is not None]
    distance_before = [ET.tostring(t) for t in tags if t.get('depth') != depth]
    changed = 0
    for tag in tags:
        matrix = tag.find('matrix')
        if tag.get('depth') == depth and matrix is not None:
            matrix.set('translateY', rest_y)
            x, y = int(matrix.get('translateX', '0')), int(rest_y)
            matrix.set('nTranslateBits', str(max(abs(x).bit_length(), abs(y).bit_length()) + 1))
            changed += 1
    assert changed >= 2
    assert alpha_before == [ET.tostring(t.find('colorTransform')) for t in tags
                            if t.find('colorTransform') is not None]
    assert distance_before == [ET.tostring(t) for t in tags if t.get('depth') != depth]
    tree.write(xml, encoding='utf-8', xml_declaration=True)
    rebuilt = work / 'fade-only.swf'
    subprocess.run(command + ['-xml2swf', str(xml), str(rebuilt)], check=True)
    subprocess.run(command + ['-swf2xml', str(rebuilt), str(xml)], check=True)
    verified = ET.parse(xml).getroot()
    target = next(t for t in verified.find('tags')
                  if t.get('type') == 'DefineSpriteTag' and t.get('spriteId') == '136')
    values = [t.find('matrix').get('translateY') for t in target.find('subTags')
              if t.get('depth') == depth and t.find('matrix') is not None]
    assert len(values) == changed and set(values) == {rest_y}
    # Verify the encoded alpha envelope survived the XML roundtrip.
    alpha_after = [ET.tostring(t.find('colorTransform')) for t in target.find('subTags')
                   if t.find('colorTransform') is not None]
    assert alpha_before == alpha_after
    output.write_bytes(rebuilt.read_bytes())
    print('Name animation verified: fixed Y=' + rest_y + ' twips; alpha fades preserved.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ffdec', type=Path)
    parser.add_argument('--check', action='store_true')
    parser.add_argument('--output', type=Path, help='Preflight output; leave the baseline and hash manifest unchanged')
    args = parser.parse_args()
    if args.check:
        if args.output:
            parser.error('--check and --output cannot be combined')
        if not MANIFEST.exists() or json.loads(MANIFEST.read_text()) != hashes():
            raise SystemExit('Compass baseline/source mismatch; run tools/build_compass_swf.py --ffdec <jar>')
        print('Compass sources and baseline hash verified.')
        return
    if not args.ffdec or not args.ffdec.is_file():
        parser.error('--ffdec must name an existing JPEXS ffdec-cli.jar')
    command = ['java', '-jar', str(args.ffdec.resolve())]
    with tempfile.TemporaryDirectory(prefix='cno-compass-') as temp:
        work = Path(temp)
        scripts = work / 'scripts'
        timeline_target = scripts / 'frame_1/DoAction.as'
        timeline_target.parent.mkdir(parents=True, exist_ok=True)
        timeline_target.write_text(prepare_timeline(debug_timeline(command, ROOT / TARGETS[0], work)), encoding='utf-8')
        class_target = scripts / '__Packages/CompassMarkerInfo.as'
        class_target.parent.mkdir(parents=True, exist_ok=True)
        class_target.write_text(
            strip_as2_types((ROOT / 'swf/CompassMarkerInfo.as').read_text(encoding='utf-8')),
            encoding='utf-8')
        baseline = ROOT / TARGETS[0]
        output = work / 'Compass.swf'
        subprocess.run(
            command + ['-onerror', 'abort', '-importScript', str(baseline), str(output), str(scripts)],
            check=True)
        assert artwork(baseline) == artwork(output), 'Non-script Compass tags changed'
        name_fade_only(command, output, work)
        export = work / 'export'
        subprocess.run(command + ['-export', 'script', str(export), str(output)], check=True,
                         stdout=subprocess.DEVNULL)
        exported = export / 'scripts'
        timeline = (exported / 'frame_1/DoAction.as').read_text(encoding='utf-8')
        cls = (exported / '__Packages/CompassMarkerInfo.as').read_text(encoding='utf-8')
        # Split name/distance scale API (2.12.0): presence + percent pass-through.
        assert 'function SetMarkerNameScale(' in timeline
        assert 'function SetMarkerDistanceScale(' in timeline
        assert 'SetNameScale(a_scale)' in timeline and 'SetDistanceScale(a_scale)' in timeline
        assert not re.search(r'a_scale\s*/\s*100', timeline), 'Divide-by-100 must never return'
        assert 'function SetNameScale(' in cls and 'Target.TextFieldInstance._xscale' in cls and 'Target.TextFieldInstance._yscale' in cls
        assert 'function SetDistanceScale(' in cls and 'Distance.TextFieldInstance._xscale' in cls and 'Distance.TextFieldInstance._yscale' in cls
        # No collateral loss in the two replaced scripts.
        for name in ('SetMarkers', 'SetFocusedMarkerInfo', 'UpdateFocusedMarker', 'FocusMarker',
                     'UnfocusMarker', 'SetUnits', 'SetMarkerTextScale'):
            assert 'function %s(' % name in timeline, name
        for name in ('SetTextScale', 'SetDistanceAndHeightDifference'):
            assert 'function %s(' % name in cls, name
        assert re.search(r'==\s*MarkerUnknownLocation[\s\S]{0,200}gotoAndStop\(3\)', timeline), \
            'Unknown-marker frame-3 fix missing'
        # Frame-1 statements kept from the old baseline (main timeline has 2 frames).
        assert '_global.gfxExtensions = true' in timeline
        assert 'HeightIndicatorInstance.gotoAndStop("Above")' in timeline
        assert re.search(r'(?m)^stop\(\);$', timeline), 'Main timeline must stop on frame 1'
        # The other 7 scripts must survive importScript byte-identical.
        current = work / 'current'
        subprocess.run(command + ['-export', 'script', str(current), str(baseline)], check=True,
                         stdout=subprocess.DEVNULL)
        for rel in PRESERVED:
            before = (current / 'scripts' / rel).read_text(encoding='utf-8')
            after = (exported / rel).read_text(encoding='utf-8')
            assert before == after, rel
        if args.output:
            args.output.resolve().parent.mkdir(parents=True, exist_ok=True)
            args.output.resolve().write_bytes(output.read_bytes())
        else:
            for target in TARGETS:
                (ROOT / target).write_bytes(output.read_bytes())
    if not args.output:
        MANIFEST.write_text(json.dumps(hashes(), indent=2) + '\n', encoding='utf-8')
    print('Compass baseline compiled; split name/distance scale API and artwork verified.')


if __name__ == '__main__':
    main()
