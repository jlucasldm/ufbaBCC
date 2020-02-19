#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "no.h"

typedef struct no no;

struct no{
	int chave;
	int qnt_operacao;
	int saldo; 
	int altura;
	no* pai;
	no* esq;
	no* dir;
};

no* create_n(int chave, int saldo){
	no* n = (no*) malloc(sizeof(no));
	if(n!=NULL){
		n->chave=chave;
		n->qnt_operacao=0;
		n->saldo=saldo;
		n->pai=NULL;
		n->esq=NULL;
		n->dir=NULL;
	}
	return n;
}

void destroy_n(no* n){
		free(n);
}
