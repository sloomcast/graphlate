#include "matrix.h"

using namespace std;

template <typename T>
Matrix<T>::Matrix(int size){
    dimensions = size;
}

//EFFECTS:  returns the width/height of the matrix
template <typename T>
int Matrix<T>::matrix_dimension(){
    return dimensions;
}

//REQUIRES: 0 <= row,col <= dimensions
//EFFECTS:  returns by reference the value stored at row,col
template <typename T>
T* Matrix<T>::matrix_at(int row, int col){
    int index = row*dimensions + col;
    return &data[index];
}

//REQUIRES: 0 <= row <= dimensions
//EFFECTS:  returns by reference the row at row
template <typename T>
List<T> Matrix<T>::return_row(int row){

}

//REQUIRES: 0 <= col <= dimensions
//EFFECTS:  returns by reference the column at col
template <typename T>
List<T> Matrix<T>::return_col(int col){

}

//REQUIRES: os is a valid output stream capable of being written to
//MODIFIES: the file specified in os
//EFFECTS:  prints the matrix object to os
template <typename T>
void Matrix<T>::print(ostream *os){

}

//REQUIRES: option is and integer 1-4 corresponding to the desired fill type
//MODIFIES: the matrix object the method is called on
//EFFECTS:  randomly fills the matrix with the specified type of number
//          1: rational number
//          2: irrational number
//          3: integer
//          4: natural number
template <typename T>
void Matrix<T>::fill_random(int option){

}