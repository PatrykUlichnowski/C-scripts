#ifndef CARDS_H
#define CARDS_H
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
#endif