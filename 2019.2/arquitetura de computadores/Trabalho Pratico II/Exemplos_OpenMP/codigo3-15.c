/********************************************************************
* Francisco Almeida, Domingo Giménez, José Miguel Mantas, Antonio M. Vidal:
* Introducción a la programación paralela,
* Paraninfo Cengage Learning, 2008
*
* Código 3.15 - Exemplo da diretiva parallel for
* Adaptado em 20/10/2014 - Marcos Barreto
* Para compilar: gcc -o <nomedoexecutavel> codigo3-15.c -fopenmp
*********************************************************************/
#include <stdio.h>
#include <omp.h>

#define N   10   // tamanho do vetor
#define M   10   // tamanho do vetor

int main (int argc, char **argv) 
{
    int i, j;
    int nthreads, tid;
    int n, m, sum;
    int a[M], c[N], b[M][N];
    // Inicializa b, c, m, n
    m=M;
    n=N;
    for(i=0;i<n;i++)
      c[i]=i;
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        b[i][j]=i+j;
    // As variáveis a, b, c, m, n, nthreads são compartilhadas
    // As variáveis i, j, sum, tid são privadas
    #pragma omp parallel for private(tid, i, j, sum) shared(m, n, a, b, c, nthreads)
    for (i = 0; i < m; i++) {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        sum = 0;
        for (j = 0; j < n; j++)
            sum += b[i][j] * c[j];
         a[i] = sum;
         printf("O thread %d, de %d threads, calcula a iteração i = %d\n", tid, nthreads, i); 
    }
return 0;
}
