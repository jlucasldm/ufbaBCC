//Gustavo de Oliveira Ferreira
#ifndef AVL_H
#define AVL_H

typedef struct no no;
typedef struct arvore arvore;

//Função para alocar espaço do arvore
//Retorna um ponteiro para a arvore alocada
arvore *create_tree();

//Função para alocar espaço do no
//Retorna ponteiro para o nó alocado
no *create_no(int codCliente, int saldo);

// Função para verificar se arvore está vazia
//Recebe como argumento um ponteiro para a arvore
//Retorna 1 se estiver vazia ou 0 caso não vazia
int isEmpty(arvore *arv);

//Função para realizar busca na Arvore, complexidade: BigO(qntElementos)
//Recebe o nó principal, utilizar função raiz() e o nó que se quer ser procurado
//Retorna um ponteiro para o nó se ele for encontrado e NULL se não houver na arvore
no *search_no(no *x, no *n);

//Função para retornar tamanho da arvore
//Recebe como argumento um ponteiro para a arvore a ser analisada
//Retorna um int com o tamanho da arvore
int size(arvore *arv);

//Função para remover da arvore
//Recebe como argumento um ponteiro para a arvore e um ponteiro para o nó a ser removido
//Retorna um ponteiro para o nó removido
no *remover_abb(arvore *t, no *z);

//Acessa toda a arvore na sequencia recursiva: raiz - esq - dir
//Recebe como argumento um ponteiro para a raiz, utilizar função raiz()
void PreOrdem(no *x);

//Acessa toda a arvore na sequencia recursiva: esq - raiz - dir
//Recebe como argumento a raiz, utilizar função raiz()
//Imprime todos os elementos da arvore em ordem crescente
void InOrdem(no *x);

//Acessa toda a arvore na sequencia recursiva: esq - dir - raiz
//Recebe como argumento a raiz, utilizar função raiz()
void PosOrdem(no *x);

//Desaloca o espaço de todas os nós da árvore
//Usa como principio a ideia de acesso PosOrdem
//Recebe como argumento a raiz, utilizar função raiz()
arvore *destroyTree(arvore *arv, no *x);

//Retorna um ponteiro para o primeiro pai da arvore
//Recebe como argumento um ponteiro para a arvore
//Retorna um ponteiro do tipo nó contendo o nó principal
no *raiz(arvore *arv);

//Retorna o menor elemento das subarvores de um nó
//Recebe como argumento o nó raiz
//Para saber o menor elemento de toda a raiz, utilize a função raiz(arv)
no *minimo(no *x);

//Retorna o maior elemento das subarvores de um nó
//Recebe como argumento o nó raiz
//Para saber o maior elemento de toda a raiz, utilize a função raiz(arv)
no *maximo(no *x );

//Função para encontrar o nó com chave sucessora ao nó dado
//Recebe como argumento um ponteiro para o nó que se quer saber seu sucessor
//Retorna o ponteiro para o nó sucessor
no *sucessor(no *x);

//Função para encontrar o nó com chave predecessora ao nó dado
//Recebe como argumento um ponteiro para o nó que se quer saber seu predecessor
//Retorna o ponteiro para o nó predecessor
no *predecessor(no *x);

//Função para saber a altura de um nó;
//Recebe como argumento o nó que se quer saber a altura
//Retorna um inteiro contendo a altura do nó dado
int altura(no *n);

no *search_cod(no *x, int codCliente);
int saldo_sub(no* n, int valor);
int saldo_add(no* n, int valor);

int saldo_add(no* n, int valor);
int saldo_sub(no* n, int valor);
no *rotacaoSimplesEsq(arvore *T, no *x);
no *rotacaoSimplesDir(arvore *T, no *x);
no *rotacaoDuplaEsq(arvore *T, no *x);
no *rotacaoDuplaDir(arvore *T, no *x);
no *balanceamento(arvore* T, no *x);
void imprime_AVL_crescente(no *x);
void imprime_AVL_decrescente(no *x);
int max(int a, int b);
int balanco(no *n);
no *insereAVL(arvore *T, no *x, no *novo);
no *removeAVL(arvore *T, no *x, int codCliente);
int codCliente(no *n);
void mostraArvore(no* a, int b);
void imprimeNo(int c, int b);
no *noPai(no *n);
no *noDir(no *n);

#endif
