#include<stdio.h>
#include<stdlib.h>

/*
A função criaArquivo() é responsável por dar início ao programa. Ela cria um arquivo binário "dados", caso o arquivo não exista.

Uma vez criado, é preenchido por uma quantidade MAXNUMREGS de registros, todos vazios.
*/
int criaArquivo() {

	FILE *f;
	
	//tentativa de abertura do arquivo "dados"
	f = fopen("dados", "r+");

	//se "dados" não existe, é então criado um arquivo binário vazio com este nome
	if(f == NULL){
		if (!(f = fopen("dados","w+"))){
			printf ("Erro na criacao do arquivo \"dados\".");
			exit(-1);
		}

		//registro vazio auxiliar para inserção em "dados"
		Registro r;
		r.ocupado = 0;

		//inserção de MAXNUMREGS registros "r", todos vazios, no arquivo "dados"
		for (int i=0; i < MAXNUMREGS; i++) {
			fwrite (&r, sizeof(Registro), 1, f);
		}
			
		fclose(f);
	}

    return 1;
}
	  
