#include <stdlib.h>
#include <stdio.h>
#include "no.h"

typedef struct no no;

struct no{
    unsigned long int cpf,cpft;
    long int valor;
    char op;
    no* prox;
};

//Função para inicializar nó
no* create_n(unsigned long int cpf, unsigned long int cpft, char op, long int valor){
  no *n = (no*) malloc(sizeof(no));
  if(n!=NULL){ //Testa a alocação
	    n->cpf = cpf;
	    n->cpft = cpft;
	    n->valor = valor;
	    n->op = op;
	    n->prox = NULL;
	    return n;
	}
	else return NULL;
}


