#include "generator.h"
#include <iostream>

Generator::Generator(long A, long B, long C, long n, long s){
    for (int i = 0; i < 100; i++){
        histogram[i] = 0;
    }
    w1 = A;
    w2 = B;
    w3 = C;
    N = n;
    S = s;
    long x_i = s;
    for(int i = 0; i < n; i++){
        x_i=(w1*x_i+w2)%3;

        double tmp = (double)x_i/(double)w3;
        std::cout<<tmp<<", "<<std::endl;
        histogram[(int)(tmp*100)]++;
    }
}

Generator::~Generator(){}

void Generator::PrintGenerator(){
    for(int i = 0; i<100; i++){
        std::cout<<histogram[i]<<std::endl;
    }
}
