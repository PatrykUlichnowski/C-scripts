#include <stdio.h>
#include <malloc.h>

static void print_2d_array(int *p, size_t rows, size_t columns)
{
    for (int i = 0; i < rows / sizeof(int); i++)
    {
        printf("%d ", p[i]);
        if (i == columns / sizeof(int) - 1)
        {
            printf("\n");
        }
    }
}
static void print_pointers_array(int **p, size_t rows, size_t cols)
{
    printf("test %d %d\n", cols, rows);
    for (int i = 0; i < rows; i++)
    {
        // printf("i = %d\n", i);
        for (int j = 0; j < cols; j++)
        {
            // printf("j = %d\n", j);
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

static int **copy_2d_array(int *tab, size_t columns, size_t rows)
{
    int number_of_columns = columns / sizeof(int);
    int number_of_rows = rows / sizeof(int);
    int **pt = (int **)malloc(number_of_columns * sizeof(int *));

    for (int i = 0; i < number_of_rows; i++)
    {
        pt[i] = (int *)malloc(number_of_columns * sizeof(int));
    }
    int x = 0, y = 0;
    for (int i = 0; i < number_of_columns * number_of_rows; i++)
    {
        pt[x][y] = tab[i];
        y++;
        if (y == number_of_columns)
        {
            x++;
            y = 0;
        }
    }
    printf("debug\n");
    for (int i = 0; i < number_of_rows; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            printf("xd %d ", pt[i][j]);
        }
        // printf("%d ", pt[i]);
    }

    return pt;
}

int main()
{
    int b[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d ", b[i][j]);
    //     }
    //     printf("\n");
    // }
    // print_2d_array(*b, sizeof(b), sizeof(b[0]));
    int **coppied_array = copy_2d_array(b, sizeof(b), sizeof(b[0]));
    // print_pointers_array(coppied_array, sizeof(coppied_array), sizeof(coppied_array[0]));

    return 0;
    /*
    Wskaźnik do wskaźnika (czyli int **) jest używany do reprezentowania tablicy wskaźników, gdzie każdy wskaźnik w tablicy wskazuje na inną tablicę. Używanie dwóch gwiazdek (**) oznacza, że mamy wskaźnik do wskaźnika, co pozwala nam stworzyć tablicę dwuwymiarową.

    Oto co dzieje się w linijce int **pointers_table = (int **)malloc(ROWS * sizeof(int *));:

    int **pointers_table: Deklaracja wskaźnika do wskaźnika. pointers_table będzie przechowywać adresy wskaźników do tablic wierszy.

    malloc(ROWS * sizeof(int *)): Funkcja malloc alokuje pamięć dla tablicy wskaźników. Potrzebujemy ROWS wskaźników (po jednym dla każdego wiersza). sizeof(int *) zwraca rozmiar wskaźnika do int.

    (int **): Rzutowanie (castowanie) przydzielonej pamięci na typ int **, aby upewnić się, że pointers_table jest wskaźnikiem do wskaźników int.

    W skrócie, dwie gwiazdki są używane, aby reprezentować tablicę wskaźników do tablic. W ten sposób możemy dynamicznie alokować pamięć dla tablicy dwuwymiarowej i łatwo zarządzać pamięcią w języku C.
    */
}