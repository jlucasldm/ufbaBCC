#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
  
// inicializa a matriz passada como parametro (A) com um valor aleatorio
void inicializa_matrix(int *A, int n)
{
  int i,j;

  for (i=0; i < n; i++)
    for (j=0; j < n; j++)
       A[i*n+j] = rand()%(10-1)*1;
}

// imprime os valores da matriz passada como parametro (A)
void imprime_matrix(int *A, int n)
{
  int i,j;
   
  for (i=0; i < n; i++)
  {
    for (j=0; j < n; j++)
      printf("%d\t", A[i*n+j]);
    printf("\n");
  }
  printf("\n");
}

// funcao principal	
int main(int argc, char **argv)
{
  int n, i,j,k;

  printf("\nInforme o tamanho da matriz: ");
  scanf("%d",&n);
 
  // alocacao dinamica das matrizes	
  int *A = (int *) malloc (sizeof(int)*n*n);
  int *B = (int *) malloc (sizeof(int)*n*n);
  int *C = (int *) malloc (sizeof(int)*n*n);

  // Define a quantidade de threads a serem criados.
  printf("Configurando a quantidade de threads para 10\n");
  omp_set_num_threads(10);

  // chamada de funcao para inicializar as matrizes de entrada (A e B) 	
  inicializa_matrix(A,n);
  inicializa_matrix(B,n);

  // laço paralelo para multiplicar as matrizes A e B
  for(i = 0; i < n; i++)
    for( j = 0; j < n; j++)
      for( k = 0; k < n; k++)
         C[i*n+j]+=A[i*n+k]*B[k*n+j];

  // chamada de funcao para imprimir as matrizes
  imprime_matrix(A,n);
  imprime_matrix(B,n);
  imprime_matrix(C,n);
  return 0;
}	
  
