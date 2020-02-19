//João Lucas Lima de Melo
#ifndef AVL_H
#define AVL_H

typedef struct avl avl;
typedef struct no no;

//Função para criar nó
//Recebe um inteiro como parâmetro, sendo ele a chave do nó
//Retorna ponteiro contendo o endereço do nó
no* create_n(int chave);

//Função para identificar o pai de um nó
//Recebe como parametro um ponteiro para um nó
//Retorna um ponteiro contendo o endereço do pai do nó
no* pai_n(no* n);

//Função para identificar o filho esquerdo de um nó
//Recebe como parametro um ponteiro para um nó
//Retorna um ponteiro contendo o endereço do filho esquerdo do nó
no* esq_n(no* n);

//Função para identificar o filho direito de um nó
//Recebe como parametro um ponteiro para um nó
//Retorna um ponteiro contendo o endereço do filho direito do nó
no* dir_n(no* n);

//Função para identificar a chave de um nó
//Recebe como parametro um ponteiro para um nó
//Retorna um inteiro, a chave do nó
int chave_n(no* n);

//Função para identificar a quantidade de operações feitas por um nó
//Recebe como parametro um ponteiro para um nó
//Retorna um inteiro, a quantidade de operações feitas pelo nó
int qnt_operacao_n(no* n);

//Função para identificar o saldo de um nó
//Recebe como parametro um ponteiro para um nó
//Retorna um inteiro, o saldo do nó
int saldo_n(no* n);

//Função para atualizar a altura de um nó
//Recebe como parametro um ponteiro para um nó cuja altura será atualizada
//Retorna um inteiro com a altura do nó
int update_altura_n(no* n);

//Função para checar o balanco de um nó
//Recebe como parametro um ponteiro de um nó cujo balanço será verificado
//Retorna um inetiro, o balanço do nó
int balanco_n(no* n);

//Função para balancear um nó
//Recebe como parâmetros ponteiros para uma AVL e um nó em que será feito o balanceamento
void balancear_n(avl* a, no* n);

//Função para remover um nó de uma AVL
//Recebe como parâmetros ponteiros para uma AVL e o nó a ser removido
//Retorna um ponteiro para o nó removido
no* remove_n(avl* a, no* n);

//Função para remover um nó de uma AVL segundo sua chave
//Recebe como parâmetros um ponteiro para uma AVL e um inteiro com a chave do nó a ser removido
void remove_chave_a(avl* a, int chave);

//Função para criar AVL
//Retorna ponteiro contendo o endereço da AVL
avl* create_a();

//Função para identificar a raiz de uma AVL
//Recebe como parametro um ponteiro para uma AVL
//Retorna um ponteiro contendo o endereço da raiz da AVL
no* raiz_a(avl* a);

//Função para identificar o tamanho(quantidade de nós) de uma AVl
//Recebe como parametro um ponteiro para uma AVL
//Retorna um inteiro, o tamanho da AVL
int tamanho_a(avl* a);

//Função para identificar a altura de uma AVL
//Recebe como parametro um ponteiro para uma AVL
//Retorna um inteiro, a altura da AVL
int altura_a(avl* a);

//Função para inserir um nó em uma AVL
//Recebe como parametro poiteiros para uma AVL, o nó a ser inserido, e nós auxiliares
//Retorna um ponteiro para o nó adicionado
no* insere_a(avl* a, no* n, no*x, no* y);

//Função para buscar um nó em uma AVL pela sua chave
//Recebe como parametro um ponteiro para uma AVL e um inteiro, a chave do nó
//Retorna um ponteiro para o nó buscado
no* busca_n(avl* a, int key);

//Função para realizar uma rotação simples à direita
//Recebe como parâmetros ponteiros de uma AVL e de um nó em que será realizada a rotação
void rotacaoSimplesDir(avl* a, no* n);

//Função para realizar uma rotação simples à esquerda
//Recebe como parâmetros ponteiros de uma AVL e de um nó em que será realizada a rotação
void rotacaoSimplesEsq(avl* a, no* n);

//Função para realizar uma rotação dupla à direita
//Recebe como parâmetros ponteiros de uma AVL e de um nó em que será realizada a rotação
void rotacaoDuplaDir(avl* a, no* n);

//Função para realizar uma rotação dupla à esquerda
//Recebe como parâmetros ponteiros de uma AVL e de um nó em que será realizada a rotação
void rotacaoDuplaEsq(avl* a, no* n);

//Função para inserir um nó com seus dados já informados
//Recebe como parâmetros um ponteiro para uma AVL, e três inteiros (chave, operação a ser realizada e saldo)
void insere(avl* a, int chave, int operacao, int saldo);

//Função para transferir os dados de um nó ao outro
//Recebe como parâmetros ponteiros para dois nós, o cujos dados serão atualizados e o fornecedor dos dados
//Retorna um ponteiro para o nó atualizado
no* transferencia_de_dados(no* n, no* aux);

#endif