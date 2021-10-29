from gramatica import GLC

V = {'P', 'B'}
Sigma = {'0', '1'}
R = {('P', '00P'),
     ('P', '11P'),
     ('P', 'B'),
     ('B', '')}
S = 'P'

G = GLC(V, Sigma, R, S)
G.print()
print(':\t', G.gera(''))
print('0011:\t', G.gera('0011'))
print('001111:\t', G.gera('001111'))
print('11:\t', G.gera('11'))
