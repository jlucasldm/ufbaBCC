//
// Created by Luca on 03/06/2022.
//

#ifndef UTILS_H
#define UTILS_H

#include "registros.h"

int int_pow(int x, int y);

bool buscaKMP(char palavra[31], char filename[21], bool stop);

void constroiTabelaPi(const char palavra[31], int tamanhoPalavra, int tabelaPi[tamanhoPalavra]);

#endif //UTILS_H
