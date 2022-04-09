#include<stdbool.h>
#include <math.h>

int MAXNUMREGS = 11;
int ACESSOS = 0;
int REGISTROS = 0;

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

typedef struct{   
    int chave;
    char nome[20];
    int idade;
} Dados;

typedef struct{
    int ocupado;
    Dados dados;
} Registro;

