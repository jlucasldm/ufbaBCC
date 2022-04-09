def solucao(palavras, tamanho):
    espaco = " "
    for i in palavras:
        print(str(espaco*(tamanho - len(i)) + i))
    print("")

n = int(input())
while n != 0:
    tamanho = 0
    palavras = []
    for i in range(n):
        aux = input()
        palavras.append(aux)
        if len(aux) > tamanho:
            tamanho = len(aux)
    solucao(palavras, tamanho)
    n = int(input())
    if n != 0:
        print("")

