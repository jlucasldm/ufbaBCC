#include <stdio.h>

void towersOfHanoi(int n, char source, char destination, char auxiliar)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towersOfHanoi(n-1, source, auxiliar, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towersOfHanoi(n-1, auxiliar, destination, source);
}

int main()
{
    int n = 4; // Number of disks
    towersOfHanoi(n, 'S', 'D', 'A');    //source, destination, auxiliar
    return 0;
}