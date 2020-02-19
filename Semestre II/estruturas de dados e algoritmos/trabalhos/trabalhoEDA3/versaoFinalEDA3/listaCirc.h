#ifndef LISTACIRC_H
#define LISTACIRC_H

typedef struct lista lista;
typedef struct nol nol;

//Função para inicializar lista
//Retorna um ponteiro contendo o endereço da lista
lista* create_l();

//Função para criar nol do tipo lista
//Recebe como argumento um usigned long int com o valor do cpf
//Retorna um ponteiro para o nol criado
nol* create_nol(unsigned long int cpf);

//Função para checar se lista está vazia
//Recebe como argumento um ponteiro para a lista a ser analizada
//Retorna 1 se Vazia e 0 se Não vazia
int isEmpty_l(lista* l);

//Função para buscar elemento na lista
//Recebe como argumento um ponteiro para a lista e um usigned long int com o valor do cpf
//Retorna um ponteiro para o nol ou NULL se não encontrado
nol* search_l(lista* l, unsigned long int k);

//Função para inserir elemento na lista em um local de maneira que a lista sempre fica ordenada
//Recebe como argumento um ponteiro para a lista e um ponteiro para o nol de lista que
//Retorna um ponteiro para o nol inserido
nol* push_l(lista* l, nol* x);

//Função para remover elemento da lista
//Recebe como argumento um ponteiro para a lista e um nol para lista
//Retorna elemento que foi retirado da lista
nol* pop_l(lista* l, nol* k);

//Função para destruir lista e todo seu conteúdo
//Recebe como argumento um ponteiro para a lista
lista* destroy_l(lista* l);

//Função para retornar o valor do cpf da lista
//Recebe como argumento um ponteiro para o nol da lista
//Retorna um unsigned long int contendo o valor do cpf
unsigned long int cpf_l(nol *n);

//Função para retornar a quantidade de operações de um certo cpf
//Recebe como argumento um ponteiro para o nol da lista
//Retorna um unsigned long int contendo a quantidade de operações
unsigned long int ops_l(nol *n);

//Função para retornar o saldo de um certo cpf
//Recebe como argumento um ponteiro para o nol da lista
//Retorna um long int contendo o saldo do nol da lista
long int saldo_l(nol *n);

//Função para retornar o primeiro elemento da lista
//Recebe como argumento um ponteiro para a lista
//Retorna um ponteiro do tipo nol para o primeiro nol da lista
nol *lPrimeiro(lista *l);

//Função para retornar o tamanho da lista
//Recebe como argumento um ponteiro para a lista
//Retorna um unsigned long int contendo o tamanho da lista
unsigned long int cont_l(lista *l);

//Função para retornar o proximo nol de um nol dado
//Recebe como um argumento um nol da lista
//Retorna um ponteiro para o próximo nol
nol *prox_l(nol *n);

//Função para retornar o nol anterior de um nol dado
//Recebe como um argumento um nol da lista
//Retorna um ponteiro para o nol anterior
nol *ant_l(nol *n);

//Função para adicionar valor ao saldo do nol
//Recebe como um argumento um ponteiro para o nol e um long int contendo o valor
void saldo_l_add(nol* n, long int valor);

//Função para subtrair valor ao saldo do nol
//Recebe como um argumento um ponteiro para o nol e um long int contendo o valor
void saldo_l_sub(nol* n, long int valor);

//Função para incrementar número de operações ao nol
//Recebe como argumento um ponteiro para o nol
void ops_l_add(nol* n);

#endif // PILHACIRC_H