#include <iostream>
#include <stack>
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

// An iterative function to do postorder traversal of a given binary tree
void iterativePostorder(no* root) {
    // Check for empty tree
    if (root == NULL) return;
    stack<no*> stack;

    do{
        // Vai para o no mais para a esquerda
		// cout << "Debug" << endl;
        while (root != NULL){
			// Push o nó a direita da raiz e depois a raiz para a fila
            if (root->dir)
				stack.push(root->dir);
			stack.push(root);

            // Raiz agora é a raiz->esq
            root = root->esq;
        }

        // Tira o nó da pilha e coloca-o como raiz
		root = stack.top();
		stack.pop();

		//Se o nó retirado tem um filho a direito e a
        // If the popped item has a dir child and the dir child is not
        // processed yet, then make sure dir child is processed before root
        if (!stack.empty() && root->dir == root->dir && stack.top() == root->dir){
            stack.pop();  // remove dir child from stack
            stack.push(root);  // push root back to stack
            root = root->dir; // change root so that the dir child is processed next
        }
        else{ // Else print root's data and set root as NULL
			cout << root->num << " ";
            root = NULL;
        }
    }while (!stack.empty());
    cout << "\n";
}
// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(no* root){
    // Base Case
    if (root == NULL) return;

    // Create an empty stack and push root to it
    stack<no *> stack;
    stack.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its dir child
       c) push its 'esq' child
    Note that dir child is pushed first so that esq is processed first */
    while (stack.empty() == false){
        // Pop the top item from stack and print it
        struct no *no = stack.top();
        printf ("%d ", no->num);
        stack.pop();

        // Push dir and esq children of the popped no to stack
        if (no->dir)
            stack.push(no->dir);
        if (no->esq)
            stack.push(no->esq);
    }
}

// Driver program to test above functions
int main(){
    arvore *arv = create_tree();
    int vetor[11] = {15, 5, 18, 16, 25, 2, 1, 3, 7, 13, 9};

    no *a0 = create_no(vetor[0]);
    no *a1 = create_no(vetor[1]);
    no *a2 = create_no(vetor[2]);
    no *a3 = create_no(vetor[3]);
    no *a4 = create_no(vetor[4]);
    no *a5 = create_no(vetor[5]);
    no *a6 = create_no(vetor[6]);
    no *a7 = create_no(vetor[7]);
    no *a8 = create_no(vetor[8]);
    no *a9 = create_no(vetor[9]);
    no *a10 = create_no(vetor[10]);

    insert(arv, a0);
    insert(arv, a1);
    insert(arv, a2);
    insert(arv, a3);
    insert(arv, a4);
    insert(arv, a5);
    insert(arv, a6);
    insert(arv, a7);
    insert(arv, a8);
    insert(arv, a9);
    insert(arv, a10);
	cout << "PreOrder: ";
    iterativePreorder(arv->raiz);
	cout << endl << "PostOrder: ";
	iterativePostorder(arv->raiz);

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