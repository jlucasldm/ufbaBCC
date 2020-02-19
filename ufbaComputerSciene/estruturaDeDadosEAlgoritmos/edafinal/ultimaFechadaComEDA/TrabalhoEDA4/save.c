//Jukera Johnsons
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no no;
typedef struct avl avl;

//Declaração do tipo nó
struct no{
    int chave;      //código do cliente
    int operacao;   
    int saldo;
    int altura;
    no* pai;
    no* esq;
    no* dir;
    
};

//Declaração do tipo avl
struct avl{
    no* raiz;
    int altura; //na verdade, é quantidade de nós
};

avl* create_a(){
    avl *a = (avl*) malloc(sizeof(avl));
    if(a!=NULL){
        a->raiz = NULL;
        a->altura = 1;
    }
    return a;
};

avl* destroy_a(avl* a, no* n){
    if(n!=NULL){
        destroy_a(a, n->esq);
        destroy_a(a, n->dir);
        free(n);
    }
    free(a);
    a->raiz = NULL;
    return a;
}

no* create_n(int chave, int operacao, int saldo){
    no *n = (no*) malloc(sizeof(no));
    if(n!=NULL){
        n->chave = chave;
        n->operacao = operacao; //seila, joguei qualquer merda
        n->saldo = saldo;
        n->altura = 0;
        n->pai = NULL;
        n->esq = NULL;
        n->dir = NULL;
    }
    return n;
}

no* copia_n(no* n){
    no *m = create_n(n->chave, n->operacao, n->saldo);
    m->operacao = n->operacao;
    m->pai = n->pai;
    m->esq = n->esq;
    m->dir = n->dir;
}

no* raiz_a(avl* a){
    if(a==NULL){
        return NULL;
    }
    return a->raiz;
}

int altura_a(avl* a){
    if(a==NULL){
        return 0;
    }
    return a->altura;
}

no* pai_n(no* n){
    if(n==NULL){
        return NULL;
    }
    return n->pai;
}

no* esq_n(no* n){
    if(n==NULL){
        return NULL;
    }
    return n->esq;
}

no* dir_n(no* n){
    if(n==NULL){
        return NULL;
    }
    return n->dir;
}

int chave_n(no* n){
    if(n==NULL){
        return 0;
    }
    return n->chave;
}

int operacao_n(no* n){
    if(n==NULL){
        return 0;
    }
    return n->operacao;
}

int saldo_n(no* n){
    if(n==NULL){
        return 0;
    }
    return n->saldo;
}

int altura_n(no* n){
    if(n==NULL){
        return 0;
    }
    return n->altura;
}

int empty_a(avl* a){
    if(a->raiz == NULL){
        return 1;
    }else if(a->raiz != NULL){
        return 0;
    }
}

no* minimo_a(no* n){
    while(n->esq!=NULL){
        n = n->esq;
    }
    return n;
}

no* maximo_a(no* n){
    while(n->dir!=NULL){
        n = n->dir;
    }
    return n;
}

no* predecessor_n(no* n){
    if(n->esq!=NULL){
        return minimo_a(n);
    }
    no* y = n->pai;
    while(y!=NULL && y->esq==n){
        n=y;
        y=n->pai;
    }
    return y;
}

no* sucessor_n(no* n){
    if(n->dir!=NULL){
        return maximo_a(n);
    }
    no* y = n->pai;
    while(y!=NULL && y->dir==n){
        n=y;
        y=n->pai;
    }
    return y;
}

int balanco_n(no* n){
    return altura_n(n->esq)-altura_n(n->dir);
}

no* transplante(avl* a, no* z, no* y){
    if(raiz_a(a)== NULL){
        a->raiz = y;
    }else if(z == z->pai->esq){
        z->pai->esq = y;
    }else{
        z->pai->dir = y;
    }
    if(y!=NULL){
        y->pai = z->pai;
    }
    return z;
}
    
no* busca_chave(no* x, int saldo){
    while(x!=NULL && x->saldo!=saldo){
        if(saldo>x->saldo){
            x=x->dir;
        }else{
            x=x->esq;
        }
    }
    return x;
}

