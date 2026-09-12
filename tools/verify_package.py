"""Compare staged packages (and optionally ZIPs) to their release inputs."""

import argparse
import hashlib
import json
from pathlib import Path
import zipfile
from release_files import release_assets, verify_dll

ROOT = Path(__file__).resolve().parents[1]
MOD = "Compass Navigation Overhaul VR"


def digest(data):
    return hashlib.sha256(data).hexdigest()


def files(directory):
    if not directory.is_dir():
        raise ValueError(f"Missing directory: {directory}")
    return {p.relative_to(directory).as_posix(): digest(p.read_bytes())
            for p in directory.rglob('*') if p.is_file()}


def compare(expected, actual, label):
    missing = sorted(expected.keys() - actual.keys())
    extra = sorted(actual.keys() - expected.keys())
    changed = sorted(k for k in expected.keys() & actual.keys() if expected[k] != actual[k])
    if missing or extra or changed:
        raise ValueError(f"{label}: missing={missing}, extra={extra}, changed={changed}")
    print(f"{label}: {len(expected)} files match")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--archives', action='store_true', help='Also verify both release ZIPs')
    parser.add_argument('--main-only', action='store_true', help='Use when MAKE_CHS=0')
    args = parser.parse_args()
    verify_dll(ROOT / 'build/relwithdebinfo-vr-only/CompassNavigationOverhaulVR.dll')
    expected = {name: digest(p.read_bytes()) for name, p in release_assets(ROOT / 'assets/main').items()}
    if any(Path(p).name in ('QuestItemList.swf', 'config.zh-CN.json') for p in expected):
        raise ValueError('Standalone QuestItemList or locale authoring file in main assets')
    expected['SKSE/Plugins/CompassNavigationOverhaulVR.dll'] = digest(
        (ROOT / 'build/relwithdebinfo-vr-only/CompassNavigationOverhaulVR.dll').read_bytes())
    expected['LICENSE'] = digest((ROOT / 'LICENSE').read_bytes())
    packages = [('main', '', expected)]
    if not args.main_only:
        relative = f'MCM/Config/{MOD}/config.json'
        packages.append(('chs', '-CHS', {relative: digest(
            (ROOT / 'assets/localization/zh-CN' / relative).read_bytes())}))
    version = json.loads((ROOT / 'vcpkg.json').read_text(encoding='utf-8'))['version-string']
    for folder, suffix, inputs in packages:
        compare(inputs, files(ROOT / 'build/package' / folder), folder)
        if args.archives:
            archive = ROOT / 'dist' / f'{MOD} {version}{suffix}.zip'
            with zipfile.ZipFile(archive) as package:
                entries = [p for p in package.infolist() if not p.is_dir()]
                if len({p.filename for p in entries}) != len(entries):
                    raise ValueError(f'Duplicate ZIP members: {archive.name}')
                actual = {p.filename: digest(package.read(p)) for p in entries}
            compare(inputs, actual, archive.name)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
