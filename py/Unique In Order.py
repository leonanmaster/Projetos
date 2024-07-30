def unique_in_order(sequence):
    lista = [element for element in sequence]
    list = []
    i = 0
    for element in lista:
        if i < len(sequence):
            if element != sequence[i-1]:
                list.append(element)
                i += 1 
            else:
                i += 1
                continue
            
    return list

print(unique_in_order('ABBCcAAAADDjDD'))
print (len([1, 1, 2, 2, 3, 3]))