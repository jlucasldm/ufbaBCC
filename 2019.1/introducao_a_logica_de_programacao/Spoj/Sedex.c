#include <stdio.h>
int main(){
 
int N,A,L,P;
scanf("%d%d%d%d", &N, &A, &L, &P);

if (N<=A && N<=L && N<=P){
printf("S\n");}

else{
printf("N\n");}

return 0;

}
