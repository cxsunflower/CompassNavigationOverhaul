"""Shared production-package exclusions and linked-DLL profile validation."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil


def excluded(name):
    parts = name.replace('\\', '/').lower().split('/')
    return any(p == 'meta.ini' or 'palmtest' in p or p == 'cnoquestpanel' for p in parts)


def release_assets(root):
    if not root.is_dir():
        raise ValueError(f'Missing release assets: {root}')
    return {p.relative_to(root).as_posix(): p for p in root.rglob('*')
            if p.is_file() and not excluded(p.relative_to(root).as_posix())}


def verify_dll(dll):
    profile = Path(str(dll) + '.build-profile.json')
    if not profile.is_file():
        raise ValueError('Missing linked DLL build profile; rebuild the production DLL')
    data = json.loads(profile.read_text(encoding='utf-8'))
    if data.get('palmtest') is not False:
        raise ValueError('Experimental PalmTest DLL cannot enter a production package')
    if data.get('sha256') != hashlib.sha256(dll.read_bytes()).hexdigest():
        raise ValueError('DLL build profile hash mismatch; rebuild the production DLL')


def stage_assets(source, destination):
    for name, source_file in release_assets(source).items():
        target = destination / name
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source_file, target)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--source', type=Path, required=True)
    p.add_argument('--destination', type=Path, required=True)
    p.add_argument('--dll', type=Path, required=True)
    args = p.parse_args()
    verify_dll(args.dll)
    stage_assets(args.source, args.destination)

if __name__ == '__main__':
    main()
