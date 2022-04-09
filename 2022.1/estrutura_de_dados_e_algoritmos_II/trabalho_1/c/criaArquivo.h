#include<stdio.h>
#include<stdlib.h>

int criaArquivo() {

	FILE *f;
	
	f = fopen("dados", "r+");

	if(f == NULL){
		if (!(f = fopen("dados","w+"))){
			printf ("Erro na criacao do arquivo \"dados\".");
			exit(-1);
		}

		Registro r;
		r.ocupado = 0;

		int i;
		for (i=0; i < MAXNUMREGS; i++) {
			fwrite (&r, sizeof(Registro), 1, f);
		}
			
		fclose(f);
	}

    return true;
}
	  
