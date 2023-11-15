#ifndef VECTOR_H
#define VECTOR_H

class Wektor{
    int *X;
    int rozmiar;
    float wartosc;
    int index;
    static int counter;
    public:
    Wektor(int rozmiar);
    ~Wektor();
    void print();
    float set(float wartosc, int index);
    static int getVecNo(){return counter;}

};
#endif