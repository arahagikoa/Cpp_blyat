#include <iostream>
#include "kurs.h"
#include <iomanip>

int main(){
    std::cout << std::fixed;
    std::cout<<std::setprecision(3);
    kurs usd("dolar.txt");
    kurs euro("euro.txt");
    kurs usdEur(usd);
    usdEur = usdEur/euro;

    usd.print();
    euro.print();
    usdEur = usdEur;//dla pewności
    usdEur.print();
    return 0;
}