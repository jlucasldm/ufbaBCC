/*
Álvaro Souza Oliveira
Gustavo de Oliveira Ferreira
João Lucas Lima de Melo
Natan Santos Moura
 */
#include<stdio.h>
#include<stdlib.h>

//Definição do tipo pilha, fila, lista e nó
typedef struct fila fila;
typedef struct pilha pilha;
typedef struct lista lista;
typedef struct no no;
typedef struct nol nol;

//Declaração do tipo nó
struct no{
    unsigned long int cpf,cpft,valor; //unsigned long int utilizado para suportar entrada <= 2^32-1
    char op;
    no* prox;
};

//Declaração do tipo nó para lista
struct nol{
    unsigned long int cpf,ops,saldo; //unsigned long int utilizado para suportar entrada <= 2^32-1
    nol* prox;
};

//Declaração do tipo pilha
struct pilha{
    no* topo;
    unsigned long int cont;
};

//Função para inicializar nó
no* create_n(unsigned long int cpf,unsigned long int cpft,char op,unsigned long int valor){
  no *n = (no*) malloc(sizeof(no));
  if(n!=NULL){
	    n->cpf = cpf;
	    n->cpft = cpft;
	    n->valor = valor;
	    n->op = op;
	    n->prox = NULL;
	    return n;
	}
	else return NULL;

}

