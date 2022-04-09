#include<stdio.h>
int main(){

 int n;
 int c;
 int s;
 int e;
 int t;
 char saida;
 
 scanf("%d%d",&n,&c);
 
 saida='N';
 
 int i= 0;
 t= 0;
 while(i<n){
   scanf("%d%d",&s,&e);
   t+=e-s;
    if(t>c){
     saida='S';}
   i++;}

 printf("%c",saida);

return 0;}
