#include "kurs.h"
#include <iostream>
#include <fstream>
using namespace std;
class kurs;

void kurs::wczytaj_plik(string nazwa, kurs& zmienna){
    fstream plik;
    plik.open(nazwa, ios::in);
    if(plik.is_open()){
        cout<<"Otworzyłem plik"<<endl;
        plik>>zmienna.n;
        for(int i = 0; i < zmienna.n; i++){
            plik>>zmienna.data[i]>>curs[i];
        }
        plik.close();
    }
}

void kurs::print() const {
    cout << "Wczytano" << n << "kursów" << endl;
    for (int i = 0; i < n; i++) {
        cout << convert(data[i]) << ", " << curs[i] << endl;
    }
}
