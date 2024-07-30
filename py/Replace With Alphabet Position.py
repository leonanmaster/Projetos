def alphabet_position(text):
    positions = ''
    for letter in text:
        if letter.isalpha():
            positions += str(ord(letter.lower()) - 96)
            positions += ' '
        else:
            continue
    positions = positions[:-1]
    return positions

print(alphabet_position('lkg-g'))