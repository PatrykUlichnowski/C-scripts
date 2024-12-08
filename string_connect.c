#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_LEN 100

void join(char t1[], char *t2)
{
    // this function changes the bytes after t1 to those of t2, therefore when we call it for the second
    // time we get different result
    int last = 0;
    while (t1[last] != '\0')
    {
        last++;
    }
    int i = 0;
    while (t2[i] != '\0')
    {
        t1[last + i] = t2[i];
        i++;
    }
    t1[last + i] = '\0';
    printf("%s\n", t1);
}

static char *string_connect(char t1[], char t2[])
{
    // this function doesnt change bytes after t1 so its better to print the new string
    static char newtab[100] = "";
    int last = 0;
    while (t1[last] != '\0')
    {
        newtab[last] = t1[last];
        last++;
    }
    int i = 0;
    while (t2[i] != '\0')
    {
        newtab[last + i] = t2[i];
        i++;
    }
    newtab[last + i] = '\0';
    // printf("%s\n", newtab);
    return newtab;
}

static char *string_connect_malloc(char t1[], char t2[])
{
    // with malloc we can use size_t, which is a part of the stdlib.h and its basically just an unsigned int
    // f.e. (char *)malloc(size_t size) <- size is in bytes and thats why we use unsigned int cause it can't be negative

    // with static char *newtab there are 10 errors in the compiler but it works (sort of?)
    // (char *) - this part is casting the type of the return from malloc so that it points to a first char in an array
    // otherwise malloc returns void pointer
    // we need to add +1 at the end of malloc to store '\0' that ends the string
    char *newtab = (char *)malloc((sizeof(char) * strlen(t1)) + sizeof(char) * strlen(t2) + 1);
    int last = 0;
    while (t1[last] != '\0')
    {
        newtab[last] = t1[last];
        last++;
    }
    int i = 0;
    while (t2[i] != '\0')
    {
        newtab[last + i] = t2[i];
        i++;
    }
    newtab[last + i] = '\0';
    // printf("%s\n", newtab);
    return newtab; // we DON'T return the the adress by adding & at the beggining
}

int main()
{
    char n1[] = "First string, ";
    char n2[] = " second string";
    char *newtab = string_connect(n1, n2); // this must be a pointer
    printf("%s\n", newtab);

    char a[] = " Ricardo ";
    char k[] = " Kaka ";
    static char *w1, *w2;
    w1 = string_connect(a, k);
    w2 = string_connect(k, a);
    printf("without malloc:\n");
    printf("%s\n", w1);
    printf("%s\n", w2); // prints the same value as w1

    printf("with malloc:\n");
    w1 = string_connect_malloc(a, k);
    w2 = string_connect_malloc(k, a);
    printf("%s\n", w1);
    printf("%s\n", w2);
    free(w1); // we use free to release the momery that was assigned to w1 by malloc
    free(w2);
    return 0;
}