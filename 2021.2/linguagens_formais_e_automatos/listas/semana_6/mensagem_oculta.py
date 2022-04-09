def solucao(entrada):
    entrada = entrada.split(' ')
    res = ''
    for palavra in entrada:
        if len(palavra) > 1 and palavra[0].isalpha():
            res += palavra[0]
        elif len(palavra) == 1 and palavra.isalpha():
            res += palavra
    print(res)
    return res

# solucao('compete·online·design·event·rating')

n = int(input())
for i in range(n):
    solucao(input())