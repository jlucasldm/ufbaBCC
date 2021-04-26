/*
Álvaro Souza Oliveira
Gustavo de Oliveira Ferreira
João Lucas Lima de Melo
Natan Santos Moura
 */
#include<stdio.h>
#include<stdlib.h>

//Definição do tipo pilha e nó
typedef struct pilha pilha;
typedef struct no no;


//Declaração do tipo nó
struct no{
    unsigned long long int cpf,cpft,valor; //Unsigned long long int utilizado para suportar entrada <= 10^10
    char op;
    no* prox;
};

//Declaração do tipo pilha
struct pilha{
    no* topo;
    unsigned long long int cont;
};

//Função para inicializar nó
no* create_n(unsigned long long int cpf,unsigned long long int cpft,unsigned long long int valor,char op){
    no *n = (no*) malloc(sizeof(no));
    n->cpf = cpf;
    n->cpft = cpft;
    n->valor = valor;
    n->op = op;
    n->prox = NULL;
    return n;

}
//Função para inicializar pilha
pilha* create_p(){
    pilha *p = (pilha*) malloc(sizeof(pilha));
    p->topo = NULL;
    p->cont = 0;
    return p;
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
			printf("[%llu, %llu, %c, %llu]\n",aux->cpf,aux->cpft,aux->op,aux->valor);
			aux = aux->prox;
			if(aux==NULL) break;
		}
	}
}

int main(){
    //Vetor de ponteiros para pilhas (guiche)
    pilha **vetor_pilhas = (pilha**) malloc(sizeof(pilha*)*3);
    //Preenchimento do vetor de ponteiros para pilhas
    for(int i =0; i<3;i++){
    	 vetor_pilhas[i] = create_p();
    }
	unsigned long long int n, cpf, cpft, valor;
    char op;
    no *cliente = NULL; //Ponteiro auxiliar para manipular inserção de nós
    scanf("%llu",&n); // Entrada de N
    //Preenchimento do ponteiro auxiliar, criação do nó e associação à guiche referente
    for(unsigned long long int i = 0; i<n;i++){
    	scanf("%llu %llu %c %llu", &cpf, &cpft, &op, &valor);
    	cliente = create_n(cpf, cpft, valor, op);
    	int guiche  = i%3;  //Cálculo do guiche para qual o cliente irá
    	push_p(vetor_pilhas[guiche],cliente);
    }
    
    //Formatação da saída, utilização da função de exibição para exibir todos os dados de determinada pilha
    printf("-:| RELATÓRIO PARCIAL |:-\n3\n");
    for(int i =0; i<3;i++){
    	printf("Guiche %d: %llu\n",i+1,vetor_pilhas[i]->cont);
    	show_p(vetor_pilhas[i]);
    	destroy_p(vetor_pilhas[i]);
    }
    free(vetor_pilhas);
}
