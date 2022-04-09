from collections import Counter

def solucao(entrada):
    entrada = ''.join(filter(str.isalpha, entrada))
    count = Counter(entrada.lower())
    keys = sorted(count)

    max_val = max(count.values())
    res = ''

    for i in keys:
        if count[i] == max_val:
            res += i

    print(res)
    return res

n = int(input())

for i in range(n):
    entrada = input()
    solucao(entrada)