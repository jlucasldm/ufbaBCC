def ternary (n):
    if n == 0:
        return '0'
    nums = []
    while n:
        n, r = divmod(n, 3)
        nums.append(str(r))
    return ''.join(reversed(nums))


testes = []

def casos_testes(caracteres):
    for i in range(1, caracteres):
        for j in range(3**i):
            if len(ternary(j)) < i:
                palavra = '0'*(i-len(ternary(j))) + ternary(j)
                palavra = palavra.replace('0', 'a').replace('1', 'b').replace('2', 'c')
                testes.append(palavra)
            else:
                palavra = ternary(j)
                palavra = palavra.replace('0', 'a').replace('1', 'b').replace('2', 'c')
                testes.append(palavra)

    print(testes)
    return testes
