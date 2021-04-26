/********************************************************************
* Francisco Almeida, Domingo Giménez, José Miguel Mantas, Antonio M. Vidal:
* Introducción a la programación paralela,
* Paraninfo Cengage Learning, 2008
*
* Código 3.14 - Exemplo da diretiva section
* Adaptado em 20/10/2014 - Marcos Barreto
* Para compilar: gcc -o <nomedoexecutavel> codigo3-14.c -fopenmp
*********************************************************************/
#include <stdio.h>
#include <omp.h>

int main (int argc, char **argv) 
{
    int nthreads, tid;
    int A=10, B=20;
    // Variável tid é privada para cada thread 
    #pragma omp parallel private(tid)
    {
        #pragma omp sections  // cria seções paralelas de código
        {
            #pragma omp section  // seção 1 
            {
                tid = omp_get_thread_num();
                nthreads = omp_get_num_threads();
                printf("O thread %d, de %d threads, executa a seção 1\n", tid, nthreads); 
                printf("Soma: %d + %d = %d\n", A, B, A+B);
            }
            #pragma omp section  // seção 2
            {
                tid = omp_get_thread_num();
                nthreads = omp_get_num_threads();
                printf("O thread %d, de %d threads, calcula a seção 2\n", tid, nthreads); 
                printf("Subtracao: %d - %d = %d\n", A, B, A-B);
            }
            #pragma omp section  // seção 3
            {
                tid = omp_get_thread_num();
                nthreads = omp_get_num_threads();
                printf("O thread %d, de %d threads, calcula a seção 3\n", tid, nthreads); 
                printf("Multiplicacao: %d * %d = %d\n", A, B, A*B);
            }
            #pragma omp section  // seção 4
            {
                tid = omp_get_thread_num();
                nthreads = omp_get_num_threads();
                printf("O thread %d, de %d threads, calcula a seção 4\n", tid, nthreads); 
                printf("Divisao: %d / %d = %d\n", A, B, A/B);
            }
        }  // fim das seções
    }  // Sincronização implícita - todos os threads criados terminam e o thread principal segue sua execução

return 0;

}
