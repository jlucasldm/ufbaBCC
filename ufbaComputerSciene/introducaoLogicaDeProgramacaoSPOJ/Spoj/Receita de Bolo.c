#include<stdio.h>
int main(){

 int a;
 int b;
 int c;
 int ma;
 int mb;
 int mc;
 
 scanf("%d%d%d",&a,&b,&c);

 ma=a/2;
 mb=b/3;
 mc=c/5;

 if(ma<=mb && ma<=mc){
  printf("%d",ma);}

 else if(mc<=mb && mc<=ma){
  printf("%d",mc);}

 else if(mb<=ma && mb<=mc){
  printf("%d",mb);}


return 0;}
