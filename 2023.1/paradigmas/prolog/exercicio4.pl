% fatos
genitor(pam, bob).
genitor(pat, jim).
genitor(tom, bob).
genitor(tom, liz).
genitor(bob, ann).
genitor(bob, pat).

mas(tom).
mas(bob).
mas(jim).

fem(pam).
fem(liz).
fem(ann).
fem(pat).


% regras
filho(X, Y) :- genitor(Y,X).
mae(X, Y) :- genitor(X, Y), fem(X).
irmao(X, Y) :- genitor(Z, X), genitor(Z, Y).
avo(X, Y) :- genitor(X, Z), genitor(Z, Y).
neto(X, Y) :- avo(Y, X).






