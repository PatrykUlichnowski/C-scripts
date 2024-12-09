#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cards.h"
#include "color_match.h"
#include "pair_match.h"
#include "triple_match.h"
#include "quad_match.h"
int main()
{
    struct Card cards_tab[5];
    cards_tab[0].figura = walet;
    cards_tab[0].kolor = trefl;

    cards_tab[1].figura = krol;
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

    bool is_there_a_triple = triple_match(cards_tab);
    printf("Is there a triple in your cards: %s\n", is_there_a_triple ? "true" : "false");

    bool is_ther_a_quad = quad_match(cards_tab);
    printf("Is there a quadruple in your cards: %s\n", is_ther_a_quad ? "true" : "false");

    // zdekomponowac program tak aby kazda funkcja byla w innym pliku
    // np color_match w color_match.c
    return 0;
}