#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>

#define NRA 620              /* number of rows in matrix A */
#define NCA 150                 /* number of columns in matrix A */
#define NCB 70                  /* number of columns in matrix B */

int i, j, k;
double a[NRA][NCA],           /* matrix A to be multiplied */
	   b[NCA][NCB],           /* matrix B to be multiplied */
       c[NRA][NCB];           /* result matrix C */

int preencheMatrizes() {
for (i=0; i<NRA; i++)
    for (j=0; j<NCA; j++)
      a[i][j]= i+j;

  for (i=0; i<NCA; i++)
    for (j=0; j<NCB; j++)
      b[i][j]= i*j;

  for (i=0; i<NRA; i++)
    for (j=0; j<NCB; j++)
      c[i][j]= 0;
}

int multiplicaMatrizes() {
  for (i=0; i<NRA; i++)    
    {
    for(j=0; j<NCB; j++)       
      for (k=0; k<NCA; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
}

int main (int argc, char *argv[]) 
{
struct timeval tv1, tv2, tv3, tv4;
double t1, t2, t3, t4;
       
gettimeofday(&tv3, NULL); /* processo pai continua ... */
t3 = (double)(tv3.tv_sec) + (double)(tv3.tv_usec)/ 1000000.00;
preencheMatrizes();
      
gettimeofday(&tv1, NULL); /* processo pai continua ... */
t1 = (double)(tv1.tv_sec) + (double)(tv1.tv_usec)/ 1000000.00;

multiplicaMatrizes();

gettimeofday(&tv2, NULL);
t2 = (double)(tv2.tv_sec) + (double)(tv2.tv_usec)/ 1000000.00;

/*** Print results ***/
printf("******************************************************\n");
printf("Result Matrix:\n");
for (i=0; i<NRA; i++)
  {
  for (j=0; j<NCB; j++) 
    printf("%6.2f   ", c[i][j]);
  printf("\n"); 
  }
printf("******************************************************\n");

      gettimeofday(&tv4, NULL);
t4 = (double)(tv4.tv_sec) + (double)(tv4.tv_usec)/ 1000000.00;

printf("\nO tempo de execucao mxm foi: %lf\n", (t2 - t1));
printf("\nO tempo total de execucao foi: %lf\n", (t4-t3));

printf ("Done.\n");
}
