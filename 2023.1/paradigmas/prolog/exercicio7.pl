aluno(joao, calculo).
aluno(maria, calculo).
aluno(joel, programacao).
aluno(joel, estrutura).

frequencia(joao, ufba).
frequencia(maria, ufba).
frequencia(joel, ifba).

professor(carlos, calculo).
professor(ana_paula, estrutura).
professor(pedro, programacao).

funcionario(pedro, ifba).
funcionario(ana_paula, ufba).
funcionario(carlos, ufba).

alunos(Y, X) :- aluno(Y, Z), professor(X, Z), funcionario(X, W), frequencia(Y, W).
associados(Y, X) :- frequencia(Y, X); funcionario(Y, X).
