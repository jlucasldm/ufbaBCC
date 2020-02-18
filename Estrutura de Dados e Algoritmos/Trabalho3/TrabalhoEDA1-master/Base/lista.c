#include <stdio.h>
#include <stdlib.h>
typedef struct lista lista;
typedef struct no no;

struct no{
	int chave;
	no *prox;
};

struct lista{
	no* primeiro;
	int qtelemen;
};

no* criar_no(int k){
	no* n = (no*) malloc(sizeof(no));
	if(n==NULL) return NULL;
	else{
		n->chave = k;
		n->prox = NULL;
		return n;	
	}
}

lista* criar_lista(){
	lista* l = (lista*) malloc(sizeof(lista));
	if (l == NULL) return NULL;
	else{
		l->primeiro = NULL;
		l->qtelemen=0;
		return l;	
	}
	
}

int lista_vazia(lista* l){
	if (l->primeiro == NULL)
		return 1;
	else
		return 0;
}

no* lista_buscar(lista* l,int k){
	no* aux = l->primeiro;
	while(aux != NULL){
		if(aux->chave == k) return aux;
	aux = aux->prox;	
	}
	return NULL;
}

void inserir_lista(lista* l,int pos, no* x){
	if(lista_vazia(l)==1 || pos == 1){
		x->prox = l->primeiro;
		l->primeiro = x;	
	}
	else{
		int i = 1;
		no* aux = l->primeiro;
		while(i!=pos-1 && aux->prox!=NULL){
			aux = aux->prox;
			i++;	
		}
	x->prox = aux->prox;
	aux->prox = x;
	}
}

no* remover_lista(lista* l, no* k){
	if(l->primeiro == k)
		l->primeiro = l->primeiro->prox;
	else{
		no* x = l->primeiro;
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

void exibir_lista(lista *l){
	no* x = l->primeiro;
	int i = 1;
	while(x!=NULL){
		printf("ID: %d POS: %d\n",x->chave,i);
		x = x->prox;	
		i++;
	}
}

int main(){
	lista *l = criar_lista();
	int c = 0;
	int pos = 0;
	while(0==0){
		scanf("%d%d",&c,&pos);
		if(c==0 && pos==0) break;
		no* aux = criar_no(c);
		//printf("%d\n",c);
		inserir_lista(l,pos,aux);
	}
	exibir_lista(l);
	int k = 0;
	scanf("%d",&k);
	no* x = lista_buscar(l,k);
	remover_lista(l,x);
	exibir_lista(l);
}	




















