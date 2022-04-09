#include<stdio.h>
#include<stdlib.h>

int imprimeRegistro() {

	FILE *f;
	
	if (!(f = fopen("dados","r"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	int i;
	bool found = false;
	Registro r;
	fseek (f, 0, SEEK_SET);
	
	for (i=0; i < MAXNUMREGS; i++) {
        printf("%d: ", i);
		fread (&r, sizeof (Registro), 1, f);
        if(r.ocupado == 0){
            printf("vazio\n");
        }else if(r.ocupado == 2){
			printf("*\n");
		}else{
            printf("%d %s %d\n", r.dados.chave, r.dados.nome, r.dados.idade);
        }
	}
	
	fclose(f);
}
	  
