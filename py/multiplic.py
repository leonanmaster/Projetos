def mult (*args):
    total = 1
    for n in args:
        total *= n
    return total

x = []

while True:
    num = input('Novo número ou (sair): ')
    if num.lower() == 'sair':
        print()
        print('Ok')
        break
    else:
        if num.isdigit():
            num = int(num)
            x.append(num)
            print ()
            print (x)
        else:
            print()
            print ('Não é um número aceito por esse programa!')

result = mult(*x)
print(result)