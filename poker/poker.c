#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

enum Colour
{
    karo = 1,
    trefl = 2,
    kier = 3,
    pik = 4
};
enum Figure
{
    walet = 11,
    dama = 12,
    krol = 13,
    as = 14
};
struct Card
{
    enum Colour kolor;
    enum Figure figura;
};
static bool color_match(struct Card cards_tab[5])
{
    for (int i = 1; i < 5; i++)
    {
        if (cards_tab[i].kolor != cards_tab[0].kolor)
            return false;
    }
    return true;
}
static bool pair_match(struct Card cards[5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1 + i; j < 5; j++)
        {
            if (cards[i].figura == cards[j].figura)
                return true;
        }
    }

    return false;
}

int main()
{
    struct Card cards_tab[5];
    cards_tab[0].figura = walet;
    cards_tab[0].kolor = trefl;

    cards_tab[1].figura = dama;
    cards_tab[1].kolor = trefl;

    cards_tab[2].figura = krol;
    cards_tab[2].kolor = trefl;

    cards_tab[3].figura = as;
    cards_tab[3].kolor = trefl;

    cards_tab[4].figura = krol;
    cards_tab[4].kolor = trefl;
    bool x = color_match(cards_tab);
    printf("Is there a colour match between the cards: %s\n", x ? "true" : "false");

    bool is_pair_match = pair_match(cards_tab);
    printf("Is there at least one pair of your cards: %s\n", is_pair_match ? "true" : "false");

    // zdekomponowac program tak aby kazda funkcja byla w innym pliku
    // np color_match w color_match.c
    return 0;
}