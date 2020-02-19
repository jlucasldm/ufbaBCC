#include<stdio.h>
int main(){
    int n; //numero de movimentos
    int mov; //entrada com os números correspondentes aos movimentos
    int tab[8][8]; //matriz do tabuleiro
    int posicao[] = {4,4};
    int i;
    int j;
    int valido = 1;
    int cont = 0; //contagem, se bem sucedido o movimento
    int movimentos[8][2] = {{-2,1},{-1,2},{1,2},{2,1},
                            {2,-1},{1,-2},{-1,-2},{-2,-1}};

    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            tab[i][j]=1;
        }
    }

    tab[4][1] = 0; //definindo os buracos como "1" na matriz do tabuleiro
    tab[4][2] = 0; //definindo os buracos como "1" na matriz do tabuleiro
    tab[2][2] = 0; //definindo os buracos como "1" na matriz do tabuleiro
    tab[3][5] = 0; //definindo os buracos como "1" na matriz do tabuleiro

    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&mov);
        posicao[0]+= movimentos[mov-1][0];
        posicao[1]+= movimentos[mov-1][1];
        
        if(valido){
            cont++;
            valido = tab[posicao[0]][posicao[1]];
        }
    }
printf("%d\n",cont);
return 0;
}