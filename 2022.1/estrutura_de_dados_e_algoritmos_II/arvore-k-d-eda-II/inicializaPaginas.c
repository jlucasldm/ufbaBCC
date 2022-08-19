//
// Created by kid-a on 04/06/2022.
//

#include <stdio.h>

#include "insereRegistro.h"

/*
 * Função responsável por, após a construção do índice, inserir os livros utilizados em sua
 * construção nas suas devidas páginas.
 *
 * A função abre reg.dat onde os livros, iterados sobre a contrução do indice, foram armazenados
 * e itera sobre as estruturas invocando insereRegistro() para alocá-los em suas respectivas páginas.
 * */

void inicializaPaginas(){
    FILE *f;
    int size;
    Livro l;

    //abro o arquivo com todos os registros nos índices
    f = fopen("reg.dat", "rb+");

    //checo quantos arquivos são
    fseek(f, 0, SEEK_END);
    size = ftell(f) / sizeof (Livro);
    fseek(f, 0, SEEK_SET);

    //itero sobre os arquivos e realizo a inserção em páginas individualmente
    for(int i = 0; i < size; i++){
        fread(&l, sizeof (Livro), 1, f);
        insereRegistro(l);
    }

    fclose(f);
}