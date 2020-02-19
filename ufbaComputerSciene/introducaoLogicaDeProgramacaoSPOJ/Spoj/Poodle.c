#include<stdio.h>
int main(){
 int N,P;
 scanf("%d %d",&N,&P);
 while(N!=0 && P!=0){
     if(N%P!=0){
      int x =(N/P)+1-6;
      if((N/P)+1<=6){
      printf("Poodle\n");
      }
     
      else if((N/P)+1>=20){
         printf("Poooooooooooooooodle\n");
      }

      else{
         printf("Po");
         int i=0;
         while(i<=x){
             printf("o");
             i++;
         }
         printf("dle\n");
      }
     }
     if(N%P==0){
         int x = (N / P) - 6;
         if ((N / P) <= 6)
         {
             printf("Poodle\n");
         }

         else if ((N / P) >= 20)
         {
             printf("Poooooooooooooooodle\n");
         }

         else
         {
             printf("Po");
             int i = 0;
             while (i <= x)
         {
             printf("o");
             i++;
             }
         printf("dle\n");
         }
     }
     scanf("%d%d",&N,&P);
 }
return 0;
}