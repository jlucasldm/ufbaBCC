def solucao(a, b):
    operacao = 0
    for n in range(len(a)):
        if ord(a[n]) < ord(b[n]):
            operacao += ord(b[n]) - ord(a[n])
        elif ord(a[n]) == ord(b[n]):
            operacao += 0
        else:
            operacao += ord(b[n]) - ord(a[n]) + ord('z') - ord('a') + 1
    print(operacao)
    
n = int(input())
for i in range(n):
    a,b = input().split()
    solucao(a, b)