/*
Álvaro Souza Oliveira
Gustavo de Oliveira Ferreira
João Lucas Lima de Melo
Natan Santos Moura
 */
#include<stdio.h>
#include<stdlib.h>

//Definição do tipo pilha, fila, lista e nó e nó da lista
typedef struct fila fila;
typedef struct pilha pilha;
typedef struct lista lista;
typedef struct no no;
typedef struct nol nol;

//Declaração do tipo nó
struct no{
    unsigned long int cpf,cpft; //unsigned long int utilizado para suportar entrada <= 2^32-1
    long int valor;
    char op;
    no* prox;
};

//Declaração do tipo nó para lista
struct nol{
    unsigned long int cpf,ops; //unsigned long int utilizado para suportar entrada <= 2^32-1
    long int saldo;
    nol* prox;
};

//Declaração do tipo pilha
struct pilha{
    no* topo;
    unsigned long int cont;
};

//Função para inicializar nó
no* create_n(unsigned long int cpf,unsigned long int cpft,char op, long int valor){
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

//Retorna primeiro elemento da fila (NULL - Caso fila vazia)
no* front_f(fila*f){
	if(isEmpty_f(f)==1) return NULL;
	else return f->vetor[f->inicio];
}

//Retorna tamanho da fila
unsigned long int size_f(fila* f){
  return f->tam;
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
    unsigned long int cont;
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

//Função que opera sobre o nó referente para depositar valor na conta, além de atualizar a quantidade de operações realizadas
void deposit(nol* cliente1, nol* cliente2, long int valor){
  cliente2->saldo += valor;
  cliente2->ops++;
  cliente1->ops++;
}

//Função que opera sobre o nó referente para retirar valor da conta, além de atualizar a quantidade de operações realizadas
void saque(nol* cliente, long int valor){
  cliente->saldo -= valor;
  cliente->ops++;
}

//Função que opera sobre o nó referente para transferir valor de uma conta para outra, além de atualizar a quantidade de operações realizadas
void transfer(nol* cliente1, nol* cliente2, long int valor){
  cliente1->saldo-=valor;
  cliente2->saldo+=valor;
  cliente1->ops++;
  cliente2->ops++;
}

//Função para enviar cliente para atendimento
void attendance(unsigned long int ordem, no* cliente, pilha** vetor, int qt_guiche){
  int guiche = ordem%qt_guiche; //Cálculo do guiche para qual o cliente irá
  push_p(vetor[guiche],cliente);
}

//Função para atualizar/criar registros para lista do relatório final
void update_frelat(lista*l, no* cliente){
  if(cliente->op != 'S'){
      //Procura pela existência de CPF ou CPFT na lista, e adiciona-os caso não existam
      if(search_l(l,cliente->cpf) == NULL) push_l(l,create_nol(cliente->cpf));
      if(search_l(l,cliente->cpft) == NULL) push_l(l,create_nol(cliente->cpft));
      //Realiza as operações sobre os nós da lista
      switch(cliente->op){
        case 'D' : deposit(search_l(l,cliente->cpf),search_l(l,cliente->cpft),cliente->valor);
        break;
        case 'T': transfer(search_l(l,cliente->cpf),search_l(l,cliente->cpft),cliente->valor);
        break;
      }
  }
  else{
      //Procura pela existência de CPF na lista, e adiciona-o caso não exista
      if(search_l(l,cliente->cpf) == NULL) push_l(l,create_nol(cliente->cpf));
      saque(search_l(l,cliente->cpf), cliente->valor);
  }
}

//Exibe as informações referente a pilha desejada, retirando o topo, lendo-o e adicionando à uma fila auxiliar, depois a pilha original retorna a
//seu estado inicial (Além disso enquanto exibe atualiza o relatório final)
void show_p(pilha *p,lista* l){
	if(isEmpty_p(p) == 0){
    pilha* paux = create_p();
		while(isEmpty_p(p)!=1){
      no* aux = pop_p(p); 
			printf("[%lu,%lu,%c,%lu]\n",aux->cpf,aux->cpft,aux->op,aux->valor);
      update_frelat(l,aux);
			push_p(paux,aux);
		}
    while(isEmpty_p(paux)!=1) push_p(p,pop_p(paux));
    free(paux);
	}
}

//Função para gerar/exibir relatório parcial e atualizar relatório final
void show_relat_parc(pilha** vetor,int qt_guiche,lista* l){
  //Formatação da saída, utilização da função de exibição para exibir todos os dados de determinada pilha
  printf("-:| RELATÓRIO PARCIAL |:-\n%d\n",qt_guiche);
    for(int i =0; i<qt_guiche;i++){
    	printf("Guiche %d: %lu\n",i+1,vetor[i]->cont);
    	show_p(vetor[i],l);
    	destroy_p(vetor[i]);
    }
}

//Função para exibir relatório final
void show_relat_final(lista* l){
  //Formatação da saída, utilização da função de exibição para exibir todos os dados de determinada lista
  printf("\n-:| RELATÓRIO FINAL |:-\n %lu\n",l->cont);
    nol* aux = l->primeiro;
    while(aux!=NULL){
      printf("-:[ %lu : %lu %li\n",aux->cpf,aux->ops,aux->saldo);
      aux=aux->prox;
    }
}

//Cria e inicializa vetor de pilhas para funcionarem como guichê
pilha** create_vet_p(int qt_guiches){
  pilha **vetor_pilhas = (pilha**) malloc(sizeof(pilha*)*qt_guiches);
  if(vetor_pilhas != NULL){
    for(int i =0; i<qt_guiches;i++){
      vetor_pilhas[i] = create_p();
    }
    return vetor_pilhas;
  }
  else return NULL;
}

int main(){

    int qt_guiches = 3; //Quantidade de guichês que serão disponibilizados para atendimento.
	  unsigned long int n, cpf, cpft, valor;
    char op;
    scanf("%lu",&n); // Entrada de N
    fila* f = create_f(n); //Cria fila com tamanho máximo igual à quantidade de inserts
    //Criação do cliente integrado à inserção na fila de atendimento
    for(unsigned long int i = 0; i<n;i++){
    	scanf("%lu %lu %c %lu", &cpf, &cpft, &op, &valor);
      no* cliente = create_n(cpf,cpft,op,valor);
      push_f(f,cliente); //Envia clientes para fila de espera
    } 
    //Vetor de ponteiros para pilhas (guiches)
    pilha **vetor_pilhas = create_vet_p(qt_guiches); 
    lista* l = create_l(); //Criação da lista para relatório final
    for(unsigned long int k = 0; k<size_f(f);k++){
      no* aux = pop_f(f); //Pega primeiro elemento da fila
      attendance(k,aux,vetor_pilhas,qt_guiches); //Envia primeiro elemento da fila para atendimento
    } 
    //Chamada para a função de exibição do relatório Parcial 
    show_relat_parc(vetor_pilhas,qt_guiches,l);
     //Chamada para a função de exibição do relatório Final
    show_relat_final(l);

    free(vetor_pilhas);
    destroy_f(f);
    destroy_l(l);
   
}
