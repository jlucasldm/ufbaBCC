#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int entrada, saida, rem, resul, valor, i=0, sum=0;
	int valorb,valoro, valorh;
	int v[100];
	int v1[100];
	scanf("%d", &entrada);
	if(entrada == 0){ //binary to decimal
		scanf("%d", &valor);
		while(valor>0){
			rem = valor % 10;
			sum = sum + rem * pow(2,i);
	    valor = valor/10;
	    i++;
	 	}
	 	valor = sum;
	}
	else if(entrada == 1){ //octal to decimal
		scanf("%d", &valor);
		sum=0;
		while(valor>0){
			rem = valor % 10;
			sum = sum + rem * pow(8,i);
	    valor = valor/10;
	    i++;
	 	}
	 	valor = sum;
	}
	else if(entrada == 2) //decimal
		scanf("%d", &valor);
	else if(entrada == 3) //hexadecimal to decimal
		scanf("%x", &valor);
		
	valorb = valor;
	valoro = valor;
	valorh = valor;
	printf("<"); //decimal to binary
	int count = 0;
	for(int i=0; ;i++){
		count++;
		if(valorb>=2 && valorb%2==0){
			v1[i] = 0;
			valorb = valorb/2;
		}
		else if(valorb>=2 && valorb%2!=0){
			v1[i] = 1;
			valorb = valorb/2;
		}
		else{
			v1[i] = 1;
			break;
		}
	}
	for(int i=(count-1);i>=0;i--){
		printf("%d", v1[i]);
	}
  printf(">\n"); //end of decimal to binary
  
  printf("<"); //decimal to octal
  count = 0;
	for(int i=0; ;i++){
		count++;
		if(valoro>=8 && valoro%8==0){
			v[i] = 0;
			valoro = valoro/8;
		}
		else if(valoro>=8 && valoro%8!=0){
			v[i] = valoro%8;
			valoro = valoro/8;
		}
		else{
			v[i] = valoro%8;
			break;
		}
	}
  for(int i=(count-1);i>=0;i--){
		printf("%d", v[i]);
	}
	printf(">\n"); //end of decimal to octal
	
  printf("<%x>\n", valor); //decimal to hexadecimal
}
