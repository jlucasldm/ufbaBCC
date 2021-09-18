import dados

def questao1(testes):
    flag = True
    for frase in testes:
        if len(frase) <=2:
                print(frase,":\t", True)
        else:
            for i in range(len(frase)):
                #print('frase:', frase,'\tfrase[2*',i,']:', frase[2*i+1])
                if i+2>= len(frase):
                    break
                if frase[i] == frase[i+2]:
                    flag = False
                    break
            if flag:
                print(frase,":\t", True)
            else:
                print(frase,":\t", False)
            flag = True


testes = dados.caso_testes(10)
questao1(testes)

