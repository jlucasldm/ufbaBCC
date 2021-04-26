//João Lucas Lima de Melo
#include<stdio.h>
#include<stdlib.h>

//Função que converte um inteiro "a" em base binária em um número decimal
int binDec(int a){
	int dec = 0;
	int pot = 1;	
	for(int i = 0; a != 0; i++){
		if(a%10 == 1){
			dec+=pot;
			a-1;		
		}
		pot*=2;
		a/=10;	
	}
	return dec;
}

//Função que converte um inteiro "a" em base octal em um número decimal
int ocDec(int a){
	int dec = 0;
	int pot = 1;
	int resto;	
	for(int i = 0; a != 0; i++){
		resto = a%10;
		dec+=resto*pot;
		a-resto;
		a/=10;
		pot*=8;		
	}	
	return dec;
}

//Função que converte um inteiro "a" em base decimal em um número octal
int decOc(int a){
	int dec = 0;
	int pot = 1;
	int resto;	
	for(int i = 0; a != 0; i++){
		resto = a%8;
		if(resto!=0){
			dec+=resto*pot;
		}
		pot*=10;	
		a=(a-resto)/8;
	}	
	return dec;
}

//Função que converte um inteiro "a" em base decimal em um número binário
int decBin(int a){
	int dec = 0;
	int pot = 1;
	int resto;	
	for(int i = 0; a != 0; i++){
		resto = a%2;
		if(resto!=0){
			dec+=resto*pot;
		}
		pot*=10;	
		a=(a-resto)/2;
	}	
	return dec;
}


int main(){
	int base;
	int numero;
	int binario;
	int octal;
	int decimal;

	/*
	Selecionar a base do numero a ser avaliado
	0::binário
	1::octal
	2::decimal
	3::hexadecimal
	*/

	scanf("%d", &base);

	if(base == 0){
		scanf("%d", &numero);			//entrada do número	binario
		binario = numero;
		octal = decOc(binDec(numero));	//transformação em octal
		decimal = binDec(numero);		//transformação em decimal
	}else if(base == 1){
		scanf("%d", &numero);			//entrada do número	octal
		binario = decBin(ocDec(numero));//transformação em binario
		octal = numero;
		decimal = ocDec(numero);		//transformação em decimal
	}else if(base == 2){
		scanf("%d", &numero);			//entrada do número	decimal
		binario = decBin(numero);		//transformação em binario
		octal = decOc(numero);			//transformação em octal
		decimal = numero;
	}else if(base == 3){
		scanf("%x", &numero);			//entrada do número hexadecimal
		binario = decBin(numero);		//transformação em binario
		octal = decOc(numero);			//transformação em octal
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
	
	return 0;
}