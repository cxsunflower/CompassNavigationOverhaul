"""Portable CI packaging and release-artifact integrity checks."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess
import zipfile
from release_files import excluded, stage_assets, verify_dll

ROOT = Path(__file__).resolve().parents[1]
MOD = 'Compass Navigation Overhaul VR'

def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def version(root):
    value = json.loads((root / 'vcpkg.json').read_text(encoding='utf-8'))['version-string']
    if not re.fullmatch(r'[0-9]+\.[0-9]+\.[0-9]+(?:[-+][A-Za-z0-9.-]+)?', value):
        raise ValueError('Invalid release version')
    return value

def package(root, sha):
    if not re.fullmatch(r'[0-9a-f]{40}', sha):
        raise ValueError('Expected a full source commit SHA')
    ver = version(root)
    dll = root / 'build/relwithdebinfo-vr-only/CompassNavigationOverhaulVR.dll'
    relative = Path('MCM/Config') / MOD / 'config.json'
    chinese = root / 'assets/localization/zh-CN' / relative
    for p in (dll, chinese, root / 'LICENSE'):
        if not p.is_file():
            raise ValueError(f'Missing release input: {p}')
    verify_dll(dll)
    stage = root / 'build/package'
    dist = root / 'dist'
    # These are generated CI outputs, never installed game directories.
    for p in (stage, dist):
        if p.exists():
            shutil.rmtree(p)
        p.mkdir(parents=True)
    stage_assets(root / 'assets/main', stage / 'main')
    (stage / 'main/SKSE/Plugins').mkdir(parents=True, exist_ok=True)
    shutil.copy2(dll, stage / 'main/SKSE/Plugins' / dll.name)
    shutil.copy2(root / 'LICENSE', stage / 'main/LICENSE')
    target = stage / 'chs' / relative
    target.parent.mkdir(parents=True)
    shutil.copy2(chinese, target)
    archives = {}
    for folder, suffix in [('main', ''), ('chs', '-CHS')]:
        archive = dist / f'{MOD} {ver}{suffix}.zip'
        with zipfile.ZipFile(archive, 'w', zipfile.ZIP_DEFLATED) as z:
            for p in sorted((stage / folder).rglob('*')):
                if p.is_file():
                    z.write(p, p.relative_to(stage / folder).as_posix())
        archives[archive.name] = digest(archive)
    (dist / 'build-metadata.json').write_text(json.dumps({
        'version': ver, 'source_sha': sha, 'archives': archives
    }, indent=2) + '\n', encoding='utf-8')
    return ver

def verify_release(directory, sha, expected_version):
    data = json.loads((directory / 'build-metadata.json').read_text(encoding='utf-8'))
    if data['source_sha'] != sha or data['version'] != expected_version:
        raise ValueError('Artifact does not match the selected source commit/version')
    expected = {f'{MOD} {expected_version}{suffix}.zip' for suffix in ('', '-CHS')}
    if set(data['archives']) != expected or {p.name for p in directory.glob('*.zip')} != expected:
        raise ValueError('Expected exactly the main and CHS archives')
    for name in expected:
        p = directory / name
        if digest(p) != data['archives'][name]:
            raise ValueError(f'Archive hash mismatch: {name}')
        with zipfile.ZipFile(p) as z:
            names = [i.filename for i in z.infolist() if not i.is_dir()]
            if any(excluded(n) for n in names):
                raise ValueError(f'Non-production file in archive: {name}')
            if len(names) != len(set(names)) or z.testzip() is not None:
                raise ValueError(f'Invalid archive: {name}')

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('command', choices=['version', 'package', 'verify-release'])
    p.add_argument('--sha')
    p.add_argument('--directory', type=Path, default=ROOT / 'dist')
    args = p.parse_args()
    if args.command == 'version':
        print(version(ROOT))
    elif args.command == 'package':
        package(ROOT, args.sha or '')
        subprocess.run(['python', str(ROOT / 'tools/verify_package.py'), '--archives'], check=True)
    else:
        verify_release(args.directory, args.sha, version(ROOT))
        print('Release artifacts match source SHA, version, hashes and ZIP integrity.')

if __name__ == '__main__':
    main()
