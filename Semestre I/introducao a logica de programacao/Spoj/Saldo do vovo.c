#include<stdio.h>
 int main(){
   int n; //numero de dias
   int s; //saldo inicial

   scanf("%d%d",&n,&s);
   int i=0;
   int m;//movimentação
   int menor=s;//claramente, o menor valor
  
   while(i<n){
     scanf("%d",&m);
       if((s+m)<menor){
         menor = s+m;}
     s+=m;
     i++;}
 
   printf("%d\n",menor);

   return 0;
 
  }
