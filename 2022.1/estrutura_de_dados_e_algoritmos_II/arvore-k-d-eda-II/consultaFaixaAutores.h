//
// Created by Luca on 03/06/2022.
//

#ifndef CONSULTAFAIXAAUTORES_H
#define CONSULTAFAIXAAUTORES_H

#include "registros.h"

bool consultaFaixaAutoresUtil(char n1[21], char n2[21], bool exists, int index, int profundidade, int offset, char filename[21]);

bool consultaFaixaAutores(char n1[21], char n2[21]);

#endif //CONSULTAFAIXAAUTORES_H
