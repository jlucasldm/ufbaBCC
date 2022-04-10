#include <stdlib.h>
#include <stdio.h>

/*
A função removeRegistro() recebe como argumento um inteiro "chave", usado como referência para a chave de um registro a ser buscado 
e removido do arquivo "dados". A função retorna 1 caso o registro tenha sido removido e 0 caso contrário.

É utilizada a função consultaRegistro() para iterar sobre os estados dos registros do arquivo. As funções hash1() e hash2() (ambas recebendo
o valor inteiro de uma chave e retornando seu valor hash em suas respectivas funções, de acordo com a especificação do projeto) são usadas
para iterar sobre as posições do arquivo. 

Inicialmente é acessada a posição hash1(chave) do arquivo. Caso o registro encontrado não seja o buscado, será acrescentado o valor de hash2(chave)
ao ponteiro do arquivo, continuando a busca de forma circular (se hash1(chave) + hash2(chave)*i > MAXNUMREGS, para qualquer que seja i, 
o ponteiro volta ao início do arquivo e continua a busca).

Uma vez encontrado, o registro será sobrescrito por um registro vazio "aux". Na inserção de "aux" na posição do registro removido, é informado
que está vazio, mas o endereço apontado já foi ocupado.

A busca termina se o registro for removido ou se todo o arquivo foi percorrido e o registro não foi encontrado.
*/
int removeRegistro(int chave){
    FILE *f;
	int i = 0;
	int acessos = 0;
	Registro r;
	
	//abertura do arquivo "dados"
	if (!(f = fopen("dados","r+"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	//registro a sobrescrever o que será removido. irá indicar que está vazio, porém já foi ocupado
	Registro aux;
    aux.ocupado = 2;
	
	while(true){
		acessos += 1;

		//alocação do ponteiro de arquivo para a posição hash1(chave) + i*has2(chave)
		//uma vez não encontrado o registro na posição hash1, o ponteiro é alocado para a casa atual + hash2(chave) até o fim da busca
		fseek(f, ((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS)*sizeof(Registro), SEEK_SET);
		if(consultaRegistro((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS) == 1){	//o registro apontado está ocupado
			fread(&r, sizeof(Registro), 1, f);
			if(r.dados.chave == chave){	//o registro ocupado é o buscado
				//realocação do ponteiro para a sobrescrita
				fseek(f, ((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS)*sizeof(Registro), SEEK_SET);
				//sobrescrita do arquivo a ser removido por um vazio
				fwrite(&aux, sizeof(Registro), 1, f);
    			printf("chave removida com sucesso: %d\n", chave);
				fclose(f);
				return 1;
			}
		}

		//controle para adição de hash2(chave) casas ao ponteiro
		i += 1;

		//todo o arquivo já foi percorrido
		if(i == MAXNUMREGS){
			printf("chave nao encontrada: %d\n", chave);
			fclose(f);
			return 0;
		}
	}
}