#ifndef REGISTROS_H
#define REGISTROS_H

#include <stdbool.h>

typedef struct{
    char autor[21];
    char titulo[21];
    int ano_publicacao;
    char nome_arquivo[21];
}Livro;

typedef struct {
    int ano;
    bool dir;
    bool esq;
}NoAno;

typedef struct {
    char autor[21];
    bool dir;
    bool esq;
}NoAutor;

#endif //REGISTROS_H