def solucao(str):
    metade = len(str)//2 - 1
    line = ""
    
    for i in range(metade, -1, -1):
        line += str[i]
    
    for i in range(len(str)-1, metade, -1):
        line += str[i]

    print(line)
    return line

n = int(input())

for i in range(n):
    line = str(input())
    solucao(line)
