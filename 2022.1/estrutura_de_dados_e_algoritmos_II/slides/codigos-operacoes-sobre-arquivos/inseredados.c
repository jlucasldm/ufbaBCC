#include<stdio.h>
#include<stdlib.h>

#include "tiposArquivo.h"

int main() {

	FILE *f;
	
	if (!(f = fopen("dados","r+"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}
	
	Registro r;
	int posarq;
	
	printf("Informe uma chave: ");
	scanf("%d",&(r.dados.chave));
	printf("Entre com um nome: ");
	scanf("%s", r.dados.nome);
	printf("Entre com uma posicao do arquivo: ");
	scanf("%d",&posarq);
	
	printf("Armazenando registro no arquivo ...\n");
	r.ocupado = true;
	fseek(f, posarq*sizeof(Registro), SEEK_SET);	
	if (fwrite (&r, sizeof(Registro), 1, f) == 1)
		printf("Registro armazenado com sucesso\n");
	else
		printf("Erro no armazenamento do registro\n");

	fclose(f);
}
	  
