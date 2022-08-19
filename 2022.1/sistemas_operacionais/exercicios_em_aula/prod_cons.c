#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define FALSE 0
#define TRUE 1

#define N 20

struct timespec t;

sem_t  mutex, empty, full;
//empty: semaforo utilizado pra controlar os sinais relativos as posicoes vazias no buffer
//full: semaforo utilizado pra controlar os sinais relativos as posicoes preenchidas no buffer
//mutex: semaforo binário utilizado p/ garantir exclusao mutua na regiao critica   

int buffer[N], lo, hi, count;
// buffer: utilizado para armazenar os dados produzidos pelo produtor e consumidos pelo consumidor
//lo: proxima posicao cheia
//hi: proxima posicao vazia
//count: usado para controlar a quantidade de dados presentes no buffer

void *producer(void *);
void *consumer(void *);

int main(void)
{
	//Seta a semente da funcao geradora de numeros aleatorios
	srand(time(NULL));

	count = 0;
	lo = 0;
	hi = 0;

	/*Inicializa os semaforos
	1o parametro: variavel semaforo
	2o parametro: indica se um semaforo sera compartilhado entre as threads de um processo ou entre processos
		      o valor 0 indica q/ o semaforo sera compartilhado entre as threads de um processo	(digit o comando
		      "man sem_init" no shell do linux p/ ver os detalhes)
	3o parametro: valor inicial do semaforo
	*/ 
	sem_init (&mutex, 0 , 1);
	sem_init(&empty, 0, N);
	sem_init(&full, 0, 0);
	
	pthread_t thd0, thd1;

	/*
	Incializa as threads
	1o parametro: variavel thread
	2o parametro: indica se uma thread é "joinable", ou seja, se a thread nao sera finalizada ate chegar a uma chamada de funcao
		      pthread_join().
	3o parametro: indica o nome do metodo que irá compor o trecho de codigo q/ sera executado pela thread
	4o parametro: utilizado qdo se necessita passar algum paramentro a thread. Pode se passar quaisquer tipos de dados,
		      inclusive uma estrutura de dados qdo houver a necessidade de passar mais de um parametro.
		      (dentro do método chamado realiza-se um cast p/ recuperar os dados)	
	*/
	pthread_create(&thd0, 0, (void *) producer, NULL);
	pthread_create(&thd1, 0, (void *) consumer, NULL);

	//Esses dois metodos indicam q/ a tread não será finalizada até ocorrer a chamada dos mesmos (como mencionado anteriormente)
	pthread_join(thd0,0);
	pthread_join(thd1,0);
	
	exit(0);
}


// Metodo que produz os itens q/ serao inseridos no buffer (numeros aleatorios)
int produce_item()
{
	int val;
	val = rand() % 100;
	printf("\nProduzindo item: %d", val);
	return val;
}

// Metodo utilizado p/ mostra o valor q foi consumido (meramente implementado p/ fins didáticos)
void consume_item(int item)
{
	printf("\nCosumindo item: %d", item);
	if (count == 0)
		printf("\n####Vazio\n");
}

//Metodo que a realiza a insercao do dado no buffer
void insert_item(int val)
{
	if(count < N)
	{
		buffer[hi] = val;
		// A utilizacao da divisao em modulo implementa um comportamento circular da utilizacao do buffer
		// ou seja, qdo o contador chegar no valor de N (N % N = 0) o valor da variavel voltara ao inicio do buffer
		hi = (hi + 1) % N; 
		count = count + 1;
		if(count == N)
			printf("\n############## Buffer completo ##############");
	}
}

// Metodo que realiza a retirada do dado do buffer
int remove_item()
{
	int val;
	if(count > 0)
	{
		val = buffer[lo];
		lo = (lo + 1) % N;
		count = count - 1;
		return val;
	}
}

void *producer(void *p_arg)
{
	int item;
	
	while(TRUE)
	{
		item = produce_item();
		
	        // sem_wait (realiza o down no semaforo (ver pag. 81 do livro Sistemas Operacionais - 2a ediçao - Tanenbaum ))
		// sem_post (realiza o up no semaforo)
		sem_wait(&empty);
		sem_wait(&mutex);
		insert_item(item);
		sem_post(&mutex);
		sem_post(&full);

	}
}

void *consumer(void *p_arg)
{
	int item;

	while(TRUE)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		item = remove_item();
		sem_post(&mutex);
		sem_post(&empty);
		consume_item(item);
		
		
	}
}
