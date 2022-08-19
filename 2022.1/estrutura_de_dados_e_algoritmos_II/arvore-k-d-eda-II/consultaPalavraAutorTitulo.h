//
// Created by Luca on 03/06/2022.
//

#ifndef CONSULTAPALAVRAAUTORTITULO_H
#define CONSULTAPALAVRAAUTORTITULO_H

#include "registros.h"

bool consultaPalavraAutorTituloUtil(char palavra[31], char autor[21], char titulo[21], bool exists, int index, int profundidade, int offset, char filename[21]);

bool consultaPalavraAutorTitulo(char palavra[31], char autor[21], char titulo[21]);

#endif //CONSULTAPALAVRAAUTORTITULO_H
