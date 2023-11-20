#ifndef VECTOR_H
#define VECTOR_H
#include "animation.h"
#include<vector>
#include <cstdlib> // do funkcji rand()
#include <ctime> // do funkjci time
using namespace std;

class Virus{
    public:
    int choroba_counter = 0;
    int martwy_counter = 0;
    int uodporniony_counter = 0;
    int choroba_dni_counter = 0;
    int zarazliwosc; //procnet
    int choroba_time; // dni
    int umarlnosc; // dni po ktorych umiera
    Virus(int zarazliwosc, int choroba_time, int umarlnosc);
    ~Virus();
    bool czy_zarazic();
    bool czy_odporny(Populasjon D, int i, int j);
    bool czy_martwy(Populasjon D, int i, int j);
    friend class Ludek;
    friend class Populasjon;
};

class Populasjon{
    public:
    int szerokosc, dlugosc;
    vector<vector<Ludek>> ludzie;
    Populasjon(int szerokosc, int dlugosc);
    ~Populasjon();
    vector<vector<Ludek>> zarazanie_ludkow(Virus &virus, Animation &aninini);
    friend class Ludek;
    friend class Virus;
};

class Ludek {
public:
    bool chory;
    bool zdrowy;
    bool uodporniony;
    bool martwy;
    
    enum Stan {
        CHORY, 
        MARTWY, 
        UODPORNIONY, 
        ZDROWY
    };
    Stan currentStan;
    Ludek(Stan initial_state = ZDROWY); //wartość domyślna
    Ludek(Stan inital_state);
    ~Ludek();
    friend class Virus;
    friend class Populasjon;
};

#endif
