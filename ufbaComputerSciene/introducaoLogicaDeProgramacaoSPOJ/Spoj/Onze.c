#include<stdio.h>
int main(){
    char num[1000];
    scanf("%s", num);

    while (num[0] != '0' || num[1]!='\0')
    {
        int resultado=0;
        int sinal = 1;
        int i;
        for(i=0;num[i]!='\0';i++){
            resultado += sinal*(num[i]-'0');
            sinal = sinal*(-1);
        }
        if((resultado % 11) != 0){
            printf("%s is not a multiple of 11.\n",num);
        }
        if((resultado % 11) == 0){
            printf("%s is a multiple of 11.\n",num);
        }
        scanf("%s", num);
    }
return 0;
}