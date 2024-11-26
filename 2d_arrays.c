#include <stdio.h>
#include <malloc.h>

void print_2d_array(int *p, size_t size, size_t size_of_row)
{
    for (int i = 0; i < size / sizeof(int); i++)
    {
        printf("%d ", p[i]);
        if (i == size_of_row / sizeof(int) - 1)
        {
            printf("\n");
        }
    }
}

static int *copy_2d_array(int *tab, size_t _size_of_the_array)
{
    int *pt = (int *)malloc(_size_of_the_array / sizeof(int));
    for (int i = 0; i < sizeof(tab) / sizeof(int); i++)
    {
        pt[i] = (int *)malloc(sizeof(tab[0]) / sizeof(int));
    }
}

int main()
{
    int b[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    print_2d_array(*b, sizeof(b), sizeof(b[0]));

    // zrobic tablice wskaznikow i potem przekopiowac do niej og dwuwymiarowa tablice

    return 0;
}