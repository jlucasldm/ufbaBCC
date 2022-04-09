import dados

def questao1(testes):
    palavras_aceitas = []

    for palavra in testes:
        #print('palavra:\t', palavra)
        flag = True
        if len(palavra) % 2 == 0:
            for i in range(len(palavra)):
                if i % 2 == 1 and palavra[i] == '0':
                    flag = False
                    break
            if flag:
                palavras_aceitas.append(palavra)
        elif len(palavra) % 2 == 1:
            for i in range(len(palavra)):
                if i % 2 == 0 and palavra[i] == '0':
                    flag = False
                    break
            if flag:
                palavras_aceitas.append(palavra)

    # for i in palavras_aceitas:
    #     print(i)

    for frase in testes:
        if frase in palavras_aceitas:
            print(frase,":\t", True)
        else:
            print(frase,":\t", False)

        

testes = dados.caso_testes(10)
questao1(testes)

