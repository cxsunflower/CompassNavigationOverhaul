"""Read the single AS2 Passenger contract and encode its authored SWF matrix."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = 'swf/QuestItemList.as'


def load_config(root=ROOT):
    text = (Path(root) / SOURCE).read_text(encoding='utf-8-sig')
    match = re.search(r'var compassPassengerConfig:Object\s*=\s*\{([^{}]+)\}', text)
    if not match:
        raise ValueError('Missing Passenger configuration')
    values = {key: float(value) for key, value in re.findall(
        r'\b([A-Za-z]+)\s*:\s*(-?\d+(?:\.\d+)?)\s*(?:,|$)', match.group(1))}
    required = {'width', 'height', 'offsetX', 'offsetY', 'scale', 'minScale'}
    if set(values) != required or values['width'] <= 0 or values['height'] <= 0 or not 0 < values['minScale'] <= values['scale'] <= 110:
        raise ValueError('Invalid Passenger configuration')
    return values


def placement_matrix():
    # The runtime solver positions the sprite at the live text anchor. A
    # neutral authored matrix prevents a pre-initialization jump or double scale.
    return dict(type='MATRIX', hasRotate='false', hasScale='false',
                nRotateBits='0', nScaleBits='0', nTranslateBits='0',
                translateX='0', translateY='0')
