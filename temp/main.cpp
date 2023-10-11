#include <iostream>
class Myclass{
        int x;
        double y;   
    public:
        void setdata(int a, double b){
            x = a;
            y = b;
        }
        void displaydata(){
            std::cout << "x:" << x << ", y:" << y << std::endl;
        }   
    };

int main() {
    Myclass obj;
    std::cout << "Hello world !" << std::endl;
    
    double *x = new double();
    delete x;

    double *j = new double[10];
    delete []j;

    double **k = new double*[20];
    for (int i = 0; i < 20; i++){
        k[i] = new double[10];
    }
    for (int i = 0; i < 20; i++){
        delete []k[i];
    }
    delete []k;

    obj.setdata(42, 3.14);
    obj.displaydata();
    return 0;
}
