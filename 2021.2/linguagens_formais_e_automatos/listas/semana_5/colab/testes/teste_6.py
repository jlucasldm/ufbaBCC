import abc

#código incompleto

def questao_6(testes):
    for palavra in testes:
        if palavra.count('abc') < 2:
            print(palavra,":\t", False)
        else:
            return

testes = abc.caso_testes(10)
questao_6(testes)

