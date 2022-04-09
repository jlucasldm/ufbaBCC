/********************************************************************
* Francisco Almeida, Domingo Giménez, José Miguel Mantas, Antonio M. Vidal:
* Introducción a la programación paralela,
* Paraninfo Cengage Learning, 2008
*
* Código 3.12 - Exemplo da diretiva parallel
* Adaptado em 20/10/2014 - Marcos Barreto
* Para compilar: gcc -o <nomedoexecutavel> codigo3-12.c -fopenmp
*********************************************************************/
#include <stdio.h>
#include <omp.h>

int main (int argc, char **argv)  
{
    int nthreads, tid;
    // Define a quantidade de threads a serem criados.
    printf("Configurando a quantidade de threads para 4\n");
    omp_set_num_threads(4);
    // Obtém a quantidade de threads criados
    nthreads = omp_get_num_threads();
    printf("Quantidade de threads criados = %d\n", nthreads);

    #pragma omp parallel private(tid)       // Cria um grupo de threads, cada um com suas variáveis privadas
    {
        tid = omp_get_thread_num(); // Obtém o identificador do thread
        printf("Sou o thread = %d\n", tid);
        if (tid == 0) { // Esta seção executa somente no thread mestre (tid 0)
            nthreads = omp_get_num_threads();
            printf("Quantidade de threads = %d\n", nthreads);
        }
    }  // Sincronização implícita - todos os threads criados terminam e o thread principal segue sua execução

    printf("Configurando a quantidade de threads para 3\n");
    omp_set_num_threads(3);
    nthreads = omp_get_num_threads();
    printf("Quantidade de threads criados = %d\n", nthreads);
    #pragma omp parallel
    {
        tid = omp_get_thread_num();
        printf("Sou o thread = %d\n", tid);
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Quantidade de threads = %d\n", nthreads);
        }
    }
return 0;
}
