import dados

def questao1(testes):
    flag = True
    for frase in testes:
        if len(frase) <= 3:
                print(frase,":\t", True)
        else:
            for i in range(len(frase)):
                #print('frase:', frase,'\tfrase[2*',i,']:', frase[2*i+1])
                if 2*i+3 >= len(frase):
                    break
                if frase[2*i+1] == frase[2*i+3]:
                    flag = False
                    break
            if flag:
                print(frase,":\t", True)
            else:
                print(frase,":\t", False)
            flag = True


testes = dados.caso_testes(10)
questao1(testes)

