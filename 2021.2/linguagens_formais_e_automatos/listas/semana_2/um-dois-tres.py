n = int(input())
words = []

for i in range(n):
    aux = str(input())

    if len(aux) == 5:
        words.append(3)
    else:
        if aux[0] == 'o' and (aux[1] == 'n' or aux[2] == 'e') or (aux[0] == 'o' or aux[1] == 'n') and aux[2] == 'e':
            words.append(1)
        else:
            words.append(2)


for count in words:
    print(str(count))