def mul(n):
    while '*' in n:
        i = n.index('*')
        aux = set(n[i - 1]).intersection(set(n[i + 1]))
        aux = ''.join(aux)
        n.insert(i-1, aux)
        n.pop(i)
        n.pop(i)
        n.pop(i)
    return n

def sum(n):
    while '+' in n:
        i = n.index('+')
        aux = set(n[i - 1]).union(set(n[i + 1]))
        aux = ''.join(aux)
        n.insert(i-1, aux)
        n.pop(i)
        n.pop(i)
        n.pop(i)
    return n

def sub(n):
    while '-' in n:
        i = n.index('-')
        aux = set(n[i - 1]).difference(set(n[i + 1]))
        aux = ''.join(aux)
        n.insert(i-1, aux)
        n.pop(i)
        n.pop(i)
        n.pop(i)
    return n

def amigos(n):
    outer_terms = n.replace('(', ' ').replace(')', ' ').split(' ')
    print('outer_terms:\t', outer_terms)

    '''
    n = n.replace('{', ' ')
    n = n.replace('}', ' ')
    n = n.split(' ')
    print(n)

    n = mul(n)
    print('n: ', n)

    n = sum(n)
    print('n: ', n)

    n = sub(n)
    print('n: ', n)
    
    n[0] = '{'
    n[2] = '}'
    n[1] = ''.join(sorted(n[1]))
    n = ''.join(str(x) for x in n)
    print('final_n:\t', n)
    return n
    '''

#print(amigos('{ABC}'))
#print(amigos('{ABC}+{DEFG}+{Z}+{}'))
#print(amigos('{ABE}*{ABCD}'))
#print(amigos('{ABCD}-{CZ}'))
#print(amigos('{ABC}+{CDE}*{CEZ}'))
print(amigos('({ABC}+{CDE})*{CEZ}'))
print(amigos('({ABC}+({CDE}*({A}-{B})+({A}+{B})))*{CEZ}'))

'''
while 1: 
    try: 
        print(amigos(input()))         
    except EOFError: 
        break
'''

'''
def amigos(n):
    if '+' in n:
        to_sum = n.split('+')
        print('to_sum', to_sum)
    if '-' in n:
        to_sub = n.split('-')
        print('to_sub', to_sub)
    if '*' in n:
        to_mul = n.split('*')
        print('to_mul', to_mul)
    '''