#include "matrix.h"
#include <iostream>

    matrix::matrix(int row, int col){
        nRows = row;
        nCols = col;
        fdata = new double*[row];
        for(int i = 0; i < col; i++){
            fdata[i] = new double[col];
        }
    }
    void matrix::print(){
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                std::cout <<fdata[i][j]<< " ";
            }
            std::cout << std::endl;
        }
    }
    double matrix::get(int row, int col){
        return fdata[row][col];
    }
    void matrix::set(int row, int col, double value){
        fdata[row][col] = value;
    }
    matrix::~matrix(){
        for(int i = 0; i < nRows; i ++){
            delete []fdata[i];
        }
        delete[] fdata;
    }