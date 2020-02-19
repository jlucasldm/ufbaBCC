#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fila.h"
// #include "lista.h"

int main(){
    fila *f = create_f(6*6);
    unsigned long int cpf, cpft;
    long int valor;
    char op;
    scanf("%lu %lu %c %ld", &cpf, &cpft, &op, &valor);


    // Imprime os valores no topo da pilha, como os nós foram apenas criados mas não
    // foi feito push, dará falha de segmentação, afinal, os nós não foram ligados
    // a pilha ainda
    // //printf("%d %d %d %c \n",p->topo->cpf,p->topo->cpft,p->topo->valor,p->topo->op);


    // printf("Vazia: %d \n",isEmpty_l(l));  //Verifica se a pilha está vazia

    //Um ponteiro para cada cliente receber o retorno da função create_n
    no *cliente0 = create_n(cpf+1, cpft+1, op, valor);
    no *cliente1 = create_n(cpf+2, cpft+2, op, valor+1);
    no *cliente2 = create_n(cpf+3, cpft+3, op, valor+2);
    no *cliente3 = create_n(cpf+4, cpft+4, op, valor+3);
    no *cliente4 = create_n(cpf+5, cpft+5, op, valor+4);
    no *cliente5 = create_n(cpf+6, cpft+6, op, valor+5);

    //Cria dois ponteiros auxiliares para facilitar o push e o printf
    no *ax0 = cliente0;
    no *ax1 = cliente1;
    no *ax2 = cliente2;
    no *ax3 = cliente3;
    no *ax4 = cliente4;
    no *ax5 = cliente5;

    //Empilha os nós de cada cliente imprime para testar
    push_f(f, ax4);
    push_f(f, ax2);
    push_f(f, ax0);
    push_f(f, ax5);
    push_f(f, ax1);
    push_f(f, ax3);

    // no *aux = lPrimeiro(l);
    // unsigned long int x = cpf_l(prox_l(aux));
    // printf("Teste: %ld\n", x);

    while(isEmpty_f(f) == 0){
        no *aux = front_f(f);
        unsigned long int x = cpf_f(aux);
        unsigned long int y = cpft_f(aux);
        char o = op_f(aux);
        long int v = valor_f(aux);

        printf("Cpf: %lu Cpft: %lu Op: %c Valor: %ld\n", x, y, o, v);
        pop_f(f);
        // if(isEmpty_l(l) == 1) break;
    }
    // printf("debug\n");

    //Verificando se a função pop_p está retornando corretamente
    // no *a = pop_l(l, ax2);
    // printf("%p\n", (void*)a);

    // printf("Vazia: %d\n",isEmpty_l(l)); //Imprime 0 pois a foram feitos 2 push e 1 pop

    // destroy_l(l);     //Destrói toda a pilha e seus dados

    return 0;
}
