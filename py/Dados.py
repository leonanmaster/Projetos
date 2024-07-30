nome = input('Qual o seu nome? ')
idade = input('Qual a sua idade? ')
altura = input('Qual a sua altura? ')
peso = input('Qual o seu peso? ')

dados = {
    'Nome' : nome,
    'Idade' : idade,
    'Altura' : altura,
    'Peso' : peso
}

def exibe_dados(**kwargs):
    for chave, dado in kwargs.items():
        print (f'{chave} : {dado}')

exibe_dados(**dados)