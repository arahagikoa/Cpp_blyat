#include "point.h"
#include <iostream>

int main(){
    float x1, x2, x3, y1, y2, y3, x_odc;
    std::cout<<"Wprowadź współrzędnie pierwszego punktu x, y:"<<std::endl;
    std::cin>>x1>>y1;
    std::cout<<"Wprowadź współrzędnie drugiego punktu x, y:"<<std::endl;
    std::cin>>x2>>y2;
    std::cout<<"Wprowadź współrzędnie trzeciego punktu x, y:"<<std::endl;
    std::cin>>x3>>y3;
    if (x1 == x2 || x1 == x3 || x2 == x3) {
        std::cout << "Error: Dwa albo więcej punktów mają takie same współrzędnie x. Wpisz różne wartości x." << std::endl;
        return 1; 
    }

    point *Point1 = new point(x1, y1);
    point *Point2 = new point(x2, y2);
    point *Point3 = new point(x3, y3);

    parabola parbl1;
    parbl1.calculate(Point1, Point2, Point3);
    parbl1.print_equation();

    std::cout<<"Wprowadź wartość odciętej x do wyznaczenia równania paraboli:"<<std::endl;
    std::cin>>x_odc;
    point *point_odc = new point(x_odc, 0);
    point_odc->setY(point_odc->calculate_y(parbl1));
    point_odc->print_info();
    
    point_odc->calculate_y_ax_b(*point_odc, parbl1);
    
    delete Point3;
    delete Point2;
    delete Point1;
    delete point_odc;
}