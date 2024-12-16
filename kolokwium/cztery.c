#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrom_zdanie(char text[])
{
    int left = 0;
    int right = strlen(text) - 1;

    while (left < right)
    {
        // Pomijanie nie-alfanumerycznych znaków z lewej strony
        while (left < right && !isalnum(text[left]))
        {
            left++;
        }
        // Pomijanie nie-alfanumerycznych znaków z prawej strony
        while (left < right && !isalnum(text[right]))
        {
            right--;
        }
        // Sprawdzanie znaków (ignorowanie wielkości liter)
        if (tolower(text[left]) != tolower(text[right]))
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

void last_char(char text[])
{
    printf("oryginal: %s\n", text);
    int len = strlen(text);
    char lastc = text[len - 1];
    for (int i = 0; i < len; i++)
    {
        text[i] = lastc;
    }

    printf("zmieniony: %s\n", text);
}
char *second_word(char text[])
{
    char *ptr = text;
    for (int i = 0; i < strlen(text); i++)
    {
        if (*ptr == ' ' || *ptr == '\t')
        {
            ptr++;
            break;
        }
        ptr++;
    }

    return ptr;
}
int palindrom(char text[])
{
    int len = strlen(text);
    for (int i = 0; i < len / 2; i++)
    {
        if (tolower(text[i]) != tolower(text[len - 1 - i]))
        {
            return 0;
        }
    }

    return 1;
}
void reverse_word(char text[])
{
    char *ptr = second_word(text);
    printf("test %s\n", ptr);
    while (*ptr != ' ' || *ptr != '\t' || *ptr != '\0')
    {
        printf("debug %c\n", ptr);
        ptr++;
    }
}
int main()
{
    char string[] = "testowy";
    char string2[] = "testowy sgrting";
    last_char(string);
    char *returnstring = second_word(string2);
    printf("debug %s\n", returnstring);
    char pali[] = "kAjaK";
    int czytopali = palindrom(pali);
    printf("%d\n", czytopali);
    char zdanie[] = "Zakopane na pokaz";
    printf("czy to zdanie - %s - jest palindromem: %s \n", zdanie, palindrom_zdanie(zdanie) ? "Tak" : "Nie");
    reverse_word(zdanie);
    return 0;
}