#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vertices  := lista de inteiros [0, ..., n-1]
# arestas   := lista de tuplas sinalizando conexão estre os vértices
# cop       := inteiro sinalizando um vértice
# robber    := inteiro sinalizando um vértice

def copWin(vertices, arestas):
    n = len(vertices)
    neighbors = {}
    flag = 1
    # criando dicionário contendo o conjunto de vértices vizinhos para
    # todo vértice vi do grafo
    for i in range(n):
        neighbors_i = []
        for j in range(len(arestas)):
            if arestas[j].count(i):
                if arestas[j].index(i) == 0:
                    neighbors_i.append(arestas[j][1])
                else:
                    neighbors_i.append(arestas[j][0])
        neighbors_i.sort()
        neighbors.update({i: neighbors_i})
    print(neighbors)

    # implementação do teorema 2.1
    for i in range(n - 1):
        for j in range(i + 1, n):
            # criando as listas de vizinhos para os vértices vi e vj
            neighbors_i = neighbors[i]
            neighbors_j = neighbors[j]

            if j in neighbors_i:
                neighbors_i.remove(j)
            if i in neighbors_j:
                neighbors_j.remove(i)

            # checagem de condição do teorema
            print("neighbors[i =", i, "]:", neighbors_i)
            print("neighbors[j =", j, "]:", neighbors_j, "\n")
            if not (all(x in neighbors_j for x in neighbors_i)):
                flag = 0
                return flag
    return flag


print(copWin([0, 1, 2, 3], [(0, 1), (1, 2), (2, 3), (3, 0),()]))
print("\n")
print(copWin([0, 1, 2], [(0, 1), (1, 2), (2, 0)]))
