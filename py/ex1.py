
nome = (input ("Qual é o seu nome? "))
idade = (input ("Quantos anos você tem? "))
# n necessito colocar str pois phyton reconhece automatico

if (nome == "" or idade == ""):
    print("Desculpe, você deixou campos vazios.")
else:
    len_nome = len(nome) 
    
    print('Seu nome é:', nome )
    print('Seu nome invertido é:', nome[::-1] )
    
    if (" " in nome):
        print('Seu nome contem espaços')
        len_nome -= 1
    else:
        print('Seu nome não conte espaços')

    print('Seu nome tem ', len_nome , ' letras.')
    print('A primeira letra do seu nome é:', nome[0] )
    print('A ultima letra do seu nome é:', nome[-1] )
