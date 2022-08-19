#include <stdio.h>
#include <string.h>

#include "consultaFaixaAutores.h"

#include "utils.h"

/*
 * Função responsável por iterar sobre o índice da árvore, in-order, lendo todos os registros
 * salvos nas páginas e verificando a ocorrencia da palavra informada nas mesmas.
 *
 * Recebe a palavra que será procurada e variáveis de controle para iteração sobre o índice,
 * retornando true caso a palavra seja encontrada em algum arquivo e false caso contrario.
 * */

bool consultaPalavraArvoreUtil(char palavra[31], bool exists, int index, int profundidade, int offset, char filename[21]) {

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
            if(buscaKMP(palavra, l.nome_arquivo, true)) {
                achou = true;
                printf("palavra: %s\n", palavra);
                printf("titulo: %s\n", l.titulo);
                printf("autor: %s\n", l.autor);
                printf("ano: %d\n", l.ano_publicacao);
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
            char filename_e[21] = "";
            strcpy(filename_e, filename);
            strcat(filename_e, "e");
            int offset_a_1 = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b_1 = bit_b * ((index * 2) - int_pow(2, profundidade + 1)); //CERTO
            bool e = consultaPalavraArvoreUtil(palavra, profundidade % 2 == 0 ? no_a.esq : no_b.esq, index * 2, profundidade + 1, offset + bit_a + offset_a_1 + offset_b_1, filename_e);

            char filename_d[21] = "";
            strcpy(filename_d, filename);
            strcat(filename_d, "d");
            int offset_a_2 = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b_2 = bit_b * (((index * 2) + 1) - int_pow(2, profundidade + 1)); //CERTO
            bool d = consultaPalavraArvoreUtil(palavra, profundidade % 2 == 0 ? no_a.dir : no_b.dir, (index * 2) + 1,profundidade + 1, offset + bit_a + offset_a_2 + offset_b_2, filename_d);

            return e || d;
        }else{
            char filename_e[21] = "";
            strcpy(filename_e, filename);
            strcat(filename_e, "e");
            int offset_a_1 = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b_1 = bit_b * ((index * 2) - int_pow(2, profundidade + 1)); //CERTO
            bool e = consultaPalavraArvoreUtil(palavra, profundidade % 2 == 0 ? no_a.esq : no_b.esq, index * 2, profundidade + 1,offset + bit_a + offset_a_1 + offset_b_1, filename_e);

            char filename_d[21] = "";
            strcpy(filename_d, filename);
            strcat(filename_d, "d");
            int offset_a_2 = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b_2 = bit_b * (((index * 2) + 1) - int_pow(2, profundidade + 1)); //CERTO
            bool d = consultaPalavraArvoreUtil(palavra, profundidade % 2 == 0 ? no_a.dir : no_b.dir, (index * 2) + 1,profundidade + 1, offset + bit_a + offset_a_2 + offset_b_2, filename_d);

            return e || d;
        }
    }

}

bool consultaPalavraArvore(char palavra[31]) {
    char filename[21] = "";
    return consultaPalavraArvoreUtil(palavra, true, 1, 0, 0, filename);
}

