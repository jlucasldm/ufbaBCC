#include<stdio.h>
#include<stdlib.h>

/*
A função mediaComSucesso() retorna o resultado, com casas decimais, da divisão entre a quantidade de acessos bem sucedidos em consultas
de um registro em um arquivo sobre o total de consultas bem sucedidas realizadas. Caso nenhuma consulta foi efetuada, a função retorna
0.000000.

Por exemplo, se apenas a consulta do registro de chave 12 foi efetuada em um arquivo, houve o acesso a 3 endereços de memória
e o registro foi encontrado, a função retornaria 3.0000000.

*/
float mediaComSucesso(){
    if(CONSULTA_SUCESSO > 0){   //se houve ao menos uma consulta
        return (double)ACESSOS_SUCESSO/(double)CONSULTA_SUCESSO;
    }else{
        return 0;
    }
}

/*
A função mediaSemSucesso() retorna o resultado, com casas decimais, da divisão entre a quantidade de acessos mal sucedidos em consultas
de um registro em um arquivo sobre o total de consultas mal sucedidas realizadas. Caso nenhuma consulta foi efetuada, a função retorna
0.000000.

Por exemplo, se apenas a consulta do registro de chave 7 foi efetuada em um arquivo, houve o acesso a 4 endereços de memória
e o registro não foi encontrado, a função retornaria 4.0000000.
*/
float mediaSemSucesso(){
    if(CONSULTA_FRACASSO > 0){  //se houve ao menos uma consulta
        return (double) ACESSOS_FALHA / (double) CONSULTA_FRACASSO;
    }else{
        return 0;
    }
}