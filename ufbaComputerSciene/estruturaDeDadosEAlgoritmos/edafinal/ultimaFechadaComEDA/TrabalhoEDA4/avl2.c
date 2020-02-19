//Jukera Johnsons
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no no;
typedef struct avl avl;

//Declaração do tipo nó
struct no{
    int chave;      //código do cliente
    int qnt_operacao;   
    int saldo;
    int altura;
    no* pai;
    no* esq;
    no* dir;
    
};

//Declaração do tipo avl
struct avl{
    no* raiz;
    int tamanho; //na verdade, é quantidade de nós
};

avl* create_a(){
    avl *a = (avl*) malloc(sizeof(avl));
    if(a!=NULL){
        a->raiz = NULL;
        a->tamanho = 0;
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

no* create_n(int chave, int saldo){
    no *n = (no*) malloc(sizeof(no));
    if(n!=NULL){
        n->chave = chave;
        n->qnt_operacao = 1;
        n->saldo = saldo;
        n->altura = 0;
        n->pai = NULL;
        n->esq = NULL;
        n->dir = NULL;
    }
    return n;
}

no* copia_n(no* n){
    no *m = create_n(n->chave, n->saldo);
    m->qnt_operacao = n->qnt_operacao;
    m->pai = n->pai;
    m->esq = n->esq;
    m->dir = n->dir;
    return m;
}

no* raiz_a(avl* a){
    if(a==NULL){
        return NULL;
    }
    return a->raiz;
}

int tamanho_a(avl* a){
    if(a==NULL){
        return 0;
    }
    return a->tamanho;
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

int qnt_operacao_n(no* n){
    if(n==NULL){
        return 0;
    }
    return n->qnt_operacao;
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
    int esq = altura_n(n->esq);
    int dir = altura_n(n->dir);
    if(dir>esq){
        return dir+1;
    }else{
        return esq+1;
    }
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
    if(n==NULL && n->dir != NULL){
        return NULL;
    }
    no* aux = n->dir;
    while(aux->esq != NULL){
        aux = aux->esq;
    }
    return aux;
    
}

int balanco_n(no* n){
    if(n==NULL){
        return 0;
    }
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
    
no* busca_chave(no* n, int key){
   no* aux = n;
   while(n!=NULL && n->chave != key){
       aux = n;
       if(key > n->chave){
           n=n->dir;
       }
       else if(key < n->chave){
           n=n->esq;
       }
    }
    return n;
}

no* rotacaoSimplesEsq(avl* a, no* n){
    no* m = n->dir;
    n->dir = m->esq;
    if(m->esq!=NULL){
        m->esq->pai = n;
    }
    m->esq = n;
    m->pai = n->pai;
    if(a->raiz==n){
        a->raiz = m;
    }else if(n=n->pai->esq){
        n->pai->esq = m;
    }else{
        n->pai->dir = m;
    }
    n->pai = m;
    n->altura = altura_n(n);
    m->altura = altura_n(m);
    return m;
}

no* rotacaoSimplesDir(avl* a, no* n){
    no* m = n->esq;
    n->esq = m->dir;
    if(m->dir!=NULL){
        m->dir->pai = n;
    }
    m->dir = n;
    m->pai = n->pai;
    if(a->raiz==n){
        a->raiz = m;
    }else if(n=n->pai->dir){
        n->pai->dir = m;
    }else{
        n->pai->esq = m;
    }
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
    if(n == NULL){
        return NULL;
    }
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
    balanceamento(a, n->pai);
    return n;
}

no* insere_a(avl* a, no* raiz, no* novo){
    if(a->raiz == NULL){
        a->raiz = novo;
        novo->altura = 1;
        novo->pai = NULL;
        a->tamanho ++;
    }else{
        if(novo->chave < raiz->chave){
            if(raiz->esq == NULL){
                raiz->esq = novo;
                novo->pai = raiz;
                novo->altura = 1;
                a->tamanho ++;
            }else{
                insere_a(a, raiz->esq, novo);
            }
        }
        else if(novo->chave > raiz->chave){
            if(raiz->dir == NULL){
                raiz->dir = novo;
                novo->pai = raiz;
                novo->altura=1;
                a->tamanho ++;
            }else{
                insere_a(a, raiz->dir, novo);
            }
        }
        if(balanco_n(raiz) == 2 || balanco_n(raiz) == -2){
            balanceamento(a, raiz);
        }                  
    }
    return raiz;
}

/*
no* remove_a(avl* a, no* raiz, int chave){
    no* n = busca_chave(raiz, chave);
    no* aux = NULL;
    a->tamanho--;
    if(n!=NULL){
        if(n->esq == NULL || n->dir == NULL){
            if(n->esq!=NULL){
                n->esq->pai=n->pai;
                aux=n->esq;
            }
            if(n->dir!=NULL){
                n->dir->pai=n->pai;
                aux=n->dir;
            }
            if(a->raiz == n){
                a->raiz = aux;
            }
            else{
                if(n->pai->esq==n){
                    n->pai->esq=aux;
                }
                else{
                    n->pai->dir=aux;
                }
            }
            if(aux==NULL){
                aux=n->pai;
            }
            free(n);
            return aux;
        }
        else{
            aux=n->dir;
            while(aux->esq!=NULL){
                aux=aux->esq;
            }
            transplante(a, n, aux);
            return aux;
        }
        while(n!=NULL){
            altura_n(n);
            balanceamento(a, n);
            n=n->pai;
        }
    }
}
*/

/*
no* remove_a(avl* a, no* n, int chave){
    if(n == NULL){
        return NULL;
    }
    if(chave < n->chave){
        return remove_a(a, n->esq, chave);
    }
    else{
        if(chave > n->chave){
            return remove_a(a, n->dir, chave);
        }                                     
        else{
            a->tamanho--;
            no* r = n;
            if(n->esq == NULL && n->dir == NULL){
                if(a->raiz == n){
                    a->raiz = NULL;
                }
                else if(n->pai->dir == n){
                    n->pai->dir = NULL;
                }
                else if(n->pai->esq == n){
                    n->pai->esq = NULL;
                }
                balanceamento(a, n->pai);
            }
            else if(n->esq == NULL){
                transplante(a, n, n->dir);
                balanceamento(a, n->dir);
            }
            else if(n->dir == NULL){
                transplante(a, n, n->esq);
                balanceamento(a, n->esq);
            }
            else{
                no* s = sucessor_n(n);
                no* sp = s->pai;
                if(n->dir == s){
                    sp = s;
                }
                if(a->raiz == n){
                    a->raiz = s;
                    if(n->dir != s){
                        if(s->dir != NULL){
                            s->dir->pai = s->pai;
                        }
                        s->pai->esq = s->dir;
                    }
                    s->pai = NULL;
                }else{
                    if(n->pai->dir == n){
                        n->pai->esq = s;
                        if(n->dir != s){
                            s->pai->esq = s->dir;
                            if(s->dir!=NULL){
                                s->dir->pai = s->pai;
                            }
                        }
                        s->pai = n->pai;
                    }
                    else{
                        n->pai->esq = s;
                        if(n->dir!=s){
                            s->pai->esq = s->dir;
                            if(s->dir){
                                s->dir->pai = s->pai;
                            }
                        }
                        s->pai=n->pai;
                    }
                }
                s->esq = n->esq;
                if(s->esq != NULL){
                    s->esq->pai = s;
                }
                if(n->dir != s){
                    s->dir = n->dir;
                    if(s->dir!=NULL){
                        s->dir->pai = s;
                    }
                }
                balanceamento(a, sp);
            }
            return r;
        }
    }
}
*/

no* remove_a(avl* a, no* n, int chave){
    if(n==NULL){
        return NULL;
    }
    if(chave < n->chave){
        n->esq = remove_a(a, n->esq, chave);
    }
    else if(chave > n->chave){
        n->dir = remove_a(a, n->dir, chave);
    }
    else{
        if(n->esq == NULL){
            no* aux = transplante(a, n, n->dir);
            free(n);
            n = aux;
        }
        else if(n->dir == NULL){
            no* aux = transplante(a, n, n->esq);
            free(n);
            n = aux;
        }
        else{
            no* y = minimo_a(n->dir);
            no* z = copia_n(y);
            transplante(a, n, z);
            z->dir = n->dir;
            z->esq = n->esq;
            n->dir->pai = z;
            n->esq->pai = z;
            free(n);
            n=z;
            remove_a(a, z->dir, y->chave);
        }
    }
    if(n==NULL){
        return NULL;
    }
    n->altura = altura_n(n);
    balanceamento(a, n);
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
    if(n==NULL){
        return;
    }
    if(n!=NULL){
        crescente_n(esq_n(n));
        printf("%d %d %d\n", chave_n(n), qnt_operacao_n(n), saldo_n(n));
        crescente_n(dir_n(n));
    }
}

void decrescente_n(no* n){
    if(n==NULL){
        return;
    }
    if(n!=NULL){
        decrescente_n(dir_n(n));
        printf("%d %d %d\n", chave_n(n), qnt_operacao_n(n), saldo_n(n));
        decrescente_n(esq_n(n));
    }
}

void lista_chaves(no* raiz, int nivel){ 
    if (raiz == NULL) 
        return;
    if (nivel == 1) 
        printf("%d\n", raiz->chave); 
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

//coisas que vão ficar no main, eu acho, vamo ver né, é possível

int atualiza_n(no* n, int saldo){
    n->saldo+=saldo;
    n->qnt_operacao++;
    return n->saldo;
}

void insere(avl* a, int chave, int operacao, int saldo){
    no* aux = busca_chave(raiz_a(a), chave);
    if(aux==NULL){
        insere_a(a, raiz_a(a), create_n(chave, saldo)); 
    }
    else{
        if(operacao == 1){
            saldo=saldo*(-1);
        }
        atualiza_n(aux, saldo);
    }
}

void consulta(avl* a, int chave){
    no* n = busca_chave(raiz_a(a), chave);
    if(n!=NULL){
        printf("existe no com chave: %d\n", chave);
    }else if(n==NULL){
        printf("nao existe no com chave: %d\n", chave);
    }
}

void remocao(avl* a, int chave){
    no* n = busca_chave(raiz_a(a), chave);
    if(n!=NULL){
        no* aux = remove_a(a, raiz_a(a), chave);
        free(aux);
    }
}

void relatorio(avl* a){
    int tam =tamanho_a(a);
    printf("-+- Inicio relatorio -+-\n%d\n", tam);
    for(int i =0; i<tam; i++){
        no* aux = remove_a(a, raiz_a(a), chave_n(raiz_a(a)));
        printf("%d %d %d\n", chave_n(aux), qnt_operacao_n(aux), saldo_n(aux));
        free(aux);
    }
    printf("-+- Fim relatorio -+-\n");
}

int main(){
    int chave;
    int operacao;
    int saldo;
    int nivel;
    char c;
    char entrada;

    avl* a = create_a();
    while(0!=1){
        scanf("%c", &entrada);

        if(entrada=='i'){
            scanf("%d %d %d", &chave, &operacao, &saldo);
            insere(a, chave, operacao, saldo);
        }
        else if(entrada == 'c'){
            scanf("%d", &chave);
            consulta(a, chave);
        }
        else if(entrada == 'r'){
            scanf("%d", &chave);
            remocao(a, chave);
        }
        else if(entrada == 'p'){
            scanf("%c", &c);
            if(c=='c'){
                crescente_n(raiz_a(a));
            }else if(c=='d'){
                decrescente_n(raiz_a(a));
            }
        }
        else if(entrada == 'n'){
            scanf("%d", &nivel);
            lista_chaves(raiz_a(a), nivel);
        }
        else if(entrada == 'h'){
            printf("%d\n", altura_n(raiz_a(a)));
        }
        else if(entrada == 'f'){
            relatorio(a);
            free(a);
            break;
        }
    }
    return 0;

    /*
    avl* a = create_a();
    int key[5] = {1, 2, 5, 3 , 4};
    no* n1 = create_n(key[0], 0);
    no* n2 = create_n(key[1], 10);
    no* n3 = create_n(key[2], 20);
    no* n4 = create_n(key[3], 30);
    no* n5 = create_n(key[4], 40);

    printf("Inserindo %d\n", chave_n(n1));
    insere_a(a, raiz_a(a), n1);
    printf("Raiz: %d\n", a->raiz->chave);
    //printf("Balanço %d: %d\n", raiz_a(a)->chave, balanco_n(raiz_a(a)));
    //printf("Chaves de nível 1:\n");
    //lista_chaves(a->raiz, 1);
    printf("Inorder:\n");
    inorder(raiz_a(a));
    printf("\n");

    printf("Inserindo %d\n", chave_n(n2));
    insere_a(a, raiz_a(a), n2);
    printf("Raiz: %d\n", a->raiz->chave);
    //printf("Balanço %d: %d\n", raiz_a(a)->chave, balanco_n(raiz_a(a)));
    //printf("Chaves de nível 1:\n");
    //lista_chaves(a->raiz, 1);
    //printf("\nChaves de nível 2:\n");
    //lista_chaves(a->raiz, 2);
    printf("Inorder:\n");
    inorder(raiz_a(a));
    printf("\n");

    printf("Inserindo %d\n", chave_n(n3));
    insere_a(a, raiz_a(a), n3);
    printf("Raiz: %d\n", a->raiz->chave);
    //printf("Balanço %d: %d\n", raiz_a(a)->chave, balanco_n(raiz_a(a)));
    //printf("Chaves de nível 1:\n");
    //lista_chaves(a->raiz, 1);
    //printf("\nChaves de nível 2:\n");
    //lista_chaves(a->raiz, 2);
    printf("Inorder:\n");
    inorder(raiz_a(a));
    printf("\n");

    printf("Inserindo %d\n", chave_n(n4));
    insere_a(a, raiz_a(a), n4);
    printf("Raiz: %d\n", a->raiz->chave);
    //printf("Balanço %d: %d\n", raiz_a(a)->chave, balanco_n(raiz_a(a)));
    //printf("Chaves de nível 1:\n");
    //lista_chaves(a->raiz, 1);
    //printf("\nChaves de nível 2:\n");
    //lista_chaves(a->raiz, 2);
    //printf("\nChaves de nível 3:\n");
    //lista_chaves(a->raiz, 3);
    printf("Inorder:\n");
    inorder(raiz_a(a));
    printf("\n");

    printf("Inserindo %d\n", chave_n(n5));
    insere_a(a, raiz_a(a), n5);
    printf("Raiz: %d\n", a->raiz->chave);
    //printf("Balanço %d: %d\n", raiz_a(a)->chave, balanco_n(raiz_a(a)));
    //lista_chaves(a->raiz, 1);
    //printf("\nChaves de nível 2:\n");
    //lista_chaves(a->raiz, 2);
    //printf("\nChaves de nível 3:\n");
    //lista_chaves(a->raiz, 3);
    printf("Inorder:\n");
    inorder(raiz_a(a));
    printf("\n");

    printf("Tamanho da avl: %d\n", tamanho_a(a));

    printf("\nChaves de nível 1:\n");
    lista_chaves(a->raiz, 1);

    printf("\nChaves de nível 2:\n");
    lista_chaves(a->raiz, 2);

    printf("\nChaves de nível 3:\n");
    lista_chaves(a->raiz, 3);

    printf("\nRemovendo 2");
    remove_a(a, raiz_a(a), 2);

    printf("\nInorder:\n");
    inorder(raiz_a(a));

    printf("Raiz: %d\n", a->raiz->chave);

    printf("\nReeee mermao\n");
    return 0;*/
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

/*void insere(avl* a,int id,int op,int val){
	no* n=create_n(id, val);
	n=insere_busca(a,n,a->raiz,NULL);
	n->qnt_operacao++;
	if(op==1)
		n->saldo-=val;
	else
		n->saldo+=val;
	while(n!=NULL){
		recalcular_altura(n);
		rebalancear(a,n);
		n=n->pai;
	}
}*/