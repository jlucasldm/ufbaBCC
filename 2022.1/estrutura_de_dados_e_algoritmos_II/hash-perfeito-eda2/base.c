#include<stdio.h>
#include<stdlib.h>

#include "base.h"

/*
Função responsável por criar a tabela de nível um. Recebe um valor m (tamanho de registros a serem inseridos), o valor do primo p (global),
e os coeficientes a e b para uso da função hash em nível primário.

A função cria um arquivo contendo m células e, no final do arquivo, armazena os valores de p (global), e os coeficientes a e b de primeiro nível.
*/
int criaArquivoNivelUm(int m, int p, int a_global, int b_global) {
	FILE *f;
	
	f = fopen("nivelUm.dat", "r+b");

	//Criação do arquivo da tabela de nível um "nivelUm".
	if(f == NULL){
		if (!(f = fopen("nivelUm.dat","w+b"))){
			printf ("Erro na criacao do arquivo \"nivelUm\".");
			exit(-1);
		}

		//Inicialização de células vazias para inserção no arquivo
		Celula c;
		c.mtab = 0;

		/*
		Definição dos coeficientes de a e b referentes a célula.
		Escolhemos definir manualmente os coeficientes de a e b para as células de índice 0, 2, 5 e 7
		para controle e teste de acordo com os exemplos utilizados em sala e com os arquivos testes
		disponibilizados.
        Caso seja necessario definir outros coeficientes de segundo nível manualmente, favor editar o código abaixo.
		*/
		for (int i = 0; i < m; i++) {
			if(i == 0 || i == 5){
				c.a = 0;
				c.b = 0;
			}else if(i == 2){
				c.a = 10;
				c.b = 18;
			}else if(i == 7){
				c.a = 23;
				c.b = 88;
			}else{
				c.a = (rand() % p) + 1;
				c.b = rand() % p;
			}
			fwrite (&c, sizeof(Celula), 1, f);
		}

		//Escrita dos valores de p (global) e coeficientes de primeiro nível a e b no final do arquivo nivelUm.
		fseek(f, 0, SEEK_END);
		fwrite(&p, sizeof(int), 1, f);

		fwrite(&a_global, sizeof(int), 1, f);
		fwrite(&b_global, sizeof(int), 1, f);
			
		fclose(f);
	}

    return 1;
}

/*
Função responsável por retornar o valor da função hash para um dado registro. Recebe os valores dos coeficientes de a e b, primo p,
tamanho do arquivo m e chave do registro k.
*/
int hash(int a, int b, int p, int m, int k){
    return (((a*k + b) % p) % m);
}
	  
