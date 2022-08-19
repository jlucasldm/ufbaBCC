#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "base.h"
#include "registros.h"

//Constante utilizada para iterar sobre todos os possíveis primos.
const int PRIMOS[] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                      29, 31, 37, 41, 43, 47, 53, 59,
                      61, 67, 71, 73, 39, 83, 89, 97, 101};


/*
Função responsável por receber os registros, iterar sobre as células da tabela de primeiro nível e agrupa-lós por suas posições hash (primeiro nível) 
em arquivos distintos de nome [índice_célula].dat. 

Recebe como parâmetro a quantidade de registros m, os ponteiros para os coeficientes de primeiro nível a 
e b e do número primo p (global).
*/
int insereRegistros(int m, int *a, int *b, int *p) {
    FILE *fnivelum;
    FILE *fniveldois;
    Registro r;
    Celula c;
    char filename[3];

    //Iterando sobre todos os registros a serem inseridos
    for (int i=0; i < m; i++) {
        scanf("%d\n", &r.dado.chave);
        scanf("%[^\n]%*c", r.dado.nome);
        scanf("%d", &r.dado.idade);

        /*Recebido o primeiro registro, portanto, maior chave da aplicação. Definição dos valores do
        primo p, e coeficientes de primeiro nível a e b.
        */
        if (i == 0){
            //////Este trecho irá gerar um número primo levando em conta a maior chave inserida, e posteriormente irá gerar a e b modularizados em p/////
            ///////////Deixamos essa parte comentada, pois, nos exemplos em slide e nos arquivos teste é necessario a pré definição de valores//////////
            //int j = 0;
            //*p = PRIMOS[0];
            //while (*p <= r.dado.chave){
            //    j++;
            //    *p = PRIMOS[j];
            //}
            //
            //*a = (rand() % *p) + 1;
            //*b = rand() % *p;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            criaArquivoNivelUm(m, *p, *a, *b);
            fnivelum = fopen("nivelUm.dat", "r+b");
        }

        //Definindo posição do registro na tabela de nível um
        r.hash = hash(*a, *b, *p, m, r.dado.chave);
        r.ocupado = 1;

        //Tentativa de abertura do arquivo [índice_celula].dat. Caso não exista, o arquivo é criado.
        sprintf(filename, "%d", r.hash);
        fniveldois = fopen(filename, "r+b");

        if(fniveldois == NULL){
            if (!(fniveldois = fopen(filename,"w+b"))){
                printf ("Erro na criacao do arquivo \"%s\".", filename);
                exit(-1);
            }
        }

        //Leitura de célula de índice r.hash.
        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fread(&c, sizeof(Celula), 1, fnivelum);

        //Escrita do registro no arquivo [índice_celula].dta.
        fseek(fniveldois, c.mtab * sizeof(Registro), SEEK_SET);
        fwrite (&r, sizeof(Registro), 1, fniveldois);

        //Atualização da quantidade de registros na célula de índice r.hash.
        c.mtab += 1;
        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fwrite(&c, sizeof(Celula), 1, fnivelum);

        fclose(fniveldois);

    }

    fseek(fnivelum, 0, SEEK_SET);
    //Iteração sobre as células da tabela de primeiro nível.
    for(int i = 0; i < m; i++){
        fread(&c, sizeof(Celula), 1, fnivelum);

        //Se a célula possui algum registro, o processo de realocamento é realizado.
        if(c.mtab > 0){
            sprintf(filename, "%d", i);
            realocaRegistros(filename, c.mtab, c.a, c.b, *p, i);
        }
    }

    fclose(fnivelum);

    return 1;
}