no* busca_no(no* x, no* n){
    while(x->chave != n->chave){
        if(x->chave > n->chave){
            x=x->dir;
        }else{
            x=x->esq;
        }
    }
    return x;
}

no* rotacaoSimplesEsq(avl* a, no* n){
    no* m = n->dir;
    n->dir = m->esq;
    if(m->esq!=NULL){
        m->esq->pai = n;
    }
    if(a->raiz==n){
        a->raiz = m;
    }else if(n=n->pai->esq){
        n->pai->esq = m;
    }else{
        n->pai->dir = m;
    }
    m->esq = n;
    n->pai = m;
    n->altura = altura_n(n);
    m->altura = altura_n(m);
    return m;
}

no* rotacaoSimplesDir(avl* a, no* n){
    no* m = n->esq;
    printf("n\n");
    n->dir = m->dir;
    if(m->dir!=NULL){
        printf("o\n");
        m->dir->pai = n;
    }
    if(a->raiz==n){
        printf("p\n");
        a->raiz = m;
    }else if(n=n->pai->dir){
        n->pai->dir = m;
    }else{
        n->pai->esq = m;
    }
    printf("q\n");
    m->dir = n;
    printf("r\n");
    n->pai = m;
    printf("s\n");
    n->altura = altura_n(n);
    m->altura = altura_n(m);
    return m;
}

no* rotacaoDuplaEsq(avl* a, no* n){
    no *m = n->dir;
    m = rotacaoSimplesDir(a, m);
    n = rotacaoSimplesEsq(a, n);
    return n;
}

no* rotacaoDuplaDir(avl* a, no* n){
    no *m = n->esq;
    printf("l\n");
    m = rotacaoSimplesEsq(a, m);
    printf("m\n");
    n = rotacaoSimplesDir(a, n);
    return n;
}

no* balanceamento(avl* a, no* n){
    printf("w\n");
    if(balanco_n(n)==-2){
        printf("b\n");
        no* m = n->dir;
        if(balanco_n(m)==1){
            printf("c\n");
            rotacaoDuplaEsq(a, n);
        }else{
            printf("d\n");
            rotacaoSimplesEsq(a, n);
        }
    }
    else if(balanco_n(n)==2){
        printf("e\n");
        no* m=n->esq;
        if(balanco_n(m)==-1){
            printf("f\n");
            rotacaoDuplaDir(a, n);
        }else{
            printf("g\n");
            rotacaoSimplesDir(a, n);
        }        
    }
    return n;
}

no* insereAvl(avl* a, no* raiz, no* novo){
    if(a->raiz == NULL){
        a->raiz = novo;
        novo->altura = 1;
        novo->pai = NULL;
        a->altura = altura_n(a->raiz);
        return novo;
    }
    else if(novo->chave < raiz->chave){
        if(raiz->esq == NULL){
            raiz->esq = novo;
            novo->altura = 1;
            novo->pai = raiz;
            a->altura ++;
        }else{
            insereAvl(a, raiz->esq, novo);
        }
    }
    else if(novo->chave > raiz->chave){
        if(raiz->dir == NULL){
            raiz->dir = novo;
            novo->altura=1;
            novo->pai = raiz;
            a->altura ++;
        }else{
            insereAvl(a, raiz->dir, novo);
        }                   
    }
    if(balanco_n(raiz) == 2 || balanco_n(raiz) == -2){
        balanceamento(a, raiz);
        printf("flag\n");
    }
    return novo;
}

