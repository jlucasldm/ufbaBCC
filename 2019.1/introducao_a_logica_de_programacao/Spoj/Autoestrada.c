#include<stdio.h>
int main(){
int c;
scanf("%d",&c);
char estradas[c];
char v[c];
int soma=0;
 
 
for(int i=0; i<=c; i++){
scanf("%c",&estradas[i]);
 }
 
for(int i=0; i<=c; i++){
	estradas[i];
	if(estradas[i] == 'D'){
		soma += 0;}
	if(estradas[i] == 'A'){
		soma += 1;}
	if(estradas[i] == 'C'){
		soma += 2;}
	if(estradas[i] == 'P'){
		soma += 2;}
	
}
 
printf("%d\n",soma);
return 0;
} 