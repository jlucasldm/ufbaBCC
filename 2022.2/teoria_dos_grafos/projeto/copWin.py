# Implementação do Jogo Polícia e Ladrão em Grafos
# Discentes: Kaio Rodrigo, João Lucas Melo e Thiago Andrade
# Docente: Roberto Parente
# Disciplina: Teoria dos Grafos
# Instituição: Universidade Federal da Bahia
# Departamento: Ciência da Computação


# Função principal do algoritmo. Recebe como argumento uma lista de inteiros
# vertices, representando o conjunto de vértices do grafo, e uma lista arestas
# de tuplas, representando o conjunto de arestas do grafo (onde cada tupla
# representa um par de vértices u,v tal que exista uma aresta uv).
#
# Ao receber as entradas, a função cria um dicionário cujas chaves são os
# vértices do grafo e os valores são uma lista contendo todos seus vértices
# adjacentes. O dicionário, portanto, armazena todos os vizinhos de cada
# vértice v do grafo. O dicionário é atribuído a variável neighbors.
#
# A função então invoca permutationWrapper() para testar a condição do teorema
# para todas as possíveis ordenações de vértices do grafo. Caso alguma
# ordenação satisfaça a condição, copWin() retorna 1, sinalizando que o grafo
# é cop-win. Caso nenhuma ordenação de vértices satisfaça a condição, copWin()
# retorna 0, sinalizando que o grafo não é cop-win.
def copWin(vertices, arestas):
    n = len(vertices)

    # Inicialização do dicionário de vizinhos para todos os vértices do
    # grafo.
    neighbors = {}

    # Alimentando o dicionário de vizinhos para todos os vértices do grafo
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

    # Checagem de toda possível ordenação de vértices, buscando alguma que
    # satisfaça a condição do Teorema 2.1
    if permutationWrapper(vertices, [], len(vertices), neighbors):
        return 1
    else:
        return 0


# Função auxiliar para checagem da condição do teorema para todas as
# permutações possíveis de ordenação entre os vértices. Recebe como entrada
# listV (uma lista de inteiros representando vértices do grafo), listC (uma
# lista auxiliar que conterá os vértices da sequência iterada), n (um
# inteiro representando o tamanho da lista de vértices iterada) e listE
# (um dicionário contendo o conjunto de vizinhos para cada vértice v do
# grafo).
#
# A função instancializa todas as possíveis permutações da ordenação de
# vértices de listV através de uma abordagem recursiva. Invoca a função
# theoremCondition() passando o dicionário de vizinhos e uma das possíveis
# ordenações de vértices como argumentos. Dessa forma, o algoritmo garante
# a checagem da condição do teorema para todas as possibilidades de ordenação.
def permutationWrapper(listV: list, listC: list, n: int, listE: dict) -> bool:
    if n == 0:
        if theoremCondition(listE, listC):
            return True
    for v in listV:
        lista = listC + [v]
        listaaux = listV.copy()
        listaaux.remove(v)
        if permutationWrapper(listaaux, lista, len(listaaux), listE):
            return True


# Função auxiliar para checagem da condição do teorema. Recebe como entradas
# listE (um dicionário contendo o conjunto de vizinhos para cada vértice v
# do grafo) e listV (uma lista de inteiros representando vértices do grafo).
#
# A função traduz o teorema em termos computacionais. Busca para todo i na
# sequência 1 <= i < n (onde n representa o tamanho do conjunto de vértices
# do grafo), um j, i < j <= n tal que N_i[v_i] seja subconjunto de N_i[v_j].
#
# Para todo i na condição estabelecida, a função busca um j tal que a
# condição dos vizinhos seja satisfeita. A checagem dessa condição é feita
# ao invocar a funções neighbourIntersection e subsetComparison. A primeira
# define os subconjuntos a serem comparados e a segunda efetivamente checa
# a condição de um estar ou não contido no outro.
#
# Caso para todo i exista o j desejado tal que valha a condição do teorema,
# a função retorna True. Caso contrário, retorna False.
def theoremCondition(listE: dict, listV: list):
    for i in range(0, len(listV) - 1):
        for j in range(i + 1, len(listV)):
            flag = 0
            # Definindo os conjuntos a serem comparados
            subsetv1 = neighbourIntersection(
                i, listV[i], listV, listE)
            subsetv2 = neighbourIntersection(
                i, listV[j], listV, listE)

            # Comparando os conjuntos
            if (subsetComparison(subsetv1, subsetv2)):
                # Encontrado um j para um i
                flag = 1
                break

        if flag == 0:
            # Não foi encontrado nenhum j para um dado i. Portanto, a
            # condição não foi satisfeita.
            return False

    return True


