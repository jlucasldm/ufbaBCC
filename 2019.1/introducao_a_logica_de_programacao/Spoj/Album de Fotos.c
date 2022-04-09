#include<stdio.h>
int main(){
 int x;
 int y;
 int l1;
 int h1;
 int l2;
 int h2;
 
 scanf("%d%d%d%d%d%d",&x,&y,&l1,&h1,&l2,&h2);

 if ((l1+l2<=x && h1<=y && h2<=y)
 || (h1+h2<=y && l1<=x && l2<=x)
 || (l1+l2<=y && h1<=x && h2<=x)
 || (h1+h2<=x && l1<=y && l2<=y)
 || (l1+h2<=x && h1<=y && l2<=y)
 || (l1+h2<=y && h1<=x && l2<=x)
 || (l2+h1<=y && l1<=x && h2<=x)
 || (l2+h1<=x && l1<=y && h2<=y)){
   printf("S");}
   
 else{printf("N");}

return 0;}
