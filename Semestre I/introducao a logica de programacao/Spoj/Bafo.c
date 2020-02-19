#include <stdio.h>
int main(){
int R;
int a=0;
int b=0;
int T=0;

scanf("%d",&R); 
while(R!=0){
int A=0;
int B=0;
 for(int l=0;l<R;l++){
  scanf("%d",&a);
  scanf("%d",&b);
  A+=a;
  B+=b;
}
 T++;
 if(A>B){
  printf("Teste ");
  printf("%d",T);
  printf("\nAldo\n\n");}
 if(B>A){
  printf("Teste ");
  printf("%d",T);
  printf("\nBeto\n\n");}

 scanf("%d",&R);
} 
return 0;
}