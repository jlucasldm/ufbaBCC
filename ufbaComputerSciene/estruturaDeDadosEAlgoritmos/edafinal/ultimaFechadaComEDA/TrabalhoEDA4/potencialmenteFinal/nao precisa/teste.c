 //Jukera Johnosns
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no no;
typedef struct avl avl;

struct no{
	int chave;
	int qnt_operacao;
	int saldo; 
	int altura;
	no* pai;
	no* esq;
	no* dir;
};

struct avl{
	no* raiz;
	int tamanho;
};

no* create_n(int chave){
	no* n = (no*) malloc(sizeof(no));
	if(n!=NULL){
		n->chave=chave;
		n->qnt_operacao=0;
		n->saldo=0;
		n->pai=NULL;
		n->esq=NULL;
		n->dir=NULL;
	}
	return n;
}

void destroy_n(no* n){
		free(n);
}

avl* create_a(){
	avl* a = (avl*) malloc(sizeof(avl));
	if(a!=NULL){
		a->raiz=NULL;
		a->tamanho=0;
	}
	return a;
}

/*
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
*/

/*
void destroy_n(no* n){
		free(n);
}
*/

no* raiz_a(avl* a){
    if(a==NULL){
        return NULL;
    }
    return a->raiz;
}

int tamanho_a(avl* a){
    if(a==NULL){
        return 0;
    }
    return a->tamanho;
}

no* pai_n(no* n){
    if(n==NULL){
        return NULL;
    }
    return n->pai;
}

no* esq_n(no* n){
    if(n==NULL){
        return NULL;
    }
    return n->esq;
}

no* dir_n(no* n){
    if(n==NULL){
        return NULL;
    }
    return n->dir;
}

int chave_n(no* n){
    if(n==NULL){
        return 0;
    }
    return n->chave;
}

int qnt_operacao_n(no* n){
    if(n==NULL){
        return 0;
    }
    return n->qnt_operacao;
}

int saldo_n(no* n){
    if(n==NULL){
        return 0;
    }
    return n->saldo;
}

int empty_a(avl* a){
    if(raiz_a(a) == NULL){
        return 1;
    }else if(a->raiz != NULL){
        return 0;
    }
}

int altura_a(avl* a){
		if(raiz_a(a)==NULL)
			return 0;
		return raiz_a(a)->altura;
}

no* insere_a(avl* a,no* n,no* x,no* y){
	if(x==NULL){
		a->tamanho++;
		if(y==NULL)
			a->raiz=n;
		else{
			n->pai=y;
			if(n->chave>y->chave)
				y->dir=n;
			else
				y->esq=n;
		}
		return n;
	}
	else{
		if(x->chave==n->chave){
			destroy_n(n);
			return x;
		}
		y=x;
		if(x->chave < n->chave)
			x=x->dir;
		else
			x=x->esq;
		return insere_a(a,n,x,y);
	}
}

void lista_chaves(no* n,int padrao,int nivel){
		if(n!=NULL){
			if(padrao==nivel){
                printf("%d\n",n->chave);
            }
			else{
				lista_chaves(n->esq,padrao+1,nivel);
				lista_chaves(n->dir,padrao+1,nivel);
			}
		}
}

void inorder_crescente(no* n){
    if(n != NULL){
        inorder_crescente(n->esq);
        printf("%d %d %d\n", chave_n(n), qnt_operacao_n(n), saldo_n(n));
        inorder_crescente(n->dir);
    }
}

void inorder_decrescente(no* n){
    if(n != NULL){
        inorder_decrescente(n->esq);
        printf("%d %d %d\n", chave_n(n), qnt_operacao_n(n), saldo_n(n));
        inorder_decrescente(n->dir);
    }
}

no* busca_n(avl* a,int key){
	no* aux=a->raiz;
	while(aux!=NULL && aux->chave!=key){
		if(key > aux->chave){
            aux=aux->dir;
        }
		else{
            aux=aux->esq;
        }
	}
	return aux;
}

void update_altura_n(no* n){
	int piso = 1;
    if(n!=NULL){
	    if(n->esq!=NULL){
            piso=n->esq->altura+1;
        }
	    if(n->dir!=NULL && n->dir->altura+1 > piso){
            piso=n->dir->altura+1;
        }
	    n->altura=piso;
	}
}

int balanco_n(no* n){
	int aux = 0;
    if(n==NULL){
        return 0;
    }
	if(n->esq!=NULL){
        aux+=n->esq->altura;
    }
	if(n->dir!=NULL){
        aux-=n->dir->altura;
    }
	return aux;
}
	
void rotacaoSimplesDir(avl* a,no* n){
	no* r=n->esq;
	no* s=n->esq;           
	s->pai=n->pai;
	if(r->dir!=NULL){
        r->dir->pai=n;
    }
	if(n->pai!=NULL){
		if(n->pai->esq==n){
            n->pai->esq=s;
        }
		else{
            n->pai->dir=s;
        }
	}
	else{
        a->raiz=s;
    }
	n->esq=r->dir;
	n->pai=s;
	s->dir=n;
	update_altura_n(n);
	update_altura_n(s);
}

