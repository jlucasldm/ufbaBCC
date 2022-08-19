#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "base.h"
#include "registros.h"
#include "impressao.h"

/*
Função responsável pela impressão da tabela de primeiro nível de acordo com a especificação, iterando sobre as células
e os registros do referido índice.

Recebe como parâmetros os coeficientes a e b de hash de primeiro nível e o primo p.
*/
int imprimeNivelUm(int a, int b, int p) {
    FILE *f;
    FILE *fniveldois;
    char filename[10];
    Registro r;
    Celula c;

    //Abertura da tabela de nível um.
    if (!(f = fopen("nivelUm.dat","r"))) {
        printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
        exit(-1);
    }

    fseek(f, 0, SEEK_END);
    int m = (ftell(f) - 3*sizeof(int))/sizeof(Celula);
    fseek (f, 0, SEEK_SET);

    printf("hashing perfeito: primeiro nivel\n");
    printf("tamanho da tabela: %d\n", m);
    printf("parametro a: %d\n", a);
    printf("parametro b: %d\n", b);
    printf("numero primo: %d\n", p);

    //Iteração sobre as células da tabela de nível um.
    for (int i=0; i < m; i++) {
        fread (&c, sizeof (Celula), 1, f);

        //Consulta se há regsitros alocados na referida célula de índice i.
        if(c.mtab != 0){
            printf("%d:", i);

            sprintf(filename, "%d", i);
            strcat(filename, "aloc.dat");

            //Abertura do arquivo [índice_célula]aloc.dat, onde os registros estão devidamente alocados.
            if (!(fniveldois = fopen(filename,"r"))) {
                printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
                exit(-1);
            }

            fseek (fniveldois, 0, SEEK_SET);

            //Iteração sobre todos os registros e consulta de chave para os registros não vazios
            for(int j = 0; j < c.mtab * c.mtab; j ++){
                fread (&r, sizeof (Registro), 1, fniveldois);
                if(r.ocupado != 0){
                    printf(" %d", r.dado.chave);
                }
            }
            printf("\n");
        }
    }

    fclose(f);
    return 1;
}


/*
Função responsável pela impressão da tabela de segundo nível de acordo com a especificação, iterando sobre os registros
de um dado índice (de primeiro nível) e imprimindo as chaves de todos os registros encontrados.

Recebe como parâmetros o índice de primeiro nível e o primo p.
*/
int imprimeNivelDois(int indice, int p) {
    FILE *fnivelum;
    FILE *fniveldois;
    Celula c;
    Registro r;
    char filename[10];

    //Abertura da tabela de primeiro nível.
    if (!(fnivelum = fopen("nivelUm.dat","r"))) {
        printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
        exit(-1);
    }

    fseek(fnivelum, 0, SEEK_SET);
    fseek(fnivelum, indice * sizeof(Celula), SEEK_SET);
    fread(&c, sizeof(Celula), 1, fnivelum);

    printf("hashing perfeiro: segundo nivel - indice: %d\n", indice);
    printf("tamanho da tabela: %d\n", c.mtab * c.mtab);
    printf("parametro a: %d\n", c.a);
    printf("parametro b: %d\n", c.b);
    printf("numero primo: %d\n", p);

    //Checagem se existe registros atribuídos ao índice.
    if(c.mtab > 0){
        sprintf(filename, "%d", indice);
        strcat(filename, "aloc.dat");

        //Abertura do arquivo de nível dois do dado índice.
        if (!(fniveldois = fopen(filename,"r"))) {
            printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
            exit(-1);
        }

        fseek (fniveldois, 0, SEEK_SET);

        //Iteração sobre todos os registros do arquivo de nível dois e impressão de chaves, quando encontrado registro.
        for(int j = 0; j < c.mtab * c.mtab; j ++){
            fread (&r, sizeof (Registro), 1, fniveldois);
            if(r.ocupado != 0){
                printf("%d: ", j);
                printf("%d\n", r.dado.chave);
            }
        }
        
        fclose(fniveldois);
    }

    fclose(fnivelum);
    return 1;
}


/*
Função responsável pela impressão da tabela de segundo nível de acordo com a especificação, iterando sobre os registros
de todos os segundos níveis e imprimindo as chaves dos registros encontrados.

Recebe como parâmetro o primo p.
*/
int imprimeTodosNiveisDois(int p){
    FILE *fnivelum;
    FILE *fniveldois;
    Celula c;
    Registro r;
    char filename[10];

    //Abertura da tabela de primeiro nível.
    if (!(fnivelum = fopen("nivelUm.dat","r"))) {
        printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
        exit(-1);
    }

    fseek(fnivelum, 0, SEEK_END);
    int tam = (ftell(fnivelum) - 3*sizeof(int))/sizeof(Celula);
    fseek (fnivelum, 0, SEEK_SET);

    //Iteração sobre todas as células de primeiro nível.
    for (int i=0; i < tam; i++) {
        fread (&c, sizeof (Celula), 1, fnivelum);

        //Caso exista registros alocados na tabela de nível um no índice i.
        if(c.mtab > 0){
            printf("hashing perfeiro: segundo nivel - indice: %d\n", i);
            printf("tamanho da tabela: %d\n", c.mtab * c.mtab);
            printf("parametro a: %d\n", c.a);
            printf("parametro b: %d\n", c.b);
            printf("numero primo: %d\n", p);

            sprintf(filename, "%d", i);
            strcat(filename, "aloc.dat");

            //Abertura de [índice_células]aloc.dat.
            if (!(fniveldois = fopen(filename,"r"))) {
                printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
                exit(-1);
            }

            fseek (fniveldois, 0, SEEK_SET);
            //Iteração sobre todos os registros de [índice_células]aloc.dat e impressão das chaves dos registros encontrados.
            for(int j = 0; j < c.mtab * c.mtab; j ++){
                fread (&r, sizeof (Registro), 1, fniveldois);
                if(r.ocupado != 0){
                    printf("%d: ", j);
                    printf("%d\n", r.dado.chave);
                }
            }
        }
    }

    fclose(fnivelum);
    fclose(fniveldois);
    return 1;
}