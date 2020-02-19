//João Lucas Lima de Melo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

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

//Função para imprimir altura de uma AVL
//Recebe como parâmetro um ponteiro para a AVL cuja altura será impressa
void imprime_altura(avl* a){
	printf("%d\n", altura_a(a));
}

//Função para remover a raíz de uma AVL
//Recebe como parâmetro o ponteiro para a AVL cuja raíz será removida
void remove_raiz(avl* a){
	no* n=raiz_a(a);
	if(n!=NULL){
		printf("%d %d %d\n",chave_n(raiz_a(a)),qnt_operacao_n(raiz_a(a)),saldo_n(raiz_a(a)));
		n=remove_n(a,n);
		while(n!=NULL){
			update_altura_n(n);
			balancear_n(a,n);
			n=pai_n(n);
		}
	}
}

//Função para destruir uma AVL e imprimir o relatório final
//Recebe como parâmetro um ponteiro para a AVL a ser destruída
void destroy_a(avl* a){
	printf("-+- Inicio relatorio -+-\n%d\n",tamanho_a(a));
	while(raiz_a(a)!=NULL){
		remove_raiz(a);
	}
	free(a);
	printf("-+- Fim relatorio -+-\n");
}


//Função para listar chaves contidas no nível dado
//Recebe como parâmetros um ponteiro para um nó, um inteiro auxiliar e o nível desejado
void lista_chaves(no* n,int padrao,int nivel){
		if(n!=NULL){
			if(padrao==nivel){
                printf("%d\n",chave_n(n));
            }
			else{
				lista_chaves(esq_n(n),padrao+1,nivel);
				lista_chaves(dir_n(n),padrao+1,nivel);
			}
		}
}

//Função para consultar a existência de um nó com dada chave em uma AVL
//Recebe como parâmetros um inteiro com a chave do nó a ser buscado na AVl e o ponteiro para a AVL
void consulta(avl* a, int chave){
    no* n = busca_n(a, chave);
    if(n!=NULL){
        printf("existe no com chave: %d\n", chave);
    }else if(n==NULL){
        printf("nao existe no com chave: %d\n", chave);
    }
}

//Função para imprimir os nós de uma AVl de forma crescente
//Recebe como parâmetro o ponteiro para um nó
void inorder_crescente(no* n){
    if(n != NULL){
        inorder_crescente(n->esq);
        printf("%d %d %d\n", chave_n(n), qnt_operacao_n(n), saldo_n(n));
        inorder_crescente(n->dir);
    }
}

//Função para imprimir os nós de uma AVl de forma decrescente
//Recebe como parâmetro o ponteiro para um nó
void inorder_decrescente(no* n){
    if(n != NULL){
        inorder_decrescente(n->dir);
        printf("%d %d %d\n", chave_n(n), qnt_operacao_n(n), saldo_n(n));
        inorder_decrescente(n->esq);
    }
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