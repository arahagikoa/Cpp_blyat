#include "animation.h"
#include "virus.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    cout << "Podaj zarazliwosc, umieralnosc i czas choroby: ";
    int zarazliwosc, umieralnosc, czas_choroby;
    cin >> zarazliwosc >> umieralnosc >> czas_choroby;

    Virus moj_wirus(zarazliwosc, czas_choroby, umieralnosc);
    cout<< "wprowadź rozmiary populacji długość x szerokość"<<endl;
    int szerokosc, dlugosc;
    cin>>szerokosc>>dlugosc;
    Populasjon populacja(szerokosc, dlugosc);
    Animation animacja;

    populacja.zarazanie_ludkow(moj_wirus, animacja);
    cout<<"Umarło, "<<moj_wirus.martwy_counter<<"Uodporniło się, "<<moj_wirus.uodporniony_counter<<"Zachorowało, "<<moj_wirus.choroba_counter<<endl;
    return 0;
}
