#include <stdio.h>

char small_to_big_chars(char *t)
{
    for (int i = 0; i < sizeof(t) / sizeof(*t); i++)
    {
        t[i] = (int) t[i] - ;
    }
    return t;
} 

int main()
{
    char n1[] = "Ala ma 2 koty";

}