#include "Histogram.h"

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
/*
*
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
void draw(const Histogram& histogram) {
    auto maxCountIterator = std::max_element(0, histogram.getSize());
    int maxCount = (maxCountIterator != histogram.getSize()) ? maxCountIterator : 0;

    for (int i = maxCount; i > 0; i--) {
        for (int j = 0; j < histogram.getSize(); j++) {
            if (histogram.getCount(j) >= i)
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < histogram.getSize(); i++) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    int numThrows = 100;  // Number of throws
    int numDice = 2;      // Number of dice for each throw
    int numBins = numDice * 6 + 1;  // Maximum possible sum

    Histogram histogram(numBins);

    // Simulate rolling the dice and adding the sums to the histogram
    histogram.dice(numThrows, numDice);

    // Display the histogram
    std::cout << "Histogram counts:\n";
    for (int i = 0; i < histogram.getSize(); ++i) {
        std::cout << "Sum " << i << ": " << histogram.getCount(i) << "\n";
    }

    // Draw the histogram
    std::cout << "\nHistogram:\n";
    draw(histogram);

    return 0;
}


