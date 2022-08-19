#include <stdio.h>

#include "registros.h"

#include "constroiArvore.h"
#include "imprimeIndiceArvore.h"
#include "insereRegistro.h"
#include "consultaSimples.h"
#include "consultaFaixaAutores.h"
#include "consultaFaixaAnos.h"
#include "consultaFaixaAutoresAnos.h"
#include "imprimePagina.h"
#include "consultaPalavraArvore.h"
#include "consultaPalavraAutorTitulo.h"
#include "tabelaPiPalavra.h"

const int NREGSPORPAGINA = 3;

/*
 * Contém a lógica de entrada básica e chama as outras funções a depender da operação escolhida
 * As entradas seguem a especificação fornecida, chamando as funções de acordo com a operação solicitada
 * */

int main(){
    constroiArvore();
    Livro livro;
    int a1, a2, p;
    char entrada, n1[21], n2[21], palavra[31];
    scanf(" %c", &entrada);

    while (entrada != 'e'){
        switch (entrada){
            case 'i':
                scanf(" %[^\n\r]", livro.autor);
                scanf(" %[^\n\r]", livro.titulo);
                scanf(" %d", &livro.ano_publicacao);
                scanf(" %[^\n\r]", livro.nome_arquivo);
                insereRegistro(livro);
                printf("inserido registro com nome: %s\n", livro.autor);
                break;
            case 'c':
                scanf(" %[^\n\r]", livro.autor);
                bool achouNome = consultaSimples(livro.autor);
                if(!achouNome) {
                    printf("nao foi encontrado registro com nome: %s\n", livro.autor);
                }
                break;
            case 'n':
                scanf(" %[^\n\r]", n1);
                scanf(" %[^\n\r]", n2);
                consultaFaixaAutores(n1, n2);
                break;
            case 'a':
                scanf(" %d", &a1);
                scanf(" %d", &a2);
                consultaFaixaAnos(a1, a2);
                break;
            case 'q':
                scanf(" %[^\n\r]", n1);
                scanf(" %[^\n\r]", n2);
                scanf(" %d", &a1);
                scanf(" %d", &a2);
                consultaFaixaAutoresAnos(n1, n2, a1, a2);
                break;
            case 't':
                imprimeIndiceArvore();
                break;
            case 'p':
                scanf(" %d", &p);
                imprimePagina(p);
                break;
            case 'f':
                scanf(" %[^\n\r]", palavra);
                bool achouPalavra = consultaPalavraArvore(palavra);
                if(!achouPalavra) {
                    printf("nao ha ocorrencia da palavra: %s\n", palavra);
                }
                break;
            case 'w':
                scanf(" %[^\n\r]", palavra);
                scanf(" %[^\n\r]", livro.autor);
                scanf(" %[^\n\r]", livro.titulo);
                bool achouObra = consultaPalavraAutorTitulo(palavra, livro.autor, livro.titulo);
                if(!achouObra) {
                    printf("obra inexistente: titulo: %s - autor: %s\n", livro.titulo, livro.autor);
                }
                break;
            case 'm':
                scanf(" %[^\n\r]", palavra);
                tabelaPiPalavra(palavra);
                break;
            default:
                break;
        }

        scanf(" %c", &entrada);
    }

    return 0;
}