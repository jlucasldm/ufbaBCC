#ifndef PILHA_H
#define PILHA_H

typedef struct pilha pilha;
typedef struct no no;

//Função para criar pilha
//Retorna ponteiro contendo o endereço da pilha
pilha* create_p();

//Função para checar se a pilha está vazia
//Recebe como argumento um ponteiro para a pilha a ser analizada
//Retorna 1 se Vazia e 0 se Não vazia
int isEmpty_p(pilha *p);

//Função para buscar um elemento na pilha
//Recebe como argumento um ponteiro para a pilha e um usigned long int contendo o valor do cpf a ser buscado
//Retorna um ponteiro para o nó ou NULL se não encontrado
no* search_p(pilha* p, unsigned long int cpf);

//Função para inserir elemento no topo da pilha
//Recebe como argumento um ponteiro para a pilha e um ponteiro para o nó que vai ser inserido
//Retorna um ponteiro para o nó recem criado
no* push_p(pilha *p, no *n);

//Função para retirar elemento do topo da pilha
//Recebe como argumento um ponteiro para a pilha
//Retorna um ponteiro para o nó que foi retirado
no* pop_p(pilha *p);

//Função para destruir a pilha e todo seu conteudo
//Recebe como argumento um ponteiro para a pilha a ser destruida
//Retorna um ponteiro para a pilha destruida, se bem sucedido retorna NULL
pilha *destroy_p(pilha *p);

//Função para retornar o topo da pilha
//Recebe como argumento um ponteiro para a pilha
//Retorna um ponteiro do tipo no para o topo da pilha
no *top_p(pilha *p);

//Função para retornar o tamanho da pilha
//Recebe como argumento um ponteiro para a pilha
//Retorna um unsigned long contendo o tamanho da pilha
unsigned long int cont_p(pilha *p);

//Função para retornar o valor de um certo cpf
//Recebe como argumento um ponteiro para um nó
//Retorna um unsigned long int para o valor do cpf
unsigned long int cpf_p(no *n);

//Função para retornar o valor de um certo cpf de terceiro
//Recebe como argumento um ponteiro para um nó
//Retorna um unsigned long int para o valor do cpf de terceiro
unsigned long int cpft_p(no *n);

//Função para retornar o valor de um certo no
//Recebe como argumento um ponteiro para o no
//Retorna um long int contendo o valor do no
long int valor_p(no *n);

//Função para retornar a operação de um certo no
//Recebe como argumento um ponteiro para o no analisado
//Retorna um char contendo a operação
char op_p(no *n);

//Função para retornar um ponteiro para o proximo no da pilha
//Recebe como argumento um ponteiro para o nó
//Retorna um ponteiro para o proximo nó depois deste na pilha
no *prox_p(no *n);

#endif // PILHA_H