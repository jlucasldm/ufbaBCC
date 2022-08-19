/*
Discente: João Lucas Lima de Melo

Olá, professor. Tive muitos problemas ao longo da semana com trabalhos de outras disciplinas.
Não consegui concluir minhas outras atividades até 23:12 da noite de domingo 01/05. O código abaixo é resultado das poucas interações
que tive com exemplos e explicações do problema dos filósofos proposta na última semana. Quis com esse código apenas deixar registrado 
uma tentativa de solução.
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
 
#define N 5
#define ESQUERDA (phnum + 4) % N
#define DIREITA (phnum + 1) % N
#define FOME 1
#define COMENDO 0
#define PENSANDO 2
 
int mesa[N];
int filosofos[N] = { 0, 1, 2, 3, 4 };
 
sem_t mutex;
sem_t S[N];

void pega_garfo(int phnum){
    sem_wait(&mutex);
 
    mesa[phnum] = FOME;
 
    printf("filosofo %d com fome\n", phnum + 1);
    test(phnum);
    sem_post(&mutex);
    sem_wait(&S[phnum]);
 
    sleep(1);
}

void abaixa_garfo(int phnum){
    sem_wait(&mutex);
    mesa[phnum] = PENSANDO;
 
    printf("filosofo %d colocando os garfos %d e %d para baixo\n", phnum + 1, ESQUERDA + 1, phnum + 1);
    printf("filosofo %d pensando\n", phnum + 1);
 
    test(ESQUERDA);
    test(DIREITA);
 
    sem_post(&mutex);
}
 
void* filosofo(void* num){
    while (1) {
        int* i = num;
        sleep(1);
        pega_garfo(*i);
        sleep(0);
        abaixa_garfo(*i);
    }
}

void test(int phnum){
    if (mesa[phnum] == FOME && mesa[ESQUERDA] != COMENDO && mesa[DIREITA] != COMENDO){
        mesa[phnum] = COMENDO;
        sleep(2);
        printf("filosofo %d pega os garfos %d e %d\n", phnum + 1, ESQUERDA + 1, phnum + 1);
        printf("filosofo %d comendo\n", phnum + 1);

        sem_post(&S[phnum]);
    }
}
 
int main(){
    int i;
    pthread_t thread_id[N];

    sem_init(&mutex, 0, 1);
 
    for (i = 0; i < N; i++){
        sem_init(&S[i], 0, 0);
    }

    for (i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, filosofo, &filosofos[i]);
        printf("filosofo %d pensando\n", i + 1);
    }
 
    for (i = 0; i < N; i++){
        pthread_join(thread_id[i], NULL);
    }

    return 0;
        
}