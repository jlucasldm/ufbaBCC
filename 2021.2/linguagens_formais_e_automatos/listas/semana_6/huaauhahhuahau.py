def solucao(entrada):
    res = ''
    for i in entrada:
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u':
            res += i

    if res == res[::-1]:
        print('S')
        return 'S'
    else:
        print('N')
        return('N')


solucao(input())