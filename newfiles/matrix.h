#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <typeinfo>
#include <cmath>
#include "randos.h"
#include "meme.h"
#include "maths.h"

using namespace std;

const int MAX_DIMENSION = 100;
bool debug_flag = false;

template <typename T>
class Matrix{
    public:

    // Constructor to create a random matrix of specified flavor
    // Flavors: 1 - Random rationals
    //          2 - Random irrationals
    //          3 - Random integers
    //          4 - Random natural numbers
    //          5 - Meme
    //          6 - Complete graphs
    Matrix(int size = 10, int flavor = 5) { //defaults to meme flavor
        //error handling
        if(flavor < 1 || flavor > 6)throw std::invalid_argument("ERROR: Please enter a matrix fill designation between 1-5");

        dimensions = size;
        this->fill_by_option(flavor);
    }

    Matrix(std::initializer_list<T> il){
        //add assert to make sure it's a square matrix
        double s1 = sqrt(il.size());
        int s2 = sqrt(il.size());
        if(double(s2) != s1) throw std::invalid_argument("ERROR: Initializer list must be a 1D square matrix");

        dimensions = sqrt(il.size());  //set size

        for(int r=0; r<dimensions; ++r){
            for(int c=0; c<dimensions; ++c){
                *this->matrix_at(r,c) = *(il.begin() + r*dimensions + c);
            }
        }
    }

    //EFFECTS:  returns the width/height of the matrix
    int matrix_dimension() {
        return dimensions;
    }

    //REQUIRES: 0 <= row,col <= dimensions
    //EFFECTS:  returns by reference the value stored at row,col
    T* matrix_at(int row, int col){
        //error handling
        if(row < 0 || row > dimensions) throw std::invalid_argument("ERROR: Invalid row value");
        if(col < 0 || col > dimensions) throw std::invalid_argument("ERROR: Invalid column value");

        int index = row*dimensions + col;
        return &data[index];
    }

    //REQUIRES: 0 <= row <= dimensions
    //EFFECTS:  returns by reference the row at row
    list<T> return_row(int row) {
        //error handling
        if(row < 0 || row > dimensions) throw std::invalid_argument("ERROR: Invalid row value");

        //make list
        list<T> to_return;

        //add to list
        for(int i=0; i<dimensions; ++i){
            to_return.push_back(*matrix_at(row, i));
        }

        return to_return;
    }

    //REQUIRES: 0 <= col <= dimensions
    //EFFECTS:  returns by reference the column at col
    list<T> return_col(int col) {
        //error handling
        if(col < 0 || col > dimensions) throw std::invalid_argument("ERROR: Invalid column value");

        //make list
        list<T> to_return;

        //add to list
        for(int i=0; i<dimensions; ++i){
            to_return.push_back(*matrix_at(i,col));
        }

        return to_return;
    }

    //REQUIRES: os is a valid output stream capable of being written to
    //MODIFIES: the file specified in os
    //EFFECTS:  prints the matrix object to os
    //NOTE:     if the ofstream passed to the print function is not in append mode
    //          the function WILL OVERWRITE any existing contents in the corresponding file
    void print(ofstream &os) {
        //error handling
        if(!os.is_open()) throw std::invalid_argument("ERROR: Please input a valid ofstream to print to");

        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                os << *matrix_at(i,j) << " ";
            }
            os << endl;
        }
        os << endl << endl;
    }

    //REQUIRES: f_out is the name of an existing file or a file to be created
    //MODIFIES: the file specified in f_out
    //EFFECTS:  opens the file f_out or creates a new file and prints the matrix to it
    void print(string f_out) {
        //error handling
        if(f_out == "") throw std::invalid_argument("ERROR: Please input a valid filename");

        //creates stream
        ofstream of;
        of.open(f_out, ios::app);
        if(!of.is_open()) throw std::invalid_argument("ERROR: Encountered an issue opening file" + f_out);

        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                of << *matrix_at(i,j) << " ";
            }
            of << endl;
        }
        of << endl << endl;

        of.close();
    }

    //EFFECTS:  prints the matrix to stdout
    void print() {
        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                cout << *matrix_at(i,j) << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    //operators
    bool operator==(Matrix<T> rhs){
        if(rhs.matrix_dimension() != this->matrix_dimension()) return false;    //has to be the same size

        for(int r=0; r<rhs.matrix_dimension(); ++r){
            for(int c=0; c<rhs.matrix_dimension(); ++c){
                if(*(this->matrix_at(r,c)) != *rhs.matrix_at(r,c)) return false;
            }
        }

        return true;
    }

    bool operator!=(Matrix<T> rhs){    
        return !(*this == rhs);
    }

    //REQUIRES: option is an integer 1-7 corresponding to the desired fill type
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
        //error handling
        if(option < 1 || option > 7)throw std::invalid_argument("ERROR: Please specify an integer in the range 1-5 to fill with");

        for (int column=0; column<dimensions; column++){
            for (int row=0; row<dimensions; row++) {
                switch (option){                    // Switching to funcs for readability, could inline if wanted
                    case 1: data[column*dimensions+row]= random_float(200) - (float) 100;
                        break;
                    case 2: data[column*dimensions+row]= (double) 3.14 * (random_int(1023)+1);
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


// BASIC, BAD, TYPE-SPECIFIC
void print_eq(Matrix<int> matrix_1, Matrix<int> matrix_2, Matrix<int> result) {
    int size1 = matrix_1.matrix_dimension();
    int size2 = matrix_2.matrix_dimension();
    int size3 = result.matrix_dimension();

    if(size1 != size2 || size1 != size3 || size2 !=size3){  //Currently only working with square matrices, will only use size1 after this
        printf("BAD. DON'T. STOP.\n");
        return;
    }

    // Print each line top to bottom
    for (int j=0; j<size1; j++) {                    
        for(int k=0; k<size1; k++)//Print each value in the jth row for Matrix 1
        {
            printf(" %d ",*matrix_1.matrix_at(j,k));
        }
        
        //If it's in the right spot, print a multiplication symbol
        if(j == size1/2)
        {
            printf("\tX\t");
        }
        else //Else, don't
        {
            printf("\t\t");
        }
    
        //Print each value in the jth row for for Matrix 2
        for(int k=0; k<size1; k++)
        {
           printf(" %d ",*matrix_2.matrix_at(j,k));
        }
    
        //If it's in the right spot, print the equals symbol
        if(j == size1/2)
        {
            printf("\t=\t");
        }
        else//Otherwise, don't
        {
            printf("\t\t");
        }

        //Print each value in the jth row for the result matrix
        for(int k=0; k<size1; k++)
        {
            printf(" %d ",*result.matrix_at(j,k));
        }
        printf("\n");
    }
};

// BASIC, BAD, TYPE-SPECIFIC, MEME
Matrix<int> mat_mult(Matrix<int> matrix_1, Matrix<int> matrix_2) {
    Matrix<int> matrix(3,1);
    return matrix;
}
#endif