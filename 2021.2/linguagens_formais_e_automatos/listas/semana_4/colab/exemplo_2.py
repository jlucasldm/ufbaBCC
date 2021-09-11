#@title 2. Construa um AFN sobre $\Sigma = \{a, b, c\}$ que reconheça o conjunto das palavras em que o último símbolo não tenha ocorrido antes.
import lfa

Q = {'q0','ta','tb','tc','f'}
Sigma = {'a','b','c'}
delta = {('q0',''):{'ta','tb','tc'},
         ('ta','b'):{'ta'},
         ('ta','c'):{'ta'},
         ('tb','a'):{'tb'},
         ('tb','c'):{'tb'},
         ('tc','a'):{'tc'},
         ('tc','b'):{'tc'},
         ('ta','a'):{'f'},
         ('tb','b'):{'f'},
         ('tc','c'):{'f'}}
q0 = 'q0'
F = {'q0','f'}
 
M = lfa.AFN(Q,Sigma,delta,q0,F)
M.visualizar()
# M.aceita("aacacacacccacaccacaacab")