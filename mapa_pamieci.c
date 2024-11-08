#include <stdio.h>
#include <stdlib.h>

long L = 17;
short A = 15;
int I = 18;
double D = 13.1;
char C = 'A';
float F = 12.5;
int *P = &I;

// void *: This is a pointer to a variable of an unspecified type. It is often referred to as a “generic pointer” because it can point to any data type (e.g., int, char, float, etc.)
void print_variable_bytes(FILE *ff, void *var, size_t size)
{
    // This part is a type cast. It converts the pointer var (which is of type void *) to a pointer of type unsigned char *
    unsigned char *p = (unsigned char *)var;
    // Iterates through each allocated byte starting with the pointing one. Prints them to the terminal and to a txt file
    for (size_t j = 0; j < size; j++)
    {
        if (j == 0)
        {
            fprintf(ff, "size of variable in bytes: %zu\n", size);
        }
        printf("%p: %u\n", &p[j], p[j]);
        fprintf(ff, "%p: %u\n", &p[j], p[j]);
    }
}

int main()
{
    long l = 7;
    short s = 5;
    int i = 8;
    double d = 3.1;
    char c = 'a';
    float f = 2.5;
    int j;
    int *p = &i;

    char *fname = "test.txt";
    FILE *ff = fopen(fname, "w");

    // global variables

    fprintf(ff, "GLOBAL VARIABLES\n");
    print_variable_bytes(ff, &L, sizeof(L));
    print_variable_bytes(ff, &A, sizeof(A));
    print_variable_bytes(ff, &I, sizeof(I));
    print_variable_bytes(ff, &D, sizeof(D));
    print_variable_bytes(ff, &C, sizeof(C));
    print_variable_bytes(ff, &F, sizeof(F));
    print_variable_bytes(ff, &P, sizeof(P));

    // local variables
    fprintf(ff, "LOCAL VARIABLES\n");
    print_variable_bytes(ff, &l, sizeof(l));
    print_variable_bytes(ff, &s, sizeof(s));
    print_variable_bytes(ff, &i, sizeof(i));
    print_variable_bytes(ff, &c, sizeof(c));
    print_variable_bytes(ff, &d, sizeof(d));
    print_variable_bytes(ff, &f, sizeof(f));
    print_variable_bytes(ff, &j, sizeof(j));
    print_variable_bytes(ff, &p, sizeof(p));

    fclose(ff);
    return 0;
}