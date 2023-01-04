#include "../include/Kontrol.hpp"
/**
 * @file test.cpp
 * @description Veri.txt dosyasindaki sayilar kumesini cozumleyip hucre-doku-organ-sistem-organizma hiyerarsisinde yapilara donusturmek.

 */

int main()
{
    system("cls");
    // kontrol sinifi yarattim.
    Kontrol *kontrol = new Kontrol();
    // dosya okuma
    kontrol->dosya_oku("Veri.txt");
    // mutasyonsuz organizmanın ekrana yazdırılması
    cout << "\t\t\t\tOrganizma\n";
    kontrol->ekrana_yazdir();
    // enter girdisi
    getchar();
    system("cls");
    // mutasyonlu organizmanın ekrana yazdırılması
    cout << "\t\t\t  Organizma(Mutasyona Ugradi)\n";
    kontrol->organizma->mutasyona_ugrat();
    kontrol->ekrana_yazdir();
    // bellek temizliği
    delete kontrol;
    system("pause");

    return 0;
}