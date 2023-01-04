#include "../include/Sistem.hpp"
/**
 * @file sistem.cpp
 * @description Sistem için farklı parametrelerle kurucu fonksiyonlar tanımlandı ve sistem mutasyona uğradığında çalışıcak fonksiyonlar çağrıldı.

 */

Sistem::Sistem(Organ **organlar, Sistem *next, Sistem *prev)
{
    this->next = next;
    this->prev = prev;
    this->organlar = organlar;
}
Sistem::Sistem(Organ **organlar, Sistem *next)
{
    this->next = next;
    this->prev = NULL;
    this->organlar = organlar;
}
Sistem::Sistem(Organ **organlar)
{
    this->next = NULL;
    this->prev = NULL;
    this->organlar = organlar;
}
Sistem::Sistem()
{
    this->next = NULL;
    this->prev = NULL;
    this->organlar = NULL;
}
void Sistem::mutasyona_ugra()
{

    for (int i = 0; i < 100; i++)
    {
        this->organlar[i]->mutasyona_ugrat();
    }
}

Sistem::~Sistem()
{
    delete[] organlar;
}
