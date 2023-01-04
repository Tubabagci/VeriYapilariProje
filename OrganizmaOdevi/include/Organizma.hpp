#if !defined(ORGANISMA)
#define ORGANISMA
#include "Sistem_listesi.hpp"

class Organizma
{
public:
    Sistem_listesi *sistem_listesi;
    Organizma(Sistem_listesi *);
    void mutasyona_ugrat();
    ~Organizma();
};

#endif // ORGANISMA
