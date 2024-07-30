palavra = 'amor'
i = 0 
while True: 
    i += 1   
    letra = input('Letra:')
    if letra == 'amor':
        print ('vc acertou a palavra em ',i,' tentativas!!!')
        break
    elif letra in palavra:
        print (letra)
    else:
        print ('*')
   