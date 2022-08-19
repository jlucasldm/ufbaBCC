/* 
 * Template de programa bison para T1
 * Serve apenas para definir tokens associados ao analisador léxico implentado com flex.
 * Executar  'bison -d iclc.y' para gerar arquivos iclc.tab.c e iclc.tab.h.
 */

%{
/* includes, C defs */

#include <stdio.h>

void yyerror(const char* msg) {
      fprintf(stderr, "%s\n", msg);
}

int yylex();
%}

/* declare tokens */

%token ID
%token KEY
%token NUM
%token STRING
%token SYM
%token ERROR
%token TEST

%%

program: 
/* void */

%%



