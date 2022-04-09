#include <stdio.h>
int main (){

  int A;
  int B;
  int C;
  
  scanf("%d %d %d",&A, &B, &C);
  
  if ((A>B && B>C) || (C>B && B>A)){
  printf("%d\n",B);}

  if ((B>C && C>A) || (A>C && C>B)){
  printf("%d\n",C);}

  if ((C>A && A>B) || (B>A && A>C)){
  printf("%d\n",A);}

return 0;
}
