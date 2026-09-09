"""Wrap the immutable QuestTitle symbol in the QuestItem layout root.

The original 18-frame QuestItem timeline animates its depth-one Title. Replace
only that placement with a one-frame wrapper so the same transforms and fades
apply to the complete layout. No original title artwork is copied or edited.
"""

from copy import deepcopy
import xml.etree.ElementTree as ET

from build_questlist_art import definition_id

WRAPPER_ID = 306


def canonical_tag(tag):
    # JPEXS rewrites XML indentation on round-trip. Ignore formatting-only
    # whitespace without stripping meaningful text or action payloads.
    result = deepcopy(tag)
    for node in result.iter():
        if node.text is not None and not node.text.strip():
            node.text = None
        if node.tail is not None and not node.tail.strip():
            node.tail = None
    return ET.canonicalize(ET.tostring(result, encoding='unicode'))


def definitions(root):
    return {int(tag.get('spriteId')): tag for tag in root.findall('./tags/item')
            if tag.get('type') == 'DefineSpriteTag'}


def placement(sprite, name):
    matches = [tag for tag in sprite.findall('./subTags/item') if tag.get('name') == name]
    assert len(matches) == 1, f'Expected exactly one {name} placement'
    return matches[0]


def wrap_header(root):
    sprites = definitions(root)
    assert WRAPPER_ID not in {definition_id(t) for t in root.findall('./tags/item')}, 'Reserved layout wrapper ID is already in use'
    title = sprites[5]
    quest = sprites[6]
    assert title.get('frameCount') == '1' and quest.get('frameCount') == '18'
    original = placement(quest, 'Title')
    assert original.get('characterId') == '5' and original.get('depth') == '1'
    color = original.find('colorTransform')
    assert color is not None and color.get('hasAddTerms') == 'false'
    assert all(color.get(c) == '256' for c in ('redMultTerm', 'greenMultTerm', 'blueMultTerm'))

    header = deepcopy(original)
    header.set('name', 'Header')
    header.set('placeFlagHasColorTransform', 'false')
    for color in list(header):
        if color.tag == 'colorTransform':
            header.remove(color)
    # The outer placement retains its original alpha, matrix and blend mode.
    # The nested Header starts opaque and at the original local origin.
    wrapper = ET.Element('item', type='DefineSpriteTag', spriteId=str(WRAPPER_ID),
                         frameCount='1', hasEndTag='true', forceWriteAsLong='true')
    children = ET.SubElement(wrapper, 'subTags')
    children.append(header)
    ET.SubElement(children, 'item', type='ShowFrameTag', forceWriteAsLong='false')

    original.set('name', 'DetailBox')
    original.set('characterId', str(WRAPPER_ID))
    tags = root.find('tags')
    tags.insert(list(tags).index(quest), wrapper)
    check_header_layout(root)


def check_header_layout(root, original_root=None):
    sprites = definitions(root)
    assert all(i in sprites for i in (5, 6, WRAPPER_ID))
    wrapper = sprites[WRAPPER_ID]
    assert wrapper.get('frameCount') == '1'
    header = placement(wrapper, 'Header')
    assert header.get('characterId') == '5' and header.get('depth') == '1'
    assert header.get('placeFlagHasColorTransform') == 'false'
    assert header.find('colorTransform') is None
    matrix = header.find('matrix')
    assert matrix is not None and matrix.get('translateX') == '0' and matrix.get('translateY') == '0'
    assert matrix.get('hasScale') == 'false' and matrix.get('hasRotate') == 'false'
    assert len(wrapper.findall('./subTags/item')) == 2
    assert wrapper.findall('./subTags/item')[1].get('type') == 'ShowFrameTag'
    assert sprites[6].get('frameCount') == '18'
    outer = placement(sprites[6], 'DetailBox')
    assert outer.get('characterId') == str(WRAPPER_ID) and outer.get('depth') == '1'
    assert not any(t.get('name') == 'Title' for t in sprites[6].findall('./subTags/item'))
    assert [t.get('name') for t in sprites[5].findall('./subTags/item') if t.get('name')] == [
        'EndPiece', 'TitleTextField', 'Bracket']

    if original_root is not None:
        original = definitions(original_root)
        # The original title definition and every non-script animation tag
        # must survive. Only the first placement's name and character change.
        assert canonical_tag(sprites[5]) == canonical_tag(original[5]), 'Original Header artwork changed'
        expected_header = deepcopy(placement(original[6], 'Title'))
        expected_header.set('name', 'Header')
        expected_header.set('placeFlagHasColorTransform', 'false')
        for color in list(expected_header):
            if color.tag == 'colorTransform':
                expected_header.remove(color)
        assert canonical_tag(header) == canonical_tag(expected_header), 'Header placement changed'
        expected = deepcopy(original[6])
        old = placement(expected, 'Title')
        old.set('name', 'DetailBox')
        old.set('characterId', str(WRAPPER_ID))
        def without_actions(sprite):
            result = deepcopy(sprite)
            for tag in list(result.find('subTags')):
                if tag.get('type') in ('DoActionTag', 'DoInitActionTag'):
                    result.find('subTags').remove(tag)
            return canonical_tag(result)
        assert without_actions(sprites[6]) == without_actions(expected), 'Original animation changed'
    return True
