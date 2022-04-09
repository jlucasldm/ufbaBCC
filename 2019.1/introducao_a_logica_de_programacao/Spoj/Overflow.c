#include <stdio.h>
int main (){

  int N;
  int P;
  char C;
  int Q;

  scanf("%d\n",&N);
  scanf("%d %c %d",&P,&C,&Q);

  if((C=='+' && P+Q<=N) || (C=='*' && P*Q<=N)){
   printf("OK\n");}

  if((C=='+' && P+Q>N) || (C=='*' && P*Q>N)){
   printf("OVERFLOW\n");}

return 0;
}
