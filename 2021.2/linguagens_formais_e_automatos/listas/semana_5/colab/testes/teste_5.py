import dados

def questao1(testes):
    palavras_aceitas = []

    for palavra in testes:
        impar = 0
        par =0
        #print('palavra:\t', palavra)

        if len(palavra) % 2 == 0:
            for i in range(len(palavra)):
                if i % 2 == 1 and palavra[i] == '1':
                    par += 1
            if par % 2 == 0:
                palavras_aceitas.append(palavra)
        else:
            for i in range(len(palavra)):
                if i % 2 == 0 and palavra[i] == '1':
                    impar += 1
            if impar % 2 == 1:
                palavras_aceitas.append(palavra)

    for frase in testes:
        if frase in palavras_aceitas:
            print(frase,":\t", True)
        else:
            print(frase,":\t", False)

        

testes = dados.caso_testes(10)
questao1(testes)

