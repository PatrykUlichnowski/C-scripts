#include <stdio.h>
#include <malloc.h>
int main()
{
    int tab[5] = {10, 20, 30, 40, 50};
    printf("1. %d\n", *tab);
    printf("2. %u\n", tab);
    printf("3. %d\n", tab[1]);
    printf("4. %d\n", *(tab + 4));
    printf("5. %d\n", *tab + 4);
    printf("6. %u\n", tab + 1);
    // Deklaracja tablicy wskaźników
    int *p[5];

    // Alokacja pamięci i inicjalizacja wartości
    p[0] = (int *)malloc(2 * sizeof(int)); // Alokacja pamięci dla 2 wartości
    p[1] = (int *)malloc(3 * sizeof(int)); // Alokacja pamięci dla 3 wartości
    p[2] = (int *)malloc(3 * sizeof(int)); // Alokacja pamięci dla 3 wartości
    p[3] = (int *)malloc(2 * sizeof(int)); // Alokacja pamięci dla 2 wartości
    p[4] = (int *)malloc(4 * sizeof(int)); // Alokacja pamięci dla 4 wartości

    // Inicjalizacja wartości
    p[0][0] = 3;
    p[0][1] = 1;

    p[1][0] = 41;
    p[1][1] = 15;
    p[1][2] = 27;

    p[2][0] = 120;
    p[2][1] = 250;
    p[2][2] = 170;

    p[3][0] = 2200;
    p[3][1] = 1100;

    p[4][0] = 5003;
    p[4][1] = 9004;
    p[4][2] = 6007;
    p[4][3] = 8001;
    printf("zadanie 2\n");
    printf("a. %d\n", **p);
    printf("b. %d\n", (*p)[1]);
    printf("c. %u\n", p[0]);
    printf("d. %d\n", *p[1]);
    printf("e. %d\n", p[1][1]);
    printf("f. %u\n", *(p + 2));
    printf("g. %u\n", *p + 2);
    printf("h. %d\n", *p[2]);

    // Zwolnienie pamięci
    for (int i = 0; i < 5; i++)
    {
        free(p[i]);
    }
    return 0;
}