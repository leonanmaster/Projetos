nome = 'leonan'
tamanho_nome = len(nome)
cont = 0
novo_nome = ''

while cont < tamanho_nome:
    novo_nome += nome[cont] + '*'
    cont += 1

print(novo_nome)