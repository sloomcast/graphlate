#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "randos.h"
#include "meme.h"

using namespace std;

const int MAX_DIMENSION = 100;
bool debug_flag = false;

template <typename T>
class Matrix{
    public:
    Matrix(int size){
        dimensions = size;
    }

    // Constructor to create a random matrix of specified flavor
    // Flavors: 1 - Random rationals
    //          2 - Random irrationals
    //          3 - Random integers
    //          4 - Random natural numbers
    //          5 - Meme
    //          6 - Complete graphs
    Matrix(int size, int flavor) {
        dimensions = size;
        this->fill_by_option(flavor);
    }
    //default constructor
    Matrix(){
        dimensions = 10;
        this->fill_by_option(5); //default to meme flavor
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
                cout << *matrix_at(i,j) << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    //REQUIRES: option is and integer 1-5 corresponding to the desired fill type
    //MODIFIES: the matrix object the method is called on
    //EFFECTS:  fills the matrix with the specified flavor of fill
    //          1: random rational number
    //          2: random irrational number
    //          3: random integer
    //          4: random natural number
    //          5: meme
    //          6: make a complete graph
    //          7: make an identity matrix
    //          default: meme
    void fill_by_option(int option){
        for (int column=0; column<dimensions; column++){
            for (int row=0; row<dimensions; row++) {
                switch (option){                    // Switching to funcs for readability, could inline if wanted
                    case 1: data[column*dimensions+row]= random_float(200) - (float) 100;
                        break;
                    case 2: data[column*dimensions+row]= (double) 3.14;
                        break;
                    case 3: data[column*dimensions+row]= random_int(2) - 1;
                        break;
                    case 4: data[column*dimensions+row]= random_int() % 10;
                        break;
                    case 5: data[column*dimensions+row]=meme_array[(column*dimensions+row) % 50];
                        break;
                    case 6: data[column*dimensions+row]= column==row ? 0 : 1;
                        break;
                    case 7: data[column*dimensions+row]= column==row ? 1 : 0;
                    default: data[column*dimensions+row] = 0;
                        break;
                }
            }
        }
    }

    protected:
    int dimensions;
    T data[MAX_DIMENSION*MAX_DIMENSION];
};

#endif