import entrada_abc

def questao_6(testes):
    for palavra in testes:
        flag = False
        if palavra.count('abc') < 2:
            print(palavra,":\t", False)
        else:
            palavra_aux = palavra[palavra.find('abc'):palavra.rfind('abc')+3].replace('abc','0').split('0')
            palavra_aux = list(filter(lambda a: a != '', palavra_aux))
            
            for i in palavra_aux:
                if len(i) % 2 == 1:
                    flag = True
                    break
            if flag:
                print(palavra,":\t", True)
            else:
                print(palavra,":\t", False)

            #abc a abc abc

testes = entrada_abc.casos_testes(9)
questao_6(testes)


#ternary = abc.ternary()

'''
def teste_logica(palavra):
    palavra = palavra[palavra.find('abc'):palavra.rfind('abc')+3]
    print(palavra)
    palavra = palavra.replace('abc','0').split('0')
    palavra = list(filter(lambda a: a != '', palavra))
    print(palavra)

teste_logica('aabcabcaabca')
aaa_abc_asbsbaa_abc_basbba abc_asbsbaasbsa
'''