no* remove_a(avl* a, no* n, int chave){
    if(n == NULL){
        return NULL;
    }
    if(chave < n->chave){
        n = remove_a(a, n->esq, chave);
    }
    else{
        if(chave > n->chave){
            n = remove_a(a, n->dir, chave);
        }                                     
        else{
            a->altura--;
            if(n->esq == NULL){
                transplante(a, n, n->dir);
            }
            else if(n->dir == NULL){
                transplante(a, n, n->esq);
            }
            else{
                no* y = sucessor_n(n);
                no* z = copia_n(y);
                transplante(a, n, z);
                z->dir = n->dir;
                z->esq = n->esq;
                n->dir->pai = z;
                n->esq->pai = z;
                remove_a(a, z->dir, y->chave);
            }
        }
    }
    if(n == NULL){
        return NULL;
    }
    n->altura = altura_n(n);
    if(balanco_n(n) == 2 || balanco_n(n) == -2){
        balanceamento(a, n);
    }
    return n;
}

void preorder(no* n){
    if(n != NULL){
        printf("%d\n", n->chave);
        preorder(n->esq);
        preorder(n->dir);
    }
}

void inorder(no* n){
    if(n != NULL){
        inorder(n->esq);
        printf("%d\n", n->chave);
        inorder(n->dir);
    }
}

void postorder(no* n){
    if(n != NULL){
        postorder(n->esq);
        postorder(n->dir);
        printf("%d\n", n->chave);
    }
}

void crescente_n(no* n){
    if(n!=NULL){
        crescente_n(n->esq);
        printf("%d %d %d\n", chave_n(n), operacao_n(n), saldo_n(n));
        crescente_n(n->dir);
    }
}

void decrescente_n(no* n){
    if(n!=NULL){
        decrescente_n(n->dir);
        printf("%d %d %d\n", chave_n(n), operacao_n(n), saldo_n(n));
        decrescente_n(n->esq);
    }
}

void lista_chaves(no* raiz, int nivel){ 
    if (raiz == NULL) 
        return;
    if (nivel == 1) 
        printf("%d ", raiz->chave); 
    else if (nivel > 1){ 
        lista_chaves(raiz->esq, nivel-1); 
        lista_chaves(raiz->dir, nivel-1); 
    }
}

int add_saldo(no* n, int saldo){
    n->saldo += saldo;
    return n->saldo;
}

int sub_saldo(no* n, int saldo){
    n->saldo -= saldo;
    return n->saldo;
}

int main(){
    char c;
    avl* a = create_a();
    int chave[5] = {1, 2, 3, 4 , 5};
    no* n1 = create_n(chave[0], 1, 0);
    no* n2 = create_n(chave[1], 0, 10);
    no* n3 = create_n(chave[2], 0, 20);
    no* n4 = create_n(chave[3], 1, 30);
    no* n5 = create_n(chave[4], 1, 40);

    printf("Inserindo %d\n", chave_n(n1));
    insereAvl(a, raiz_a(a), n1);
    printf("Raiz: %d\n", a->raiz->chave);

    printf("Inserindo %d\n", chave_n(n2));
    insereAvl(a, raiz_a(a), n2);
    printf("Raiz: %d\n", a->raiz->chave);

    printf("Inserindo %d\n", chave_n(n3));
    insereAvl(a, raiz_a(a), n3);
    printf("Raiz: %d\n", a->raiz->chave);

    printf("Inserindo %d\n", chave_n(n4));
    insereAvl(a, raiz_a(a), n4);
    printf("Raiz: %d\n", a->raiz->chave);

    printf("Inserindo %d\n", chave_n(n5));
    insereAvl(a, raiz_a(a), n5);
    printf("Raiz: %d\n", a->raiz->chave);

    printf("Inorder:\n");
    inorder(raiz_a(a));

    printf("Tamanho da avl: %d\n", altura_a(a));

    printf("Chaves de nível 0:\n");
    lista_chaves(a->raiz, 0);

    printf("Chaves de nível 1:\n");
    lista_chaves(a->raiz, 1);

    printf("\nChaves de nível 2:\n");
    lista_chaves(a->raiz, 2);

    printf("\nChaves de nível 3:\n");
    lista_chaves(a->raiz, 3);

    printf("\nRemovendo 3");
    remove_a(a, raiz_a(a), 3);

    printf("\nInorder:\n");
    inorder(raiz_a(a));

    printf("Reeee mermao\n");
    return 0;
}





