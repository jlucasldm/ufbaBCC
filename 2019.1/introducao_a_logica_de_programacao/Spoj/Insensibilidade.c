#include<stdio.h>
 int main(){
   int N;
   int X1;
   int Y1;
   int X2;
   int Y2;

   scanf("%d",&N);
   int i=0;
   int s=0;   

   while(i<N){
     scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
     i ++;
     s+=(X2-X1)*(X2-X1)+(Y2-Y1)*(Y2-Y1);}
 
   printf("%d\n",s);

   return 0;
 
  }
