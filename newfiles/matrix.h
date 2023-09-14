#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

const int MAX_DIMENSION = 10;

template <typename T>
class Matrix{
    public:
    Matrix(int size){
        dimensions = size;
    }

    //default constructor
    Matrix(){
        dimensions = 10;
        this->fill_random(3);
    }

    //EFFECTS:  returns the width/height of the matrix
    int matrix_dimension(){
        return dimensions;
    }

    //REQUIRES: 0 <= row,col <= dimensions
    //EFFECTS:  returns by reference the value stored at row,col
    T* matrix_at(int row, int col){
        int index = row*dimensions + col;
        return &data[index];
    }

    //REQUIRES: 0 <= row <= dimensions
    //EFFECTS:  returns by reference the row at row
    list<T> return_row(int row){
        //make list
        list<T> to_return;

        //add to list
        for(int i=0; i<dimensions; ++i){
            to_return.push_front(matrix_at(row, i));
        }

        return to_return;
    }

    //REQUIRES: 0 <= col <= dimensions
    //EFFECTS:  returns by reference the column at col
    list<T> return_col(int col){
        //make list
        list<T> to_return;

        //add to list
        for(int i=0; i<dimensions; ++i){
            to_return.push_front(matrix_at(i,col));
        }

        return to_return;
    }

    //REQUIRES: os is a valid output stream capable of being written to
    //MODIFIES: the file specified in os
    //EFFECTS:  prints the matrix object to os
    void print(ofstream *os){
        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                *os << matrix_at(i,j);
            }
        }
    }

    //REQUIRES: f_out is the name of an existing file or a file to be created
    //MODIFIES: the file specified in f_out
    //EFFECTS:  opens the file f_out or creates a new file and prints the matrix to it
    void print(string f_out){
        //creates stream
        ofstream of;
        of.open(f_out);

        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                of << matrix_at(i,j);
            }
        }
    }

    //EFFECTS:  prints the matrix to stdout
    void print(){
        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                cout << matrix_at(i,j);
            }
        }
    }

    //REQUIRES: option is and integer 1-4 corresponding to the desired fill type
    //MODIFIES: the matrix object the method is called on
    //EFFECTS:  randomly fills the matrix with the specified type of number
    //          1: rational number
    //          2: irrational number
    //          3: integer
    //          4: natural number
    void fill_random(int option){

    }

    protected:
    int dimensions;
    T data[MAX_DIMENSION];
};

#endif