void rotacaoSimplesEsq(avl* a,no* n){
	no* r=n->dir;
	no* s=n->dir;
	if(r->esq!=NULL)
		r->esq->pai=n;
	s->pai=n->pai;
	if(n->pai!=NULL){
		if(n->pai->esq==n){
            n->pai->esq=s;
        }
		else{
            n->pai->dir=s;
        }
	}
	else{
        a->raiz=s;
    }
	n->dir=r->esq;
	n->pai=s;
	s->esq=n;
	update_altura_n(n);
	update_altura_n(s);
}

void rotacaoDuplaDir(avl* a,no* n){
	no *m = n->esq;
    rotacaoSimplesEsq(a, m);
    rotacaoSimplesDir(a, n);
}

void rotacaoDuplaEsq(avl* a,no* n){
	no *m = n->dir;
    rotacaoSimplesDir(a, m);
    rotacaoSimplesEsq(a, n);
}

void balancear_n(avl* a,no* n){
	if(n==NULL){
        return;
    }
	if(balanco_n(n)==2){
		if(balanco_n(n->esq)==-1){
            rotacaoDuplaDir(a,n);
        }
		else{
            rotacaoSimplesDir(a,n);
        }
	}
	else if(balanco_n(n)==-2){
        if(balanco_n(n->esq)==1){
            rotacaoDuplaEsq(a,n);
        }
		else{
            rotacaoSimplesEsq(a,n);
        }
    }
}

void insere(avl* a,int chave,int operacao,int saldo){
	no* n=create_n(chave);
	n=insere_a(a,n,a->raiz,NULL);
	n->qnt_operacao++;
	if(operacao==1){
        n->saldo-=saldo;
    }
	else{
        n->saldo+=saldo;
    }
	while(n!=NULL){
		update_altura_n(n);
		balancear_n(a,n);
		n=n->pai;
	}
}

void transferencia_de_dados(no* n,no* aux){
	if(n!=NULL && aux!=NULL){
        n->qnt_operacao=aux->qnt_operacao;
        n->chave=aux->chave;
	    n->saldo=aux->saldo;
    }
}

no* remove_n(avl* a,no* n){
	no* aux=NULL;
	if(n->esq==NULL||n->dir==NULL){
		a->tamanho--;
		if(n->esq!=NULL){
			n->esq->pai=n->pai;
			aux=n->esq;
		}
		if(n->dir!=NULL){
			n->dir->pai=n->pai;
			aux=n->dir;
		}
		if(a->raiz==n){
            a->raiz=aux;
        }
		else{
			if(n->pai->esq==n){
                n->pai->esq=aux;
            }
			else if(n->pai->esq!=n){
                n->pai->dir=aux;
            }
		}
		if(aux==NULL){
            aux=n->pai;
        }
		destroy_n(n);
		return aux;
	}
	else{
		aux=n->dir;
		while(aux->esq!=NULL){
            aux=aux->esq;
        }
		transferencia_de_dados(n,aux);
		return remove_n(a,aux);
	}
}

void remove_chave_a(avl* a,int chave){
	no* n=busca_n(a,chave);
	if(n!=NULL){
		n=remove_n(a,n);
		while(n!=NULL){
			update_altura_n(n);
			balancear_n(a,n);
			n=n->pai;
		}
	}
}

void remove_raiz(avl* a){
	no* n=a->raiz;
	if(n!=NULL){
		printf("%d %d %d\n",a->raiz->chave,a->raiz->qnt_operacao,a->raiz->saldo);
		n=remove_n(a,n);
		while(n!=NULL){
			update_altura_n(n);
			balancear_n(a,n);
			n=n->pai;
		}
	}
}

void destroy_a(avl* a){
	printf("-+- Inicio relatorio -+-\n%d\n",tamanho_a(a));
	while(a->raiz!=NULL)
		remove_raiz(a);
	free(a);
	printf("-+- Fim relatorio -+-\n");
}

void consulta(avl* a, int chave){
    no* n = busca_n(a, chave);
    if(n!=NULL){
        printf("existe no com chave: %d\n", chave);
    }else if(n==NULL){
        printf("nao existe no com chave: %d\n", chave);
    }
}

void imprime_altura(avl* a){
	printf("%d\n",altura_a(a));
}


int main(){
	int chave;
	int operacao;
	int saldo;
	int nivel;
	char c;
	char entrada;

	avl* a=create_a();
	while(0!=1){
		scanf("%c",&entrada);

		if(entrada == 'i'){
			scanf(" %d %d %d", &chave, &operacao, &saldo);
			insere(a, chave, operacao, saldo);
		}
		else if(entrada == 'c'){
			scanf(" %d", &chave);
			consulta(a, chave); //consulta tem como puxar do meu
		}
		else if(entrada == 'r'){
			scanf(" %d", &chave);
			remove_chave_a(a, chave);
		}
		else if(entrada == 'p'){
			scanf(" %c", &c);
			if(c=='c'){
				inorder_crescente(raiz_a(a));
			}
			else if(c=='d'){
				inorder_decrescente(raiz_a(a));
			}
		}
		else if(entrada == 'n'){
			scanf(" %d", &nivel);
			lista_chaves(raiz_a(a), 1, nivel);
		}
		else if(entrada == 'h'){
			imprime_altura(a);
		}
		else if(entrada == 'f'){
			destroy_a(a);
			break;
		}
	}
	return 0;
}