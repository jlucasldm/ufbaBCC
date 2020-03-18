#include<stdio.h>
#include<stdlib.h>

int main(){
	float numero;
	int vetor[16];
	int i = 0;
	int j;
	
	scanf("%f", &numero);

	while(numero != 0 && i<16){
		if(numero<1){
			numero*=2;
			if(numero<1){
				vetor[i]=0;			
			}else if(numero>=1){
				vetor[i]=1;
				numero-=1;			
			}		
		}
		i++;
		j=i;
	}

	printf("%d\n", j);
	printf("0.");
	for(i=0; i<j; i++){
		printf("%d", vetor[i]);
	}
	printf("\n");	
	return 0;
}
