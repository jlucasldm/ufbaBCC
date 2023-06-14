%Questao 15
progenitor(maria, jose).
progenitor(joao, jose).
progenitor(joao, ana).
progenitor(jose, julia).
progenitor(jose, iris).
progenitor(iris, jorge).

avo(X, Y):-
    progenitor(X, W), progenitor(W, Y).

ancestral(Ancestral,Pessoa):-
    progenitor(Ancestral, Pessoa).
ancestral(Ancestral,Pessoa):-
    progenitor(Pai, Pessoa),
    ancestral(Ancestral, Pai).

descendente(Descendente, Pessoa):-
    progenitor(Pessoa, Descendente).
descendente(Descendente, Pessoa):-
    progenitor(Pessoa, Filho),
    descendente(Descendente, Filho).

lista_desc(Pessoa):-
    findall(Descendente, descendente(Descendente, Pessoa), ListaDesc),
    write(ListaDesc).

lista_anc(Pessoa):-
    findall(Ancestral, ancestral(Ancestral, Pessoa), ListaAncestral),
    write(ListaAncestral).


%Questao 16
localizado_em(salvador, bahia).
localizado_em(bahia, brasil).
localizado_em(brasil,america).
localizado_em(maceio, brasil).
localizado_em(roma, italia).

nasceu_em(joao, salvador).
nasceu_em(maria, maceio).
nasceu_em(giuseppe, roma).

localizado_em_recursao(X, Y):-
    localizado_em(X, Y).
localizado_em_recursao(X, Y):-
    localizado_em(Z, Y),
    localizado_em_recursao(X, Z).

nasceu_em_recursao(Pessoa, Lugar):-
    nasceu_em(Pessoa, Lugar).
nasceu_em_recursao(Pessoa, Lugar):-
    localizado_em_recursao(L, Lugar),
    nasceu_em_recursao(Pessoa, L).

percorre_lista([]).
percorre_lista([Cabeca|Cauda]):-
    writeln(Cabeca),
    percorre_lista(Cauda).

lista_nasc_local(Pessoa):-
    findall(Local, nasceu_em_recursao(Pessoa, Local), ListaLocal),
    list_to_set(ListaLocal, SetLocal),
    percorre_lista(SetLocal).

lista_nasc_pessoa(Local):-
    findall(Pessoa, nasceu_em_recursao(Pessoa, Local), ListaPessoa),
    list_to_set(ListaPessoa, SetPessoa),
    percorre_lista(SetPessoa).


%Questao 17
animal(urso).
animal(peixe).
animal(peixinho).
animal(lince).
animal(raposa).
animal(coelho).
animal(veado).
animal(guaxinim).

planta(alga).
planta(grama).

come(urso, peixe).
come(lince, veado).
come(urso, raposa).
come(urso, veado).
come(peixe, peixinho).
come(peixinho, alga).
come(guaxinim, peixe).
come(raposa, coelho).
come(coelho, grama).
come(veado, grama).
come(urso, guaxinim).

come_rec(Predador, Presinha):-
    come(Predador, Presinha).
come_rec(Predador, Presinha):-
    come(Presa, Presinha),
    come_rec(Predador, Presa).

lista_cadeia(Predador):-
    findall(Presa, come_rec(Predador, Presa), ListaPresa),
    list_to_set(ListaPresa, SetPresa),
    percorre_lista(SetPresa).
