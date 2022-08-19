#include <stdio.h>
#include <stdlib.h>

typedef struct processo{
    int id;
    int tc; //tempo de chegada
    int te; //tempo de execucao
    int d;  //deadline
    int p;  //prioridade
};

int quantum;
int sobrecarga;
int n;  //qtd processos
int m = 30;  //tempo total

scanf("%d", &n);

int matriz[n][m];
