#include <stdio.h>
int main()
{
    int m;
    int n;
    scanf("%d %d", &m, &n);
    char map[m][n];
    int i;
    int j;
    int costa = 0;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            scanf("\n%c", &map[i][j]);
        }
    }

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if ((map[i][j] == '#') && !(map[i + 1][j] == '#' &&
                                       map[i - 1][j] == '#' &&
                                       map[i][j + 1] == '#' &&
                                       map[i][j - 1] == '#' ))
            {
                costa ++;
            }
            else if((map[i][j] == '#') && (i==0 || j ==0 || i==m-1 || j==n-1))
            {
                costa++;
            }
        }
    }
    printf("%d\n", costa);
    return 0;
}