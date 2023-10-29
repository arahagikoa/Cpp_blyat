#include "wektor.h"
#include <iostream>

Punkt::Punkt() {
    mX = mY = mZ = 0.0f;
}

Punkt::Punkt(float x, float y, float z) {
    mX = x;
    mY = y;
    mZ = z;
}

Punkt::~Punkt() {}

void Punkt::Przedstaw() {
    std::cout << mX << ", " << mY << ", " << mZ << std::endl;
}

Wektor::Wektor() {
    mA = mB = mC = 0.0f;
}

Wektor::Wektor(Punkt p1, Punkt p2) {
    mA = p2.mX - p1.mX;
    mB = p2.mY - p1.mY;
    mC = p2.mZ - p1.mZ;
}

Wektor::~Wektor() {}

void Wektor::Przestaw() {
    std::cout << "Vector: " << mA << ", " << mB << ", " << mC << std::endl;
}

float Wektor::Dlugosc() {
    return sqrt(mA * mA + mB * mB + mC * mC);
}