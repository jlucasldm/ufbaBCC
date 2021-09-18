import ab

def questao_8(testes):
    for palavra in testes:
        if palavra.count('a') or palavra.count('b'):
            print(palavra,":\t", True)
        else:
            print(palavra,":\t", False)


testes = ab.caso_testes(10)
questao_8(testes)
            