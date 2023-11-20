/*
 * Animation.cpp
 *
 *  Created on: 16 gru 2022
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#include "animation.h"
#include "virus.h"
using namespace std;

Animation::Animation() {
  // TODO Auto-generated constructor stub
}

void Animation::wait(int milliseconds) {
#ifdef _WIN32
  Sleep(milliseconds);
#else
  usleep(milliseconds * 1000);  // takes microseconds
#endif
}
/**
 * czyści terminal
 */
void Animation::clear() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
/**
 * printuje pojedynczy znak w jednym z kolorów 0-7, w przeciwnym razie
 * zamiast drukować kolorowy znak drukuje numer koloru
 * @param col
 * @param ch
 */
void Animation::drawPixel(Ludek &lulu, char ch) {
#ifdef _WIN32
    if(lulu.chory){
        system("Color 01");
    }
    if(lulu.martwy){
        system("Color 02");
    }
    if(lulu.zdrowy){
        system("Color 03");
    }
    if(lulu.uodporniony){
        system("Color 04");
    }
  std::cout << ch << std::endl;
#else
  switch (col) {
    case 0: cout << "\x1B[31m" << ch << "\033[0m"; break;
    case 1: cout << "\x1B[32m" << ch << "\033[0m"; break;
    case 2: cout << "\x1B[33m" << ch << "\033[0m"; break;
    case 3: cout << "\x1B[34m" << ch << "\033[0m"; break;
    case 4: cout << "\x1B[35m" << ch << "\033[0m"; break;
    case 5: cout << "\x1B[36m" << ch << "\033[0m"; break;
    case 6: cout << "\x1B[37m" << ch << "\033[0m"; break;
    case 7: cout << "\x1B[90m" << ch << "\033[0m"; break;
    default: cout << col; break;
  }
#endif
}
void Animation::drawLine(Populasjon &populacja) {
    for(int i = 0; i < populacja.dlugosc; i++) {
        for(int j = 0; j < populacja.szerokosc; j++) {
            Ludek &ludzik = populacja.ludzie[i][j];
            drawPixel(ludzik, '@');  // ' ' to znak, który chcesz rysować w miejscu danego ludzika
        }
        std::cout << std::endl;
    }
}
Animation::~Animation() {}
