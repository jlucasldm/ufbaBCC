from typing import Counter


def solucao(num):
    res = ''
    count = 1
    for i in range(int(num/2), -1, -1):
        res += " "*i + "*"*((count*2)-1) + "\n"
        count += 1
    res += " "*int(num/2) + "*" + "\n"
    res += " "*(int(num/2) - 1) + "***" + "\n"
    return res


while 1: 
    try:
        s = input()
        print(solucao(int(s)))
    except EOFError: 
        break