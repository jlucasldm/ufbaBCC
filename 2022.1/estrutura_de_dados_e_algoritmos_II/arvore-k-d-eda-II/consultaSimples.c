#include <stdio.h>
#include <string.h>

#include "consultaSimples.h"

#include "utils.h"

/*
 * Função responsável por realizar a consulta de um livro armazenado em página em função do valor do
 * nome do autor. A busca ocorre iterando-se pelos índices da árvore k-d, consultando a existência do
 * livro na sua devida página (em função da sua posição na estrutura).
 *
 * Recebe o nome do autor do livro a ser buscado e parâmetros para controle da busca sobre o índice
 * e páginas da estrutura. Imprime os valores do livro, caso encontrado, e retorna um booleano
 * sinalizando se a consulta foi bem-sucedida.
 * */

bool consultaSimplesUtil(char autor[21], bool exists, int index, int profundidade, int offset, char filename[21]) {

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
            if(strcmp(l.autor, autor) == 0) {
                achou = true;
                printf("nome: %s\n", l.autor);
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
            if (strcmp(autor, no_a.autor) <= 0) {
                strcat(filename, "e");
                int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
                int offset_b = bit_b * ((index * 2) - int_pow(2, profundidade + 1)); //CERTO
                return consultaSimplesUtil(autor, profundidade % 2 == 0 ? no_a.esq : no_b.esq, index * 2, profundidade + 1,offset + bit_a + offset_a + offset_b, filename);
            } else {
                strcat(filename, "d");
                int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
                int offset_b = bit_b * (((index * 2) + 1) - int_pow(2, profundidade + 1)); //CERTO
                return consultaSimplesUtil(autor, profundidade % 2 == 0 ? no_a.dir : no_b.dir, (index * 2) + 1,profundidade + 1, offset + bit_a + offset_a + offset_b, filename);
            }
        }else{
            char filename_e[21] = "";
            strcpy(filename_e, filename);
            strcat(filename_e, "e");
            int offset_a_1 = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b_1 = bit_b * ((index * 2) - int_pow(2, profundidade + 1)); //CERTO
            bool e = consultaSimplesUtil(autor, profundidade % 2 == 0 ? no_a.esq : no_b.esq, index * 2, profundidade + 1,offset + bit_a + offset_a_1 + offset_b_1, filename_e);

            char filename_d[21] = "";
            strcpy(filename_d, filename);
            strcat(filename_d, "d");
            int offset_a_2 = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b_2 = bit_b * (((index * 2) + 1) - int_pow(2, profundidade + 1)); //CERTO
            bool d = consultaSimplesUtil(autor, profundidade % 2 == 0 ? no_a.dir : no_b.dir, (index * 2) + 1,profundidade + 1, offset + bit_a + offset_a_2 + offset_b_2, filename_d);
            return e || d;
        }

    }

}

bool consultaSimples(char autor[21]) {
    char filename[21] = "";
    return consultaSimplesUtil(autor, true, 1, 0, 0, filename);
}

