#include <stdio.h>
#include <string.h>

#include "tabelaPiPalavra.h"

#include "utils.h"

/*
 * Função responsável por construir a tabela Pi para uma determinada palavra e imprimir tal tabela
 * de acordo com a especificação.
 *
 * Recebe a palavra que deve gerar a tabela pi, e imprime sua tabela.
 * */

void tabelaPiPalavra(char palavra[31]) {
    printf("tabela pi para a palavra: %s:\n", palavra);
    int M = strlen(palavra);
    int lps[M];
    constroiTabelaPi(palavra, M, lps);
    for(int i = 0; i < M; i++) {
        printf("\'%c\': %d\n", palavra[i], lps[i]);
    }
}
