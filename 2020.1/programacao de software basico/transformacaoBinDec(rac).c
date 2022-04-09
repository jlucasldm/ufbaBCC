//João Lucas Lima de Melo
#include<stdio.h>
#include<stdlib.h>

int main(){
	float numero; 	//entrada decimal
	int vetor[16];	//vetor armazenando bits binários
	int i = 0;		//auxiliar
	int j;			//auxiliar
	
	scanf("%f", &numero);	//entrada do dado

	/*gera o número binário, salvando os bits no vetor, a partir da concatenação do último quociente
	com os restos das divisões por 2 no sentido inverso ao que foram obtidos*/
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
		j=i;	//j é atualizado sempre como o tamanho do vetor
	}

	printf("0.");
	for(i=0; i<j; i++){				//imprime o valor binário com até 16 bits
		printf("%d", vetor[i]);
	}
	printf("\n");	
	return 0;
}
