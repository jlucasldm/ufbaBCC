#include<stdio.h>
#include<stdlib.h>

/*
A função imprimeRegistro() irá iterar de forma sequencial por todos os registro no arquivo "dados". Em função do estado de ocupação 
do registro acessado, informações ao seu respeito serão impressas.

De acordo com a especificação:
	1. caso um registro esteja vazio, será impresso "vazio". 
	2. caso um registro esteja ocupado, será impresso "chave: " e o valor de sua chave, seu nome e sua idade em linhas separadas.
	3. caso um registro esteja vazio mas já foi ocupado, será impresso "*".
*/
int imprimeRegistro() {
	FILE *f;
	Registro r;
	
	//abertura do arquivo "dados"
	if (!(f = fopen("dados","r"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	//alocação do ponteiro para o início do arquivo
	fseek (f, 0, SEEK_SET);
	
	//iteração por todo o arquivo
	for (int i=0; i < MAXNUMREGS; i++) {
        printf("%d: ", i);
		
		//uso de um registro auxiliar "r" para iterar sobre o registro apontado
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
	return 1;
}
	  
