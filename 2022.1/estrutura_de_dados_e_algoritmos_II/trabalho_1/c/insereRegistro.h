#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
A função insereRegistro() solicitará ao usuário informações de um registro, um inteiro não negativo "chave", uma sequência de 
no máximo 20 caracteres "nome" e um inteiro não negativo "idade". Os dados serão preenchidos em um registro, que será inserido no arquivo
"dados" caso não já exista e se houver espaço. É retornado 1 caso o arquivo tenha sido inserido e 0 caso contrário.

É utilizada a função consultaRegistro() para iterar sobre os estados dos registros do arquivo. As funções hash1() e hash2() (ambas recebendo
o valor inteiro de uma chave e retornando seu valor hash em suas respectivas funções, de acordo com a especificação do projeto) são usadas
para iterar sobre as posições do arquivo. 

Inicialmente é acessada a posição hash1(chave) do arquivo. Caso a posição esteja ocupada, será acrescentado o valor de hash2(chave)
ao ponteiro do arquivo, continuando a busca de forma circular (se hash1(chave) + hash2(chave)*i > MAXNUMREGS, para qualquer que seja i, 
o ponteiro volta ao início do arquivo e continua a busca).

A busca termina se o registro foi inserido com sucesso, já foi inserido ou não há mais espaço para inserção no arquivo.
*/
int insereRegistro(){
	FILE *f;
	Registro aux;
	int i = 0;
	int posarq;

	Registro r;
	r.ocupado = 1;

	//abertura do arquivo "dados"
	if (!(f = fopen("dados", "r+"))){
		printf("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	scanf("%d", &(r.dados.chave));
	scanf("%s", r.dados.nome);
	scanf("%d", &(r.dados.idade));

	while(true){
		//alocação do ponteiro de arquivo para a posição hash1(chave) + i*has2(chave)
		//uma vez não encontrado o registro na posição hash1, o ponteiro é alocado para a casa atual + hash2(chave) até o fim da busca
		fseek(f, ((hash1(r.dados.chave)+(hash2(r.dados.chave)*i))%MAXNUMREGS)*sizeof(Registro), SEEK_SET);
		int consulta = consultaRegistro((hash1(r.dados.chave)+(hash2(r.dados.chave)*i))%MAXNUMREGS);
		if(consulta != 1){	//registro não está ocupado no momento, idependente se já foi ocupado uma vez
			fwrite(&r, sizeof(Registro), 1, f);
			printf("insercao com sucesso: %d\n", r.dados.chave);
			fclose(f);
			return 1;
		}else{
			//uso do registro auxiliar "aux" para checagem da chave do registro no endereço atual
			fread(&aux, sizeof(Registro), 1, f);
			if(aux.dados.chave == r.dados.chave){
				printf("chave ja existente: %d\n", r.dados.chave);
				fclose(f);
				return 0;
			}
		}

		//controle para adição de hash2(chave) casas ao ponteiro
		i+=1;

		//percorrido todo o arquivo, não havendo espaço para inserção
		if(i == MAXNUMREGS){
			printf("insercao de chave sem sucesso - arquivo cheio: %d\n", r.dados.chave);
			fclose(f);
			return 0;
		}
	}
}
