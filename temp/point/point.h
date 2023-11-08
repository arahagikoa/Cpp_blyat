#ifndef POINT_H
#define POINT_H

#include <iostream>

class point{
    float x; 
    float y;
    static int counter;
    public:
    point(float, float);
    ~point();
    float get_x(){
        return x;
    }
    float get_y(){
        return y;
    }
    void setY(float newY) {
        y = newY;
    }
    void print_info();
    float calculate_y(parabola A);
    //float calculate_y_ax_b(point A, point B);
    void _counter();
    friend class parabola;
};

class parabola{
    float a;
    float b;
    float c;
    static int counterp;
    public:
    parabola(float a1 = 1, float a2 = 1, float a3 = 1);
    ~parabola();
    float getA(){
        return a;
    }
    float getB(){
        return b;
    }
    float getC(){
        return c;
    }
    void print_p();
    void print_equation();
    void calculate(point *a1,point *b1,point *c1);
    static void _counterp();
    friend class parabola;  
};

#endif