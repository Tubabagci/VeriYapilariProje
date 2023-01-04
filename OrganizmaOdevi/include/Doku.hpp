#if !defined(DOKU)
#define DOKU
#include "Radix.hpp"
class Doku
{
public:
    Hucre *hucreler;
    Doku *sol;
    Doku *sag;
    Hucre orta_hucre;
    int toplam_hucre_sayisi;
    Doku();
    void mutasyona_ugrat();
    ~Doku();
};

#endif // DOKU
