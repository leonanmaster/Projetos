while True:

    palavra = input('Digite uma palavra secreta: ')
    letra_acertada = '' #serve apenas para salvar as letras que estao na palavra
    i = 0

    while True:
        letra_digi = input('Letra: ')

        i+=1

        if len(letra_digi)>1 : #caso seja digitada mais de uma letra
            print('Digite uma letra apenas!')
            continue

        if letra_digi in palavra: #salva letras acertadas
            letra_acertada += letra_digi

        palavra_formada = ''

        for letra_secreta in palavra: #percorre palavra secreta e forma uma nova identica
            if letra_secreta in letra_acertada:
                palavra_formada += letra_secreta
            else:
                palavra_formada += '*'
        
        if palavra_formada == palavra:
            print(palavra)
            print('Vc acertou a palavra em ', i ,' tentativas!')
            break

        print(palavra_formada)