//Função para inicializar nó de lista
nol* create_nol(unsigned long int cpf,unsigned long int ops,unsigned long int saldo){
  nol *n = (nol*) malloc(sizeof(nol));
  if(n!=NULL){
	    n->cpf = cpf;
      n->ops = ops;
      n->saldo = saldo;
	    return n;
	}
	else return NULL;

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
void push_p(pilha *p, no *n){
    n->prox = p->topo;
    p->topo = n;
    p->cont++;
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
void destroy_p(pilha *p){
	while(1 == 1){
		if(isEmpty_p(p) == 1) break;
		free(pop_p(p)); //Libera o espaço de memória do Nó enquanto desempilha-o
	}
	free(p);
}

//Exibe as informações referente a pilha desejada
void show_p(pilha *p){
	if(isEmpty_p(p) == 0){
		no* aux = p->topo;
		while(1==1){
			printf("[%lu, %lu, %c, %lu]\n",aux->cpf,aux->cpft,aux->op,aux->valor);
			aux = aux->prox;
			if(aux==NULL) break;
		}
	}
}

//Busca elemento na pilha e retorna-o
no* search_p(pilha* p, unsigned long int cpf){
  //A função retira do topo da pilha e aloca em uma pilha auxiliar, para poder buscar no topo da pilha se o elemento existe. Findado o processo de busca
  //os valores da pilha auxiliar retornam à fila principal
  pilha* paux = (pilha*) malloc(sizeof(pilha));
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

//Declaração do tipo fila
struct fila{
	unsigned long int inicio,fim,qtd,tam;
	no** vetor;
};

//Função para inicializar fila
fila* create_f(unsigned long int tamanho){
	fila* f = (fila*) malloc(sizeof(fila));
 	if(f!=NULL){
 		f->inicio = 0;
 		f->fim = tamanho-1;
 		f->qtd = 0;
 		f->tam = tamanho;
 		f->vetor = (no**) malloc(sizeof(no*)*f->tam);
 		if(f->vetor == NULL) return NULL;
 		else return f;
 	}
 	else return NULL;
}

//Função que retorna 1 se a fila está cheia ou 0 senão
int full_f(fila *f){
	if(f->qtd == f->tam) return 1;
	else return 0;
}

//Função para checar se a fila está vazia
int isEmpty_f(fila *f){
	if(f->qtd == 0) return 1;
	else return 0;
}

//Função para enfileirar elemento
void push_f(fila *f,no* x){
	if(full_f(f)==1) printf("FILA CHEIA!");
	else{
		  f->fim = (f->fim+1)%f->tam;
		  f->vetor[f->fim] = x;
		  f->qtd++;
	}
}

//Função para desenfileirar primeiro elemento da fila (NULL se vazia)
no* pop_f(fila *f){
 	if(isEmpty_f(f)==1){
    return NULL;
  }
 	else{
 		unsigned long int x = f->inicio;
 		f->inicio = (f->inicio+1)%f->tam;
 		f->qtd--;
 		return f->vetor[x];
 	}
}

//Retorna cpf do primeiro elemento da fila (-1 - Caso fila vazia)
no* front_f(fila*f){
	if(isEmpty_f(f)==1) return NULL;
	else return f->vetor[f->inicio];
}

//Procura pela primeira ocorrência de um CPF na fila, e retorna-a (NULL Caso não encontrado ou Fila Vazia)
no* search_f (fila* f,unsigned long int cpf){
  no* resultado = NULL;
  if(isEmpty_f(f)==0){
    int flag=0;
    for(unsigned long int i =0; i<f->tam;i++){
      no* aux = front_f(f);
      if(aux->cpf == cpf && flag == 0){
          resultado = aux;
      }
      pop_f(f);
      push_f(f,aux);
    }
  }
  return resultado;
}

//Função para destuir a fila e todos os nós referentes
void destroy_f(fila* f){
  while(isEmpty_f(f)==0){
    no* cliente  = pop_f(f);
    free(cliente);
  }
  free(f->vetor);
  free(f);
}

//Definição do tipo lista
struct lista{
    nol* primeiro;
    int cont;
};

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

//Função para checar se lista está vazia
int isEmpty_l(lista* l){
    if (l->primeiro == NULL)
        return 1;
    else
        return 0;
}

//Função para buscar elemento na lista
nol* search_l(lista* l,unsigned long int k){
    nol* aux = l->primeiro;
    while(aux != NULL){
        if(aux->cpf == k) return aux;
        aux = aux->prox;
    }
    return NULL;
}

//Função para inserir elemento na lista
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
}

//Função para destruir lista e todo seu conteúdo
void destroy_l(lista* l){
  while(l->primeiro != NULL){
    free(pop_l(l, l->primeiro)); //O "pop" sempre atualiza o primeiro da lista, logo funcionará até a lista se esvaziar
  }
  free(l);
}

//Função para exibir relatório parcial
void show_relat_parc(pilha** vetor){
  //Formatação da saída, utilização da função de exibição para exibir todos os dados de determinada pilha
  printf("-:| RELATÓRIO PARCIAL |:-\n3\n");
    for(int i =0; i<3;i++){
    	printf("Guiche %d: %lu\n",i+1,vetor[i]->cont);
    	show_p(vetor[i]);
    	destroy_p(vetor[i]);
    }
}

//Função para enviar cliente para atendimento
void send_to_stack(unsigned long int ordem, no* cliente, pilha** vetor){
  int guiche = ordem%3; //Cálculo do guiche para qual o cliente irá
  push_p(vetor[guiche],cliente);
}

//Cria e inicializa vetor de pilhas para funcionarem como guichê
pilha** create_vet_p(){
  pilha **vetor_pilhas = (pilha**) malloc(sizeof(pilha*)*3);
  for(int i =0; i<3;i++){
    vetor_pilhas[i] = create_p();
  }

int main(){
   /* //Vetor de ponteiros para pilhas (guiche)
    pilha **vetor_pilhas = create_vet_p();
	  unsigned long int n, cpf, cpft, valor;
    char op;
    scanf("%lu",&n); // Entrada de N
    //Criação do cliente integrado à inserção no guiche, pela função "send_to_stack"
    for(unsigned long int i = 0; i<n;i++){
    	scanf("%lu %lu %c %lu", &cpf, &cpft, &op, &valor);
      no* cliente = create_n(cpf,cpft,op,valor);
      send_to_stack(i,cliente,vetor_pilhas);
    } 
    //Chamada para a função de exibição do relatório Parcial
    show_relat_parc(vetor_pilhas);
    free(vetor_pilhas);
    fila* f = create_f(3);
    push_f(f,create_n(123,456,'D',150));
    push_f(f,create_n(798,658,'O',200));
    push_f(f,create_n(111,222,'O',100));
    printf("%p",search_f(f,3333));
    printf("\n%lu\n",front_f(f)->cpf);
    pop_f(f);
    printf("%lu\n",front_f(f)->cpf);
    pop_f(f);
    printf("%lu\n",front_f(f)->cpf);
    pop_f(f);
    destroy_f(f); // TESTAR COM VALGRIND
    pilha* p = create_p();
    no* aux = create_n(123,456,400,'d');
    push_p(p,aux);
    aux = create_n(777,888,200,'d');
    push_p(p,aux);
    aux = create_n(999,454,150,'d');
    push_p(p,aux);
    show_p(p);
    printf("%p\n",search_p(p,222));
    show_p(p);
    lista* l = create_l();
    push_l(l,create_nol(119,2,100));
    push_l(l,create_nol(114,3,100));
    push_l(l,create_nol(112,4,100));
    push_l(l,create_nol(110,5,100));
    printf("%lu",l->primeiro->cpf);
    pop_l(l,l->primeiro);
    printf("\n%lu",l->primeiro->cpf);
    pop_l(l,l->primeiro);
    printf("\n%lu",l->primeiro->cpf);
    pop_l(l,l->primeiro);
    printf("\n%lu",l->primeiro->cpf);
*/
}
