/********************************************************************
* Francisco Almeida, Domingo Giménez, José Miguel Mantas, Antonio M. Vidal:
* Introducción a la programación paralela,
* Paraninfo Cengage Learning, 2008
*
* Código 3.1 - Cálculo de PI en forma sequencial
* Ver codigo3-16.c para versão paralela
* Adaptado em 20/10/2014 - Marcos Barreto
* Para compilar: gcc -o <nomedoexecutavel> codigo3-1.c
*********************************************************************/
#include <stdio.h>
#include <math.h>

double f(double a) 
{
    return (4.0 / (1.0 + a * a));
}

int main(int argc, char *argv[]) 
{
    int  n, i;
    double PI25DT = 3.141592653589793238462643;
    double pi, h, sum, x;

    n = 100;
    h   = 1.0 / (double) n;
    sum = 0.0; // Soma dos intervalos

    for (i = 1; i <= n; i++) {
        x = h * ((double)i - 0.5);
        sum += f(x);
    }

    pi = h * sum;
    printf("\npi eh aproximadamente %.16f, com erro estimado em %.16f\n", pi, fabs(pi - PI25DT));

    return 0;
}
