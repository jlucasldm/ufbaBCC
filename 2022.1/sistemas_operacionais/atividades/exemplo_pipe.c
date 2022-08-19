#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
int status = 0;
int fd1[2], fd2[2], fd3[2], fd4[2], a, b;
pipe(fd1); pipe(fd2);
pipe(fd3); pipe(fd4);
printf("Input two numbers for + and - ");
scanf("%d,", &a); scanf("%d,", &b);
write(fd1[1], &a, sizeof(int));
write(fd2[1], &b, sizeof(int));
printf("Input two numbers for multiplication and division\n");
scanf("%d,", &a); scanf("%d,", &b);
write(fd3[1], &a, sizeof(int));
write(fd4[1], &b, sizeof(int));
pid_t child1 = fork();
if (child1 == 0)
{
    int status = 0, a, b, c;
    read(fd1[0], &a, sizeof(int));
    read(fd2[0], &b, sizeof(int));
    printf("I'm 1st child and calculating + and -\n");
    c = a + b;
    a = a - b;
    write(fd1[1], &c, sizeof(int));
    write(fd2[1], &a, sizeof(int));
    pid_t c3 = fork();
    if (c3 == 0)
    {
        int sum, sub, mul, div;
        read(fd1[0], &sum, sizeof(int));
        read(fd2[0], &sub, sizeof(int));
        read(fd3[0], &mul, sizeof(int));
        read(fd4[0], &div, sizeof(int));
        printf("SUM = %d\n", sum);
        printf("SUB = %d\n", sub);
        printf("MUL = %d\n", mul);
        printf("DIV = %d\n", div);
    }
}
else
{
    pid_t child2 = fork();
    if (child2 == 0) {
        int status = 0, a, b, c;
        read(fd3[0], &a, sizeof(int));
        read(fd4[0], &b, sizeof(int));
        printf("I'm 2nd child and calculating multiplication and division");
        c = a*b;
        a = a / b;
        write(fd3[1], &c, sizeof(int));
        write(fd4[1], &a, sizeof(int));
    }
}
return 0;
}