#include<stdio.h>
int main(){
    int n; //numero de movimentos
    int mov[n]; //entrada com os números correspondentes aos movimentos
    int tab[8][8]; //matriz do tabuleiro
    int i;
    int j;
    int cont = 0; //contagem, se bem sucedido o movimento
    int x=4;
    int y=4;

    scanf("%d",&n);
    for(i =0; i<n; i++){
        scanf("%d",&mov[i]);
    }//entrada de quantos movimentos e quais serão realizados

    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            tab[i][j]=0;
        }
    }

    tab[4][1] = 1; //definindo os buracos como "1" na matriz do tabuleiro
    tab[4][2] = 1; //definindo os buracos como "1" na matriz do tabuleiro
    tab[2][2] = 1; //definindo os buracos como "1" na matriz do tabuleiro
    tab[3][5] = 1; //definindo os buracos como "1" na matriz do tabuleiro

    for(i=0; i<n; i++){
        if(mov[i]==1){
            x+=1;
            y-=2;
            if(tab[x][y] != 1){
                cont++;
            }
            if(tab[x][y] == 1){
                break;
            }
        }
        else if(mov[i]==2){
            x+=2;
            y-=1;
            if(tab[x][y] != 1){
                cont++;
            }
            if(tab[x][y] == 1){
                break;
            }
        }
        else if(mov[i]==3){
            x+=2;
            y+=1;
            if(tab[x][y] != 1){
                cont++;
            }
            if(tab[x][y] == 1){
                break;
            }
        }
        else if(mov[i]==4){
            x+=1;
            y+=2;
            if(tab[x][y] != 1){
                cont++;
            }
            if(tab[x][y] == 1){
                break;
            }
        }
        else if(mov[i]==5){
            x-=1;
            y+=2;
            if(tab[x][y] != 1){
                cont++;
            }
            if(tab[x][y] == 1){
                break;
            }
        }
        else if(mov[i]==6){
            x-=2;
            y+=1;
            if(tab[x][y] != 1){
                cont++;
            }
            if(tab[x][y] == 1){
                break;
            }
        }
        else if(mov[i]==7){
            x-=2;
            y-=1;
            if(tab[x][y] != 1){
                cont++;
            }
            if(tab[x][y] == 1){
                break;
            }
        }
        else if(mov[i]==8){
            x-=1;
            y-=2;
            if(tab[x][y] != 1){
                cont++;
            }
            if(tab[x][y] == 1){
                break;
            }
        }
        
    }
    printf("%d\n",cont);
    return 0;
}