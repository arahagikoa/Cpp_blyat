#include "hist.h"
#include <iostream>
#include <random>
#include <list>

histc::histc(std::list<int> results) : results(results) {};
std::list<int> histc::roll_dice() {
    std::random_device rd;
    std::mt19937 gen(rd());

    int min = 1;
    int max = 6;
    int toss_count = 18; 
    results.clear(); // Clear the previous results

    for (int i = 0; i < toss_count; i++) {
        for (int j = 0; j < 3; j++) {
            std::uniform_int_distribution<int> distribution(min, max);
            int score = distribution(gen);
            results.push_back(score); // Add the score to the results list
        }
    }
    return results; // Return the updated results list
}
void histc::print(){
    int myArray[6] = {0};
    for(std::list<int>::iterator it = results.begin(); it != results.end(); it++){
        for(int i = 1; i <= 6; i++){
            if(*it == i){
                myArray[i-1]++;
            }
        }
    }
    for(int i =0; i < 6; i++){
        int value = myArray[i];
        std::cout << "Simple histogram: "<<std::endl; 
        std::cout<<(i+1);
        for(int j = 0; j < value; j++){
            std::cout<<"*";
        }
        std::cout << std::endl;
    }
}
