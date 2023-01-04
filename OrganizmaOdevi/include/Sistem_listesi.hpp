
#ifndef SISTEMLISTESI
#define SISTEMLISTESI
#include "iostream"
#include "Sistem.hpp"

class Sistem_listesi
{
private:
    int size;

    Sistem *FindPreviousByPosition(int index);

public:
    Sistem *head;
    Sistem_listesi();
    int Count() const;
    bool isEmpty() const;
    void add(const Sistem &item);
    void insert(int index, const Sistem &item);
    const Sistem &first();
    const Sistem &last();
    int indexOf(const Sistem &item);
    void remove(const Sistem &item);
    void removeAt(int index);
    bool find(const Sistem &item);
    void reverse();
    Sistem &elementAt(int index);
    void clear();
    friend ostream &operator<<(ostream &screen, Sistem_listesi &rgt);
    ~Sistem_listesi();
};

#endif // SISTEMLISTESI
