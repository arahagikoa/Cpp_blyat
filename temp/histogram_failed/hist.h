#include <random>
#include <iostream>
#include <list>

class histc{
    std::list<int> results; // A member variable to store results, if needed

public:
    histc(std::list<int> results);
    std::list<int> roll_dice();
    void print();
    ~histc();
}; 
