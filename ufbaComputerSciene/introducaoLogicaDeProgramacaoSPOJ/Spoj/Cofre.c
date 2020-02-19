#include<stdio.h>
int main(){
 int N; //Cada um depósito nos cofrinhos
 int T=1;
 int J;
 int Z;
 scanf("%d",&N);

 while(N!=0){
     int i=0;
     int j = 0;
     int z = 0;
     printf("Teste %d\n",T);
     while(i<N){
        scanf("%d%d",&J,&Z);
         j+=J;
         z+=Z;
         i++;
         printf("%d\n",j-z);
        }
    T++;
    printf("\n");
    scanf("%d", &N);
 }
 return 0;
}