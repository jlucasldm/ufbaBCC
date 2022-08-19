#include <stdio.h>
#include <string.h>

#include "consultaFaixaAutores.h"

#include "utils.h"

/*
 * Função responsável por realizar a consulta de um conjunto de registros por uma determinada
 * faixa de valores. É dado o piso e teto (inclusivo) do intervalo buscado e é consultado, a
 * partir do índice, todos os livros guardados em páginas cujo valor de nome_autor esteja
 * contido no intervalo.
 *
 * Recebe o piso e teto do intervalo buscado e parametros de controle para iteracao sobre o indice
 * e arvore. Imprime os valores do livro, caso encontardo, e retorna um booleano sinalizando se a
 * consulta foi bem sucedida.
 * */

bool consultaFaixaAutoresUtil(char n1[21], char n2[21], bool exists, int index, int profundidade, int offset, char filename[21]) {

    if(!exists) {
        strcat(filename, ".dat");

        FILE *f;
        f = fopen(filename, "rb+");

        //caso nao exista a pagina
        if (f == NULL) {
            return false;
        }

        fseek(f, 0, SEEK_END);
        int n_livros = ftell(f) / sizeof(Livro);
        fseek(f, 0, SEEK_SET);

        Livro l;
        bool achou = false;
        for(int i = 0; i < n_livros; i++) {
            fread(&l, sizeof(Livro), 1, f);
            if(strcmp(l.autor, n1) >= 0 && strcmp(l.autor, n2) <= 0) {
                achou = true;
                printf("%s\n", l.autor);
                printf("%s\n", l.titulo);
                printf("%d\n", l.ano_publicacao);
                printf("%s\n", l.nome_arquivo);
            }
        }
        fclose(f);
        return achou;
    }else {

        NoAutor no_a;
        NoAno no_b;

        FILE *f;
        f = fopen("arvore.dat", "rb+");
        if (f == NULL) {
            return false;
        }
        fseek(f, offset, SEEK_CUR);
        profundidade % 2 == 0 ? fread(&no_a, sizeof(NoAutor), 1, f) : fread(&no_b, sizeof(NoAno), 1, f);
        fclose(f);

        int bit_a = profundidade % 2 == 0 ? sizeof(NoAutor) : sizeof(NoAno);
        int bit_b = profundidade % 2 == 0 ? sizeof(NoAno) : sizeof(NoAutor);

        if(profundidade % 2 == 0) {
            bool e = false, d = false;

            if (strcmp(n1, no_a.autor) <= 0) {
                char filename_e[21] = "";
                strcpy(filename_e, filename);
                strcat(filename_e, "e");
                int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
                int offset_b = bit_b * ((index * 2) - int_pow(2, profundidade + 1)); //CERTO
                e = consultaFaixaAutoresUtil(n1, n2, profundidade % 2 == 0 ? no_a.esq : no_b.esq, index * 2, profundidade + 1,offset + bit_a + offset_a + offset_b, filename_e);
            }

            if(strcmp(n2, no_a.autor) >= 0){
                char filename_d[21] = "";
                strcpy(filename_d, filename);
                strcat(filename_d, "d");
                int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
                int offset_b = bit_b * (((index * 2) + 1) - int_pow(2, profundidade + 1)); //CERTO
                d = consultaFaixaAutoresUtil(n1, n2, profundidade % 2 == 0 ? no_a.dir : no_b.dir, (index * 2) + 1,profundidade + 1, offset + bit_a + offset_a + offset_b, filename_d);
            }

            return e || d;
        }else{
            char filename_e[21] = "";
            strcpy(filename_e, filename);
            strcat(filename_e, "e");
            int offset_a_1 = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b_1 = bit_b * ((index * 2) - int_pow(2, profundidade + 1)); //CERTO
            bool e = consultaFaixaAutoresUtil(n1, n2, profundidade % 2 == 0 ? no_a.esq : no_b.esq, index * 2, profundidade + 1,offset + bit_a + offset_a_1 + offset_b_1, filename_e);

            char filename_d[21] = "";
            strcpy(filename_d, filename);
            strcat(filename_d, "d");
            int offset_a_2 = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b_2 = bit_b * (((index * 2) + 1) - int_pow(2, profundidade + 1)); //CERTO
            bool d = consultaFaixaAutoresUtil(n1, n2, profundidade % 2 == 0 ? no_a.dir : no_b.dir, (index * 2) + 1,profundidade + 1, offset + bit_a + offset_a_2 + offset_b_2, filename_d);
            return e || d;
        }

    }

}

bool consultaFaixaAutores(char n1[21], char n2[21]) {
    char filename[21] = "";
    return consultaFaixaAutoresUtil(n1, n2, true, 1, 0, 0, filename);
}

