a.out:	avl.o
	@cc -Wall -Wextra -Werror -Wpedantic main.c avl.o

avl.o:	avl.c
	gcc -c avl.c -o avl.o

clear:
	rm -rf *.o
	rm -rf a.out