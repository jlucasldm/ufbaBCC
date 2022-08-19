#include <stdio.h>
#include <string.h>

#include "registros.h"
#include "utils.h"
#include "math.h"

/*
 * Função usada para eliminar problemas de precisão na hora da conversão de double para int.
 */

int int_pow(int x, int y) {
    return (int) (pow(x, y) + 0.5);
}

/*
 * Função responsável por realizar o pattern matching usando um algorítmo KMP
 *
 * Recebe a palavra que deve ser procurada, o nome do arquivo em que a palavra sera procurada
 * e uma booleana de controle que indica se a função deve retornar true caso encontre a palavra
 * ou se deve apenas imprimir as ocorrencias da mesma no arquivo.
 * */

bool buscaKMP(char palavra[31], char filename[21], bool stop) {
    FILE* f;
    f = fopen(filename, "r");

	int tamanhoPalavra = (int) strlen(palavra);
	int tamanhoArquivo = 0;
    int linha = 1;
    int offsetLinha = 0;
	int tabelaPi[tamanhoPalavra];
	char ctrl;

	for (ctrl = (char) getc(f); ctrl != EOF; ctrl = (char) getc(f)){
	    tamanhoArquivo += 1;
	}

	fseek(f, 0 , SEEK_SET);

	constroiTabelaPi(palavra, tamanhoPalavra, tabelaPi);

	int i = 0;
	int j = 0;

	ctrl = (char) getc(f);
	while (i < tamanhoArquivo) {
		if (palavra[j] == ctrl) {
			j++;
			i++;
			ctrl = (char) getc(f);
            if(ctrl == '\n') {
                linha++;
                offsetLinha = (i - j) + 1;
            }
		}

		if (j == tamanhoPalavra) {
            //Palavra encontrada
			if(stop){
			    fclose(f);
			    return true;
			}
			printf("linha: %d posicao: %d\n", linha, (i - j) + 1 - offsetLinha);
			j = tabelaPi[j - 1];
		}else if (i < tamanhoArquivo && palavra[j] != ctrl) {
			if (j != 0){
			    j = tabelaPi[j - 1];
			}else{
			    i = i + 1;
			    ctrl = (char) getc(f);
                if(ctrl == '\n') {
                    linha++;
                    offsetLinha = (i - j) + 1;
                }
			}
		}
	}

	fclose(f);
	return false;
}

/*
 * Função responsável por construir a tabela Pi que será utilizada para o pattern matching no algorítmo KMP
 *
 * Recebe a palavra que deve gerar a tabela pi, o tamanho da mesma, e a tabela Pi que será preenchida.
 * */

void constroiTabelaPi(const char palavra[31], int tamanhoPalavra, int tabelaPi[tamanhoPalavra]) {
	int len = 0;
	tabelaPi[0] = 0;
	int i = 1;

	while (i < tamanhoPalavra) {
		if (palavra[i] == palavra[len]) {
			len++;
			tabelaPi[i] = len;
			i++;
		}
		else{
			if (len != 0) {
				len = tabelaPi[len - 1];
			}
			else{
				tabelaPi[i] = 0;
				i++;
			}
		}
	}
}