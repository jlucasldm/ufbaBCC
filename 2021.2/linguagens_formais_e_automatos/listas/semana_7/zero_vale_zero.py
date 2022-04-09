def solucao(a, b):
    c = str(a+b).replace('0', '')
    print(c)
    return c

while 1:
    a, b = input().split()
    if int(a) == 0 and int(b) == 0:
        break
    else:
        solucao(int(a), int(b))