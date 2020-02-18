#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct no no;
typedef struct arvore arvore;
struct no{
    int num;
    no *esq, *dir, *pai;
};

struct arvore{
    no *raiz;
    int tam;
};
arvore *create_tree();
no *create_no(int num);
int isEmpty(arvore *arv);
no *search(no *x, no *n);
unsigned long int size(arvore *arv);
no *insert_recursiva(arvore *arv, no *x, no *n);
int insert_iterativa(arvore *arv, no *x);
no *insert(arvore *arv, no *z);
no *remover_abb(arvore *t, no *z);
void PreOrdem(no *x);
void InOrdem(no *x);
void PosOrdem(no *x);
void destroyTree(arvore *arv, no *x);
no *raiz(arvore *arv);
no *minimo(no *x);
no *maximo(no *x );
no *sucessor(no *x);
no *predecessor(no *x);
int altura(no *n);
no *n_dir(no *n);
no *n_esq(no *n);
no *n_pai(no *n);
int num_arv(no *n);
void imprimeArvorePorNivel(no *raiz);

int isSimilar(no *root1, no* root2){
    // Check if both the trees are empty
    if (root1 == NULL && root2 == NULL)
        return 1;
    // If any one of the tree is non-empty
    // and other is empty, return false
    else if (root1 != NULL && root2 == NULL || (root1 == NULL && root2 != NULL))
        return 0;
    else { // Check if current data of both trees equal
        // and recursively check for left and right subtrees
        if (isSimilar(root1->esq, root2->esq) == 1 && isSimilar(root1->dir, root2->dir) == 1) return 1;
        else return 0;
    }
}
int main(){
    arvore *arv0 = create_tree();
    int vetor[11] = {15, 5, 18, 16, 25, 2, 1, 3, 7, 13, 9};
    for(int i = 0; i < 11; i++){
        insert(arv0, create_no(vetor[i]));
    }

    arvore *arv1 = create_tree();
    int vetor1[11] = {5, 16, 18, 16, 25, 2, 1, 3, 7, 13, 9};
    for(int i = 0; i < 11; i++){
        insert(arv1, create_no(vetor1[i]));
    }

    arvore *arv2 = create_tree();
    int vetor2[11] = {16, 6, 19, 17, 26, 3, 2, 4, 8, 14, 10};
    for(int i = 0; i < 11; i++){
        insert(arv2, create_no(vetor2[i]));
    }


    cout << "Arvore 0: " << endl;
    imprimeArvorePorNivel(arv0->raiz);
    cout << "Arvore 1: " << endl;
    imprimeArvorePorNivel(arv1->raiz);
    cout << "Arvore 2: " << endl;
    imprimeArvorePorNivel(arv2->raiz);

    cout << "Teste entre arvore 0 e arvore 1" << endl;
    if(isSimilar(arv0->raiz, arv1->raiz) == 1) cout <<"Foi" << endl;
    else cout << "Deu ruim" << endl;
    cout << "Teste entre arvore 0 e arvore 2" << endl;
    if(isSimilar(arv0->raiz, arv2->raiz) == 1) cout <<"Foi" << endl;
    else cout << "Deu ruim" << endl;

    return 0;
}

//Função para alocar espaço do arvore
arvore *create_tree(){
    arvore *arv = (arvore*)malloc(sizeof(arvore));
    arv->raiz = NULL;
    arv->tam = 0;
    return arv;
}

int num_arv(no *n){
    return n->num;
}

//Função para alocar espaço do no
no *create_no(int num){
    no *n = (no*)malloc(sizeof(no));
    n->num = num;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
}

// Função para verificar se arvore está vazia
int isEmpty(arvore *arv){
    if (arv->raiz == NULL) {       //Se estiver vazia retorna 1
        return 1;
    }
    else if(arv->raiz != NULL){    //Se houver elemento, retorna 0
        return 0;
    }
    return 0;
}

//Função para realizar busca na Arvore -> BigO(qntElementos)
//Entra com (arv->raiz, no *n)
no *search(no *x, no *n){
    if(x == NULL){
        return x;
    }
    if(x->num < n->num) {
        return search(x->dir, n);
    }
    else if(x->num > n->num) {
        return search(x->esq, n);
    }
    else
        return x;
}

no *insert_recursiva(arvore *arv, no *x, no *n){
    if(arv->raiz == NULL){
        arv->raiz = n;
        arv->tam++;
        return n;
    }
    else{
        if(x == NULL) {
            printf("Debug\n");
            arv->tam++;
            return n;
        }
        else{
            if(x->num > n->num) {
                x->esq = insert_recursiva(arv, x->esq, n);
            }
            else {
                x->dir = insert_recursiva(arv, x->dir, n);
            }
        }
    }
    return n;
}

