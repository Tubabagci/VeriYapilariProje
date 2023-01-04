#if !defined(HUCRE)
#define HUCRE
#include "iostream"
class Hucre
{

public:
    int dna_uzunlugu;
    Hucre *ileri;
    Hucre();
    Hucre(int, Hucre *);
    Hucre(int);
    ~Hucre();
    void mutasyona_ugra();
};

#endif // HUCRE
