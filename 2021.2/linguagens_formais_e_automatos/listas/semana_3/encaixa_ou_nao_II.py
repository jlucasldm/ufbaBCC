def solucao(a, b):
    #print("s: ", a.find(b, (len(a) - len(b)), len(a)))
    return 'encaixa' if not a.find(b, (len(a) - len(b)), len(a)) == -1 else 'nao encaixa'

n = int(input())

for i in range(n):
    a, b = input().split()
    print(solucao(a, b))