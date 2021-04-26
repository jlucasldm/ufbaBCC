#ifndef FILA_H
#define FILA_H

typedef struct no no;
typedef struct fila fila;

//Função para criar fila
//Recebe como argumento um unsigned long int contendo o tamanho da fila
//Retorna ponteiro contendo o endereço da fila
fila* create_f(unsigned long int tam0);

//Função para verificar se a fila está cheia ou não
//Recebe como argumento um ponteiro para a fila
//Retorna 1 se cheia ou 0 se vazia
int full_f(fila *f);

//Função para verificar se a fila está vazia ou não
//Recebe como argumento um ponteiro para a fila
//Retorna 1 se vazia ou 0 se não vazia
int isEmpty_f(fila *f);

//Função para enfileirar na ultima posição da fila
//Recebe como argumento um ponteiro para a fila e um ponteiro do tipo no que é o nó a ser inserido
void push_f(fila *f,no* x);

//Função para desenfileirar primeiro elemento da fila
//Recebe como argumento um ponteiro para a fila
//Retorna um ponteiro do tipo nó contendo o nó removido ou NULL se vazia
no* pop_f(fila *f);

//Função para verificar o primeiro nó da fila
//Recebe como argumento um ponteiro para a fila
//Retorna um ponteiro para o nó na frente da fila
no* front_f(fila*f);

//Função para retornar o tamanho da fila
//Recebe como argumento um ponteiro para a fila
//Retorna um unsigned long int contendo o tamanho da fila
unsigned long int size_f(fila* f);

//Função para fazer busca na fila
//Recebe como argumento um ponteiro para a fila e o cpf a ser buscado
//Retorna um ponteiro para o nó contendo o cpf ou NULL se não houver
no* search_f (fila* f,unsigned long int cpf);

//Função para destruir a fila
//Recebe como argumento um ponteiro para a fila
void destroy_f(fila* f);

//Função para retornar o cpf do inicio da fila
//Recebe como argumento um ponteiro para a fila
//Retorna um unsigned long int do cpf
unsigned long int inicio_f(fila *f);

//Função para retornar o cpf do fim da fila
//Recebe como argumento um ponteiro para a fila
//Retorna um unsigned long int do cpf
unsigned long int fim_f(fila *f);

//Função para retornar a quantidade de elementos da fila
//Recebe como argumento um ponteiro para a fila
//Retorna um unsigned long int contendo a quantidade de elementos da fila
unsigned long int qtd_f(fila *f);

//Função para retornar tamanho da fila
//Recebe como argumento um ponteiro para a fila
//Retorna um unsigened long int contendo o tamanho da fila
unsigned long int tam_f(fila *f);

//Função para retornar ponteiro para vetor de ponteiros da fila
//Recebe como argumento um ponteiro para a fila
no** vetor_f(fila *f);

//Função para retornar cpf do nó dado
//Recebe como argumento um ponteiro para o nó
//Retorna um unsigned long int contendo o cpf do nó
unsigned long int cpf_f(no *n);

//Função para retornar cpft do nó dado
//Recebe como argumento um ponteiro para o nó
//Retorna um unsigned long int contendo o cpft do nó
unsigned long int cpft_f(no *n);

//Função para retornar o valor do nó dado
//Recebe como argumento um ponteiro para o nó
//Retorna um long int contendo o valor do nó
long int valor_f(no *n);

//Função para retornar a operação do nó dado
//Recebe como argumento um ponteiro para o nó
//Retorna um char contendo a operação do nó
char op_f(no *n);

//Função para retornar o proximo nó do nó dado
//Recebe como argumento um ponteiro para o nó
//Retorna um ponteiro para o proximo nó
no *prox_f(no *n);

#endif // FILA_H
