v_parcial = float(input('Qual é o valor dos 10 minutos? '))
tempo = int(input('Quanto tempo você falou? (em minutos) '))
multiplicador = int(tempo // 10)
v_final = float()

if (tempo <= 0):
    print('Tempo inválido!')

else:
    
    if (tempo % 10 == 0):
        v_final = v_parcial * multiplicador
        print(f'Pague: {v_final:.2f} reais.')

    elif (tempo <= 10 and tempo > 0 ):
        print(f'Pague: {v_parcial:.2f} reais.')

    else:
        v_final = v_parcial * (multiplicador + 1)
        print(f'Pague: {v_final:.2f} reais.')