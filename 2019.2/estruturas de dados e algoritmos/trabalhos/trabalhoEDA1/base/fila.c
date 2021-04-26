#include <stdio.h>
#include <stdlib.h>
typedef struct fila fila;
typedef struct no no;

struct no{
	int chave;
	no *prox;
};

struct fila{
	no* inicio;
	no* fim;
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

fila* cria_fila(){
    fila *f = (fila*) malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int vazia(fila *f){
    if (f->inicio == NULL) return 1;
    else return 0;
}

void enfileira(fila *f,no* x){
    if(vazia(f)==1){
        f->inicio = x;
        f->fim = x;
    }
    else{
        f->fim->prox = x;
        f->fim = x;
    }
    x->prox = NULL;
}

no* desenfileira(fila *f){
    if(vazia(f)==1) return NULL; //Fila vazia
    else{
        no* x = f->inicio;
        f->inicio = x->prox;
        if(f->inicio == NULL){
            f->fim=NULL;
        }
        x->prox = NULL;
        return x;
    }
}

int frente(fila*f){
    if(vazia(f)==1) return 0;
    else return f->inicio->chave;
}

int main(){
    fila *f = cria_fila();
    int chave,op=10;
    while(op!=0){
        printf("OP: ");
        scanf("%d",&op);
        switch(op){
            case 1:{
                 printf("KEY: ");
                 scanf("%d",&chave);
                 no* x = criar_no(chave);
                 enfileira(f,x);
                 } break;
            case 2:{
                desenfileira(f);
            }   break;
        }
        if(vazia(f)==0){
            no* aux = f->inicio;
            while(1==1){
                 printf("%d\n",aux->chave);
                 aux=aux->prox;
                 if(aux == NULL) break;
            }
        }
    }

}	




















