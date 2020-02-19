#include <stdio.h>
int main (){

  int N;

  scanf("%d",&N);

  if(N<=10){
   printf("7\n");}

  else if(11<=N && N<31){
   printf("%d\n",(N-10)*1+(7));}

  else if(31<=N && N<101){
   printf("%d\n",(N-30)*2+27);}
 
  else{
   printf("%d\n",(N-100)*5+167);}

return 0;
}
