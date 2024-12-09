#ifndef QUAD_MATCH_H
#define QUAD_MATCH_H

#include "cards.h"
#include <stdbool.h>

bool quad_match(struct Card cards[5])
{
    int matched = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1 + i; j < 5; j++)
        {
            if (cards[i].figura == cards[j].figura)
                matched++;
        }
        if (matched == 4)
        {
            return true;
        }
    }
    return false;
}
#endif