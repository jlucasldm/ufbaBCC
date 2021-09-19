n = int(input())
lista = []
for i in range(n):
    lista.append(input().lower())

for i in lista:
    print("print('",i,":\\t', G.gera('",i,"'))")


"""
{ABC}

{ABC}+{DEFG}+{Z}+{}

{ABE}*{ABCD}

{ABCD}-{CZ}

{ABC}+{CDE}*{CEZ}

({ABC}+{CDE})*{CEZ}

"""