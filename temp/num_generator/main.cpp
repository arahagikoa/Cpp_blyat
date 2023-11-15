#include <iostream>
#include "generator.h"

int main(){
    int n;
    double a, c, m, s;
    std::cout<<"Podaj ile liczb ma zostac wygenerowane, wspolczynniki generatora oraz jego ziarno:"<<std::endl;
    std::cin>>n>>a>>c>>m>>s;

    Generator gen(n, a, c, m, s);
    gen.PrintGenerator();

    return 0;
}
