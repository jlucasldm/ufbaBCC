#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#define N 20
 
sem_t homem, mulher, banheiro;
int conta_homem, conta_mulher;
void mulher_quer_entrar();
void mulher_sai();
void mulher_usa_banheiro();
void adiciona_mulher();
void homem_quer_entrar();
void homem_sai();
void homem_usa_banheiro();
void adiciona_homem();
 
int main() {
    conta_mulher = 0;
    conta_homem = 0;
    pthread_t thread[N];
 
    /* Inicializando os semaforos */
    int i, res_parc, res = 0;
    res_parc = sem_init(&homem, 0, 1);
    res += res_parc;
    res_parc = sem_init(&mulher, 0, 1);
    res += res_parc;
    res_parc = sem_init(&banheiro, 0, 1);
    res += res_parc;
    if (res != 0) {
        perror("Falha na inicializacao dos semaforos\n");
        exit(EXIT_FAILURE);
    }
 
    /* Inicializando threads */
    for (res = 0, i = 0; i < N; i++) {
        usleep(rand() % 300000);
        if (rand() % 2 != 0)
            res_parc = pthread_create(&thread[i], NULL,
                    (void*) adiciona_mulher, (int*) (i + 1));
        else
            res_parc = pthread_create(&thread[i], NULL, (void*) adiciona_homem,
                    (int*) (i + 1));
        res += res_parc;
    }
    if (res != 0) {
        perror("Erro em criacao de threads\n");
        exit(EXIT_FAILURE);
    }
    /* Juntando threads */
    for (i = 0; i < N; i++) {
        res_parc = pthread_join(thread[i], NULL);
        res += res_parc;
    }
    if (res != 0) {
        perror("Erro em join threads\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

void mulher_usa_banheiro() {
    usleep(rand() % 500000);
}
 
void adiciona_mulher() {
    usleep(rand() % 400000);
    mulher_quer_entrar();
    mulher_usa_banheiro();
    mulher_sai();
    pthread_exit();
}

void homem_usa_banheiro() {
    usleep(rand() % 300000);
}
 
void adiciona_homem() {
    usleep(rand() % 400000);
    homem_quer_entrar();
    homem_usa_banheiro();
    homem_sai();
    pthread_exit();
}
 
void mulher_quer_entrar() {
    sem_wait(&mulher);    //aguardando pra entrar
    conta_mulher += 1;
    if (conta_mulher == 1) {
        sem_wait(&banheiro);    //tem gente no banheiro
        printf("--------- Estado: Com mulher ---------\n");
    }
    printf("Entrou mulher, total: %d\n", conta_mulher);
    sem_post(&mulher);    //a mulher conseguiu entrar
}

void mulher_sai() {
    sem_wait(&mulher);
    conta_mulher -= 1;
    printf("Saiu mulher, total: %d\n", conta_mulher);
    if(conta_mulher == 0){
        sem_post(&banheiro);
        printf("--------- Estado: Vazio ---------\n");
    }
    sem_post(&mulher);
}
 
void homem_quer_entrar() {
    sem_wait(&homem);  
    conta_homem += 1;
    if(conta_homem == 1){
        sem_wait(&banheiro);
        printf("--------- Estado: Com homem ---------\n");
    }
    printf("Entrou homem, total: %d\n", conta_homem);
    sem_post(&homem);
}
 
void homem_sai() {
    sem_wait(&homem);
    conta_homem -= 1;
    printf("Saiu homem, total: %d\n", conta_homem);
    if(conta_homem == 0){
        sem_post(&banheiro);
        printf("--------- Estado: Vazio ---------\n");
    }
    sem_post(&homem);
}