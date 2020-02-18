#include <stdio.h>
#include <stdlib.h>
#include "listaCirc.h"

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

//Função para inicializar lista
lista* create_l(){
    lista* l = (lista*) malloc(sizeof(lista));
    if (l == NULL) return NULL; //Teste de alocação de memória
    else{
        l->primeiro = NULL;
        l->cont=0;
        return l;
    }
}

//Função para inicializar nó de lista
nol* create_nol(unsigned long int cpf){
  nol *n = (nol*) malloc(sizeof(nol));
  if(n!=NULL){ //Teste de alocação de memória
	    n->cpf = cpf;
      n->ops = 0;
      n->saldo = 0;
      n->ant = NULL;
      n->prox = NULL;
	    return n;
	}
	else return NULL;
}

//Função para checar se lista está vazia (1 - Vazia / 0 - Não vazia)
int isEmpty_l(lista* l){
    if (l->primeiro == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Função para buscar elemento na lista (NULL - Se não encontrado)
nol* search_l(lista* l,unsigned long int k){
    nol* aux = l->primeiro;
    while(aux != NULL){
        if(aux->cpf == k){
          return aux;
        }
        aux = aux->prox;
        if(aux==l->primeiro){
          break;
        }
    }
    return NULL;
}

//Função para inserir elemento na lista, já ordenando-o
nol* push_l(lista* l, nol* x){
    if(isEmpty_l(l)==1){
        l->primeiro = x;
        x->prox = x;
        x->ant = x;
    }
    else{
      if(x->cpf < l->primeiro->cpf){
        x->prox = l->primeiro;
        x->ant = l->primeiro->ant;
        l->primeiro->ant->prox = x;
        l->primeiro->ant = x;
        l->primeiro = x;
      }
      else{
        nol* aux = l->primeiro;
        while(x->cpf > aux->cpf){
            if(x->cpf < aux->prox->cpf || aux->prox==l->primeiro){
              x->prox = aux->prox;
              aux->prox->ant = x;
              x->ant = aux;
              aux->prox = x;
              break;
            }
            aux = aux->prox;
        }
      }
    }
    l->cont++;
    return x; //Retorna ponteiro para o elemento inserido
}

//Função para remover elemento da lista
nol* pop_l(lista* l, nol* k){
  if(isEmpty_l(l)==1) return NULL;
  if(search_l(l, k->cpf)==NULL){
    return NULL;
  }
  if(l->cont == 1){
      nol* aux = l->primeiro;
      aux->prox = NULL;
      aux->ant = NULL;
      l->primeiro = NULL;
      return aux;
  }
  else{
      if(l->primeiro == k){
        l->primeiro->ant = l->primeiro->prox;
        l->primeiro->prox = l->primeiro->ant;
        l->primeiro->ant = NULL;
        nol* aux = l->primeiro->prox;
        l->primeiro->prox = NULL;
        l->primeiro = aux;
        aux = NULL;
      }else{
          nol* x = l->primeiro;
          while(x->prox !=NULL){
              if(x->prox == k){
                  x->prox = k->prox;
                  k->prox->ant = k->ant;
                  break;
              }else{
                x = x->prox;
              }
              if (x == l->primeiro){
                return NULL;
              }
          }
      }
      k->prox = NULL;
      k->ant = NULL;
      l->cont--;
      return k;
    }
}

//Função para destruir lista e todo seu conteúdo
lista* destroy_l(lista* l){
    while(l->primeiro != NULL){
        free(pop_l(l, l->primeiro)); //O "pop" sempre atualiza o primeiro da lista, logo funcionará até a lista se esvaziar
    }
    free(l);
    return l; //Retorna o endereço para a pilha destruida, se destruiu corretamente, retorna NULL
}