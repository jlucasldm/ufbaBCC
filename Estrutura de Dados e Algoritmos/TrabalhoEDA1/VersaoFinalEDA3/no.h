#ifndef NO_H
#define NO_H

typedef struct no no;

//Função para criar nó
//Recebe como argumento unsigned long int cpf, unsigned long int cpft,
//char op, long int valor
//Retorna um ponteiro para o nó criado
no* create_n(unsigned long int cpf,unsigned long int cpft,char op, long int valor);


#endif // NO_H
