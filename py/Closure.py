def criar_mult (multiplicador):
    def mult(num):
        return num * multiplicador
    return mult 

duplicado = criar_mult(2) 
print (duplicado(3))