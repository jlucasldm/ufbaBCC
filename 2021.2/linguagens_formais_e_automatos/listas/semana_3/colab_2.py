from gramatica import GLC
'''
V1 = {'P'}
Sigma1 = {'a', 'b'}
R1 = {('P', 'aPa'),
     ('P', 'bPb'),
     ('P', 'a'),
     ('P', 'b'),
     ('P', '')}
S1 = 'P'
'''

V1 = {'P', 'A', 'B'}
Sigma1 = {'a', 'b'}
R1 = {('P', 'A'),
    ('P', 'B'),
    ('P', 'a'),
    ('P', 'b'),
    ('P', ''),
    ('A', 'aPa'),
    ('B', 'bPb')}
S1 = 'P'

G1 = GLC(V1, Sigma1, R1, S1)
G1.print()
print("abababababa:\t", G1.gera('abababababa'))
print("abba:\t\t", G1.gera('abba'))
print("bbabb:\t\t", G1.gera('bbabb'))
print("aabaabaa:\t", G1.gera('aabaabaa'))
print(' :\t\t', G1.gera(''))