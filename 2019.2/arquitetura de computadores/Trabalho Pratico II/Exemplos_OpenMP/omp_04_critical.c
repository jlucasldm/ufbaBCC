#include <omp.h>
#include <stdio.h>

main() 
{
  int x, tid;
 
  x = 0;

 omp_set_num_threads(20);  // number of threads to be created
 
 #pragma omp parallel shared(x) 
 {
   /* Obtain thread number */
   tid = omp_get_thread_num();
   printf("I'm thread= %d\n", tid);

   #pragma omp critical   // primitiva para garantir acesso sequencial à variável x
   printf("X antes: %d\n", x);   
   x = x + 1;
   printf("X depois: %d\n", x);
 }  /* end of parallel section */
}
