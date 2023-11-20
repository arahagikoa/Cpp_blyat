#include "virus.h"
#include "animation.h"
#include <cstdlib>
#include <ctime>
#include<vector>
using namespace std;

Virus::Virus(int a, int b, int c){
    zarazliwosc = a;
    choroba_time = b;
    umarlnosc = c;
}

Virus::~Virus(){}

bool Virus::czy_martwy(Populasjon D, int i, int j) {
    int czy_umiera_tego_dnia = rand() % 100;
        if (czy_umiera_tego_dnia < 20) {
            D.ludzie[i][j].martwy = true;
            return true;
        }
        return false;
}

bool Virus::czy_odporny(Populasjon D, int i, int j){
    if(choroba_dni_counter<choroba_time){
        if(D.ludzie[i][j].martwy){
            return false;
        }
        choroba_dni_counter++;
        return false;
    }
    return true;
}

bool Virus::czy_zarazic(){
    return rand()%100 < zarazliwosc;
}

Populasjon::Populasjon(int a, int b){
    szerokosc = a;
    dlugosc = b;
}

Ludek::Ludek(Stan initial_state) : chory(false), zdrowy(true), uodporniony(false), martwy(false), currentStan(initial_state) {
    // Constructor implementation
}
Ludek::~Ludek(){};

vector<vector<Ludek>> Populasjon::zarazanie_ludkow(Virus &virus, Animation &bubu) {
    srand(static_cast<unsigned int>(time(nullptr)));

    int kol_zar = rand() % szerokosc;
    int wier_zar = rand() % dlugosc;
    ludzie[wier_zar][kol_zar].chory = true;

    for (int krok = 0; krok < 1000; ++krok) {
        // Iteracja po wszystkich ludkach
        for (int i = 0; i < dlugosc; ++i) {
            for (int j = 0; j < szerokosc; ++j) {
                // Sprawdź, czy chory osobnik zarazi inne
                if (ludzie[i][j].chory) {
                    // Iteracja po sąsiednich polach
                    for (int x = i - 1; x <= i + 1; ++x) {
                        for (int y = j - 1; y <= j + 1; ++y) {
                            // Sprawdź, czy pole istnieje w obszarze populacji
                            if (x >= 0 && x < dlugosc && y >= 0 && y < szerokosc) {
                                // Sprawdź, czy osoba nie jest już chora lub uodporniona
                                if (!ludzie[x][y].chory && !ludzie[x][y].uodporniony) {
                                    if (virus.czy_zarazic()) {
                                        ludzie[x][y].chory = true;
                                        virus.choroba_counter++;
                                        virus.choroba_dni_counter = 0;  
                                    }
                                }
                                if (ludzie[x][y].chory) {
                                    if (virus.czy_martwy(*this, x, y)) {
                                        virus.martwy_counter++;
                                    }
                                }
                                if (ludzie[x][y].chory) {
                                    if (virus.czy_odporny(*this, x, y)) {
                                        ludzie[x][y].uodporniony = true;
                                        virus.uodporniony_counter++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        bubu.drawLine(*this);
    }
}



