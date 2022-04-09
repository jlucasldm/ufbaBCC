#include<stdio.h>
 int main(){
   int n;
   int l;
   int c;

   scanf("%d",&n);
   int i=0;
   int s=0;   

   while(i<n){
     scanf("%d%d",&l,&c);
     i ++;
      if(l>c){
     s+=c;}
    }
 
   printf("%d\n",s);

   return 0;
 
  }
