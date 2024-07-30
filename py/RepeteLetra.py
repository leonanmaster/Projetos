frase = input('frase: ') 

i=0
apareceu_mais = 0
letra_que_apareceu_mais = ''

while i < len(frase):
    letra = frase[i]
    quant_letra_aparece = frase.count(letra)
    
    if letra == ' ':
        i+=1
        continue
    
    if quant_letra_aparece > apareceu_mais:
        letra_que_apareceu_mais = frase[i]
        apareceu_mais = quant_letra_aparece

    i+=1

print(letra_que_apareceu_mais, apareceu_mais)