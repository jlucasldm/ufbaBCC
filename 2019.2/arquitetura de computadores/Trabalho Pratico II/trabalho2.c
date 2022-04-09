#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>

#define QTDE_LINHAS_MATRIZ 2000
#define QTDE_COLUNAS_MATRIZ 80
#define TAM_VETOR 80

// Ax = b
int matriz_A[QTDE_LINHAS_MATRIZ][QTDE_COLUNAS_MATRIZ]; // nao precisa ser matriz quadrada
int vetor_x[TAM_VETOR];  // tamanho do vetor x (unknowns) deve ser igual ao numero de colunas da matriz A
int vetor_b[QTDE_LINHAS_MATRIZ]; // vetor resultado (B) deve ter o mesmo numero de linha da matriz A

// funcao para gerar a matriz e o vetor
// matriz pode ser lida de arquivo, em formato CSR
int geraDados() {
  int i,j;

  //srandom(25);
  // gera matriz_A
  //matriz_A[0][0] = 3; matriz_A[0][1] = 2; matriz_A[0][2] = 1;
  //matriz_A[1][0] = 4; matriz_A[1][1] = 5; matriz_A[1][2] = 3;

  for (i=0; i<QTDE_LINHAS_MATRIZ; i++)
    for (j=0; j<QTDE_COLUNAS_MATRIZ; j++)
      matriz_A[i][j] = random();

  // gera vetor_x
  //vetor_x[0] = 1; vetor_x[1] = 2; vetor_x[2] = 3;
  for (i=0; i<TAM_VETOR; i++) vetor_x[i] = i+2;

  // inicializa vetor_b
  for (i=0; i<QTDE_LINHAS_MATRIZ; i++) vetor_b[i] = 0;
  return 0;
}

// multiplicacao sequencial do vetor pela matriz
// TO DO: implementar a funcao Ax=b e coletar o tempo sequencial
int matvecSequencial() {
  int i, j;
  int matriz_temp[QTDE_LINHAS_MATRIZ][QTDE_COLUNAS_MATRIZ]; // matriz temporaria
  struct timeval tv1, tv2;
  double t1, t2;

  printf("\nExecutando matvecSequencial...\n");
  // recupera o tempo inicial
  gettimeofday(&tv1, NULL);
  t1 = (double)(tv1.tv_sec) + (double)(tv1.tv_usec)/ 1000000.00;

  for (j=0; j<QTDE_COLUNAS_MATRIZ; j++)  // percorre a matriz_A coluna por coluna
    for (i=0; i<QTDE_LINHAS_MATRIZ; i++) {
      // matriz_temp armazena cada entrada de A * cada elemento de X
      matriz_temp[i][j] = matriz_A[i][j] * vetor_x[j];
    }
  // gera o vetor de resultado B
  for (i=0; i<QTDE_LINHAS_MATRIZ; i++)  // percorre a matriz_temp linha a linha
    for (j=0; j<QTDE_COLUNAS_MATRIZ; j++) {
    // vetor_b = somatorio dos elementos da linha da matriz_temp
    vetor_b[i] += matriz_temp[i][j];
    }
    // recupera o tempo final
    gettimeofday(&tv2, NULL);
    t2 = (double)(tv2.tv_sec) + (double)(tv2.tv_usec)/ 1000000.00;  // debug - verifica o resultado
    // calcula e imprime o tempo total de execucao
    printf("\nO tempo de execucao sequencial foi: %lf\n", (t2 - t1));

  // for (i=0; i<QTDE_LINHAS_MATRIZ; i++) printf("%d\n", vetor_b[i]);
  return 0;
}

// multiplicacao paralela (OpenMP) do vetor pela matriz
// TO DO: implementar a funcao Ax=b e coletar o tempo paralelo OpenMP
int matvecHost() {
  int tid;  // thread ID
  int i, j;  // indices para matriz e vetores
  int matriz_temp[QTDE_LINHAS_MATRIZ][QTDE_COLUNAS_MATRIZ]; // matriz temporaria
  struct timeval tv1, tv2;
  double t1, t2;

  printf("\nExecutando matvecHost...\n");
  // inicializa vetor_b
  for (i=0; i<QTDE_LINHAS_MATRIZ; i++) vetor_b[i] = 0;

  // recupera o tempo inicial
  gettimeofday(&tv1, NULL);
  t1 = (double)(tv1.tv_sec) + (double)(tv1.tv_usec)/ 1000000.00;
  // numero de threads igual a quantidade de colunas da matriz_A
  omp_set_num_threads(QTDE_COLUNAS_MATRIZ);

#pragma omp parallel private(tid,i,j) shared(matriz_A, vetor_b, vetor_x, matriz_temp)
{
  tid = omp_get_thread_num();  // recupera o ID da thread
  for (i=0; i<QTDE_LINHAS_MATRIZ; i++) {
    // printf("Thread %d calculando [linha,coluna] [%d,%d]\n", tid,i,tid);
    // matriz_temp armazena cada entrada de A * cada elemento de X
    matriz_temp[i][tid] = matriz_A[i][tid] * vetor_x[tid];
  }
  // gera o vetor de resultado B
  for (j=0; j<QTDE_COLUNAS_MATRIZ; j++) {  // percorre a matriz_temp linha a linha
    // vetor_b = somatorio dos elementos da linha da matriz_temp
    vetor_b[tid] += matriz_temp[tid][j];
  }
}  // fim do bloco paralelo

// recupera o tempo final
gettimeofday(&tv2, NULL);
t2 = (double)(tv2.tv_sec) + (double)(tv2.tv_usec)/ 1000000.00;  // debug - verifica o resultado
// calcula e imprime o tempo total de execucao
printf("\nO tempo de execucao OpenMP foi: %lf\n", (t2 - t1));

// imprime matriz_temp
// for (i=0; i<QTDE_LINHAS_MATRIZ; i++)
//   for (j=0; j<QTDE_COLUNAS_MATRIZ; j++)
  //    printf("Matriz_temp[%d][%d]=%d\n", i,j,matriz_temp[i][j]);

// debug - verifica o resultado
// for (i=0; i<QTDE_LINHAS_MATRIZ; i++) printf("%d\n", vetor_b[i]);
  return 0;
}

// multiplicacao paralela (CUDA) do vetor pela matriz
// TO DO: implementar a funcao Ax=b e coletar o tempo paralelo CUDA
int matvecDevice() {
  printf("matvecDevice\n");
  return 0;
}


int main(int argc, char * argv[]) {
  int op_exec = atoi(argv[1]);
  // programa deve gerar os dados
  geraDados();
  // programa deve realizar a multiplicacao sequencial e capturar tempo
  matvecSequencial();
  // programa deve testar parametro da linha de comando (1 – CPU e 2 – GPU)
  if (op_exec == 1) matvecHost();
  else if (op_exec == 2) matvecDevice();
  //
  return 0;
}
