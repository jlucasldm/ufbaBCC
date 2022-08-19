# A Linguagem ICL

## Aspectos Léxicos

As unidades léxicas são:
- números inteiros
- identificadores (de tipo, de objeto, especiais)
- strings
- palavras-chave
- símbolos.

Outros elementos a considerar:
- espaços em branco
- comentários
- erros léxicos.

### Inteiros (NUM) e identificadores (ID)

- Inteiros (NUM) são cadeias não vazias de dígitos de 0 a 9.
- Identificadores (ID) são cadeias de caracteres (exceto palavras-chave) 
iniciadas por letra (a-zA-Z) ou caractere sublinhado ```_```, e seguido por 
0 ou mais ocorrências de  letras, dígitos de 0 a 9 ou ```_```.
   - Identificadores _de tipos_ começam com uma letra maiúscula.
   - Identificadores _de objetos_ começam com uma letra minúscula.

Há dois outros identificadores, ```self``` e ```SELF TYPE``` 
que são considerados como especiais pela linguagem, 
mas que não são tratados como palavras-chave. 

### Strings

Strings são cadeias de caracteres colocadas entre aspas duplas ```" e "```.
Dentro de uma string, uma sequência ‘\c’ denota o caractere ‘c’, com as seguintes exceções:
```
\b backspace 
\t tab
\n newline 
\f formfeed
```

O caractere de espacejamento \n,  se não for precedido por _escape_ "\\" não pode aparecer em uma string:
```
-- string continua na próxima linha
"Esse exemplo \  
está bom"
```
```
-- sem caractere de escape
"Esse não está  
OK"
```

- Uma string não pode conter EOF.
- Uma string não pode conter _null_ (caractere \0).
- Qualquer outro caractere pode ser incluído em uma string. 
- Strings não podem cruzar os limites do arquivo (abre e fecha aspas no mesmo arquivo).

(Obs.: Refletir sobre o uso de ```%x STRING```.)

### Palavras-chave (_keywords_)

As palavras-chave de ICL são reservadas.

```
case, esac, of, class, else, fi, if, then, in, inherits, 
isvoid, let, while, loop, pool, new, not, true, false
``` 

Exceto pelas constantes *true* e *false*, 
as palavras-chave não diferenciam maiúsculas de minúsculas. 
Por exemplo, os lexemas if, iF, If e IF representam a palavra-chave _if_.

Para estar em conformidade com as regras para outros objetos, 
_a primeira letra das constantes true e false deve ser minúscula_ e
as letras finais podem ser maiúsculas ou minúsculas.

### Símbolos especiais

```
.
@
~ 
* / 
+ -
<=  <  = 
<-
=>
: ; , 
(  ) 
{  } 
``` 

O contexto de uso de cada símbolo será apresentado abaixo.

### Caracteres de espacejamento (_white space_) 

Caracteres de espacejamento
consistem em qualquer sequência de caracteres: 

```
espaço em branco (ascii 32), 
\n (nova linha, ascii 10), 
\f (form feed, ascii 12), 
\r (retorno de carro, ascii 13), 
\t (tab, ascii 9), 
\v (vertical tab, ascii 11).
```
###  Comentários

Há apenas uma forma de comentário em ICL. 
Quaisquer caracteres entre dois traços “--” e o próximo \n  
(ou EOF, se não houver \n) são tratados como comentário de uma linha.

### Erros Léxicos

+ Caracter desconhecido, por exemplo, '?'
+ String inválida (com '\0')
+ String inválida (mais de uma linha sem '\')
+ Final de arquivo encontrado
   - String aberta, sem aspas no final.

## Exemplos

#### comentário

```
-- isso é um comentário de uma linha
```

#### caracter desconhecido

```
-- linha 20
a ? b

(21, ID, "a")
(21, ERROR, "?")
(21, ID, "b")
```

#### cadeia mal-formada (falta o caracter de escape antes de \n)
```
-- linha 4
s <- "uma cadeia 
com mais 
de uma linha \0"


(5, ID, "s")
(5, SYM, "<-")
(5, ERROR, "...") ???

```

