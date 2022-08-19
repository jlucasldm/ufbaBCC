#ifndef IMPRESSAO_H
#define IMPRESSAO_H

/*
Função responsável pela impressão da tabela de primeiro nível de acordo com a especificação, iterando sobre as células
e os registros do referido índice.

Recebe como parâmetros os coeficientes a e b de hash de primeiro nível e o primo p.
*/
int imprimeNivelUm(int a, int b, int p);

/*
Função responsável pela impressão da tabela de segundo nível de acordo com a especificação, iterando sobre os registros
de um dado índice (de primeiro nível) e imprimindo as chaves de todos os registros encontrados.

Recebe como parâmetros o índice de primeiro nível e o primo p.
*/
int imprimeNivelDois(int indice, int p);

/*
Função responsável pela impressão da tabela de segundo nível de acordo com a especificação, iterando sobre os registros
de todos os segundos níveis e imprimindo as chaves dos registros encontrados.

Recebe como parâmetro o primo p.
*/
int imprimeTodosNiveisDois(int p);

#endif //IMPRESSAO_H