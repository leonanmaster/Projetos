def mod (num):
    result = ''
    if num % 2 == 0:
        result = 'Par'
    else:
        result = 'Impar'
    return result

x = int(input('Qual valor? '))
y = mod (x)
print (y) 