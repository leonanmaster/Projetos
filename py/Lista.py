lista = []

while True:

    acao = input('Desejas (i)nserir, (a)pagar, (l)istar ou (s)air: ')
    
    if acao == 'i':
        insere = input('O que desejas inserir? ')
        lista.append(insere)
    
    elif acao == 'l':
        
        for i, item in enumerate(lista):
            print(i, item)
    
    elif acao == 's':
        print('OK!')
        break
    
    elif acao == 'a':
        apaga = input('Qual indice desejas apagar? ')
        
        if apaga.isnumeric():

            tamlista = len(lista)

            if int(apaga) <= (tamlista-1):
                lista.pop(int(apaga))

            else:
                print('Indice mt alto!!! ')

        else:
            print('Indice inválido!!! ')

    else:
        print('Opção inválida!!! ')