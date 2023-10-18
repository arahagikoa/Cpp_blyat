#include <iostream>
class matrix{
    double **fdata;
    int nRows, nCols;
public:
    matrix(int row, int col);
    void print();
    double get(int row, int col);
    void set(int row, int col, double);
    ~matrix();
};