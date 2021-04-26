#include <stdlib.h>
#include <stdio.h>
#include "no.h"
#include "pilha.h"

typedef struct pilha pilha;
typedef struct no no;

//Declaração do tipo pilha
struct pilha{
    no* topo;
    unsigned long int cont;
};

struct no{
    unsigned long int cpf,cpft;
    long int valor;
    char op;
    no* prox;
};

no *top_p(pilha *p){
  return p->topo;
}

unsigned long int cont_p(pilha *p){
  return p->cont;
}

unsigned long int cpf_p(no *n){
	return n->cpf;
}

unsigned long int cpft_p(no *n){
	return n->cpft;
}

long int valor_p(no *n){
	return n->valor;
}

char op_p(no *n){
  return n->op;
}

no *prox_p(no *n){
  return n->prox;
}

//Função para inicializar pilha
pilha* create_p(){
  pilha *p = (pilha*) malloc(sizeof(pilha));
  if(p!=NULL){
	    p->topo = NULL;
	    p->cont = 0;
	    return p;
	}
	else return NULL;
}

//Função para empilhar elemento
no* push_p(pilha *p, no *n){
    n->prox = p->topo;
    p->topo = n;
    p->cont++;
	return p->topo;
}

//Checa se a pilha está vazia, retorna "1" se sim e "0" caso contrário
int isEmpty_p(pilha *p){
    if(p->topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Desempilha elemento do topo da pilha referente, retorna NULL se pilha estiver vazia
no* pop_p(pilha *p){
	if(isEmpty_p(p) == 1){
        return NULL;
    }
    else{
        no* aux = p->topo;
        p->topo = aux->prox;
        aux->prox = NULL;
        p->cont--;
        return aux;
    }
}

//Remove a pilha e todos os dados referentes a ela
pilha *destroy_p(pilha *p){
	while(1 == 1){
		if(isEmpty_p(p) == 1) break;
		free(pop_p(p)); //Libera o espaço de memória do Nó enquanto desempilha-o
	}
	free(p);
	return p;
}

//Busca elemento na pilha e retorna-o
no* search_p(pilha* p, unsigned long int cpf){
  //A função retira do topo da pilha e aloca em uma pilha auxiliar, para poder buscar no topo da pilha se o elemento existe. Findado o processo de busca
  //os valores da pilha auxiliar retornam à fila principal
  pilha* paux = (pilha*) malloc(sizeof(pilha));
  if(paux !=NULL){
    int flag = 0;
    no* resultado = NULL;
    if (isEmpty_p(p)==0){
      while(p->cont>0){
        no* aux = pop_p(p);
        if(aux->cpf == cpf && flag == 0){
          resultado = aux;
          flag = 1;
        }
        push_p(paux,aux);
      }
    }
    while(paux->cont>0){
      push_p(p,pop_p(paux));
    }
    free(paux);
    return resultado;
  }
  else return NULL;
}

