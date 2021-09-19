import ab

def xor(a, b):
    return (not a and b) or (a and not b)

def questao_8(testes):
    for palavra in testes:
        a_count = palavra.count('a')
        b_count = palavra.count('b')

        if a_count == 0:
            if b_count % 2 == 1:
                print(palavra,":\t", True)
            else:
                print(palavra,":\t", False)
        elif b_count == 0:
            if a_count % 2 == 0:
                print(palavra,":\t", True)
            else:
                print(palavra,":\t", False)
        else:
            if xor(a_count % 2 == 0, b_count % 2 == 1):
                print(palavra,":\t", True)
            else:
                print(palavra,":\t", False)


testes = ab.caso_testes(10)
questao_8(testes)

xor(0, 0)
xor(0, 1)
xor(1, 0)
xor(1, 1)
            