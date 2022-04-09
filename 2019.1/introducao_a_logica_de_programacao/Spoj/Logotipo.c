#include<stdio.h>
int main(){
    int x; //linhas
    int y; //colunas
    
    scanf("%d %d",&x,&y);
    while(x!=0 && y!=0){
    int entrada[x][y];
    int k; //quantidade de matrizes
    int m; //linhasM
    int n; //colunasN
    int contador = 0;
    int vezes = 1;
    int i;
    int j;
    int p;

    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            entrada[i][j]=0;
        }
    }

    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            scanf("%d",&entrada[i][j]);
        }
    }

    scanf("%d %d %d",&k,&m,&n);
    int logotipo[m][n];
    for(p=0;p<k;p++){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&logotipo[i][j]);
            }
        }
    }

    for(i=0; i<m; i++){
        for(j=0;j<n;j++){
            if(logotipo[i][j] == entrada[0][0]){
                int linha;
                int coluna;
                for(linha = 0; linha<x; linha++){
                    for(coluna = 0; coluna<y; coluna++){
                        if(coluna==y-1 && linha==x-1 && entrada[x-1][y-1]==logotipo[i+linha][j+coluna]){
                            contador++;
                        }
                    }
                }
            }
        }
    }

    printf("Logotipo %d\n%d\n",vezes,contador);
    vezes++;
    scanf("%d %d",&x,&y);
}
return 0;
}