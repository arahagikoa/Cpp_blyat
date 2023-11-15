#include <iostream>
#include "vector.h"

Wektor::Wektor(int a){
    float *X = new float[a];
    counter ++;
}

Wektor::~Wektor(){
    delete []X;
    counter--;
}

void Wektor::print(){
    for(int i = 0; i < rozmiar; i++){
        std::cout<<X[i]<<" ";
    }
    std::cout << std::endl;
}

float Wektor::set(float value, int indeks){
    if(indeks < 0 || indeks>rozmiar){
        return 1;
    }
    else{
        return X[indeks]=value;
    }
}

