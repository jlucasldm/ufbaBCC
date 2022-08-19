#include <stdio.h>
#include <string.h>

#include "imprimePagina.h"

#include "registros.h"
#include "utils.h"

/*
 * Função responsável por iterar sobre o índice da árvore, in-order, consultando diferentes páginas
 * existentes e imprimindo os valores dos registros armazenados.
 *
 * Recebe como parâmetros valores auxiliares para a iteração sobre o índice e registros das páginas.
 * */

int imprimePaginaUtil(int indice, int indice_original, bool exists, int index, int profundidade, int offset, char* filename) {
    if(!exists) {
        if(indice == 0) {
            strcat(filename, ".dat");

            FILE *f;
            f = fopen(filename, "rb+");

            printf("pagina: %d\n", indice_original);
            if (f != NULL) {
                Livro l;

                fseek(f, 0, SEEK_END);
                int n_livros = ftell(f) / sizeof(Livro);
                fseek(f, 0, SEEK_SET);

                for (int i = 0; i < n_livros; i++) {
                    fread(&l, sizeof(Livro), 1, f);
                    printf("%s\n", l.autor);
                    printf("%s\n", l.titulo);
                    printf("%d\n", l.ano_publicacao);
                    printf("%s\n", l.nome_arquivo);
                }

                fclose(f);
            }
            return -1;
        }else{
            return indice-1;
        }
    }else {
        NoAutor no_a;
        NoAno no_b;

        FILE *f;
        f = fopen("arvore.dat", "rb+");
        if (f == NULL) {
            return -1;
        }
        fseek(f, offset, SEEK_CUR);
        profundidade % 2 == 0 ? fread(&no_a, sizeof(NoAutor), 1, f) : fread(&no_b, sizeof(NoAno), 1, f);
        fclose(f);

        int bit_a = profundidade % 2 == 0 ? sizeof(NoAutor) : sizeof(NoAno);
        int bit_b = profundidade % 2 == 0 ? sizeof(NoAno) : sizeof(NoAutor);

        int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
        int offset_b = bit_b * ((index * 2) - int_pow(2, profundidade + 1)); //CERTO

        char filename_e[21] = "";
        strcpy(filename_e, filename);
        strcat(filename_e, "e");
        indice = imprimePaginaUtil(indice, indice_original, profundidade % 2 == 0 ? no_a.esq : no_b.esq, index * 2, profundidade + 1, offset + bit_a + offset_a + offset_b, filename_e);

        if(indice >= 0) {
            char filename_d[21] = "";
            strcpy(filename_d, filename);
            strcat(filename_d, "d");
            imprimePaginaUtil(indice, indice_original, profundidade % 2 == 0 ? no_a.dir : no_b.dir, (index * 2) + 1, profundidade + 1,offset + bit_a + offset_a + offset_b + bit_b, filename_d);
        }
    }
}

void imprimePagina(int indice) {
    char filename[21] = "";
    imprimePaginaUtil(indice, indice, true, 1, 0, 0, filename);
}