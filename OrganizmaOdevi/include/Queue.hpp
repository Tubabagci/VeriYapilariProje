#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include "Hucre.hpp"
using namespace std;
class Queue
{
private:
    int front;
    int back;
    int capacity;
    int length;

    void reserve(int newCapacity);

public:
    Hucre *items;
    Queue();
    void clear();
    int count() const;
    bool isEmpty() const;
    const Hucre &peek();
    void enqueue(const Hucre &item);
    void dequeue();
    ~Queue();
};
#endif