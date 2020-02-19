#include <omp.h>   
#include <stdio.h>
#include <stdlib.h>

int vet[1000];

int Calcular (int a)
{
  printf(" -- Valor do vetor: %d\n", vet[a]);
}

int main (int argc, char *argv[]) {
   int i;
   for (i = 0; i <1000; i++)  
      vet[i] = (double) i;

   #pragma omp parallel for
   for (i = 0; i <1000; i++)
   {
     printf("Id: %d", i);
     Calcular(vet[i]);
   }
}



