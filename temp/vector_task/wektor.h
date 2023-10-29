#ifndef WEKTOR_H
#define WEKTOR_H
#include <vector>

class Punkt{
    public:
    float mX, mY, mZ;
    Punkt();
    Punkt(float, float, float);
    ~Punkt();
    void Przedstaw();
};

class Wektor{
    private:
    float mA, mB, mC;
    public:
    Wektor();
    Wektor(Punkt, Punkt);
    ~Wektor();
    void Przestaw();
    float Dlugosc();
};

#endif