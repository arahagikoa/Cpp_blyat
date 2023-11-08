#include "point.h"
#include <iostream>
#include <vector>
#include <list>

point::point(float X=0, float Y=0){
    x=X;
    y=Y;
    counter++;
}

point::~point(){
    counter--;
}

void point::print_info(){
    std::cout<<"Współrzędnie punktu x,y to :"<<"("<<x<<","<<y<<")"<<std::endl;
}

void point::_counter(){
    std::cout<<"Liczba punktów to: "<<counter<<std::endl;
}

float point::calculate_y(parabola A){
    float y = A.getA()*x*x+A.getB()*x+A.getC();
    return y;
}

/*float point::calculate_y_ax_b(point A, point B){
    float a,b;
    float x1 = A.get_x();
    float y1 = A.get_y();
    float x2 = B.get_x();
    float y2 = B.get_y();

}*/

parabola::parabola(float A=1, float B=1, float C=1){
    a=A;
    b=B;
    c=C;
    counterp++;
}

parabola::~parabola(){
    counterp--;
}

void parabola::print_p(){
    std::cout << "Współczynniki paraboli to (a, b, c): " << getA() << ", " << getB() << ", " << getC() << std::endl;
}

void parabola::calculate(point *X, point *Y, point *Z) {
        float x1 = X->get_x();
        float x2 = Y->get_x();
        float x3 = Z->get_x();
        float y1 = X->get_y();
        float y2 = Y->get_y();
        float y3 = Z->get_y();

        float denominator = (x1 - x2) * (x1 - x3) * (x2 - x3);
        if (denominator == 0) {
            std::cout << "Nie można obliczyć równania kwadratowego - punkty są współliniowe." << std::endl;
            exit(1);
        }

        a = (y1 * (x2 - x3) - y2 * (x1 - x3) + y3 * (x1 - x2)) / denominator;
        b = (y1 * (pow(x2, 2) - pow(x3, 2)) - y2 * (pow(x1, 2) - pow(x3, 2)) + y3 * (pow(x1, 2) - pow(x2, 2))) / denominator;
        c = (y1 * (x2 * x3 * (x2 - x3)) - y2 * (x1 * x3 * (x1 - x3)) + y3 * (x1 * x2 * (x1 - x2))) / denominator;
    }

    void parabola::print_equation() {
        std::cout << "Równanie kwadratowe: y = " << a << "x^2 + " << b << "x + " << c << std::endl;
    }
