#funcao principal Encaixa ou Nao
def solucao(a, b):
    #procurar na string a, a partir do índice (len(a) - len(b))
    #ate o fim de a, pela string b

    #string.fin(substring) retorna -1 caso nao encontre a substring em 
    #questao. caso contrario, retorna o index de onde a substring comeca

    #retorna 'encaixa' caso b for encontrado nos ultimos caracteres
    #de a. caso contrario, retorna 'nao encaixa'
    return 'encaixa' if not a.find(b, (len(a) - len(b)), len(a)) == -1 else 'nao encaixa'

#entrada da quantidade de linhas a serem lidas
n = int(input())


for i in range(n):
    #entrada da string e substring
    a, b = input().split()
    
    #printando o retorno da funcao
    print(solucao(a, b))