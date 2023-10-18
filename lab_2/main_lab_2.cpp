#include "histogram.h"
#include <cstdlib>
#include <iostream>
/**
 * TODO:
 * Należy zrobić klasę histogram znajdującą się w pliku cpp oraz h,
 * oraz w programie main zasymulować rzut wieloma koścmi.
 * 1. Klasa histogram powinna zawierać (2pkt):
 * a) zmienną prywatną std::vector<int> trzymający liczby zliczeń
 * b) metodę publiczną getSize() która zwraca liczbę binów
 * c) metodę publiczną fill(int x) która wypełnia x-owy bin, UWAGA:
 * metoda ta powinna sprawdzać czy nie wychodzimy za histogram!
 * UWAGA: std::vector posiada metody do sprawdzania długości czy alokowania
 * określonej ilości pamięci (size,resize)
 * d) konstruktor histogram(int nbins) który tworzy histogram z n-binami
 * 2. Metoda dice powinna 
 * a) generować n-rzutów m-kostkami
 * b) dla każdego rzutu sumę oczek z kostek wrzucać do histogramu
 * 4. na kończu program rysuje histogram (1 pkt) wykorzystując metodę draw
 * UWAGA: metoda draw żąda dostępu do zmiennych prywatnych więc trzeba ją
 * zaprzyjaźnić z histogramem
 * UWAGA: problemem moze być wygenerowanie liczb losowych - polecam użyć metody
 * rand() z pliku <cstdlib>, generuje ona bardzo duże liczby więc przy pomocy
 * modulo można wygenerować liczby losowe z danego zakresu
 * ZADANIE EXTRA: dopisać metodę getMean() która zwróci średnią z histogramu
*/


void draw(histogram h);//definicja jest na dole

int main(){
    for(int i=0;i<4;i++){
        histogram x(25);
        dice(x,i+1);
        draw(x);
    }
    return 0;
}

void draw(histogram h){
    int maximum = 0;
    double scale = 1;
    for(int i=0;i<static_cast<int>(h.fArray.size());i++){
        if(h.fArray[i]>maximum) maximum = h.fArray[i];
        std::cout<<"-";
    }
    std::cout<<std::endl;
    scale = (double)maximum/20.0;
    for(int j=21;j>0;j--){
        for(int i=0;i<static_cast<int>(h.fArray.size());i++){
            int threshold = (int)(double(j)*scale);
            if(h.fArray[i]>threshold){
                std::cout<<"*";
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
    for(int i=0;i<static_cast<int>(h.fArray.size());i++){
        if(h.fArray[i]>maximum) maximum = h.fArray[i];
        std::cout<<"-";
    }
    std::cout<<std::endl;
}
