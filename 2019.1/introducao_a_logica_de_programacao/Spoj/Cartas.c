#include <stdio.h>
int main (){

  int A;
  int B;
  int C;
  int D;
  int E;

  scanf("%d%d%d%d%d",&A,&B,&C,&D,&E);

  if(A<B && B<C && C<D && D<E){
   printf("C");}

  else if(A>B && B>C && C>D && D>E){
   printf("D");} 

  else{printf("N");}

return 0;
}

