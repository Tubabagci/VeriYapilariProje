#include "Radix.hpp"
/**
 * @file radix.cpp
 * @description Satırlar(doku) radix sort algoritmasına göre sıralanacaktır. Bunun için gerekli algoritma adımları/fonksiyonlar tanımlanmıştır.

 */

int Radix::MaxStepNumber()
{
    int max = 0;
    for (int i = 0; i < uzunluk; i++)
    {
        if (StepCount(hucreler[i].dna_uzunlugu) > max)
            max = StepCount(hucreler[i].dna_uzunlugu);
    }
    return max;
}
int Radix::StepCount(int number)
{
    number = abs(number);
    int basamak = 0;
    while (number > 0)
    {
        basamak++;
        number /= 10;
    }
    return basamak;
}
Radix::Radix(Hucre *hucreler, int length)
{
    this->hucreler = new Hucre[length];
    this->uzunluk = length;
    for (int i = 0; i < length; i++)
    {
        this->hucreler[i] = hucreler[i];
    }
    queues = new Queue *[10];
    for (int j = 0; j < 10; j++)
    {
        queues[j] = new Queue();
    }
    maxStep = MaxStepNumber();
}
int *Radix::QueueCurrentLengths()
{
    int *lengths = new int[10];
    for (int i = 0; i < 10; i++)
    {
        lengths[i] = queues[i]->count();
    }
    return lengths;
}
int Radix::power(int e)
{
    int result = 1;
    for (int i = 0; i < e; i++)
        result *= 10;
    return result;
}
Hucre *Radix::Sort()
{
    int numberIndex = 0;
    for (; numberIndex < uzunluk; numberIndex++)
    {
        int stepValue = hucreler[numberIndex].dna_uzunlugu % 10;
        int num = hucreler[numberIndex].dna_uzunlugu;
        queues[stepValue]->enqueue(num);
    }

    for (int i = 1; i < maxStep; i++)
    {
        int *qlengths = QueueCurrentLengths();
        for (int index = 0; index < 10; index++)
        {
            int len = qlengths[index];
            for (; len > 0; len--)
            {
                int number = queues[index]->peek().dna_uzunlugu;
                queues[index]->dequeue();
                int stepValue = (number / power(i)) % 10;
                queues[stepValue]->enqueue(number);
            }
        }
        delete[] qlengths;
    }
    Hucre *ordered = new Hucre[uzunluk];
    numberIndex = 0;
    for (int index = 0; index < 10; index++)
    {
        while (!queues[index]->isEmpty())
        {
            int number = queues[index]->peek().dna_uzunlugu;
            ordered[numberIndex++] = number;
            queues[index]->dequeue();
        }
    }

    return ordered;
}
Radix::~Radix()
{
    delete[] hucreler;
    for (int i = 0; i < 10; i++)
        delete queues[i];
    delete[] queues;
}