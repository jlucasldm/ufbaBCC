#include<stdio.h>
#include<stdlib.h>

int binDec(int a){
	int dec = 0;	
	for(int i = 0, a != 0, i++){
		if(a%10 == 1){
			dec+=1*pow(2, i);
			a-1;		
		}
		a/=10;	
	}
	return dec;
}

int ocDec(int a){
	int dec = 0;
	int resto;	
	for(int i = 0, a != 0, i++){
			resto = a%10;			
			dec+=resto*pow(2, i);
			a-resto;		
		}
		a/=10;	
	}
	return dec;
}


int main(){
	int base;
	int numero;

	scanf("%d", &base);
	scanf("%d", &numero);

	if(base = 0){
		
	
	}else if(base = 1){

	}else if(base = 2){

	}else{

	}
	
}
