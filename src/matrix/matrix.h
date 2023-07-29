#ifndef MATRIX_H
#define MATRIX_H

/*Matrix.h
 *Matrix interface and implementation written by Owen Davis 
 *for some research that Derik is doing lol
 *this module is based on a module written by Andrew DeOrio for the University of Michigan
 *written August 2023
*/

//maximum dimensions for the array, can be adjusted if needed
const int MAX_MATRIX_HEIGHT = 1000;
const int MAX_MATRIX_WIDTH = 1000;

//definition of the matrix as a collapsed 2d array
struct Matrix{
    int width;
    int height;
    int data[MAX_MATRIX_HEIGHT * MAX_MATRIX_WIDTH];
};

#endif

