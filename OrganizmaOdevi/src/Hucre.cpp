#include "Hucre.hpp"

/**
 * @file hucre.cpp
 * @description Satırlardaki her sayı(hücre) için işlem yapılacak. dna_uzunlukları tutulur ve mutasyon için kontrol yapılır.

 */

Hucre::Hucre()
{
    this->ileri = NULL;
    this->dna_uzunlugu = 0;
}
Hucre::Hucre(int dna_uzunlugu, Hucre *ileri)
{
    this->ileri = ileri;
    this->dna_uzunlugu = dna_uzunlugu;
}
Hucre::Hucre(int dna_uzunlugu)
{
    this->dna_uzunlugu = dna_uzunlugu;
    this->ileri = NULL;
}

Hucre::~Hucre()
{
}
void Hucre::mutasyona_ugra()
{
    if (dna_uzunlugu % 2 == 0)
    {
        dna_uzunlugu = dna_uzunlugu / 2;
    }
}
