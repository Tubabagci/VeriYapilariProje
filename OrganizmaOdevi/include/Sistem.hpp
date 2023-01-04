#if !defined(SISTEM)
#define SISTEM
#include "Organ.hpp"
#include <iostream>
class Sistem
{
public:
    Organ **organlar;
    Sistem *next;
    Sistem *prev;

    Sistem(Organ **organlar, Sistem *next, Sistem *prev);
    Sistem(Organ **organlar, Sistem *next);
    Sistem(Organ **organlar);
    Sistem();
    void mutasyona_ugra();
    ~Sistem();
};

#endif // SISTEM
