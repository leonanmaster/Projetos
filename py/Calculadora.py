while True:
    try:
        num1 = float(input('Digite um número: '))
        num2 = float(input('Digite outro número: '))
    except:
        print ('Números invalidos!!!')
        continue

    op = input('Qual a operação? (+, -, *, /) ')
        
    if op == '+':
        print(num1 + num2)
    elif op == '-':
        print(num1 - num2)
    elif op == '*':
        print(num1 * num2)
    elif op == '/':
        print(num1 / num2)
    else:
        print('Digite um sinal valido')
        continue

    sair = input('Quer saír? (s para sim / qqr tecla para não.)')
    if sair == 's':
        break
    else:
        continue

    