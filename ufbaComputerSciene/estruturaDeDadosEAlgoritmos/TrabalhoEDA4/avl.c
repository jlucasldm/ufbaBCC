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
    int valor;
    int altura;
    no* pai;
    no* esq;
    no* dir;
    
};

//Declaração do tipo avl
struct avl{
    no* raiz;
    int altura;
};

avl* create_a(){
    avl *a = (avl*) malloc(sizeof(avl));
    if(a!=NULL){
        a->raiz = NULL;
        a->altura = 0;
    }
    return a;
};

no* raiz_a(avl* a){
    return a->raiz;
}

int altura_a(avl* a){
    return a->altura;
}

no* pai_n(no* n){
    return n->pai;
}

no* esq_n(no* n){
    return n->esq;
}

no* dir_n(no* n){
    return n->dir;
}

int chave_n(no* n){
    return n->chave;
}

int operacao_n(no* n){
    return n->operacao;
}

int valor_n(no* n){
    return n->valor;
}

int altura_n(no* n){
    if(n==NULL){
        return 0;
    }
    int d = altura_n(n->dir);
    int e = altura_n(n->esq);
    if(d>=e){
        n->altura = d+1;
    }else{
        n->altura = e+1;
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

no* create_n(int chave, int saldo){
    no *n = (no*) malloc(sizeof(no));
    if(n!=NULL){
        n->chave = chave;
        n->operacao = 1; //seila, joguei qualquer merda
        n->valor = 0;
        n->altura = 0;
        n->pai = NULL;
        n->esq = NULL;
        n->dir = NULL;
    }
    return n;
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

int transplante(avl* a, no* z, no* y){
    if(z->pai == NULL){
        a->raiz = y;
    }else if(z == z->pai->esq){
        z->pai->esq = y;
    }else{
        z->pai->dir = y;
    }
    if(z->pai != NULL){
        y->pai = z->pai;
    }
    return 1;
}
    
no* busca_chave(no* x, int key){
    while(x!=NULL && x->chave!=key){
        if(key>x->chave){
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
    n->dir = m->dir;
    if(m->dir!=NULL){
        m->dir->pai = n;
    }
    if(a->raiz==n){
        a->raiz = m;
    }else if(n=n->pai->dir){
        n->pai->dir = m;
    }else{
        n->pai->esq = m;
    }
    m->dir = n;
    n->pai = m;
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
    m = rotacaoSimplesEsq(a, m);
    n = rotacaoSimplesDir(a, n);
    return n;
}

no* balanceamento(avl* a, no* n){
    if(balanco_n(n)==-2){
        no* m = n->dir;
        if(balanco_n(m)==1){
            rotacaoDuplaEsq(a, n);
        }else{
            rotacaoSimplesEsq(a, n);
        }
    }
    else if(balanco_n(n)==2){
        no* m=n->esq;
        if(balanco_n(m)==-1){
            rotacaoDuplaDir(a, n);
        }else{
            rotacaoSimplesDir(a, n);
        }        
    }
    return n;
}

no* insereAvl(avl* t, no* x, no* novo){
    if(t->raiz == NULL){
        t->raiz = novo;
        novo->altura = 1;
        novo->pai = NULL;
    }
    if(novo->chave < x->chave){
        if(x->esq == NULL){
            x->esq = novo;
            novo->altura = 1;
            novo->pai = x;
        }else{
            x->esq = insereAvl(t, x->esq, novo);
        }
    }
    if(novo->chave > x->chave){
        if(x->dir == NULL){
            x->dir = novo;
            novo->altura=1;
            novo->pai = x;
        }else{
            x->dir = insereAvl(t, x->dir, novo);
        }                   
    }
    if(balanco_n(x) == 2 || balanco_n(x) == -2){
        balanceamento(t, x);
    }
    return x;
}

no* removeAvl(avl* a, no* n, int key){
    if(n == NULL){
        return NULL;
    }
    if(key < n->chave){
        n->esq = removeAvl(a, n->esq, key);
    }
    else{
        if(key > n->chave){
            n->dir = removeAvl(a, n->dir, key);
        }                                     
        else{
            if(n->esq == NULL){
                transplante(a, n, n->dir);
            }
            else if(n->dir == NULL){
                transplante(a, n, n->esq);
            }
            else{
                no* y = minimo_a(n->dir);
                no* z = n;
                transplante(a, n, z);
                n->dir = removeAvl(a, n->dir, y->chave);
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

int preorder(no* n){
    if(n == NULL){
        return 0;
    }
    return n->chave;
    preorder(n->esq);
    preorder(n->dir);
}

int inorder(no* n){
    if(n == NULL){
        return 0;
    }
    preorder(n->esq);
    return n->chave;
    preorder(n->dir);
}

int postorder(no* n){
    if(n == NULL){
        return 0;
    }
    preorder(n->esq);
    preorder(n->dir);
    return n->chave;
}

/*
int inserir(avl* a, no* n){
        no* aux = NULL;
        no* x = a->raiz;
        while(x!=NULL){
            aux=x;
            if(n->chave < x->chave){
                x=x->esq;
            }
            if(n->chave > x->chave){
                x=x->dir;
            }
            if(n->chave==x->chave){
                return 0;
            }
        }
        n->pai = aux;
        if(aux==NULL){
            a->raiz = n;
            return 1;
        }
        else{
            if(aux->chave > n->chave){
                aux->esq=n;
            }
            else{
                aux->dir=n;
            }
        }
        return 1;
}
*/

int main(){
    printf("Reeee mermao\n");
    return 0;
}





/*

Especificação de Entradas

• insere nó: esta operação consiste de uma linha contendo a letra ‘i’, seguida de um espaço e três
números inteiros separados com um espaço que serão respectivamente código_cliente, operação
e valor. Esta operação causa a inserção de um nó na árvore cuja chave será o número inteiro
referente ao código_cliente. Caso já haja nó na árvore com valor de chave igual a este número, o
nó com tal chave deve ter seus dados atualizados de acordo com a operação informada.

• consulta nó: esta operação consiste de uma linha contendo a letra ‘c’, seguida por um espaço,
seguido por um valor inteiro. Esta operação verifica se há ou não nó na árvore com valor de chave
igual ao número inteiro digitado.

• remove nó: esta operação consiste de uma linha contendo a letra ‘r’, seguida por um espaço,
seguido por um valor inteiro. Esta operação retira o nó da árvore que tiver chave igual ao número
inteiro indicado, se houver. Se não houver, esta operação não gera efeito.

• lista chaves dos nós da árvore em ordem: esta operação consiste de uma linha contendo a
letra ‘p’, seguida de um espaço, seguido da letra ‘c’ ou ‘d’. Se a segunda letra é ‘c’, esta operação
lista as chaves dos nós da árvore em ordem crescente. Se a segunda letra for ‘d’, esta operação
lista as chaves dos nós da árvore em ordem decrescente.

• lista chaves de um determinado nível da árvore: esta operação consiste de uma linha
contendo a letra ’n’, seguida de um espaço, seguido de um número inteiro maior ou igual a 1. Esta
operação lista as chaves dos nós da árvore que tiverem nível igual ao número fornecido. Assuma
que a raiz da árvore possui nível 1.

• informa altura: esta operação consiste de uma linha contendo a letra ‘h’. Esta operação informa
a altura da árvore.

• término da entrada: a sequência de operações será terminada por uma linha com a letra ‘f’.
*/




/*

Especificação Saída

• insere nó: esta operação não gera saída.

• consulta nó: se houver um nó na árvore com a chave informada, esta operação gera, na saída,
a sequência de caracteres “existe no com chave: X”, onde X é a chave informada. Caso não
haja, esta operação gera, na saída, a sequência de caracteres “nao existe no com chave: X”,
onde X é a chave informada.
Observação: Não usamos nenhum tipo de acentuação.

• remove chave: esta operação não gera saída (independentemente se há ou não nó com o valor
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