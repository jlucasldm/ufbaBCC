from math import floor

MAXNUMREGS = 11

class Registro (object):
    def __init__ (self, chave, nome, idade):
        self.chave = chave
        self.nome = nome
        self.idade = idade

joshua = Registro(1, 'dale', 10)
print(joshua.nome)

def hash1(chave):
    return chave % MAXNUMREGS

def hash2(chave):
    return floor(chave/MAXNUMREGS) % MAXNUMREGS

print(hash2(89))