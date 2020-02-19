#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista lista;
typedef struct nol nol;

//Declaração do tipo nó para lista
struct nol{
    unsigned long int cpf,ops; //unsigned long int utilizado para suportar entrada <= 2^32-1
    long int saldo;
    nol* ant;
    nol* prox;
};

void saldo_l_add(nol* n, long int valor){
	n->saldo += valor;
}

void saldo_l_sub(nol* n, long int valor){
	n->saldo -= valor;
}

void ops_l_add(nol* n){
	n->ops++;
}

nol *prox_l(nol *n){
  return n->prox;
}

nol *ant_l(nol *n){
  return n->ant;
}
//Definição do tipo lista
struct lista{
    nol* primeiro;
    unsigned long int cont;
};

unsigned long int cpf_l(nol *n){
	return n->cpf;
}

unsigned long int ops_l(nol *n){
	return n->ops;
}

long int saldo_l(nol *n){
	return n->saldo;
}

nol *lPrimeiro(lista *l){
	return l->primeiro;
}

unsigned long int cont_l(lista *l){
	return l->cont;
}

//Função para inicializar nó de lista
nol* create_nol(unsigned long int cpf){
  nol *n = (nol*) malloc(sizeof(nol));
  if(n!=NULL){
	    n->cpf = cpf;
      n->ops = 0;
      n->saldo = 0;
	    return n;
	}
	else return NULL;

}

//Função para inicializar lista
lista* create_l(){
    lista* l = (lista*) malloc(sizeof(lista));
    if (l == NULL) return NULL;
    else{
        l->primeiro = NULL;
        l->cont=0;
        return l;
    }

}

//Função para checar se lista está vazia (1 - Vazia / 0 - Não vazia)
int isEmpty_l(lista* l){
    if (l->primeiro == NULL)
        return 1;
    else
        return 0;
}

//Função para buscar elemento na lista (NULL - Se não encontrado)
nol* search_l(lista* l,unsigned long int k){
    nol* aux = l->primeiro;
    while(aux != NULL){
        if(aux->cpf == k) return aux;
        aux = aux->prox;
    }
    return NULL;
}

//Função para inserir elemento na lista, já ordenando-o
void push_l(lista* l, nol* x){
    if(isEmpty_l(l)==1){
        l->primeiro = x;
        l->primeiro->prox = NULL;
    }
    else{
      if(x->cpf < l->primeiro->cpf){
        x->prox = l->primeiro;
        l->primeiro = x;
      }
      else{
        nol* aux = l->primeiro;
        while(x->cpf > aux->cpf){
            if(aux->prox == NULL || x->cpf < aux->prox->cpf){
              x->prox = aux->prox;
              aux->prox = x;
            }
            aux = aux->prox;
            if(aux==NULL) break;
        }
      }
    }
    l->cont++;
  }

//Função para remover elemento da lista
nol* pop_l(lista* l, nol* k){
  if(isEmpty_l(l)==1) return NULL;
  else{
      if(l->primeiro == k)
          l->primeiro = l->primeiro->prox;
      else{
          nol* x = l->primeiro;
          while(x->prox !=NULL){
              if(x->prox == k){
                  x->prox = k->prox;
                  break;
              }
              else x = x->prox;
          }
      }
      k->prox = NULL;
      return k;
  }
  l->cont--;
}

//Função para destruir lista e todo seu conteúdo
void destroy_l(lista* l){
  while(l->primeiro != NULL){
    free(pop_l(l, l->primeiro)); //O "pop" sempre atualiza o primeiro da lista, logo funcionará até a lista se esvaziar
  }
  free(l);
}