/*
Função responsável por realocar, utilizando função hash e coeficientes para o segundo nível, os registros das funções [índice_celula].dat 
em arquivos [índice_celula]aloc.dat. 

Recebe como parâmetro o nome do arquivo [índice_celula].dat, a quantidade de registros do arquivo (tamanho), os coeficientes de hash de 
segundo nível a e b, o primo p e o índice da célula.
*/
int realocaRegistros(char filename[3], int tamanho, int a, int b, int p, int id_celula){
    FILE *f;
    FILE *falocado;
    FILE *fnivelum;
    Celula c;

    //Abertura da tabela de nível um.
    if (!(fnivelum = fopen("nivelUm.dat","r+b"))) {
        printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
        exit(-1);
    }

    //Leitura da célula no índice id_celula.
    fseek(fnivelum, id_celula * sizeof(Celula), SEEK_SET);
    fread(&c, sizeof(Celula), 1, fnivelum);
    fseek(fnivelum, 0, SEEK_SET);

    //Atribuição dos valores de a e b de segundo nível caso haja apenas um registro.
    if(tamanho == 1){
        c.a = 0;
        c.b = 0;
    }else{
        c.a = a;
        c.b = b;
    }
    
    fseek(fnivelum, id_celula * sizeof(Celula), SEEK_SET);
    fwrite(&c, sizeof(Celula), 1, fnivelum);
    fseek(fnivelum, 0, SEEK_SET);

    char filenameAlocado[10] = "";
    strcat(filenameAlocado, filename);
    strcat(filenameAlocado, "aloc.dat");

    //Criação do arquivo [índice_celula]aloc.dat
    if (!(f = fopen(filename,"r+b"))) {
        printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
        exit(-1);
    }

    falocado = fopen(filenameAlocado,"w+b");

    Registro r;
    Registro raux;
    Registro rconsulta;
    r.ocupado = 0;
    int pos;

    //Inicialização do arquivo com tamanho^2 registros vazios
    for(int i = 0; i < (tamanho*tamanho); i++){
        fwrite (&r, sizeof(Registro), 1, falocado);
    }


    fseek(falocado, 0, SEEK_SET);
    fseek(f, 0, SEEK_SET);


    //Iterando sobre os registros de [índice_arquivo].dat
    for(int i = 0; i < tamanho; i++){
        fread (&raux, sizeof(Registro), 1, f);
        pos = hash(a, b, p, tamanho*tamanho, raux.dado.chave);

        //Leitura do registro na posição hash_segundo_nível do registro a ser realocado
        fseek(falocado, (pos) * sizeof(Registro), SEEK_SET);
        fread(&rconsulta, sizeof(Registro), 1, falocado);
        fseek(falocado, 0, SEEK_SET);

        //Se a posição está livre, o registro é inserido
        if (rconsulta.ocupado == 0){
            fseek(falocado, (pos) * sizeof(Registro), SEEK_SET);
            fwrite (&raux, sizeof(Registro), 1, falocado);
            fseek(falocado, 0, SEEK_SET);

        /*Se está ocupada, os valores dos coeficientes são atualziados e a função de realocação é
        invocada novamente.*/
        }else if(rconsulta.ocupado == 1){
            c.a = (rand() % p) + 1;
            c.b = rand() % p;

            fclose(f);
            fclose(falocado);
            fclose(fnivelum);

            realocaRegistros(filename, tamanho, c.a, c.b, p, id_celula);
            return 1;
        }
    }

    fclose(f);
    remove(filename);
    fclose(falocado);
    fclose(fnivelum);
    return 1;
}


/*
Função responsável por consultar um registro por sua chave na estrutura de hashing duplo. Caso encontre, informa seus dados e sinaliza
caso contrário. 

Recebe um valor de chave a ser consultado, os coeficientes de hash primário a e b e o valor de primo p.
*/
int consultaRegistro(int chave, int a, int b, int p){
    FILE *fnivelum;
    FILE *fniveldois;
    Celula c;
    Registro r;

    //Abertura da tabela de nível um.
    if (!(fnivelum = fopen("nivelUm.dat","r"))) {
        printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
        exit(-1);
    }

    //Consultando a quantidade de células do arquivo nivelUm.
    fseek(fnivelum, 0, SEEK_END);
    int m = (ftell(fnivelum) - 3*sizeof(int))/sizeof(Celula);

    //Leitura da célula na posição hash de primeiro nível do registro a ser consultado.
    int posicao_primaria = hash(a, b, p, m, chave);
    fseek(fnivelum, posicao_primaria * sizeof(Celula), SEEK_SET);
    fread(&c, sizeof(Celula), 1, fnivelum);

    if(c.mtab > 0) {
        char filename[10] = "";
        sprintf(filename, "%d", posicao_primaria);
        strcat(filename, "aloc.dat");

        //Abertura do arquivo [índice_célula]aloc.dat.
        if (!(fniveldois = fopen(filename, "r"))) {
            printf("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
            exit(-1);
        }

        //Leitura do registro na posição hash de segundo nível do registro a ser consultado.
        int posicao_secundaria = hash(c.a, c.b, p, c.mtab * c.mtab, chave);
        fseek(fniveldois, posicao_secundaria * sizeof(Registro), SEEK_SET);
        fread(&r, sizeof(Registro), 1, fniveldois);

        //Checagem se o registro lido é o a ser consultado.
        if (r.dado.chave == chave) {
            printf("chave: %d\n", r.dado.chave);
            printf("%s\n", r.dado.nome);
            printf("%d\n", r.dado.idade);
        } else {
            printf("chave nao encontrada: %d\n", chave);
        }

        fclose(fniveldois);
    }else{
        printf("chave nao encontrada: %d\n", chave);
    }

    fclose(fnivelum);

}