#include <stdio.h>

#include "imprimeIndiceArvore.h"

#include "registros.h"
#include "utils.h"

/*
 * Função responsável por iterar sobre o índice da árvore, in-order, imprimindo todos os nós
 * encontrados, sinalizando seus elementos à esquerda, direita e a possível existência de página.
 *
 * Recebe apenas variáveis de controle para iteração sobre o índice, sem retornar valor. Imprime
 * os valores esq e dir dos índices e sinaliza com "pagina" caso haja a existencia de uma.
 * */

void imprimeIndiceArvoreUtil(int index, int profundidade, int offset) {

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

    if(profundidade % 2 == 0 ? no_a.esq : no_b.esq) {
        int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
        int offset_b = bit_b * ((index*2) - int_pow(2, profundidade + 1)); //CERTO
        imprimeIndiceArvoreUtil(index * 2, profundidade + 1, offset + bit_a + offset_a + offset_b);
    }

    f = fopen("arvore.dat", "rb+");
    fseek(f, offset, SEEK_SET);

    if(profundidade % 2 == 0) {
        NoAno no_esq;
        if(no_a.esq) {
            int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b = bit_b * ((index*2) - int_pow(2, profundidade + 1)); //CERTO
            fseek(f, bit_a + offset_a + offset_b, SEEK_CUR);
            fread(&no_esq, sizeof(NoAno), 1, f);
            fseek(f, offset, SEEK_SET);
        }
        NoAno no_dir;
        if(no_a.dir) {
            int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b = bit_b * (((index*2)+1) - int_pow(2, profundidade + 1)); //CERTO
            fseek(f, bit_a + offset_a + offset_b, SEEK_CUR);
            fread(&no_dir, sizeof(NoAno), 1, f);
            fseek(f, offset, SEEK_SET);
        }
        char ano_esq[21], ano_dir[21];
        sprintf(ano_esq, "%d", no_esq.ano);
        sprintf(ano_dir, "%d", no_dir.ano);
        printf("nome: %s fesq: %s fdir: %s\n", no_a.autor, no_a.esq ? ano_esq : "pagina", no_a.dir ? ano_dir : "pagina");
    }else{
        NoAutor no_esq;
        if(no_b.esq) {
            int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b = bit_b * ((index*2) - int_pow(2, profundidade + 1)); //CERTO
            fseek(f, bit_a + offset_a + offset_b, SEEK_CUR);
            fread(&no_esq, sizeof(NoAutor), 1, f);
            fseek(f, offset, SEEK_SET);
        }
        NoAutor no_dir;
        if(no_b.dir) {
            int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
            int offset_b = bit_b * (((index*2)+1) - int_pow(2, profundidade + 1)); //CERTO
            fseek(f, bit_a + offset_a + offset_b, SEEK_CUR);
            fread(&no_dir, sizeof(NoAutor), 1, f);
            fseek(f, offset, SEEK_SET);
        }
        printf("ano: %d fesq: %s fdir: %s\n", no_b.ano, no_b.esq ? no_esq.autor : "pagina", no_b.dir ? no_dir.autor : "pagina");
    }

    fclose(f);

    if(profundidade % 2 == 0 ? no_a.dir : no_b.dir) {
        int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
        int offset_b = bit_b * (((index*2)+1) - int_pow(2, profundidade + 1)); //CERTO
        imprimeIndiceArvoreUtil((index * 2) + 1, profundidade + 1, offset + bit_a + offset_a + offset_b);
    }
}

void imprimeIndiceArvore() {
    imprimeIndiceArvoreUtil(1, 0, 0);
}