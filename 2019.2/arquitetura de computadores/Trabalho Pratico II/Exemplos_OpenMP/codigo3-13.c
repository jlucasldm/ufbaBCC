/********************************************************************
* Francisco Almeida, Domingo Giménez, José Miguel Mantas, Antonio M. Vidal:
* Introducción a la programación paralela,
* Paraninfo Cengage Learning, 2008
*
* Código 3.13 - Exemplo da diretiva for
* Adaptado em 20/10/2014 - Marcos Barreto
* Para compilar: gcc -o <nomedoexecutavel> codigo3-13.c -fopenmp
*********************************************************************/
#include <stdio.h>
#include <omp.h>

#define CHUNKSIZE 10  // tamanho do bloco de dados do vetor para cada thread
#define N    100      // tamanho dos vetores

int main (int argc, char **argv) 
{
    int i, chunk;
    int nthreads, tid;
    int a[N], b[N], c[N];

    // inicialização dos vetores
    for (i = 0; i < N; i++)
        a[i] = b[i] = i * 1.0;

    // divide o tamanho dos vetores (N) em pedaços (chunk) iguais 
    chunk = CHUNKSIZE;

    // bloco para criação de threads e execução paralela
    // quantidade de threads = quantidade de processadores disponíveis no hardware
    // as variáveis a, b, c, chunk são compartilhadas entre as threads
    // as variáveis i, tid  são privadas para cada thread 
    #pragma omp parallel shared(a, b, c, chunk) private(i, tid)
    {
        // schedule static = associa um pedaço (chunk) de dados para cada thread criado, de forma circular
        #pragma omp for schedule(static, chunk)
        for (i = 0; i < N; i++) {
            // recupera o identificador do thread 
            tid = omp_get_thread_num();
	    // recupera a quantidade de threads criadas
            nthreads = omp_get_num_threads();
            // thread calcula a soma de vetores
            c[i] = a[i] + b[i];
            printf("O thread %d, de %d threads criados, calcula a iteração i =%d\n", tid, nthreads, i); 
        }
    }  // Sincronização implícita - todos os threads criados terminam e o thread principal segue sua execução

    return 0;
}
