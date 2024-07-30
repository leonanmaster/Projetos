def high_and_low(numbers):
    lista = [int(num) for num in numbers.split()]

    mini = min(lista)
    maxi = max(lista)
    result = f'{maxi} {mini}'

    return result


print(high_and_low("1 9 3 4 -5"))