# Função para criação dos conjuntos de vizinhos a serem comparados em
# theoremCondition. Recebe quatro parâmetros de entrad, um inteiro i (
# referente ao índice do vértice v_i na ordenação iterada), um inteiro vi
# (referente ao vértice v_i da ordenação iterada), uma lista de inteiros
# listV (referente à ordenação de vértices) e um dicionário listE (
# referente aos vértices vizinhos de todos os v vértices do grafo).
#
# A função armazena em uma lista todos os vértices vizinhos a vi que
# estão à sua frente na ordenação listV e a retorna ao final da operação.
def neighbourIntersection(i: int, vi: int, listV: list, listE: dict) -> list:
    neighbors_i = listE[vi]
    conj = []
    for index in range(len(listV) - 1, i - 1, -1):
        if listV[index] in neighbors_i:
            conj.append(listV[index])
    return conj


# Função auxiliar para comparação dos elementos de duas listas. Recebe
# como parâmetro duas listas, list1 e list2, e retorna True caso todos os
# elementos de list1 estejam em list2 e False caso contrário.
def subsetComparison(list1: list, list2: list) -> bool:
    for x in list1:
        if not x in list2:
            return False
    return True

# Entradas teste:
#
# print(copWin([0,1,2,3], [(0,1),(1,2),(2,3),(3,0),(0,0),(1,1),(2,2),(3,3)]))                                     # um quadrado, não cop-win
# print(copWin([0,1,2], [(0,1),(1,2),(2,0),(0,0),(1,1),(2,2)]))                                                   # um triangulo, cop-win
# print(copWin([0,1,2,3], [(1,2),(3,0),(2,3),(3,1),(0,1),(0,0),(1,1),(2,2),(3,3)]))                               # dois triangulos, cop-win
# print(copWin([0,1,2,3,4,5], [(0,1),(1,2),(2,3),(2,5),(3,4),(3,5),(4,5),(0,0),(1,1),(2,2),(3,3),(4,4),(5,5)]))   # um grafo cop-win
# print(copWin([0,1,2,3,4], [(0,1),(1,2),(2,3),(3,4),(4,0),(0,0),(1,1),(2,2),(3,3),(4,4)]))                       # um grafo não cop-win


def entrada():
    try:
        # ENTRADA DO TIPO 0 1 2 3 4 ...
        verticeInput = input("Digite os vértices separados por espaços: ")
        vertices = verticeInput.split()  # SEPARA AS ENTRADAS POR ESPAÇO
        # TRANSFORMA TODAS AS ENTRADAS DE VÉRTICE EM NÚMEROS INTEIROS
        for i in range(0, len(vertices)):
            vertices[i] = int(vertices[i])
        # ENTRADA DO TIPO 0,0 0,1 0,2 ...
        edgesInput = input(
            "Digite as arestas no formato v1,v2 separados por espaços: ")
        edges = edgesInput.split()  # SEPARA AS ENTRADAS POR ESPAÇO
        edgesForm = []
        # TRANSFORMA AS ENTRADAS EM UMA LISTA DE TUPLA
        for i in edges:
            aux = i.split(",")
            edgesForm.append((int(aux[0]), int(aux[1])))
        if copWin(vertices, edgesForm):
            print("Cop Win")
        else:
            print("Robber Win")
    except EOFError: #FINAL DO PROGRAMA: CTRL+D
        print("Final do programa")
        exit(0)

while True:
    entrada()
