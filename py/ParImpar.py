numero_str = (input("Digite um número inteiro: "))
try:
    numero_int = int(numero_str)
    if numero_int % 2 == 0:
        print('Número par')
    else:
        print('Número impar')
except:
    print('Isso não é um número inteiro')