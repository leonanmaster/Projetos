def likes(names):
    nlikes = len(names)
    if nlikes == 0:
        return 'no one likes this'
    elif nlikes == 1:
        return f'{names[0]} likes this'
    elif nlikes == 2:
        return f'{names[0]} and {names[1]} like this'
    elif nlikes == 3:
        return f'{names[0]}, {names[1]} and {names[2]} like this'
    else:
        return f'{names[0]}, {names[1]} and {nlikes - 2} others like this'

print(likes(["Alex", "Jacob"]))