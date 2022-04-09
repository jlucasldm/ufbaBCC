
#include<stdbool.h>

#define MTAMARQUIVO 10
#define MTAMNOME 20

typedef struct {
	   int chave;
	   char nome[MTAMNOME];
} DadosUsuario;

typedef struct {
   bool ocupado;
   DadosUsuario dados;
} Registro;

