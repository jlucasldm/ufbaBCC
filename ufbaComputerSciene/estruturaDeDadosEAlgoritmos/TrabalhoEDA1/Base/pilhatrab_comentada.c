#include<stdio.h>
#include<stdlib.h>

//Definição do tipo pilha e nó
typedef struct pilha pilha;
typedef struct no no;


/*
Declaração do struct tipo nó
Nele, são colocados todos as informações que é necessário armazenar
na pilha e um ponteiro tipo no indicando o proximo na ordem.
*/
struct no{
    unsigned long long int cpf,cpft,valor;
    char op;
    no *prox;
};

/*
Declaração do struct tipo pilha
Há um ponteiro tipo nó para o topo, pois quando a pilha for criada, 7
apesar de não conter nenhuma informação, é necessário que haja uma variável
de topo para quando fizer o primeiro push, o ponteiro no prox saber qual
seu endereço (pois o antigo "topo" será então o novo "prox");
cont é uma variável que serve para saber qual o tamanho da pilha.
*/
struct pilha{
    no *topo;
    unsigned long long int cont;
};

//Função para inicializar pilha
pilha *create_p(){
    pilha *p = (pilha*) malloc(sizeof(pilha));
    p->topo = NULL;     //É NULL pois não há nenhum nó na pilha quando é criada
    p->cont = 0;        //Retorna o endereço do espaço que foi alocado pelo malloc
    return p;
}

/*
Função para inicializar nó
Recebe como argumentos todos os valores que serão inseridos no novo nó,
para poder armazenar no espaço de memória alocado
*/
no *create_n(unsigned long long int cpf, unsigned long long int cpft, unsigned long long int valor, char op){
    no *n = (no*)malloc(sizeof(no));     //n será o end de mem alocado pelo malloc
    n->cpf = cpf;
    n->cpft = cpft;
    n->valor = valor;
    n->op = op;
    n->prox = NULL;    //NULL pois não há nenhum nó após o que acabou de ser criado
    return n;          //Retorna o endereço do espaço que foi alocado pelo malloc
}

//Função para empilhar elemento
void push_p(pilha *p, no *n){
    n->prox = p->topo; //prox (proximo na ordem) é o topo anterior
    p->topo = n;       //Recebe n (endereço da novo nó) pois este novo nó, é o novo topo
    p->cont++;         //Incrementa o contador pois aumentou a pilha
}

//Checa se a pilha está vazia
unsigned long long int isEmpty_p(pilha *p){
    if(p->topo == NULL){ //Se a pilha está vazia retorna 1
        return 1;
    }
    else{               //Se há nó na pilha retorna 0
        return 0;
    }
}

//Desempilha nó do topo da pilha
no *pop_p(pilha *p){
	if(p->topo == NULL){
        return NULL;    //Se a pilha estiver vazia retorna NULL
    }
    else{
        no *aux = p->topo;   //aux para gravar end do topo a ser desempilado
        p->topo = aux->prox; //O novo topo é o prox, ou seja, o nó anterior
        aux->prox = NULL;    //Para que não existam duas maneiras de acessar um nó
        p->cont--;
        return aux;          //Retorna endereço do nó que é o novo topo
    }
}

//Remove a pilha e todos os dados referentes a ela
void destroy_p(pilha *p){
	while(1 == 1){
		if(p->topo==NULL) break;  //Se a pilha estiver vazia, para o programa
		free(pop_p(p)); //Libera o espaço de mem dos nós que foram desempilados
	}
	free(p); //Libera o espaço de memória da pilha
}

//Exibe as informações referente a pilha desejada
void show_p(pilha *p){
	if(p->topo != NULL){  //Se a pilha não estiver vazia
		no* aux = p->topo; //Auxiliar para diminuir printf
		while(1==1){
			printf("[%llu, %llu, %c, %llu]\n", aux->cpf, aux->cpft, aux->op, aux->valor);
			aux = aux->prox; //Para imprimir o prox nó
			if(aux==NULL) break; //Se o proximo nó for NULL, a pilha está vazia
		}
	}
}

//Função principal
int main(){
    //VERIFICAÇÕES, TESTES DE CADA DAS FUNÇÕES
/*
    pilha *p = create_p();                          //Criou a pilha

    unsigned long long int cpf, cpft, valor; char op;                  //Criou variáveis para ler valores
    scanf("%d %d %d %c", &cpf, &cpft, &valor, &op);

    //Um ponteiro para cada cliente receber o retorno da função create_n
    no *cliente0 = create_n(cpf, cpft, valor, op);
    no *cliente1 = create_n(cpf+1, cpft+1, valor+1, op);

    // Imprime os valores no topo da pilha, como os nós foram apenas criados mas não
    // foi feito push, dará falha de segmentação, afinal, os nós não foram ligados
    // a pilha ainda
    // //printf("%d %d %d %c \n",p->topo->cpf,p->topo->cpft,p->topo->valor,p->topo->op);

    printf("debug\n");

    printf("Vazia: %d \n",isEmpty_p(p));  //Verifica se a pilha está vazia


    //Cria dois ponteiros auxiliares para facilitar o push e o printf
    no *ax0 = cliente0;
    no *ax1 = cliente1;

    //Empilha os nós de cada cliente imprime para testar
    push_p(p, ax0);
    printf("%d %d %d %c \n", ax0->cpf, ax0->cpft, ax0->valor, ax0->op);
    push_p(p, ax1);
    printf("%d %d %d %c \n", ax1->cpf, ax1->cpft, ax1->valor, ax1->op);

    //Verificando se a função pop_p está retornando corretamente
    no *a = pop_p(p);
    printf("%p\n", (void*)a);

    printf("Vazia: %d\n",isEmpty_p(p)); //Imprime 0 pois a foram feitos 2 push e 1 pop

    destroy_p(p);     //Destrói toda a pilha e seus dados
*/

//PROGRAMA PRINCIPAL
    //Cria vetordinamico de ponteiros para alocar o espaço de memória dos três guiches
    pilha **vetor_pilhas = (pilha**) malloc(sizeof(pilha*)*3);

    //Cria três pilhas diferentes (guiches)
    for(unsigned long long int i = 0; i<3; i++){
    	 vetor_pilhas[i] = create_p();
    }

    unsigned long long int n; //Variável que lê quantas operações serão feitas no total
	unsigned long long int cpf, cpft, valor; //Criou variáveis para ler valores
    char op;

    //Ponteiro tipo no para que as informações lidas sejam associadas e depois
    //enviadas quando fizer o push
    no *cliente = NULL;

    scanf("%llu",&n); //Lê quantas operações serão feitas no total
    for(unsigned long long int i = 0; i<n; i++){
    	scanf("%llu %llu %c %llu", &cpf, &cpft, &op, &valor);
    	cliente = create_n(cpf, cpft, valor, op); //Cria um nó com as informações lidas
    	int guiche  = i%3;  //O modulo irá verificar qual guiche será registrado a informação
    	push_p(vetor_pilhas[guiche],cliente); //Faz push do novo nó
    }

    printf("-:| RELATÓRIO PARCIAL |:-\n3\n");

    //"for" para imprimir informação e destruir cada pilha
    for(int i =0; i<3; i++){
    	printf("Guiche %d: %llu\n", i+1, vetor_pilhas[i]->cont);
    	show_p(vetor_pilhas[i]); //Imprimir
    	destroy_p(vetor_pilhas[i]); //Destruir pilha referente ao guiche
    }
    free(vetor_pilhas); //Libera vetordinamico que continha os locais das pilhas (guiches)
}
