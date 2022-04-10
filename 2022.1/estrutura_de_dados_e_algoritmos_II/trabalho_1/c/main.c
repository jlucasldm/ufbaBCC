#include "tiposArquivo.h"
#include "consultaRegistro.h"
#include "consultaRegistroChave.h"
#include "criaArquivo.h"
#include "insereRegistro.h"
#include "removeRegistro.h"
#include "imprimeRegistro.h"
#include "media.h"

/*
main() é a função principal do programa. Será solicitado do usuário uma entrada de um caractere. A partir da entrada, 
de acordo com a especificação do projeto, as funções serão chamadas. 

Os dados armazenados no arquivo podem ser consultados após o térimno do programa.

O funcionamento de cada função foi abordado em seus respectivos arquivos .h.
*/
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
            printf("%.1f\n", mediaComSucesso());
            printf("%.1f\n", mediaSemSucesso());
        }

        scanf("%c", &input);
    }
    return 0;   
}