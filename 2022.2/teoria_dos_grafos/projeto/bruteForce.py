# Implementação do Jogo Polícia e Ladrão em Grafos
# Discentes: Kaio Rodrigo, João Lucas Melo e Thiago Andrade
# Docente: Roberto Parente
# Disciplina: Teoria dos Grafos
# Instituição: Universidade Federal da Bahia
# Departamento: Ciência da Computação

from queue import Queue

# Função principal do algoritmo. Simula o comportamento dos jogadores Cop 
# e Robber durante uma partida. Ambos os jogadores se movimentam sobre os
# vértices de um grafo. Cop se movimenta tentando sempre se aproximar de
# Robber, e Robber tenta sempre se afastar de Cop.  
#
# A função recebe quatro entardas. Uma lista de inteiros vertices, 
# representando o conjunto de vértices do grafo, uma lista de tuplas 
# representando o conjunto de arestas do grafo (onde cada tupla representa
# um par de vértices u,v tal que exista uma aresta uv), um inteiro cop 
# representando o vértice ocupado por Cop e um inteiro robber representando 
# o vértice ocupado por Robber.
# 
# Ao receber as entradas, a função cria um dicionário cujas chaves são os
# vértices do grafo e os valores são uma lista contendo todos seus vértices
# adjacentes. O dicionário, portanto, armazena todos os vizinhos de cada
# vértice v do grafo. O dicionário é atribuído a variável neighbors.
# 
# A função então entra em um laço até que cop == robber, ou seja, que Cop
# e Robber ocupem o mesmo vértice. Dentro do laço os movimentos dos 
# jogadores são simulados. Os vizinhos de cop e o inteiro robber são 
# passados como parâmetro da função distances(), que retornará a distância
# de cada um dos vizinhos de cop a robber. Cop, portanto, sabe para qual 
# vértice se mover a fim de fazer a melhor jogada, que é se aproximar de
# Robber. O valor de cop é atualizado para o vértice vizinho a cop com
# menor distância a robber. O algoritmo checa se cop == robber. Se for o 
# caso, encerra a execução e retorna 1, indicando que o grafo é cop-win.
# Caso contrário, cede a vez a Robber, cujo movimento será simulado da 
# mesma fora que Cop, buscando se distanciar do oponente (se locomovendo
# para o vértice adjacente a robber mais distante de cop). Mais uma vez
# a condição cop == robber é checada. Se ocorrer, encerra a execução e 
# retorna 1, indicando que o grafo é cop-win. Caso contrário, cede a vez 
# a Cop e por assim adiante.
# 
# A função retorna 1 caso o grafo seja cop-win. Caso não seja encontrada
# uma situação de captura, onde cop == robber, o programa segue sua 
# execução. Portanto, não há condição de parada pra um grafo robber-win. 
def bruteForce(vertices, arestas, cop, robber):
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
        neighbors.update({i:neighbors_i})

    # Simulação dos movimentos de Cop e Robbers enquanto não houver 
    # captura.
    while cop != robber:
        neighbors_cop = neighbors[cop]
        distance_to_robber = distances(neighbors, robber)
        move_cop = 999999999
        
        # Turno de Cop
        for i in neighbors_cop:
            if distance_to_robber[i] <= move_cop:
                move_cop = distance_to_robber[i]
                cop = i
                
        # Checagem da condição de captura após o turno de Cop
        if cop == robber:
            return 1

        neighbors_robber = neighbors[robber]
        distance_to_cop = distances(neighbors, cop)
        move_robber = 0

        # Turno de Robber
        for i in neighbors_robber:
            if distance_to_cop[i] >= move_robber:
                move_robber = distance_to_cop[i]
                robber = i
    
    return 1


# Função auxiliar para cálculo da distância entre todos os vértices vizinhos
# de um dado vértice v a um vértice u.

# A função recebe duas entradas, uma lista de inteiros neighbors (lista de
# inteiros representando todos os vértices vizinhos a um dado vértice) e um 
# inteiro source (representando o vértice cuja distância aos vértices em 
# neighbors deve ser calculada).

# Para cada vértice v em neighbors, distances() irá calcular a distância à
# source. A função armazenará os cálculos em um dicionário, atribuindo a cada
# par key/value um vértice de neighbors e sua distância a source. A função
# retornará o dicionário de distâncias.
def distances(neighbors, source):
    q = Queue()
    q.put(source)
    visited_vertices = []
    visited_vertices.append(source)

    # Inicializando dicionário de distâncias de vértices a source
    distance = {k: 999999999 for k in neighbors.keys()}

    # Alimentando o dicionário de distâncias de vértices a source
    while not q.empty():
        vertex = q.get()

        if vertex == source:
            distance[vertex] = 0
        
        for u in neighbors[vertex]:
            if u not in visited_vertices:
                if distance[u] > distance[vertex] + 1:
                    distance[u] = distance[vertex] + 1
                q.put(u)
                visited_vertices.append(u)
    
    return distance



# Entradas teste:
#
# print(bruteForce([0,1,2,3], [(0,1),(1,2),(2,3),(3,0),(0,0),(1,1),(2,2),(3,3)]))                                         # um quadrado, não cop-win. o programa rodará indefinifamente
print(bruteForce([0,1,2], [(0,1),(1,2),(2,0),(0,0),(1,1),(2,2)], 1, 2))                                                   # um triangulo, cop-win
print(bruteForce([0,1,2,3], [(0,1),(1,2),(2,3),(3,0),(3,1),(0,0),(1,1),(2,2),(3,3)], 1, 3))                               # dois triangulos, cop-win
print(bruteForce([0,1,2,3,4,5], [(0,1),(1,2),(2,3),(2,5),(3,4),(3,5),(4,5),(0,0),(1,1),(2,2),(3,3),(4,4),(5,5)], 1, 3))   # um grafo cop-win