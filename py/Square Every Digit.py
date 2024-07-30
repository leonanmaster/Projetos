def square_digits(num):
    numero_string = ''
    for number in str(num):
        numero_string += str(int(number) ** 2)   
    return int(numero_string)

print(square_digits(29837))