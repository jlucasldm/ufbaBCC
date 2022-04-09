#1
V = {'A', 'B', 'C'}
Sigma = {'a', 'b', 'c'}
R = {('C', 'ABc'),
     ('B', 'bBcc'),
     ('B', ''),
     ('A', 'aABccc'),
     ('A', '')}
S = 'C'

G = GLC(V, Sigma, R, S)
G.print()
print(':\t', G.gera(''))
print('0011:\t', G.gera('0011'))
print('001111:\t', G.gera('001111'))
print('11:\t', G.gera('11'))