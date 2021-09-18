import dados

def questao1(testes):

    for frase in testes:
        zero_impar = 0
        zero_par = 0

        for i in range(len(frase)):
            if frase[i] == '0':
                if int(i) % 2 == 0:
                    zero_impar += 1
                elif int(i) % 2 == 1:
                    zero_par += 1

        if zero_impar%2 == 1 and zero_par%2 == 0:
            print(frase,":\t", True)
        else:
            print(frase,":\t", False)


testes = dados.caso_testes(10)
questao1(testes)

