#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>

class Generator{
    long w1, w2, w3;
    long S;
    long N;
    double *tab;
    long seed;

    public:
    int *histogram[100];
    Generator(long N = 1, long b = 1, long c = 1, long d = 1, long e = 1);
    ~Generator();
    void PrintGenerator();
};


#endif 