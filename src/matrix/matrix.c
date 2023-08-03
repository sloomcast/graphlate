#include "matrix/matrix.h"
#include "io/io.h"
#include "main.h"

//implementations of matrix.h

//REQUIRES: mat points to a valid matrix
//          0 < width && width <= MAX_WIDTH
//          0 < height && height <= MAX_HEIGHT
//MODIFIES: *mat
//EFFECTS: Initializes *mat as a matrix struct with the given width and height
void matrix_init(struct matrix *mat, int width_init, int height_init){
    //error handling here?

    //initialization
    mat->height = height_init;
    mat->width = width_init;
    mat->allocp = mat->data + width_init*height_init;
}

//REQUIRES: mat points to a valid matrix
//EFFECTS: returns the width of the matrix pointed to by *mat
int matrix_width(struct matrix *mat){
    return mat->width;
}

//REQUIRES: mat points to a valid matrix
//EFFECTS: returns the height of the matrix pointed to by *mat
int matrix_height(struct matrix *mat){
    return mat->height;
}

//REQUIRES: mat points to a valid matrix
//          0 < width && width <= MAX_WIDTH
//          0 < height && height <= MAX_HEIGHT
//EFFECTS: returns a pointer to the value at row, col
int* matrix_at(struct matrix *mat, int row, int col){
    //error handling?

    //finds the index in the 1d array
    int index = row*matrix_width(mat) + col;
    return &mat->data[index];
}

//REQUIRES: mat points to a valid matrix
//MODIFIES: *mat
//EFFECTS:  fills *mat with 0s as an empty matrix
void matrix_fill_empty(struct matrix *mat){
    for(int i=0; i<mat->height; i++){
        for(int j=0; j<mat->width; j++){
            *matrix_at(mat,i,j) = 0;
        }
    }
}
