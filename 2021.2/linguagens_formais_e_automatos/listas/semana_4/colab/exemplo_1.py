#@title 1. Construa um AFD para a seguinte linguagem sobre o alfabeto $\Sigma = \{0, 1\}$: O conjunto das palavras que contem um ou dois 1’s, cujo tamanho é múltiplo de 3.
import lfa

Q = {'z1r0','z1r1','z1r2','u1r0','u1r1','u1r2','d1r0','d1r1','d1r2'}
Sigma = {'0','1'}
delta = {('z1r0','0'):'z1r1',
         ('z1r1','0'):'z1r2',
         ('z1r2','0'):'z1r0',
         ('u1r0','0'):'u1r1',
         ('u1r1','0'):'u1r2',
         ('u1r2','0'):'u1r0',
         ('d1r0','0'):'d1r1',
         ('d1r1','0'):'d1r2',
         ('d1r2','0'):'d1r0',
         ('z1r0','1'):'u1r1',
         ('z1r1','1'):'u1r2',
         ('z1r2','1'):'u1r0',
         ('u1r0','1'):'d1r1',
         ('u1r1','1'):'d1r2',
         ('u1r2','1'):'d1r0'}
q0 = 'z1r0'
F = {'u1r0','d1r0'}
 
M = lfa.AFD(Q,Sigma,delta,q0,F)
M.visualizar()
#M.aceita("100")