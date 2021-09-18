import ab

def questao_8(testes):
    for palavra in testes:
        if palavra.count('a') % 2 == 0 and palavra.count('b') % 2 == 0:
            print(palavra,":\t", True)
        elif palavra.count('a') % 2 == 1 and palavra.count('b') % 2 == 1:
            print(palavra,":\t", True)
        else:
            print(palavra,":\t", False)


testes = ab.caso_testes(10)
questao_8(testes)
            