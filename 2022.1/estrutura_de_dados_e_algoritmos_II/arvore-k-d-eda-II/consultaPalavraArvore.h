#ifndef CONSULTAPALAVRAARVORE_H
#define CONSULTAPALAVRAARVORE_H

#include "registros.h"

bool consultaPalavraArvoreUtil(char palavra[31], bool exists, int index, int profundidade, int offset, char filename[21]);

bool consultaPalavraArvore(char palavra[31]);

#endif //CONSULTAPALAVRAARVORE_H