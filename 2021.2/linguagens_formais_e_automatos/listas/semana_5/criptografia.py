def solucao(message):
    aux = ""
    code = ""

    for i in range(len(message)):
        if message[i].isalpha():
            aux += chr(ord(message[i]) + 3)
        else:
            aux += message[i]

    for i in range(len(aux)-1, -1, -1):
        code += aux[i]

    half = len(code)//2

    aux = code
    code = aux[:half]

    for i in range(half, len(aux)):
        code += chr(ord(aux[i]) - 1)

    print(code)
    return code



n = int(input())

for i in range(n):
    line = str(input())
    solucao(line)