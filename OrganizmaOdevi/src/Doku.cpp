#include "../include/Doku.hpp"
/**
 * @file doku.cpp
 * @description dosyadaki mutasyona uğrayan satırlar(doku) için yapılacak işlemler çağrılıyor. Dokunun içinde bulundurduğu hücreler temizleniyor.

 */

Doku::Doku()
{
    this->sol = NULL;
    this->sag = NULL;
    this->hucreler = NULL;
    this->toplam_hucre_sayisi = 0;
}
void Doku::mutasyona_ugrat()
{
    for (int i = 0; i < toplam_hucre_sayisi; i++)
    {
        this->hucreler->mutasyona_ugra();
    }
    Radix *radix = new Radix(this->hucreler, toplam_hucre_sayisi);
    delete[] hucreler;
    this->hucreler = radix->Sort();
    this->orta_hucre = hucreler[toplam_hucre_sayisi / 2];
    delete radix;
}
Doku::~Doku()
{
}
