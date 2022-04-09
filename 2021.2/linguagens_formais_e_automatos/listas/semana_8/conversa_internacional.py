def solucao(lista):
    if lista.count(lista[0]) == len(lista):
        return lista[0]
    else:
        return 'ingles'


n = int(input())
for i in range(n):
    m = int(input())
    lista = []
    for j in range(m):
        aux = input()
        lista.append(aux)
    print(solucao(lista))
    lista = []
