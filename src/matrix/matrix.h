#ifndef MATRIX_H
#define MATRIX_H

/*Matrix.h
 *Matrix interface and implementation written by Owen Davis 
 *for some research that Derik is doing lol
 *written August 2023
*/

//constants
#define MAX_WIDTH 500
#define MAX_HEIGHT 500

//type definition
struct matrix{
    int width;
    int height;
    int *allocp;
    int data[MAX_HEIGHT * MAX_WIDTH];
};

//function prototypes

//REQUIRES: mat points to a valid matrix
//          0 < width && width <= MAX_WIDTH
//          0 < height && height <= MAX_HEIGHT
//MODIFIES: *mat
//EFFECTS: Initializes *mat as a matrix struct with the given width and height
void matrix_init(struct matrix *mat, int width_init, int height_init);

//REQUIRES: mat points to a valid matrix
//EFFECTS: returns the width of the matrix pointed to by *mat
int matrix_width(struct matrix *mat);

//REQUIRES: mat points to a valid matrix
//EFFECTS: returns the height of the matrix pointed to by *mat
int matrix_height(struct matrix *mat);

//REQUIRES: mat points to a valid matrix
//          0 < width && width <= MAX_WIDTH
//          0 < height && height <= MAX_HEIGHT
//EFFECTS: returns a pointer to the value at row, col
int* matrix_at(struct matrix *mat, int row, int col);

//REQUIRES: mat points to a valid matrix
//MODIFIES: *mat
//EFFECTS:  fills *mat with 0s as an empty matrix
void matrix_fill_empty(struct matrix *mat);

#endif 
