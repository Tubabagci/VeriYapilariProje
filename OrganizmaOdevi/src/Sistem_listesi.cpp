#include "../include/Sistem_listesi.hpp"
/**
 * @file sistem_listesi.cpp
 * @description Sistemler veri yapısı içinde tutulmuştur. Sistem için yapılacak işlemler tanımlanmıştır.

 */

Sistem *Sistem_listesi::FindPreviousByPosition(int index)
{
    if (index < 0 || index > size)
        throw "No Such Element";
    Sistem *prv = head;
    int i = 1;
    for (Sistem *itr = head; itr->next != NULL && i != index; itr = itr->next, i++)
    {
        prv = prv->next;
    }
    return prv;
}
Sistem_listesi::Sistem_listesi()
{
    head = NULL;
    size = 0;
}
int Sistem_listesi::Count() const
{
    return size;
}
bool Sistem_listesi::isEmpty() const
{
    return size == 0;
}
void Sistem_listesi::add(const Sistem &item)
{
    insert(size, item);
}
void Sistem_listesi::insert(int index, const Sistem &item)
{
    if (index < 0 || index > size)
        throw "Index out of Range";
    if (index == 0)
    {
        head = new Sistem(item.organlar, head);
        if (head->next != NULL)
            head->next->prev = head;
    }
    else
    {
        Sistem *prv = FindPreviousByPosition(index);
        prv->next = new Sistem(item.organlar, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
const Sistem &Sistem_listesi::first()
{
    if (isEmpty())
        throw "No Such Element";
    return *head;
}
const Sistem &Sistem_listesi::last()
{
    if (isEmpty())
        throw "No Such Element";
    return *FindPreviousByPosition(size);
}
int Sistem_listesi::indexOf(const Sistem &item)
{
    int index = 0;
    for (Sistem *itr = head; itr != NULL; itr = itr->next)
    {
        if (itr->organlar == item.organlar)
            return index;
        index++;
    }
    throw "No Such Element";
}
void Sistem_listesi::remove(const Sistem &item)
{
    int index = indexOf(item);
    removeAt(index);
}
void Sistem_listesi::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw "Index out of Range";
    Sistem *del;
    if (index == 0)
    {
        del = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        Sistem *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}
bool Sistem_listesi::find(const Sistem &item)
{
    for (Sistem *itr = head; itr != NULL; itr = itr->next)
    {
        if (itr->organlar == item.organlar)
            return true;
    }
    return false;
}
void Sistem_listesi::reverse()
{
    for (Sistem *itr = head; itr != NULL;)
    {
        Sistem *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL)
        {
            head = itr;
            break;
        }
        itr = tmp;
    }
}
Sistem &Sistem_listesi::elementAt(int index)
{
    if (index < 0 || index >= size)
        throw "No Such Element";
    if (index == 0)
        return *head->next;
    return *FindPreviousByPosition(index)->next;
}
void Sistem_listesi::clear()
{
    while (!isEmpty())
        removeAt(0);
}

Sistem_listesi::~Sistem_listesi()
{
    clear();
}