//Função iterativa para inserir na ABB
//Se foi inserido corretamente, retorna 1, se já houver o elemento,
//retorna 0 e não insere
int insert_iterativa(arvore *arv, no *x){
    if(arv->raiz == NULL){
        arv->raiz = x;
        arv->tam++;
        return 1;
    }
    else{
        no *auxPai = arv->raiz, *aux = NULL;
        while (auxPai != NULL){
            if(auxPai->num > x->num){
                aux = auxPai->esq;
                if(aux == NULL){
                    auxPai->esq = x;
                    arv->tam++;
                    return 1;
                }
            }
            else if(auxPai->num < x->num){
                aux = auxPai->dir;
                if(aux == NULL){
                    auxPai->dir = x;
                    arv->tam++;
                    return 1;
                }
            }
            auxPai = aux;
        }
    }
    return 0;
}

//Tamanho da arvore
unsigned long int size(arvore *arv){
    return arv->tam;
}

no *insert(arvore *arv, no *z){
    no *y = NULL;
    no *x = arv->raiz;
    while(x != NULL){
        y = x;
        if(z->num < x->num) x = x->esq;
        else x = x->dir;
    }
    z->pai = y;
    if(y == NULL) arv->raiz = z;
    else if(z->num < y->num) y->esq = z;
    else y->dir = z;

    arv->tam++;
    return z;
}

void transplante(arvore *T, no *u, no *v){
    if(u->pai == NULL) T->raiz = v;
    else if(u == u->pai->esq) u->pai->esq = v;
    else u->pai->dir = v;

    if(v != NULL) v->pai = u->pai;
}

no *remover_abb(arvore *t, no *z){
    if(z->esq == NULL) transplante(t, z, z->dir);
    else if(z->dir == NULL)   transplante(t, z, z->esq);
    else{
        no *y = minimo(z->dir);
        if(y->pai != z){
            transplante(t, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplante(t, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
    }
    t->tam--;
    return z;
}

//raiz - esq - dir
void PreOrdem(no *x){
    if(x!=NULL){
        printf("%d ", x->num);
        PreOrdem(x->esq);
        PreOrdem(x->dir);
    }
}

//Imprime uma ABB em ordem crescente
//esq - raiz - dir
void InOrdem(no *x){
    if(x!=NULL){
        InOrdem(x->esq);
        printf("%d ", x->num);
        InOrdem(x->dir);
    }
}

//Pode ser utilizada para destruir a arvore
//esq - dir - raiz
void PosOrdem(no *x){
    if(x!=NULL){
        PosOrdem(x->esq);
        PosOrdem(x->dir);
        printf("%d ", x->num);
    }
}

//Utiliza a idea de varrer atraves de PosOrdem
void destroyTree(arvore *arv, no *x){
    if(x != NULL){
        destroyTree(arv, x->esq);
        destroyTree(arv, x->dir);
        free(x);
    }
    arv->raiz = NULL;
}

//Retorna um ponteiro para a raiz da arvore
no *raiz(arvore *arv){
    no *aux = arv->raiz;
    return aux;
}

no *minimo(no *x){
    while(x->esq != NULL){
        x = x->esq;
    }
    return x;
}

no *maximo(no *x){
    while(x->dir != NULL){
        x = x->dir;
    }
    return x;
}

no *sucessor(no *x){
    if(x->dir != NULL) return minimo(x->dir);
    no *y = x->pai;
    while(y != NULL && x == y->dir){
        x = y;
        y = x->pai;
    }
    return y;
}

no *predecessor(no *x){
    if(x->dir != NULL) return maximo(x->esq);

    no *y = x->pai;
    while(y != NULL && x == y->esq){
        x = y;
        y = x->pai;
    }
    return y;
}

int altura(no *n){
    int hDir, hEsq;

    if(n == NULL) return -1;
    hDir = altura(n->dir);
    hEsq = altura(n->esq);

    if(hDir > hEsq) return hDir+1;
    else return hEsq+1;
}

no *n_dir(no *n){
    return n->dir;
}

no *n_esq(no *n){
    return n->esq;
}

no *n_pai(no *n){
    return n->pai;
}

void imprimeArvorePorNivel(no *raiz){
    if (raiz == NULL) {
        cout << "A arvore está vazia" << endl;
    }
    else{
        queue<no*> fila;

        fila.push(raiz);

        while (fila.empty() == false){
            for(int i = fila.size(); i > 0; i--){
                // no *aux = fila.front();
                cout << fila.front()->num << " ";
                if (fila.front()->esq != NULL)
                    fila.push(fila.front()->esq);
                if (fila.front()->dir != NULL)
                    fila.push(fila.front()->dir);
                fila.pop();
            }
            cout << endl;
        }
    }
}
