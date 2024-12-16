#include <stdio.h>
#include <malloc.h>
int main()
{
    int *p[3];
    p[0] = (int *)malloc(sizeof(int) * 1);
    p[1] = (int *)malloc(sizeof(int) * 3);
    p[2] = (int *)malloc(sizeof(int) * 2);
    p[0][0] = 3;

    p[1][0] = 400;
    p[1][1] = 200;
    p[1][2] = 100;

    p[2][0] = 90;
    p[2][1] = 80;

    printf("%d\n", p[1][1]);
    printf("%d\n", (*p)[1]);
    printf("%d\n", (*p)[0]);
    printf("%d\n", **p);

    return 0;
}