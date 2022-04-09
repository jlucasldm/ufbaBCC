import entrada_abc

def questao_6(testes):
    for palavra in testes:
        if palavra.count(palavra[len(palavra)-1]) <= 2:
            print(palavra,":\t", True)
        else:
            print(palavra,":\t", False)

testes = entrada_abc.casos_testes(9)
questao_6(testes)
