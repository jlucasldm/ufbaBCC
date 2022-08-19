/*
Faça um código em C para calcular a fórmula de Bhaskara.
Utilize os conceitos de FORK e PIPES vistos nas aulas. 
Cada processo criado deve ficar responsável por uma determinada parte da fórmula (fica a seu critério qual parte). 
Utilize PIPES para eles se comunicarem. 
A leitura de valores das variáveis da equação deve vir via teclado. 
ALÉM DO CÓDIGO C, ENVIAR TAMBÉM A FIGURA/GRAFO DE CONEXÕES COM OS PROCESSOS E PIPES.
*/

#include <sys/sem.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    //processo pai: leitura de a, b e c
    int a, b, c;
    int fd_1[2], fd_2[2], fd_3[2], fd_4[2];

    //inicializacao dos pipes
    pipe(fd_1);
    pipe(fd_2);
    pipe(fd_3);
    pipe(fd_4);

    printf("Entre os valores de a, b e c:\n");
    scanf("%d%d%d", &a, &b, &c);

    //escrita dos valores das variaveis nos pipes
    write(fd_1[1], &a, sizeof(int));
    write(fd_2[1], &b, sizeof(int));
    write(fd_3[1], &c, sizeof(int));

    //criacao do processo filho, son1
    pid_t son1 = fork();
    if(son1 == 0){
        //processo filho: calculo do delta
        int a, b, c, delta;

        //leitura das variaveis pelos respectivos pipes
        read(fd_1[0], &a, sizeof(int));
        read(fd_2[0], &b, sizeof(int));
        read(fd_3[0], &c, sizeof(int));

        delta = (b * b) -  (4 * a * c);

        //reescrita dos pipes usados para futura leitura
        write(fd_1[1], &a, sizeof(int));
        write(fd_2[1], &b, sizeof(int));
        write(fd_3[1], &c, sizeof(int));

        //escrita de delta no pipe
        write(fd_4[1], &delta, sizeof(int));

        //criacao do processo son2, filho de son1
        pid_t son2 = fork();
        if(son2 == 0){
            //calculo de x1
            int a, b, delta, x1;

            //leitura das variaveis pelos respectivos pipes
            read(fd_1[0], &a, sizeof(int));
            read(fd_2[0], &b, sizeof(int));
            read(fd_4[0], &delta, sizeof(int));

            //calculo do primeiro x
            x1 = (((-1) * b) + ((int) sqrt(delta)))/(2 * a);

            //reescrita dos pipes usados para futura leitura
            write(fd_1[1], &a, sizeof(int));
            write(fd_2[1], &b, sizeof(int));
            write(fd_4[1], &delta, sizeof(int));

            printf("Primeira raiz: %d\n", x1);

        }else{
            //criacao do processo son3, filho de son1
            pid_t son3 = fork();
            if(son3 == 0){
                //calculo de x2
                int a, b, delta, x2;

                //leitura das variaveis pelos respectivos pipes
                read(fd_1[0], &a, sizeof(int));
                read(fd_2[0], &b, sizeof(int));
                read(fd_4[0], &delta, sizeof(int));

                //calculo do segundo x
                x2 = (((-1) * b) - ((int) sqrt(delta)))/(2 * a);
                
                //reescrita dos pipes usados para futura leitura
                write(fd_1[1], &a, sizeof(int));
                write(fd_2[1], &b, sizeof(int));
                write(fd_4[1], &delta, sizeof(int));

                printf("Segunda raiz: %d\n", x2);
            }
        }
    }
    
    return 0;
}