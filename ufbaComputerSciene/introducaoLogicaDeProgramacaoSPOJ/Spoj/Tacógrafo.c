#include<stdio.h>
 int main(){
   int n;
   int t;
   int v;

   scanf("%d",&n);
   int i=0;
   int s=0;   

   while(i<n){
     scanf("%d%d",&t,&v);
     s+=t*v;
     i++;}
 
   printf("%d\n",s);

   return 0;
 
  }
