% Discentes:
% Adrielle Andrade
% Bruno Behrmann
% Fernando Franco
% João Lucas Melo
% Jonas
% Matheus

% Exemplo do professor%
power(_, 0, 1).
power(N, E, Resultado) :-
    E>0,
    E1 is E-1,
    power(N, E1, Parcial),
    Resultado is N*Parcial.

start:-
    write('Informe um numero (-1 para sair):'),
    read(N),
    (N =:= -1 -> true; calcular_potencia(N)).

calcular_potencia(N):-
    write('Informe o expoente:'), read(E),
    power(N, E, Resultado),
    write('O resultado:'), write(Resultado),
    nl,
    start.

%Questao 9%
questao9:-
    write('Informe um numero inteiro e positivo: '),
    read(N),
    (N < 0 -> true; calcular_fatorial(N)).

fatorial(0,1).
fatorial(N,F):-
    N>0, N1 is N-1,
    fatorial(N1, F1),
    F is N*F1.

calcular_fatorial(N):-
    write('O fatorial de '),
    write(N),
    write(' e '),
    fatorial(N, F),
    write(F),
    write('.').

%Questao 10%
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


%Questao 11%
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


%Questao 12
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


%Questao 13
questao_13_filhos:-
    write('Entre o nome da pessoa cujos filhos devem ser listados: '),
    read(Pessoa),
    findall(Filho, progenitor(Pessoa, Filho), ListaFilhos),
    write(ListaFilhos).

questao_13_pais:-
    write('Entre o nome da pessoa cujos pais devem ser listados: '),
    read(Pessoa),
    findall(Pais, progenitor(Pais, Pessoa), ListaPais),
    write(ListaPais).


%Questao 14
regiao(acre, norte).
regiao(amapa, norte).
regiao(amazonas, norte).
regiao(para, norte).
regiao(rondonia, norte).
regiao(roraima, norte).
regiao(tocantins, norte).
regiao(alagoas, nordeste).
regiao(bahia, nordeste).
regiao(ceara, nordeste).
regiao(maranhao, nordeste).
regiao(paraiba, nordeste).
regiao(pernambuco, nordeste).
regiao(piaui, nordeste).
regiao('rio grande do norte', nordeste).
regiao(sergipe, nordeste).
regiao('distrito federal', 'centro-oeste').
regiao(goias, 'centro-oeste').
regiao('mato grosso', 'centro-oeste').
regiao('mato grosso do sul', 'centro-oeste').
regiao('espirito santo', sudeste).
regiao('minas gerais', sudeste).
regiao('rio de janeiro', sudeste).
regiao('sao paulo', sudeste).
regiao(parana, sul).
regiao('rio grande do sul', sul).
regiao('santa catarina', sul).

capital('rio branco', acre).
capital(maceio, alagoas).
capital(macapa, amapa).
capital(manaus, amazonas).
capital(salvador, bahia).
capital(fortaleza, ceara).
capital(brasilia, 'distrito federal').
capital(vitoria, 'espirito santo').
capital(goiania, goias).
capital('sao luiz', maranhao).
capital(cuiaba, 'mato grosso').
capital('campo grande', 'mato grosso do sul').
capital('belo horizonte', 'minas gerais').
capital(belem, para).
capital('joao pessoa', paraiba).
capital(curitiba, parana).
capital(recife, pernambuco).
capital(teresina, piaui).
capital('rio de janeiro', 'rio de janeiro').
capital(natal, 'rio grande do norte').
capital('porto alegre', 'rio grande do sul').
capital('porto velho', rondonia).
capital('boa vista', roraima).
capital(florianopolis, 'santa catarina').
capital('sao paulo', 'sao paulo').
capital(aracaju, sergipe).
capital(palmas, tocantins).

capital_regiao(Capital, Regiao):-
    regiao(Estado, Regiao),
    capital(Capital, Estado).

questao_14:-
    write('Entre o nome de uma regiao cujas capitais devem ser listadas: '),
    read(Regiao),
    findall(Capital, capital_regiao(Capital, Regiao), ListaCapitais),
    write(ListaCapitais).

%Questao 15%
lista_desc(Pessoa):-
    findall(Descendente, descendente(Descendente, Pessoa), ListaDesc),
    write(ListaDesc).

lista_anc(Pessoa):-
    findall(Ancestral, ancestral(Ancestral, Pessoa), ListaAncestral),
    write(ListaAncestral).


%Questao 16%
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


%Questao 17%
lista_cadeia(Predador):-
    findall(Presa, come_rec(Predador, Presa), ListaPresa),
    list_to_set(ListaPresa, SetPresa),
    percorre_lista(SetPresa).
