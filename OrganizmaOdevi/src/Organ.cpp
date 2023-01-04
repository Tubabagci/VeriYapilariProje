#include "../include/Organ.hpp"
/**
 * @file organ.cpp
 * @description mutasyona uğrama işleminde ağaç için yapılacak işlemler yapılmıştır. Ve yıkıcı fonksiyonda ağacın temizlenmesi yapılmıştır.

 */
Organ::Organ()
{
    bst = NULL;
}
void Organ::mutasyona_ugrat()
{
    if (bst->root->orta_hucre.dna_uzunlugu % 50 == 0)
    {
        postorder_dokular = new Doku *[20];
        // postorder_dokular dizisini, agaci postorder gezerek doldur
        bst->postorder(postorder_dokular);
        bst = new BST();

        // agactan alinan dokularin hepsini mutasyona ugrat
        for (int i = 0; i < 20; i++)
        {
            postorder_dokular[i]->mutasyona_ugrat();
        }
        // yeni yaratilan agaca mutasyona ugramis dokulari yeniden ekle
        for (int i = 0; i < 20; i++)
        {
            bst->Add(*postorder_dokular[i]);
        }
        delete[] postorder_dokular;
    }
}
Organ::~Organ()
{
    delete bst;
}