#include <Histogram.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

Histogram::Histogram(int nbins) : counts(nbins, 0) {}

int Histogram::getSize() const{
    return counts.size();
}
void Histogram::fill(int x){
    if (x >= 0 && x < getSize()) {

        counts[x]++;
    } else {
        std::cout << "Not in range";
    }

}

void Histogram::dice(int dices, int throws){
    for (int i = 0; i < dices; i++){
        int sum { 0 };
        for (int j = 0; j < throws; j++){
            int roll = rand() % 6 + 1;
            sum += roll;
        }
        fill(sum);
    }
}

int Histogram::getCount(int bin) const{
    if (bin >= 0 && bin < getSize()) {
        return counts[bin];
    } else {
        return -1; 
    }
}