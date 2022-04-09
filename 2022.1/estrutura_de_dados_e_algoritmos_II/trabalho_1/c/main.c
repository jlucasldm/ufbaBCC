#include "tiposArquivo.h"
#include "consultaRegistro.h"
#include "consultaRegistroChave.h"
#include "criaArquivo.h"
#include "insereRegistro.h"
#include "removeRegistro.h"
#include "imprimeRegistro.h"
#include "media.h"

int main(){
    char input;
    int chave;
    scanf("%c", &input);
    criaArquivo();
    while(input != 'e'){
        if(input == 'i'){
            insereRegistro();
        }else if(input == 'c'){
            scanf("%d", &chave);
            consultaRegistroChave(chave);
        }else if(input == 'r'){
            scanf("%d", &chave);
            removeRegistro(chave);
        }else if(input == 'p'){
            imprimeRegistro();
        }else if(input == 'm'){
            printf("%.1f\n", media());
        }

        scanf("%c", &input);
    }
    return 0;   
}