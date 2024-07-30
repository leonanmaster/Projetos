import copy

original = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
deep_copy = copy.deepcopy(original)

# Modificando o valor de um elemento na cópia
deep_copy[2][2] = 10

print("Original:", original)
print("Cópia Profunda:", deep_copy)


dados = ['ana', 'joao']
iterator = iter(dados)
print(next(iterator))

def imprimir(numero):
    fat = 0
    if numero <= 1:
        return 1
    else:
        fat = numero * imprimir(numero - 1)
        return fat
n = imprimir(100)
print (n)
