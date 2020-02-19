a.out:	avl.o
	@gcc main.c avl.o
	@./a.out

avl.o:	avl.c
	@gcc -c avl.c -o avl.o

clear:
	@rm -rf *.o
	@rm -rf a.out