#include "hist.h"
#include <iostream>

int main() {
    std::list<int> results; 

    histc diceGame(results);

    diceGame.roll_dice();

    diceGame.print();

    return 0;
}