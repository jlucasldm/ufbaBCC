#ifndef BASE_H
#define BASE_H

//Estrutura usada na tabela de primeiro nível.
typedef struct{
    int mtab;       //quantidade de registros endereçados na posição índice_celula
    int a;          //coeficiente do hash
    int b;          //coeficiente do hash
} Celula;

/*
Função responsável por criar a tabela de nível um. Recebe um valor m (tamanho de registros a serem inseridos), o valor do primo p (global),
e os coeficientes a e b para uso da função hash em nível primário.

A função cria um arquivo contendo m células e, no final do arquivo, armazena os valores de p (global), e os coeficientes a e b de primeiro nível.
*/
int criaArquivoNivelUm(int m, int p, int a_global, int b_global);

/*
Função responsável por retornar o valor da função hash para um dado registro. Recebe os valores dos coeficientes de a e b, primo p,
tamanho do arquivo m e chave do registro k.
*/
int hash(int a, int b, int p, int m, int k);

#endif //BASE_H
