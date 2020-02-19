/********************************************************************
* Francisco Almeida, Domingo Giménez, José Miguel Mantas, Antonio M. Vidal:
* Introducción a la programación paralela,
* Paraninfo Cengage Learning, 2008
*
* Código 3.11 - Programa "Olá Mundo" em OpenMP
* Adaptado em 20/10/2014 - Marcos Barreto
* Para compilar: gcc -o <nomedoexecutavel> codigo3-11.c -fopenmp
*********************************************************************/
#include <stdio.h>
#include <omp.h>   // Inclusão da biblioteca OpenMP

int main (int argc, char **argv)  
{
    int nthreads, tid;
    
    #pragma omp parallel private(tid)      // Cria um grupo de threads, cada um com suas próprias variáveis privadas
    {					   // Quantidade de threads = número de processadores (cores)
        tid = omp_get_thread_num();        // Obtém o identificador do thread 
        nthreads = omp_get_num_threads();  // Obtém a quantidade de threads criadas 
        printf("Olá mundo! Sou o thread %d de %d threads criados\n", tid, nthreads);
    }                                      // Sincronização implícita - todos os threads criados terminam e o thread principal segue sua execução

    printf("\nSeguindo com a execução do thread principal....");
    printf("\n%d nthreads foram executadas neste programa. Terminando agora...\n", nthreads);	
    return 0;
}
