#include <stdio.h>
int main()
{
    int N;
    int i;

    scanf("%d", &N);
    int v[N];
    int total = 0;
    int metade = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
        total += v[i];
    }
    for (i = 0; i < N; i++)
    {
        metade += v[i];

        if (total / 2 == metade)
        {
            printf("%d", i + 1);
            break;
        }
    }
    return 0;
}