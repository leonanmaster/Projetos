produtos = [
    {'prod' : 'pão', 'preço' : 5},
    {'prod' : 'leite', 'preço' : 3},
    {'prod' : 'ovo', 'preço' : 10},
    {'prod' : 'açucar', 'preço' : 4}
]

novos_preços = [
    {**produto, 'preço' : produto['preço'] * 1.5}  # desempacota e pega cada produto da lista e almenta em 50% os valores dos produtos.
    if produto['preço'] <= 5 else {**produto}    # executa a linha de cima apenas em produtos com o preço menor ou igual a 5. (map)
    for produto in produtos
    if produto['preço'] < 10    # aqui, é executado um filtro, onde só produtos mais baratos q 10 sao implementados na nova lista.(ñ se usa else msm) 
    #antes do for: map, depois: filtro.
]
print ( f'{novos_preços =}')





