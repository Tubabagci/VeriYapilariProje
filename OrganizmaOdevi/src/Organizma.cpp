#include "../include/Organizma.hpp"
/**
 * @file test.cpp
 * @description Organizma mutasyona uğradığında yapılacak işlemler çağrılmıştır. Sistem silme işlemi de yapılmıştır.

 */

Organizma::Organizma(Sistem_listesi *sistem_listesi)
{
    this->sistem_listesi = sistem_listesi;
}
void Organizma::mutasyona_ugrat()
{
    for (int i = 0; i < sistem_listesi->Count(); i++)
    {
        if (i != 0)
            sistem_listesi->elementAt(i).mutasyona_ugra();
        else
            sistem_listesi->head->mutasyona_ugra();
    }
}

Organizma::~Organizma()
{
    delete sistem_listesi;
}
