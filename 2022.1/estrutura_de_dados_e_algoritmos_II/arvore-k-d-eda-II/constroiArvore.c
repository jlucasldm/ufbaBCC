#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constroiArvore.h"

#include "registros.h"
#include "utils.h"

#include "inicializaPaginas.h"

/*
 * Função responsável por criar o índice da aplicação, uma árvore k-d de
 * duas dimensões que itera sobre nome_de_autor nos índices pares e ano_de_publicação
 * em índices ímpares. O índice é construído utilizando estruturas do tipo NoAno e NoAutor,
 * armazenado em um arquivo arvore.dat.
 *
 * Os valores dos registros utilizados na construção da árvore são recebidos, instancializados
 * em um livro e armazenados em um arquivo auxiliar reg.dat para serem então inseridos em páginas.
 * */

void constroiArvore(){
    FILE *f;
    FILE *a;

    f = fopen("arvore.dat", "rb+");

    //caso nao exista o indice
    if(f == NULL){
        //indice da arvore
        if(!(f = fopen("arvore.dat", "wb+"))){
            printf ("Erro na criacao do arquivo \"indice.dat\".\n");
			exit(-1);
        }

        //arquivo auxiliar para armazenar os livros usados para construcao do indice
        if(!(a = fopen("reg.dat", "wb+"))){
            printf ("Erro na criacao do arquivo \"indice.dat\".\n");
            exit(-1);
        }

        Livro l;
        int n_registros;

        scanf(" %d", &n_registros);

        for(int i = 0; i < n_registros; i++) {

            scanf(" %[^\n\r]", l.autor);
            scanf(" %[^\n\r]", l.titulo);
            scanf(" %d", &l.ano_publicacao);
            scanf(" %[^\n\r]", l.nome_arquivo);

            fwrite(&l, sizeof (Livro), 1, a);

            fseek(f, 0, SEEK_END);
            bool empty = ftell(f) == 0;
            fseek(f, 0, SEEK_SET);

            if(empty) {
                //criacao da raiz do indice
                NoAutor root;
                strcpy(root.autor, l.autor);
                root.dir = false;
                root.esq = false;
                fwrite(&root, sizeof(NoAutor), 1, f);
            }else{
                int index = 1;
                int profundidade = 0;
                bool not_found = true;
                while (not_found) {
                    NoAutor no_a;
                    NoAno no_b;
                    profundidade % 2 == 0 ? fread(&no_a, sizeof(NoAutor), 1, f) : fread(&no_b, sizeof(NoAno), 1, f);

                    int bit_a = profundidade % 2 == 0 ? sizeof(NoAutor) : sizeof(NoAno);
                    int bit_b = profundidade % 2 == 0 ? sizeof(NoAno) : sizeof(NoAutor);

                    //CASO A VERIFICAÇÃO FOR MENOR OU IGUAL VAI PARA O NODE DA ESQUERDA CASO FOR MAIOR VAI PARA O NODE DA DIREITA
                    if (profundidade % 2 == 0 ? strcmp(l.autor, no_a.autor) <= 0 : l.ano_publicacao <= no_b.ano) {
                        //ESQUERDA
                        int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
                        int offset_b = bit_b * ((index*2) - int_pow(2, profundidade + 1)); //CERTO
                        index *= 2;

                        //CASO NÃO EXISTA UM NODE NA ESQUERDA
                        if(profundidade % 2 == 0 ? !no_a.esq : !no_b.esq) {
                            //ATUALIZAMOS O NODE LIDO PARA DIZER QUE VAI TER ALGO A SUA ESQUERDA
                            if(profundidade % 2 == 0) {
                                no_a.esq = true;
                                fseek(f, -sizeof(NoAutor), SEEK_CUR);
                                fwrite(&no_a, sizeof(NoAutor), 1, f);
                            } else {
                                no_b.esq = true;
                                fseek(f, -sizeof(NoAno), SEEK_CUR);
                                fwrite(&no_b, sizeof(NoAno), 1, f);
                            }

                            fseek(f, offset_a + offset_b, SEEK_CUR);

                            if(profundidade % 2 == 0) {
                                NoAno leaf;
                                leaf.esq = false;
                                leaf.dir = false;
                                leaf.ano = l.ano_publicacao;
                                fwrite(&leaf, sizeof(NoAno), 1, f);
                                fseek(f, -sizeof(NoAno), SEEK_CUR);
                            }else{
                                NoAutor leaf;
                                leaf.esq = false;
                                leaf.dir = false;
                                strcpy(leaf.autor, l.autor);
                                fwrite(&leaf, sizeof(NoAutor), 1, f);
                                fseek(f, -sizeof(NoAutor), SEEK_CUR);
                            }

                            not_found = false;
                        }else{
                            fseek(f, offset_a + offset_b, SEEK_CUR);
                        }
                    }else{
                        //DIREITA
                        int offset_a = bit_a * (int_pow(2, profundidade + 1) - (index + 1)); //CERTO
                        int offset_b = bit_b * (((index*2)+1) - int_pow(2, profundidade + 1)); //CERTO
                        index *= 2;
                        index++;

                        //CASO NÃO EXISTA UM NODE NA DIREITA
                        if(profundidade % 2 == 0 ? !no_a.dir : !no_b.dir) {
                            //ATUALIZAMOS O NODE LIDO PARA DIZER QUE VAI TER ALGO A SUA ESQUERDA
                            if(profundidade % 2 == 0) {
                                no_a.dir = true;
                                fseek(f, -sizeof(NoAutor), SEEK_CUR);
                                fwrite(&no_a, sizeof(NoAutor), 1, f);
                            } else {
                                no_b.dir = true;
                                fseek(f, -sizeof(NoAno), SEEK_CUR);
                                fwrite(&no_b, sizeof(NoAno), 1, f);
                            }

                            fseek(f, offset_a + offset_b, SEEK_CUR);

                            if(profundidade % 2 == 0) {
                                NoAno leaf;
                                leaf.esq = false;
                                leaf.dir = false;
                                leaf.ano = l.ano_publicacao;
                                fwrite(&leaf, sizeof(NoAno), 1, f);
                                fseek(f, -sizeof(NoAno), SEEK_CUR);
                            }else{
                                NoAutor leaf;
                                leaf.esq = false;
                                leaf.dir = false;
                                strcpy(leaf.autor, l.autor);
                                fwrite(&leaf, sizeof(NoAutor), 1, f);
                                fseek(f, -sizeof(NoAutor), SEEK_CUR);
                            }

                            not_found = false;
                        }else{
                            fseek(f, offset_a + offset_b, SEEK_CUR);
                        }
                    }
                    profundidade++;
                }
            }
        }

        fclose(a);

        printf("arvore k-d gerada\n");

        //insercao dos livros usados para construcao do indice em suas respectivas paginas
        inicializaPaginas();
    }

    fclose(f);
}