perguntas = [
    {
        'Pergunta': 'Quanto é 2+2?',
        'Opções': ['1', '3', '4', '5'],
        'Resposta': '4',
    },
    {
        'Pergunta': 'Quanto é 5*5?',
        'Opções': ['25', '55', '10', '51'],
        'Resposta': '25',
    },
    {
        'Pergunta': 'Quanto é 10/2?',
        'Opções': ['4', '5', '2', '1'],
        'Resposta': '5',
    },
]

acertos = 0


for pergunta in perguntas :
    print()
    print(pergunta['Pergunta'])

    opçs = pergunta['Opções']

    for i, opç in enumerate(pergunta['Opções']):
        print(i, ') ', opç)

    try:

        chute = int(input('Qual a sua resposta? '))
        
        if chute >= 0 and chute < len(pergunta['Opções']):
            
            if opçs[chute] == pergunta['Resposta']:
                print ('Acertou!!!')
                acertos += 1
            else:
                print ('Errou...')
                
        else:
            print('Essa opção está fora da alternativas.')

    except: 
    
        print('Você digitou uma opção inválida.')

print()
print('Qtd acertada: ', acertos, 'de ', len(perguntas), ' perguntas.')      

    