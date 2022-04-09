#include<stdio.h>
int main(){
    int rodada = 1;
    while (1){
        int x, y; //linhas e colunas da matriz logotipo
        scanf("%d %d",&x,&y);
        if(x==0 && y==0) break;
        int logotipo[x][y];
        int i, j, p, l, w;
        
        for(i = 0; i < x; i++){
            for(j = 0; j < y; j++){
                scanf("%d", &logotipo[i][j]);
            }
        }

        int k; //k matrizes
        int m; //dimensão de m linhas
        int n; //dimensão de n coluna
        
        scanf("%d %d %d",&k,&m,&n);
        int quantidade = 0;

        for(w = 0; w < k; w++){
            int emTela[m][n];
            for(i = 0; i < m; i++){
                for(j = 0; j < n; j++){
                    scanf("%d",&emTela[i][j]);
                }
            }
            
            for(i = 0; i <= m - x; i++){
                for(j = 0; j <= n - y; j++){
                    int valido = 1;
                    for(p = i; p < i + x; p++){
                        for(l = j; l < j + y; l++){
                            if(emTela[p][l] != logotipo[p - i][l - j]){
                                valido = 0;
                                break;
                            } 
                        }
                        if(!valido) break;
                    }
                    if(valido) quantidade++;
                }
            }
        }


        printf("Logotipo %d\n", rodada);
        printf("%d\n\n",quantidade);

        rodada++;
    }

return 0;   
}