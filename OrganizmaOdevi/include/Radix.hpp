#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include "Hucre.hpp"
#include <cmath>

class Radix
{
private:
    Hucre *hucreler;
    int uzunluk;
    Queue **queues;
    int maxStep;

    int MaxStepNumber();
    int power(int);
    int StepCount(int);
    int *QueueCurrentLengths();

public:
    Radix(Hucre *, int);
    Hucre *Sort();
    ~Radix();
};

#endif