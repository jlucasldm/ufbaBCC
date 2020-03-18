#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int binDec(int a){
	int dec = 0;	
	for(int i = 0; a != 0; i++){
		if(a%10 == 1){
			dec+=pow(2,i);
			a-1;		
		}
		a/=10;	
	}
	return dec;
} 							//ok

int ocDec(int a){
	int dec = 0;
	int resto;	
	for(int i = 0; a != 0; i++){
		resto = a%10;
		dec+=resto*pow(8, i);
		a-resto;
		a/=10;		
	}	
	return dec;
}							//ok


int decOc(int a){
	int dec = 0;
	int resto;	
	for(int i = 0; a != 0; i++){
		resto = a%8;
		if(resto!=0){
			dec+=resto*pow(10, i);
		}	
		a=(a-resto)/8;
	}	
	return dec;
}							//ok

int decBin(int a){
	int dec = 0;
	int resto;	
	for(int i = 0; a != 0; i++){
		resto = a%2;
		if(resto!=0){
			dec+=resto*pow(10, i);
		}	
		a=(a-resto)/2;
	}	
	return dec;
}							//ok

int main(){
	int base;
	int numero;
	int binario;
	int octal;
	int decimal;

	printf("Selecione a base do numero a ser avaliado:\n0::binário\n1::octal\n2::decimal\n3::hexadecimal\n");
	scanf("%d", &base);

	printf("Digite o numero a ser avaliado:\n");

	if(base == 0){
		scanf("%d", &numero);
		binario = numero;
		octal = decOc(binDec(numero));
		decimal = binDec(numero);
	}else if(base == 1){
		scanf("%d", &numero);
		binario = decBin(ocDec(numero));
		octal = numero;
		decimal = ocDec(numero);
	}else if(base == 2){
		scanf("%d", &numero);
		binario = decBin(numero);
		octal = decOc(numero);
		decimal = numero;
	}else if(base == 3){
		scanf("%x", &numero);
		binario = decBin(numero);
		octal = decOc(numero);
		decimal = numero;
	}
	
	if(base == 0){
		printf("octal::<%d>\n", octal);
		printf("decimal::<%d>\n", decimal);
		printf("hexadecimal::<%x>\n", decimal);
	}else if(base == 1){
		printf("binario::<%d>\n", binario);
		printf("decimal::<%d>\n", decimal);
		printf("hexadecimal::<%x>\n", decimal);
	}else if(base == 2){
		printf("binario::<%d>\n", binario);
		printf("octal::<%d>\n", octal);
		printf("hexadecimal::<%x>\n", decimal);
	}else if(base == 3){
		printf("binario::<%d>\n", binario);
		printf("octal::<%d>\n", octal);
		printf("decimal::<%d>\n", decimal);
	}
	
}