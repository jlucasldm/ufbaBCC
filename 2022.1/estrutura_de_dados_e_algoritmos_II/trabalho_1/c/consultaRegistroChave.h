#include<stdio.h>
#include<stdlib.h>

int consultaRegistroChave(int chave) {

	FILE *f;
	
	if (!(f = fopen("dados","r"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	int i = 0;
	Registro r;
	bool encontrado = false;
	fseek (f, 0, SEEK_SET);
	
	while(!encontrado){
		fseek(f, ((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS)*sizeof(Registro), SEEK_SET);
		if(consultaRegistro((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS)){
			fread(&r, sizeof(Registro), 1, f);
			if(r.dados.chave == chave){
				printf("chave: %d\n", r.dados.chave);
				printf("%s\n", r.dados.nome);
				printf("%d\n", r.dados.idade);
				encontrado = true;
			}
		}
		i+=1;
		if(i == MAXNUMREGS){
			printf("chave nao encontrada: %d\n", chave);
			break;
		}
	}
	
	fclose(f);
}
	  
