# Name of the project
PROJ_NAME=iclc

# .c files
C_SOURCE=$(wildcard *.c)

# .h files
H_SOURCE=$(wildcard *.h)

# Object files
OBJ=$(C_SOURCE:.c=.o)

# Compiler
CC=gcc

# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -ansi

# compilation and linking

all: $(PROJ_NAME)

$(PROJ_NAME): iclc.tab.o lex.yy.o
	@ echo 'Building binary using GCC linker: $@'
	$(CC) -o $@ $^
	@ echo 'Finished building binary: $@'
	@ echo ' '

iclc.tab.o: iclc.tab.c iclc.tab.h
	@ echo 'Building target using GCC compiler: $<'
	$(CC) -o $@ $< $(CC_FLAGS)
	@ echo ' ' 

lex.yy.o: lex.yy.c iclc.tab.h
	@ echo 'Building target using GCC compiler: $<'
	$(CC) -o $@ $< $(CC_FLAGS)
	@ echo ' ' 

# flex and bison

lex.yy.c: ./src/iclc.l
	@ echo 'Generating $@'
	flex ./src/iclc.l
	@ echo ' ' 

iclc.tab.c: ./src/iclc.y
	@ echo 'Generating $@'
	bison -d ./src/iclc.y
	@ echo ' ' 

clean:
	rm -rf *.o *~ lex.yy.c iclc.tab.* $(PROJ_NAME)

.PHONY: all clean

