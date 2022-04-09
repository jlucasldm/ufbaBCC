#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int insereRegistro(){

	FILE *f;

	if (!(f = fopen("dados", "r+"))){
		printf("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	Registro r;
	Registro aux;
	int i = 0;
	int acessos = 0;
	int posarq;
	bool alocado = false;

	scanf("%d", &(r.dados.chave));
	scanf("%s", r.dados.nome);
	scanf("%d", &(r.dados.idade));

	r.ocupado = 1;

	while(!alocado){
		acessos += 1;
		fseek(f, ((hash1(r.dados.chave)+(hash2(r.dados.chave)*i))%MAXNUMREGS)*sizeof(Registro), SEEK_SET);
		if(!consultaRegistro((hash1(r.dados.chave)+(hash2(r.dados.chave)*i))%MAXNUMREGS)){
			fwrite(&r, sizeof(Registro), 1, f);
			printf("insercao com sucesso: %d\n", r.dados.chave);
			alocado = true;
			ACESSOS += acessos;
			REGISTROS += 1;
		}else{
			fread(&aux, sizeof(Registro), 1, f);
			if(aux.dados.chave == r.dados.chave){
				printf("chave ja existente: %d\n", r.dados.chave);
				break;
			}
		}
		i+=1;
		if(i == MAXNUMREGS){
			printf("insercao de chave sem sucesso - arquivo cheio: %d", r.dados.chave);
			break;
		}
	}
	
	fclose(f);
}
