#include <stdlib.h>
#include <stdio.h>

int removeRegistro(int chave){
    FILE *f;
	
	if (!(f = fopen("dados","r+"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	int i = 0;
	int acessos = 0;
	Registro r;
	bool encontrado = false;

	Registro aux;
    aux.ocupado = 2;
	
	while(!encontrado){
		acessos += 1;
		fseek(f, ((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS)*sizeof(Registro), SEEK_SET);
		if(consultaRegistro((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS)){
			fread(&r, sizeof(Registro), 1, f);
			if(r.dados.chave == chave){
				fseek(f, ((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS)*sizeof(Registro), SEEK_SET);
				fwrite(&aux, sizeof(Registro), 1, f);
    			printf("chave removida com sucesso: %d\n", chave);
				REGISTROS -= 1;
				ACESSOS -= acessos;
				encontrado = true;
			}
		}
		i += 1;
		if(i == MAXNUMREGS){
			printf("chave nao encontrada: %d\n", chave);
			break;
		}
	}
	
	fclose(f);
}