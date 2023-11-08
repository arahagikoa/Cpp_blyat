#include "Animation.h"
#include "zaba.h"
#include <iostream>
#include <fstream>

int main(){
    std::fstream plik;
    plik.open("config.txt");
    string nazwa;
    plik>>nazwa;
    plik>>nazwa;
    std::cout<<nazwa;
    int czas;
    plik>>czas;
    plik>>czas;
    std::cout<<czas;
    plik.close();

    zaba klasa;
    plik.open(nazwa);
    string line;
    while(std::getline(plik, line)){
        getline(plik, line);
        klasa.toad.push_back(line);
    }
    plik.close();
    
    int abc = 0;
    srand(time(0));
    int k = rand()%7+1;
    while(abc != 17){
        Animation::drawLine(k, klasa.toad[abc]);
        abc++;
    }
}
