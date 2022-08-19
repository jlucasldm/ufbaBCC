/*
 * Estrutura de Dados e Algorítmos 2 - Hashing Perfeito
 * Alunos: João Lucas Lima e Luca Argolo
 * Prof: Flavio Assis
 * */

#include <stdio.h>

#include "impressao.h"
#include "registros.h"

//Definição de variáveis globais, caso queira atribuir. Caso contrário, apenas inicializar.
int p = 101;    //primo p.
int a = 3;      //coeficiente de hash primeiro nível a
int b = 42;     //coeficiente de hash primeiro nível b

int main(){
    char entrada;
    int m;
    int c;
    int indice;
    FILE *f;
    scanf("%c", &entrada);

    //Consulta dos valores primo p, coeficientes a e b de hash de primeiro nível caso os arquivos já tenham sido inicializados.
    f = fopen("nivelUm.dat", "r+b");
    if(f != NULL){
        fseek(f, -3*sizeof(int), SEEK_END);
        fread(&p, sizeof(int), 1, f);
        fread(&a, sizeof(int), 1, f);
        fread(&b, sizeof(int), 1, f);
    }

    while (entrada != 'e'){
        switch (entrada){
        case 'i':
            scanf("%d", &m);
            insereRegistros(m, &a, &b, &p);
            printf("estrutura de hashing perfeito criada\n");
            break;

        case 'c':
            scanf("%d", &c);
            consultaRegistro(c, a, b, p);
            break;

        case 'p':
            imprimeNivelUm(a, b, p);
            break;

        case 's':
            scanf("%d", &indice);
            imprimeNivelDois(indice, p);
            break;

        case 'h':
            imprimeNivelUm(a, b, p);
            imprimeTodosNiveisDois(p);
            break;

        case 'n':
            printf("%d\n", p * (p-1));
            break;

        default:
            break;
        }

        scanf("%c", &entrada);
    }

    return 0;
}