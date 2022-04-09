#include<stdio.h>

int matriz[2000][2000] = {0};
int main () {
    int x, y, l, c, n;

    while (1){
        scanf("%d",&n);
        if (n == 0) break;
        /*
        Declarando uma matriz com dobro de tamanho para ter margem,
        e zerando toda ela;
        Area é o área e borda mostrará o perimetro;
        */
        int area = 0, borda = 0;

        /*
        Lendo os valores das coordenadas e dos tamanhos.
        Cada local, que faz parte do terreno, será representado com '1';
        Quando o coloca esse '1', as coordenadas (matriz[j+1][k+1]) são
        somadas uma unidade a mais, para que quando for ler as bordas,
        não dê nenhum tipo de erro, por este motivo também que a matriz
        é maior do que o tamanho máximo da questão;
        */

       for (int i = 0; i < 2000; i++){
            for (int j = 0; j < 2000; j++){
                    matriz[i][j]=0;
            }
        }

        for (int p = 0; p < n; p++){
            scanf("%d%d%d%d",&x,&y,&l,&c);
            for (int j = x; j < x + l; j++){
                for (int k = y; k < y+ c; k++) matriz[j+1][k+1] = 1;
            }
        }

        /*
        Procura todos os '1' da matriz, e quando acha, adiciona mais 1km2 a
        area, assim temos a área total
        Após isso, irá verificar todas as coordenadas em volta do '1'
        encontrado buscando um '0', caso ache, soma-se mais uma unidade a
        borda, e assim encontra o perimetro;
        */
        for (int i = 0; i < 2000; i++){
            for (int j = 0; j < 2000; j++){
                if (matriz[i][j] == 1) {
                    area++;
                    if (matriz[i][j+1] == 0) borda++;
                    if (matriz[i][j-1] == 0) borda++;
                    if (matriz[i+1][j] == 0) borda++;
                    if (matriz[i-1][j] == 0) borda++;
                }
            }
        }

        printf("%d %d\n",area,borda);
    }
    return 0;
}