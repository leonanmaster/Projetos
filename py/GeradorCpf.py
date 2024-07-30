import random
import sys

cpf_iter= ''
for i in range(9):  
    cpf_iter += str(random.randint(0,9))

i = 10
j = 11
somamult, somamult_1, resto, resto_1 = 0, 0, 0, 0

primeiro_char = cpf_iter[0] # checa cpf com todos os num iguais
rep = primeiro_char * len(cpf_iter)
if cpf_iter == rep:
    print('Cpf inválido pois os números estão todos repetidos!')
    sys.exit()

for digito in cpf_iter: # calculo primeiro digito
    somamult += i * int(digito)
    i -= 1

somamult *= 10
resto = somamult % 11
resto = resto if resto <= 9 else 0 

cpf_iter_1 = f'{cpf_iter}{resto}'

for digito_1 in cpf_iter_1: # calculo segundo digito
    somamult_1 += j * int(digito_1)
    j -= 1

somamult_1 *= 10
resto_1 = somamult_1 % 11
resto_1 = resto_1 if resto_1 <= 9 else 0 

cpf_gerado = f'{cpf_iter}{resto}{resto_1}' # utilidade da fstring

print ('CPF gerado: ', cpf_gerado)