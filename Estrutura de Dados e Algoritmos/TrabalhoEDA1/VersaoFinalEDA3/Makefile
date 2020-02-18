
a.out: no.o fila.o listaCirc.o pilha.o
	gcc -Wall -Wextra -Werror -Wpedantic  main.c no.o fila.o pilha.o listaCirc.o -lm
	
no.o : no.c
	gcc -Wall -Wextra -Werror -Wpedantic -c no.c -o no.o -lm

fila.o: fila.c
	gcc -Wall -Wextra -Werror -Wpedantic -c fila.c -o fila.o -lm

listaCirc.o: listaCirc.c
	gcc -Wall -Wextra -Werror -Wpedantic -c listaCirc.c -o listaCirc.o -lm

pilha.o: pilha.c
	gcc -Wall -Wextra -Werror -Wpedantic -c pilha.c -o pilha.o -lm
