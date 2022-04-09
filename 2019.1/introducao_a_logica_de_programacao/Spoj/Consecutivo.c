#include <stdio.h>
int main()
{
    int N;
    int novo;
    int i;
    int antigo=0;
    int maior=0;
    int valor=0;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &novo);
        if(antigo==novo){
        valor++;}

        else{
            if(valor>maior){
            maior=valor;
            antigo=novo;
            valor=1;}

            else{
            antigo = novo;
            valor = 1;
            }
        }
    if(valor > maior){
    maior = valor;}
    }
printf("%d\n",maior);
return 0;
}