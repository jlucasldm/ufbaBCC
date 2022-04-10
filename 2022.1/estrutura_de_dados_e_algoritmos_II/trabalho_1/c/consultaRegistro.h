#include <stdio.h>
#include <stdlib.h>

/*
A função consultaRegistro() recebe como argumento um número inteiro "pos", usado como parâmetro na busca de registros no arquivo "dados".

A função retorna o estado do registro naquele endereço, se está vazio(0), atualmente ocupado(1) ou vazio mas um dia já foi ocupado(2).

A busca ocorre pela alocação do ponteiro de arquivo f para o endereço tamanho_de_um_registro*pos. Uma vez alocado, as informações dos próximos
tamanho_de_um_registro bytes são copiadas para um registro auxiliar r.

Usando o registro auxiliar, é possível acessar o estado de ocupação do registro naquele endereço.
*/
int consultaRegistro(int pos){
	FILE *f;

	//abertura do arquivo "dados"
	if (!(f = fopen("dados", "r+")))
	{
		printf("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	//alocação do ponteiro para o endereço "pos" no arquivo "dados"
	fseek(f, (pos) * sizeof(Registro), SEEK_SET);

	//uso do registro auxiliar "r" para checagem do estado do registro no endereço "pos"
	Registro r;
	fread(&r, sizeof(Registro), 1, f);
	if (r.ocupado == 0){		//registro vazio
		fclose(f);
		return 0;
	}else if(r.ocupado == 1){	//registro atualmente ocupado por dados
		fclose(f);
		return 1;
	}else if(r.ocupado == 2){	//registro vazio, mas uma vez ocupado por dados
		fclose(f);
		return 2;
	}
}
