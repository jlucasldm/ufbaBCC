def solucao(frase):
    palavras = frase.lower().split()
    aux = 0
    count = 0

    for i,j in enumerate(palavras):
        palavras[i] = j[0]
        if palavras[i] == palavras[i-1] and aux == 0:
            aux = 1
            count += 1
        elif palavras[i] != palavras[i-1]:
            aux = 0

    return count
    
    
while 1: 
    try: 
        print(solucao(input()))         
    except EOFError: 
        break