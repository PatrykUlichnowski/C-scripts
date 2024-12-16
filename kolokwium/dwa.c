#include <stdio.h>
int main()
{
    // int tab[5] = {1, 12, 30, 400, 5000};
    // int *ptr, a, b, c, d, e, f;
    // ptr = tab + 1;
    // a = *ptr;
    // b = ptr[2];
    // ptr++;
    // c = *ptr + 2;
    // d = *(ptr + 2);
    // ptr++;
    // e = ptr - tab;
    // f = *ptr - *tab;
    // printf("1.%d\n", a);
    // printf("2.%d\n", b);
    // printf("3.%d\n", c);
    // printf("4.%d\n", d);
    // printf("5.%d\n", e);
    // printf("6.%d\n", f);
    int a[6] = {1, 2, 3, 4, 5, 6};
    int *ptr;
    ptr = a + 2;
    ptr[1] = *ptr + 10;
    ptr[2] = ptr[0] + 20;
    *a = *ptr;
    *ptr = a[1];
    printf("test\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", a[i]);
    }
    int i, *p1, x, y, z;
    i = 7;
    p1 = &i;
    *p1 = 1;
    x = i;
    y = (int)p1;
    z = *p1;
    printf("i=%p\n", &i);
    printf("x=%d\n", x);
    printf("y=%d\n", y);
    printf("z=%d\n", z);
    return 0;
}