def solucao(alunos, presenca):
    rep = ''
    for i in range(len(alunos)):
        aluno = alunos[i]
        frequencia = presenca[i]
        if frequencia.count('P') < (75/100)*(len(frequencia) - frequencia.count('M')):
            rep += aluno + ' '
    return rep[:len(rep)-1]

casos = int(input())
for i in range(casos):
    alunos = int(input())
    alunos = input().split(' ')
    presenca = input().split(' ')
    print(solucao(alunos, presenca))