class Processo:
    def __init__(self, nome, tempo_de_chegada, tempo_de_execucao, deadline, prioridade):
        self.n = nome
        self.tc = tempo_de_chegada
        self.te = tempo_de_execucao
        self.d = deadline
        self.p = prioridade

def fifo(lista_processos, tamanho_lista, matriz):
    start = 0
    for i in range(tamanho_lista):
        processo = lista_processos[i]
        print("processo " + str(processo.n) + ":\t" + str(processo.te))
        linha = matriz[i][0]
        print("linha: " + linha)
        before = linha[:start]
        print("antes: " + before)
        after = linha[processo.te:]
        print("depois: " + after)
        res = before + "*" * processo.te + after
        print(res)
        matriz[i][0] = res
        start += processo.te
        print("start: " + str(start))
    return 1

def imprime_processo(processo):
    for i in range(numero_de_processos):
        print("processo:\t" + str(processos[i].n))
        print("t.chegada:\t" + str(processos[i].tc))
        print("t_execucao:\t" + str(processos[i].te))
        print("deadline:\t" + str(processos[i].d))
        print("prioridade:\t" + str(processos[i].p))
    return 1

def imprime_matriz(matriz):
    for i in range(numero_de_processos):
        print(str(i) + ":", end= "")
        print(matriz[i][0], end="")
        print("|", end="\n")
    return 1

print("quantidade de processos: ")
numero_de_processos = int(input())

print("quantum: ")
quantum = int(input())

print("sobrecarga: ")
sobrecarga = int(input())

# inicializando a matriz
processos = []
linha = ["." * 30]
matriz = []
for i in range(numero_de_processos):
    matriz.append(linha)

imprime_matriz(matriz)
print(matriz[2])

# inicializando os processos
for i in range(numero_de_processos):
    tempo_de_chegada = int(input())
    tempo_de_execucao = int(input())
    deadline = int(input())
    prioridade = int(input())

    p = Processo(i, tempo_de_chegada, tempo_de_execucao, deadline, prioridade)

    processos.append(p)

fifo(processos, numero_de_processos, matriz)

imprime_matriz(matriz)