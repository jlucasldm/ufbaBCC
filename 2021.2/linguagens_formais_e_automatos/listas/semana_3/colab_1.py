from gramatica import GLC
"""
V = {'P'}
Sigma = {'a', 'b'}
R = {('P', 'aaP'),
     ('P', 'aPa'),
     ('P', 'Paa'),
     ('P', 'bP'),
     ('P', 'Pb'),
     ('P', 'b'),
     ('P', '')}
S = 'P'
"""

V = {'P', 'I'}
Sigma = {'a', 'b'}
R = {('P', 'bP'),
     ('P', 'aI'),
     ('P', 'b'),
     ('P', ''),
     ('I', 'aP'),
     ('I', 'bI'),
     ('I', 'a')}
S = 'P'

G = GLC(V, Sigma, R, S)
G.print()
print('aaaabbbaa:\t', G.gera('aaaabbbaa'))
print('abba:\t\t', G.gera('abba'))
print('babba:\t\t', G.gera('babba'))
print('aa:\t\t', G.gera('aa'))
print(" :\t\t", G.gera(''))