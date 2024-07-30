def to_jaden_case(string):
    list_str = string.split(' ')    # transforma string em lista de strings.
    list = [word.capitalize() for word in list_str]     # transforma as primeiras letras das palavras da lista em maiuscula.
    str = ' '.join(list)    # esse join transforma listas em strings, o ' ' é o separador.
    return str
phrase = "How can mirrors be real if our eyes aren't real"
print(to_jaden_case(phrase))