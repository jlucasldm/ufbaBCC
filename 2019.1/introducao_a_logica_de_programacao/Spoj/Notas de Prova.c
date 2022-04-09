#include <stdio.h>
int main(){
 
int a;
scanf("%d", &a);

if (a==0){
printf("E");}

else if (a<36){
printf("D");}

else if (a<61){
printf("C");}

else if (a<86){
printf("B");}

else{
printf("A");}

printf("\n");

return 0;

}
