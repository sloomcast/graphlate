#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

using namespace std;

const int MAX_DIMENSION = 10;

template <typename T>
class Matrix{
    public:
    //Constructor
    Matrix(int size);

    //EFFECTS:  returns the width/height of the matrix
    int matrix_dimension();

    //REQUIRES: 0 <= row,col <= dimensions
    //EFFECTS:  returns by reference the value stored at row,col
    T* matrix_at(int row, int col);

    //REQUIRES: 0 <= row <= dimensions
    //EFFECTS:  returns by reference the row at row
    List<T> return_row(int row);

    //REQUIRES: 0 <= col <= dimensions
    //EFFECTS:  returns by reference the column at col
    List<T> return_col(int col);

    //REQUIRES: os is a valid output stream capable of being written to
    //MODIFIES: the file specified in os
    //EFFECTS:  prints the matrix object to os
    void print(ostream *os = nullptr);

    //REQUIRES: option is and integer 1-4 corresponding to the desired fill type
    //MODIFIES: the matrix object the method is called on
    //EFFECTS:  randomly fills the matrix with the specified type of number
    //          1: rational number
    //          2: irrational number
    //          3: integer
    //          4: natural number
    void fill_random(int option);

    protected:
    int dimensions;
    T data[MAX_DIMENSION];
};

#endif