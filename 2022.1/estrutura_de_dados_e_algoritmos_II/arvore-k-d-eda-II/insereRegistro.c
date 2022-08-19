#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insereRegistro.h"

#include "utils.h"

/*
 * Função responsável por receber os valores de um livro, instancializar um livro, atribuir a ele
 * os valores recebidos e inseri-lo em uma página.
 *
 * Recebe uma instância de livro e valores auxiliares para iteração sobre o índice e a árvore.
 * O registro é alocado para a página cujo nome seja condizente com sua moviemnatção pelo índice
 * (um livro que segue pela árvore nas posições esquerda-direita-esquerda, por exemplo, seria alocado
 * para o arquivo ede.dat). Caso o registro não exista, ele é criado.
 * */

void insereRegistroUtil(Livro livro, bool exists, int index, int profundidade, int offset, char* filename) {

    if(!exists) {
        strcat(filename, ".dat");

        FILE *f;
        f = fopen(filename, "rb+");

        //caso nao exista a pagina
        if (f == NULL) {
            if (!(f = fopen(filename, "wb+"))) {
                printf("Erro na criacao do arquivo \"%s\".\n", filename);
                exit(-1);
            }
        }

        fseek(f, 0, SEEK_END);
        int n_livros = ftell(f) / sizeof(Livro);

        fseek(f, sizeof(Livro) * n_livros, SEEK_SET);
        fwrite(&livro, sizeof(Livro), 1, f);
        fclose(f);
    }else {

        NoAutor no_a;
        NoAno no_b;

        FILE *f;
        f = fopen("arvore.dat", "rb+");
        if (f == NULL) {
            return;
        }
        fseek(f, offset, SEEK_CUR);
        profundidade % 2 == 0 ? fread(&no_a, sizeof(NoAutor), 1, f) : fread(&no_b, sizeof(NoAno), 1, f);
        fclose(f);

        int bit_a = profundidade % 2 == 0 ? sizeof(NoAutor) : sizeof(NoAno);
        int bit_b = profundidade % 2 == 0 ? sizeof(NoAno) : sizeof(NoAutor);

        if (profundidade % 2 == 0 ? strcmp(livro.autor, no_a.autor) <= 0 : livro.ano_publicacao <= no_b.ano) {
            strcat(filename, "e");
            int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b = bit_b * ((index*2) - int_pow(2, profundidade + 1)); //CERTO
            insereRegistroUtil(livro, profundidade % 2 == 0 ? no_a.esq : no_b.esq, index * 2, profundidade + 1,offset + bit_a + offset_a + offset_b, filename);
        } else {
            strcat(filename, "d");
            int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b = bit_b * (((index*2)+1) - int_pow(2, profundidade + 1)); //CERTO
            insereRegistroUtil(livro, profundidade % 2 == 0 ? no_a.dir : no_b.dir, (index * 2) + 1, profundidade + 1,offset + bit_a + offset_a + offset_b, filename);
        }

    }

}

void insereRegistro(Livro livro) {
    char filename[21] = "";
    insereRegistroUtil(livro, true, 1, 0, 0, filename);
}

