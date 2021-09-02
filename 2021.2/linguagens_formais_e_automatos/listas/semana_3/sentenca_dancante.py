#funcao principal Sentenca Dancante
def solucao(s):
    #flag para captalizacao do caractere
    upper = True
    #string auxiliar
    res = ''

    #iteracao para cada caractere da string s
    for i in range(len(s)):
        #caso o caractere atual nao seja uma letra
        if not s[i] == ' ':
            if upper == True:
                #insere o caractere, em maiusculo, para a string auxiliar
                res += s[i].upper()
                #configura o proximo caractere para ser minusculo
                upper = False
            else:
                #insere o caractere, em minusculo, para a string auxiliar
                res += s[i].lower()
                #configura o proximo caractere para ser maiusculo
                upper = True
        else:
            #insere o caractere ' ' para a string auxiliar
            res += s[i]

    #printando a string auxiliar        
    print(res)
    

#tratemnto de excecao para manter o funcionamento
#da entrada de dados
while 1: 
    try: 
        solucao(input())         
    except EOFError: 
        break
