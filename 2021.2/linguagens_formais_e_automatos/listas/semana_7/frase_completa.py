def solucao(frase):
    letras = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    count = 0

    for i in letras:
        if frase.find(i) != -1:
            count += 1

    if count == 26:
        return "frase completa"
    elif count >= 13:
        return "frase quase completa"
    else:
        return "frase mal elaborada"


n = int(input())
for i in range(n):
    frase = input()
    print(solucao(frase))