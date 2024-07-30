def convert(num_inteiro):
    
    binario_invert = ''
    
    while num_inteiro >= 1:
        string_mod = str(int(num_inteiro) % 2) 
        binario_invert += string_mod
        num_inteiro = num_inteiro / 2
   
    binario = binario_invert[::-1]
    return binario

print(convert(23))