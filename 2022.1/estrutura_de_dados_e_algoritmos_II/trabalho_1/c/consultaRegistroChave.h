#include<stdio.h>
#include<stdlib.h>

/*
A função consultaRegistroChave recebe como argumento um inteiro "chave", busca pelo registro com a chave informada pelo arquivo "dados" 
e retorna 1 caso tenha sido encontrado e 0 caso contrário.

É utilizada a função consultaRegistro() para iterar sobre os estados dos registros do arquivo. As funções hash1() e hash2() (ambas recebendo
o valor inteiro de uma chave e retornando seu valor hash em suas respectivas funções, de acordo com a especificação do projeto) são usadas
para iterar sobre as posições do arquivo. 

Inicialmente é acessada a posição hash1(chave) do arquivo. Caso o registro encontrado não seja o buscado, será acrescentado o valor de hash2(chave)
ao ponteiro do arquivo, continuando a busca de forma circular (se hash1(chave) + hash2(chave)*i > MAXNUMREGS, para qualquer que seja i, 
o ponteiro volta ao início do arquivo e continua a busca).

A busca termina se o registro for encontrado, uma casa vazia e nunca ocupada for encontrada (portanto, o registro não está no arquivo)
ou todos os registros foram consultados e o buscado não foi encontrado.
*/
int consultaRegistroChave(int chave) {
	FILE *f;
	int i = 0;
	int acessos = 0;
	Registro r;
	
	//abertura do arquivo "dados"
	if (!(f = fopen("dados","r"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}
	
	while(true){
		acessos += 1;
		
		//alocação do ponteiro de arquivo para a posição hash1(chave) + i*has2(chave)
		//uma vez não encontrado o registro na posição hash1, o ponteiro é alocado para a casa atual + hash2(chave) até o fim da busca
		fseek(f, ((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS)*sizeof(Registro), SEEK_SET);
		int consulta = consultaRegistro((hash1(chave)+(hash2(chave)*i))%MAXNUMREGS);

		//foi encontrado um registro atualmente ocupado sem ter percorrido todo o arquivo
		if(consulta == 1 && i != MAXNUMREGS - 1){
			fread(&r, sizeof(Registro), 1, f);

			//o registro apontado é o que está sendo buscado
			if(r.dados.chave == chave){
				printf("chave: %d\n", r.dados.chave);
				printf("%s\n", r.dados.nome);
				printf("%d\n", r.dados.idade);

				//controle de variáveis globais para cálculo de média de consultas
				CONSULTA_SUCESSO += 1;
				ACESSOS_SUCESSO += acessos;
				fclose(f);
				return 1;
			}
		}else if(consulta == 0 || (consulta != 0 && i == MAXNUMREGS - 1)){ //foi encontrada uma casa vazia ou percorrido todo o arquivo
			printf("chave nao encontrada: %d\n", chave);

			//controle de variáveis globais para cálculo de média de consultas
			ACESSOS_FALHA += acessos;
			CONSULTA_FRACASSO += 1;
			fclose(f);
			return 0;
		}

		//controle para adição de hash2(chave) casas ao ponteiro
		i+=1;
	}
}
	  