/*

Especificação de Entradas

• insere nó: esta operação consiste de uma linha contendo a letra ‘i’, seguida de um espaço e três
números inteiros separados com um espaço que serão respectivamente código_cliente, operação
e saldo. 
if(char == 'i')(insere_no(int chave, int operacao, int saldo))
Esta operação causa a inserção de um nó na árvore cuja chave será o número inteiro
referente ao código_cliente. Caso já haja nó na árvore com saldo de chave igual a este número, o
nó com tal chave deve ter seus dados atualizados de acordo com a operação informada.

• consulta nó: esta operação consiste de uma linha contendo a letra ‘c’, seguida por um espaço,
seguido por um saldo inteiro. 
if(char == 'c')(consulta_no(int saldo))
Esta operação verifica se há ou não nó na árvore com saldo de chave
igual ao número inteiro digitado.

• remove nó: esta operação consiste de uma linha contendo a letra ‘r’, seguida por um espaço,
seguido por um saldo inteiro. 
if(char == 'r')(remove_no(int chave))
Esta operação retira o nó da árvore que tiver chave igual ao número
inteiro indicado, se houver. Se não houver, esta operação não gera efeito.

• lista chaves dos nós da árvore em ordem: esta operação consiste de uma linha contendo a
letra ‘p’, seguida de um espaço, seguido da letra ‘c’ ou ‘d’.
if(char == p)
    if(char == c)(crescente(avl* a))
    else if(char == d)(decrescente(avl* a))
Se a segunda letra é ‘c’, esta operação
lista as chaves dos nós da árvore em ordem crescente. Se a segunda letra for ‘d’, esta operação
lista as chaves dos nós da árvore em ordem decrescente.

• lista chaves de um determinado nível da árvore: esta operação consiste de uma linha
contendo a letra ’n’, seguida de um espaço, seguido de um número inteiro maior ou igual a 1.
if(char == 'n')(lista(int nivel))
Esta operação lista as chaves dos nós da árvore que tiverem nível igual ao número fornecido. Assuma
que a raiz da árvore possui nível 1.

• informa altura: esta operação consiste de uma linha contendo a letra ‘h’.
if(char == 'h')(altura(avl* a))
Esta operação informa a altura da árvore.

• término da entrada: a sequência de operações será terminada por uma linha com a letra ‘f’.
if(char == 'f') break;
*/




/*

Especificação Saída

• insere nó: esta operação não gera saída.

• consulta nó: se houver um nó na árvore com a chave informada, esta operação gera, na saída,
a sequência de caracteres “existe no com chave: X”, onde X é a chave informada. Caso não
haja, esta operação gera, na saída, a sequência de caracteres “nao existe no com chave: X”,
onde X é a chave informada.
Observação: Não usamos nenhum tipo de acentuação.

• remove chave: esta operação não gera saída (independentemente se há ou não nó com o saldo
de chave indicado na operação).

• lista chaves dos nós da árvore em ordem: esta operação lista os dados contidos nos nós, um
em cada linha. Os dados serão três inteiros que correspondem respectivamente ao código_cliente,
quantidade_de_operação e saldo.

• lista chaves de um determinado nível da árvore: esta operação lista as chaves dos nós, uma
em cada linha. A sequência das chaves dos nós listados deve seguir a ordem da representação
gráfica da árvore, da esquerda para a direita.

• informa altura: esta operação deve retornar um inteiro que informa a altura da árvore corrente.
Considere que a árvore vazia tem algura zero.

• término da entrada: esta operação irá gerar um relatório com todos os dados armazenados
na árvore. Para tal, deve iniciar imprimindo a seguinte sequência de caractere “-+- Inicio
relatorio -+-”, depois imprimir o inteiro L que representa a quantidade distintas de clientes
seguido de L linhas que devem conter três inteiros C i , Q i e S i , para 1 ≤ i ≤ L, separados por um
espaço em branco e finalizar com a seguinte sequência de caractere “-+- Fim relatorio -+-”. A
ordem de impressão dos dados é dada pela operação de remoção da raiz da árvore.
*/