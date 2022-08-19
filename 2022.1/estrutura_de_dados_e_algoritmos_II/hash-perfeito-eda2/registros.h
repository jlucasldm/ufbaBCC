#ifndef REGISTROS_H
#define REGISTROS_H

//declaração do registro
typedef struct{
    int chave;
    char nome[20];
    int idade;
} Dados;

typedef struct{
    int ocupado;
    int hash;
    Dados dado;
} Registro;


/*
Função responsável por receber os registros, iterar sobre as células da tabela de primeiro nível e agrupa-lós por suas posições hash (primeiro nível) 
em arquivos distintos de nome [índice_célula].dat. 

Recebe como parâmetro a quantidade de registros m, os ponteiros para os coeficientes de primeiro nível a 
e b e do número primo p (global).
*/
int insereRegistros(int m, int *a, int *b, int *p);

/*
Função responsável por realocar, utilizando função hash e coeficientes para o segundo nível, os registros das funções [índice_celula].dat 
em arquivos [índice_celula]aloc.dat. 

Recebe como parâmetro o nome do arquivo [índice_celula].dat, a quantidade de registros do arquivo (tamanho), os coeficientes de hash de 
segundo nível a e b, o primo p e o índice da célula.
*/
int realocaRegistros(char filename[3], int tamanho, int a, int b, int p, int id_celula);

/*
Função responsável por consultar um registro por sua chave na estrutura de hashing duplo. Caso encontre, informa seus dados e sinaliza
caso contrário. 

Recebe um valor de chave a ser consultado, os coeficientes de hash primário a e b e o valor de primo p.
*/
int consultaRegistro(int chave, int a, int b, int p);

#endif //REGISTROS_H
