# Trabalho Prático - 2022.1

__Objetivo__: Construir um compilador completo que aceita um programa em linguagem de alto nível como entrada e produz um programa equivalente em linguagem objeto como saída.

## Linguagens

* Linguagem fonte: linguagem de alto nível [ICL](./ICL)
* Linguagem objeto: linguagem de montagem __ICO__

## Atividades

+ Escrever um programa em ICL
+ [Implementar analisador léxico](./1-lexico)
+ Implementar analisador sintático
+ Implementar analisador semântico
+ Implementar gerador de código

### Analisador léxico

Construir um analisador léxico para ICL que lê um arquivo fonte e produz uma lista de tokens, um a um, anotados com seu tipo (identificador, inteiro, cadeia, etc.) e sua posição no arquivo fonte (número da linha). Se uma entrada inválida for descoberta, gerar uma mensagem de erro, fazer a recuperação do erro e continuar. Definir um conjunto de testes para descobrir casos de erros léxicos típicos, envolvendo cadeias, comentários, etc.

### Analisador sintático

Construir um analisador sintático para ICL, usando Bison, que lê um arquivo fonte com a especificação para linguagem ICL, determina se a gramática é válida, e indica sucesso ou falha na construção de um analisador para ICL.
Incluir ações para construir a AST para um programa ICL válido.


### Verificador de tipos

Com base na especificação válida para ICL em Bison, construir um verificador de tipos que percorre a AST e realizar análise semântica para determinar a correção do programa em ICL.

### Gerador de código

Construir um gerador de código que percorre a AST construída para o programa fonte em ICL e gera o programa objeto em ICO.

### Outros

* Prettyprint: Programa que percorre a AST construída para um programa ICL e gera sua representação no formato "_labelled bracket_".
