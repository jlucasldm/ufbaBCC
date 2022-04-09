import lfa

Q = {'inicio','ia','ib','pa','pb','indef','def'}
Sigma = {'a','b'}
delta = {('inicio','a'):{'ia'},
         ('inicio','b'):{'ib'},

         ('ia','a'):{'pa'},
         ('ia','b'):{'indef'},

         ('pa','a'):{'ia'},
         ('pa','b'):{'indef'},
         
         ('ib','b'):{'pb'},
         ('ib','a'):{'def'},

         ('pb','b'):{'ib'},
         ('pb','a'):{'indef'},

         ('def','a'):{'indef'},
         ('def','b'):{'indef'},
         ('indef','a'):{'def'},
         ('indef','b'):{'def'}}
q0 = 'inicio'
F = {'ib','pa','def'}
 
M = lfa.AFN(Q,Sigma,delta,q0,F)
M.visualizar()