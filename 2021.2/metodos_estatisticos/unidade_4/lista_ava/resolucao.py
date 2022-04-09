'''
C = {pacientes acima dos 40 casados} = 60%
S = {pacientes acima dos 40 solteiros} = 40%

Dsol = solteiro a probabilidade de ter distúrbio hormonal no último ano = 10%
Dcas = casados a probabilidade de ter distúrbio hormonal no último ano = 30%

P(D) = P(D|C)*P(C) + P(D|S)*P(S)
     = 0.3*0.6 + 0.1*0.4
     = 0.18 + 0.04
     = 0.22

Se a paciente sorteada tiver distúrbio hormonal, qual a probabilidade de ser casada?

P(C|D) = P(D|C)*P(C)/P(D)
       = 0.3*0.6/0.22
       = 0.82 aprox
'''