#include <stdio.h>
int main()
{
    int maior = 0;
    int a, v, x, y, T = 1;
    scanf("%d%d", &a, &v);
    while (a != 0 && v != 0)
    {
        int z = 0;
        int i;
        int aeroportos[a];
        //zerando os valores do array
        int p;
        for (p = 0; p < a; p++)
        {
            aeroportos[p] = 0;
        }

        for (i = 0; i < v; i++)
        {
            scanf("%d %d", &x, &y);
            aeroportos[x - 1]++;
            aeroportos[y - 1]++;
            /*debug tirar na hora de rodar
        printf("aeroportos %d %d vez/vezes aeroportoc %d %d vez/vezes\n", x, aeroportos[x-1], y, aeroportos[y-1]);*/
        }
        for (i = 0; i < a; i++)
        {
            if (aeroportos[i] > maior)
            {
                maior = aeroportos[i];
                /*printf("%d %d\n", aeroportos[i], maior); //debug (tirar na hora de rodar*/
            }
        }
        printf("Teste %d\n", T);
        for (i = 0; i < a; i++)
        {
            if (maior == aeroportos[i])
            {
                printf("%d ", i + 1); //(i+1) correção por causa do array
            }
        }
        printf("\n\n"); //Os espaços fora do for para os numeros ficarem alinhados
        T++;
        scanf("%d%d", &a, &v);
    }
    return 0;
}