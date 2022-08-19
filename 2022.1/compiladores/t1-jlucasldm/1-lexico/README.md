# Projeto de um Compilador
  
## Parte I: Análise Léxica

Nesta parte do projeto, você irá implementar um analisador léxico para a [linguagem ICL](../ICL).
O analisador léxico ou _scanner_ deve ler um programa fonte e produzir uma lista de _tokens_, 
sequencialmente, um _token_ de cada vez, anotado com as seguintes informações: 
sua localização no código fonte (linha), tipo do _token_ (ID, NUM, etc) e seu lexema ("main", "123", etc.).
Se uma entrada inválida for encontrada, ele deve informar _ERROR_, anotado também com a linha e com o lexema incorreto.

Antes de iniciar a sua implementação, recomendamos que leia com atenção o [capítulo 3](../../resources/20-chapter3.pdf) 
do livro "Introduction to Compilers and Language Design" de Douglas Thain. 
Apesar da sintaxe de ICL ser diferente da usada nesse livro, os exemplos de código e o material podem ser extremamente úteis.

## Classes de _tokens_

Em sua implementação do analisador léxico, considere as seguintes classes de _tokens_ da linguagem:

__ID__      Identificador

__NUM__     Literal decimal (integer)

__STRING__  Cadeia de caracteres entre ""

__KEY__     Keyword (palavra-chave)

__SYM__     Símbolo Léxico

__ERROR__   Lexema do primeiro erro encontrado

Comentários e caracteres de espacejamento (_white space_) devem ser descartados durante a fase de análise léxica do compilador. 

O analisador léxico __não__ deve parar após encontrar o primeiro erro léxico.
Deve-se imprimir o número da linha na qual o _token_ foi encontrado, inclusive em caso de erro. 
No caso de strings, deve-se imprimir o número da linha em que a string começa (abre aspas).

No caso de erro léxico encontrado, retornar o _token_ __ERROR__.
No caso de erro léxico relacionado a strings, retornar a string mal-formada no campo "lexema".

O formato de saída, para todas as classes de tokens é:

``` (line_num,token_class,"lexeme") ```

## Exemplo 1 (hello.icl)

```
class Main inherits IO {   -- classe, herança

   main(): Object { out_string("Hello World!\n") }; -- self implicito
   
};
```
### Arquivo de saída hello.s gerado pelo analisador léxico

Após a execução do analisador léxico de ICL, tendo como entrada o arquivo contendo um programa-fonte em ICL (hello.icl)
a saída deverá ser gerada no arquivo hello.s:
```
(1,KEY,"class")
(1,ID,"Main")
(1,KEY,"inherits")
(1,ID,"IO")
(1,SYM,"{")
(3,ID,"main")
(3,SYM,"(")
(3,SYM,")")
(3,SYM,":")
(3,ID,"Object")
(3,SYM,"{")
(3,ID,"out_string")
(3,SYM,"(")
(3,STRING,""Hello World!\n"")
(3,SYM,")")
(3,SYM,"}")
(3,SYM,";")
(5,SYM,"}")
(5,SYM,";")
``` 

## Exemplo 2 (string.icl)

```
1
hello
"hello"
"hello\n"
2
"hello \
folks"
3
"hello
folks"
4
"hello \
my \
folks!"
```

### Arquivo de saída string.s

Após a execução do analisador léxico de ICL, tendo como entrada o arquivo string.icl,
a saída deverá ser gerada no arquivo string.s:
```
(1,NUM,"1")
(2,ID,"hello")
(3,STRING,""hello"")
(4,STRING,""hello\n"")
(5,NUM,"2")
(6,STRING,""hello \
folks"")
(8,NUM,"3")
(9,ERROR,""hello
folks"")
(11,NUM,"4")
(12,STRING,""hello \  
my \   
folks!"")
```
## Scripts

Observar que há dois arquivos na pasta: __makefile__ e __run_compiler.sh__ para compilar e executar o seu código:

+ Usa a ferramenta Flex com seu arquivo, obrigatoriamente chamado de iclc.l
```
make       // roda flex, bison, gcc
make all   // idem
make clean // apaga arquivos
```
+ __run_compiler.sh__ (recebe um argumento, o nome do arquivo de entrada com extensão .icl) 
compila (faz análise léxica, por enquanto) e gera arquivo de saída (mesmo nome, com extensão .s)
```
./run_compiler.sh hello.icl // executa o analisador léxico com entrada hello.icl e gera a saída (hello.s)
```

## Como executar sem run_compiler (dois argumentos: entrada e saída)

Seu analisador léxico deve ler um arquivo-fonte (_source_) com extensão ".icl", da entrada padrão e escrever em outro arquivo (_target_), com extensão ".s", na saída padrão.

```
$ ./iclc < hello.icl > hello.s
```

__Observação Importante sobre__ ___Line Endings___: 
Arquivos de texto criados com DOS/Windows machines usam _carriage return_ _line feed_ ("\r\n") para terminar uma linha, 
enquando que os criados com Unix usam apenas o _line feed_ ("\n").

## Desenvolvimento no GitHub

A atribuição do trabalho prático 1 (T1), com data de entrega serão realizadas no Classroom da turma.
