#include "../include/Kontrol.hpp"
/**
 * @file test.cpp
 * @description Dosya okuma, ekrana yazma, sayıları hücreye, satırları dokuya, organları ekleme işlemleri yapılmıştır.

 */
// istringstream araciligi ile satir icindeki string haldeki sayilari int tipine donusturme metodu.
// her okumada yeni bir hucre hucreler kuyruguna(Kuyruk veri tipinde) ekleniyor.
// her yeni satirda kuyruktaki hucreler dokuya aktariliyor ve kuyruk temizleniyor boylelikle bellek hatalarinin onune geciliyor.
void Kontrol::dosya_oku(string dosya_yolu)
{
    int i;
    string satir;
    fstream read;
    stringstream sayi_gecici;
    int sayi_gecici_uzunlug = 0;
    int satir_ici_uzunlug = 0;

    read.open(dosya_yolu.c_str(), ios::in);
    while (getline(read, satir))
    {

        while (satir.length() > satir_ici_uzunlug)
        {
            istringstream(satir.substr(satir_ici_uzunlug)) >> i;
            hucre_ekle(i);

            sayi_gecici << i;
            satir_ici_uzunlug += sayi_gecici.str().length() + 1;
            sayi_gecici.str("");
        }

        doku_ekle();

        sayi_gecici_uzunlug = 0;
        satir_ici_uzunlug = 0;
    }
    read.close();
    organizma_yarat();
}

void Kontrol::hucre_ekle(int value)
{
    hucre = new Hucre(value);
    hucreler->enqueue(*hucre);
    hucre_sayac++;
};

void Kontrol::doku_ekle()
{
    doku = new Doku();
    Radix *radix = new Radix(hucreler->items, hucreler->count());
    doku->toplam_hucre_sayisi = hucreler->count();
    doku->hucreler = radix->Sort();
    // orta hucrenin belirlenmesi
    doku->orta_hucre = doku->hucreler[(hucre_sayac / 2)];

    dokular[doku_sayac] = doku;
    doku_sayac++;
    hucre_sayac = 0;
    hucreler->clear();
    // 20 doku oldugunda yeni organ yarat
    if (doku_sayac == 20)
    {
        organ_ekle();
        doku_sayac = 0;
        dokular = new Doku *[20];
    }
}

void Kontrol::organ_ekle()
{

    organ = new Organ();
    bst = new BST();
    for (int i = 0; i < 20; i++)
    {
        bst->Add(*dokular[i]);
    }

    organ->bst = this->bst;
    organlar[organ_sayac] = organ;
    organ_sayac++;
    doku_sayac = 0;

    // 100 organ oldugunda yeni sistem yarat.
    if (organ_sayac == 100)
    {
        sistem = new Sistem(organlar);
        organ_sayac = 0;
        organlar = new Organ *[100];
        sistem_listesi->add(*sistem);
    }
}

void Kontrol::organizma_yarat()
{
    organizma = new Organizma(sistem_listesi);
}

Kontrol::Kontrol()
{
    dokular = new Doku *[20];
    organlar = new Organ *[100];
    hucreler = new Queue();
    sistem_listesi = new Sistem_listesi();
}

void Kontrol::ekrana_yazdir()
{
    BST *bst;
    for (int i = 0; i < sistem_listesi->Count(); i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i != 0)
                bst = sistem_listesi->elementAt(i).organlar[j]->bst;
            else
                bst = sistem_listesi->head->organlar[j]->bst;
            if (bst->agac_dengeli_mi(bst->root))
            {
                cout << " ";
            }
            else
                cout << "#";
        }
        cout << endl;
    }
}
Kontrol::~Kontrol()
{
    delete organizma;
}