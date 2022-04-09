#include<stdio.h>
#include<stdlib.h>

#include "tiposArquivo.h"

int main() {

	FILE *f;
	
	printf ("Criando arquivo \"dados\" ...\n");
	if ((f = fopen("dados","w+"))) 
		printf ("Arquivo \"dados\" criado com sucesso.\n");
	else {
		printf ("Erro na criacao do arquivo \"dados\".");
		exit(-1);
	}
	
	printf ("Inicializando o arquivo ...\n");

	Registro r;
	r.ocupado = false;

	int i;
	for (i=0; i < MTAMARQUIVO; i++) {
		fwrite (&r, sizeof(Registro), 1, f);
	}
			
	fclose(f);
}
	  
