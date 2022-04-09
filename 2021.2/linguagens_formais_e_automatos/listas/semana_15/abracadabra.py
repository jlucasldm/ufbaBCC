def solucao(s):
    separado = ''
    res = ''
    count = 1

    for i in range(len(s)):
        separado += s[i] + ' '
    separado = separado[:len(separado)-1] + "\n"
    
    res += separado
    for i in range(1, len(s)):
        res += ' '*count + separado[:len(separado) - 1 - i*2] + "\n"
        count += 1
    return res


while 1: 
    try:
        s = input()
        print(solucao(s))
    except EOFError: 
        break