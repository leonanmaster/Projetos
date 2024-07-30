nome = input('Qual o seu nome? ')
if len(nome) <= 4:
    print('Nome pequeno')
elif len(nome) >= 5 and len(nome) <= 6:
    print('Nome medio')
else:
    print('Nome grande')