//
// Created by Luca on 03/06/2022.
//

#ifndef INSEREREGISTRO_H
#define INSEREREGISTRO_H

#include "registros.h"

void insereRegistroUtil(Livro livro, bool exists, int index, int profundidade, int offset, char* filename);

void insereRegistro(Livro livro);

#endif //INSEREREGISTRO_H
