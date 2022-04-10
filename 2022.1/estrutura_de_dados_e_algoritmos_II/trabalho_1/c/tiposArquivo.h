#include <stdbool.h>
#include <math.h>

/*
tiposArquivo.h apenas declara funções e variáveis que serão utilizadas pelas funções do programa. É ainda declarado aqui o struct Registro, utilizado
ao longo do programa como ferramenta para armazenamento de dados no arquivo criado.
*/

//definição das variáveis globais
int MAXNUMREGS = 11;
int ACESSOS_SUCESSO = 0;
int ACESSOS_FALHA = 0;
int CONSULTA_FRACASSO = 0;
int CONSULTA_SUCESSO = 0;

//funções de hash
int max(int num1, int num2){
	return (num1 > num2) ? num1 : num2;
}

int hash1(int chave){
	return chave % MAXNUMREGS;
}

int hash2(int chave){
	double piso = floor(chave / MAXNUMREGS);
	return max((int)piso % MAXNUMREGS, 1);
}

//declaração do registro
typedef struct{   
    int chave;
    char nome[20];
    int idade;
} Dados;

typedef struct{
    int ocupado; //controle de vazio (0), atualmente ocupado por dado (1), vazio mas já ocupado uma vez (2)
    Dados dados;
} Registro;

