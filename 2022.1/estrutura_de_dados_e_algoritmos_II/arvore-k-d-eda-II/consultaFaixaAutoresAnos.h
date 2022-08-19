//
// Created by Luca on 03/06/2022.
//

#ifndef CONSULTAFAIXAAUTORESANOS_H
#define CONSULTAFAIXAAUTORESANOS_H

#include "registros.h"
#include "utils.h"

bool consultaFaixaAutoresAnosUtil(char n1[21], char n2[21], int a1, int a2, bool exists, int index, int profundidade, int offset, char filename[21]);

bool consultaFaixaAutoresAnos(char n1[21], char n2[21], int a1, int a2);

#endif //CONSULTAFAIXAAUTORESANOS_H
