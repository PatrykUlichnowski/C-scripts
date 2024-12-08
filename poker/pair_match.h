#ifndef PAIR_MATCH_H
#define PAIR_MATCH_H

#include <stdbool.h>
#include "cards.h"
bool pair_match(struct Card cards[5])
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

#endif