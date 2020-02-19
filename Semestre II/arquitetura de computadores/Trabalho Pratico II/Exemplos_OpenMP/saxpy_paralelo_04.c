// Exemplo: SAXPY - sequencial
// Adaptado de Structured Parallel Programming - Michael McCool et al.
// Data: 12/10/2014
// Autor: Marcos Barreto

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>
#include <omp.h>   

#define N 1000  // tamanho dos vetores
#define QT 20   // quantidade de threads a serem criados
#define CHUNKSIZE 100 // tamanho do bloco de dados

float X[N], Y[N];  // vetores
int   i, sa;	   // simple scalar - valor a ser multiplicado pelos vetores

int inicializaVetores()
{
  for (i=0; i<N; i++)
    X[i] = Y[i] = i * 1.0; 
  return 0;
}

int main (int argc, char *argv[]) 
{
  int nthreads, tid, chunk; // variaveis para os threads
  struct timeval tv1, tv2;  // variaveis para a medicao de tempo
  double t1, t2;            // variaveis para a medicao de tempo

  inicializaVetores();      // inicializa os vetores
  // configura a quantidade de threads a serem criados
  omp_set_num_threads(QT);
  // configura o tamanho do bloco de dados para cada thread
  chunk = CHUNKSIZE;
  // recupera o tempo inicial - antes do bloco paralelo
  gettimeofday(&tv1, NULL);   
  t1 = (double)(tv1.tv_sec) + (double)(tv1.tv_usec)/ 1000000.00;
  // laco PARALELO para calculo com os vetores - sapxy
  // cria QT threads, cada um com seu tid privado
#pragma omp parallel shared(X, Y, sa, chunk) private(i, tid)
{
  // paralelizacao do laco
  #pragma omp for schedule(dynamic,chunk)
  for (i=0; i<N; i++)
  {
     Y[i] = sa * X[i] + Y[i];
  } 
} // BARREIRA - sincroniza todos os threads 
  // recupera o tempo final - apos a execucao do bloco paralelo
  gettimeofday(&tv2, NULL);
  t2 = (double)(tv2.tv_sec) + (double)(tv2.tv_usec)/ 1000000.00;
  // calcula e imprime o tempo total de execucao
  printf("\nO tempo de execucao foi: %lf\n", (t2 - t1));
  return 0;
}




