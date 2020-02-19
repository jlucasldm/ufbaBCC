#include <omp.h>   
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>

int main (int argc, char *argv[]) {

int nthreads, tid, ttid;
struct timeval tv1, tv2;
double t1, t2;

// numero de threads a serem criados
omp_set_num_threads(1000);  
// recupera o tempo inicial - antes do bloco paralelo
gettimeofday(&tv1, NULL);   
t1 = (double)(tv1.tv_sec) + (double)(tv1.tv_usec)/ 1000000.00;
// cria os threads, cada um com 2 variaveis privadas (nthreads, tid)
#pragma omp parallel private(nthreads, tid)
  {
  // cada thread recupera o seu numero (identificador)
  tid = omp_get_thread_num();
  printf("Hello World from thread = %d\n", tid);
  // somente o thread principal (tid=0) executa o comando abaixo
  if (tid == 0) 
    {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }
  }  // todos os threads sao sincronizados e finalizados neste ponto => barreira implicita!

// recupera o tempo final - apos a execucao do bloco paralelo
gettimeofday(&tv2, NULL);
t2 = (double)(tv2.tv_sec) + (double)(tv2.tv_usec)/ 1000000.00;
// calcula e imprime o tempo total de execucao
printf("\nO tempo de execucao foi: %lf\n", (t2 - t1));

}




