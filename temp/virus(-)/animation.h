#ifndef KOLO_ANIMATION_H_
#define KOLO_ANIMATION_H_

#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <stdlib.h>
#include <unistd.h>
#endif
using namespace std;

class Animation {

public:
  Animation();
  /**
   * czeka milisekundy
   * @param milliseconds
   */
  static void wait(int milliseconds);
  /**
   * czyści terminal
   */
  static void clear();
  /**
   * printuje pojedynczy znak w jednym z kolorów 0-7, w przeciwnym razie
   * zamiast drukować kolorowy znak drukuje numer koloru
   * @param col
   * @param ch
   */
  static void drawPixel(Ludek &pop, char ch);
  static void drawLine(Populasjon &populacja);
  virtual ~Animation();
};


#endif /* KOLO_ANIMATION_H_ */
