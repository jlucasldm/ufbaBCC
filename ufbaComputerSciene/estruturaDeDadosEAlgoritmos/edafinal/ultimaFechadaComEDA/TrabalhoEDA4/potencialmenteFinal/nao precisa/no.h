#ifndef NO_H
#define NO_H

typedef struct no no;

//Função para criar nó
//Retorna um ponteiro para o nó criado
no* create_n(int chave, int saldo);

void destroy_n(no* n);

#endif // NO_H