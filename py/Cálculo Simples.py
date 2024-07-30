prod_um = input('Digite o código, quantidade de peças e valor unitário da peça 1 (separados por espaços): ')
lista_prod_um = prod_um.split(' ')
prod_dois = input('Digite o código, quantidade de peças e valor unitário da peça 2 (separados por espaços): ')
lista_prod_dois = prod_dois.split(' ')

valor_um = float(lista_prod_um[2])
qtd_um = int(lista_prod_um[1])
cod_um = int(lista_prod_um[1])
total_um = valor_um * qtd_um

valor_dois = float(lista_prod_dois[2])
qtd_dois = int(lista_prod_dois[1])
cod_dois = int(lista_prod_dois[0])
total_dois = valor_dois * qtd_dois

total = total_um + total_dois

print (f'VALOR A PAGAR: R$ {total:.2f}')