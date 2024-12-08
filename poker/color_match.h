#ifndef COLORMATCH_H
#define COLORMATCH_H

#include <stdbool.h>
#include "cards.h"

bool color_match(struct Card cards_tab[5])
{
    for (int i = 1; i < 5; i++)
    {
        if (cards_tab[i].kolor == cards_tab[0].kolor)
            return false;
    }
    return true;
}
#endif