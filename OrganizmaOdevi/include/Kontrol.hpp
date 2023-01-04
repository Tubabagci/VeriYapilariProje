#if !defined(KONTROL)
#define KONTROL

#include "iostream"
#include "Organizma.hpp"
#include "Radix.hpp"
#include "BST.hpp"
#include "iostream"
#include <string>
#include "fstream"
#include <sstream>
using namespace std;
class Kontrol
{
public:
    int hucre_sayac = 0;
    int doku_sayac = 0;
    int organ_sayac = 0;
    int sistem_sayac = 0;
    int organizma_sayac = 0;

public:
    Doku **dokular;
    Organ **organlar;
    Hucre *hucre;
    Doku *doku;
    Organ *organ;
    Sistem *sistem;
    Queue *hucreler;
    Sistem_listesi *sistem_listesi;
    Organizma *organizma;

    BST *bst;

public:
    Kontrol();
    void dosya_oku(string);
    void hucre_ekle(int);
    void doku_ekle();
    void organ_ekle();
    void organizma_yarat();
    void ekrana_yazdir();
    ~Kontrol();
};

#endif // KONTROL
