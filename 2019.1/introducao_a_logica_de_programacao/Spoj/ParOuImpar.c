#include<stdio.h>
int main(){
int n;
scanf("%d",&n);
char nome1[10];
char nome2[10];
int resultado[n];
int mao1;
int mao2;
int t=1;
while(n!=0){
 
for(int i=0; i<n; i++){
 resultado[i]=0;}
scanf("%s",nome1);
scanf("%s",nome2);
for(int i=0; i<n; i++){
  scanf("%d%d",&mao1,&mao2);
	if((mao1+mao2)%2 == 0){
	resultado[i]+=1;}
	else if((mao1+mao2)%2 != 0){
        resultado[i]+=2;}
}
 
printf("Teste %d\n",t);
for(int i=0; i<n; i++){
  resultado[i];
	if(resultado[i]==1){
	printf("%s\n",nome1);}
	if(resultado[i]==2){
	printf("%s\n",nome2);}
	
}
 
printf("\n");
t++;
scanf("%d",&n);}
return 0;
}