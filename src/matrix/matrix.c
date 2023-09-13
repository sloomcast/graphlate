// #include "src/matrix/matrix.h"
// #include "src/io/io.h"
// #include "src/main.h"
// #include <time.h>
// #include <math.h>

// //implementations of matrix.h

// //REQUIRES: mat points to a valid matrix
// //          0 < width && width <= MAX_WIDTH
// //          0 < height && height <= MAX_HEIGHT
// //MODIFIES: *mat
// //EFFECTS: Initializes *mat as a matrix struct with the given width and height
// void matrix_init(struct matrix *mat, int width_init, int height_init){
//     //error handling here?

//     //initialization
//     mat->height = height_init;
//     mat->width = width_init;
//     mat->allocp = mat->data + width_init*height_init;
// }

// //REQUIRES: mat points to a valid matrix
// //EFFECTS: returns the width of the matrix pointed to by *mat
// int matrix_width(struct matrix *mat){
//     return mat->width;
// }

// //REQUIRES: mat points to a valid matrix
// //EFFECTS: returns the height of the matrix pointed to by *mat
// int matrix_height(struct matrix *mat){
//     return mat->height;
// }

// //REQUIRES: mat points to a valid matrix
// //          0 < width && width <= MAX_WIDTH
// //          0 < height && height <= MAX_HEIGHT
// //EFFECTS: returns a pointer to the value at row, col
// double* matrix_at(struct matrix *mat, int row, int col){
//     //error handling?

//     //finds the index in the 1d array
//     int index = row*matrix_width(mat) + col;
//     return &mat->data[index];
// }

// //REQUIRES: mat points to a valid matrix
// //MODIFIES: *mat
// //EFFECTS:  fills *mat with 0s as an empty matrix
// void matrix_fill_empty(struct matrix *mat){
//     for(int i=0; i<mat->height; i++){
//         for(int j=0; j<mat->width; j++){
//             *matrix_at(mat,i,j) = 0;
//         }
//     }
// }

// //REQUIRES: width <= MAX_WIDTH
// //          height <= MAX_HEIGHT
// //EFFECTS:  returns a pointer to a matrix of the designated size filled with random integers
// struct matrix* random_matrix(int width, int height, int param){
//     //make nwe matrix
//     struct matrix new_mat;
//     struct matrix *mp = &new_mat;

//     //initialize matrix
//     matrix_init(mp,width,height);

//     //randomly fill each slot
//     struct timespec nanos;
//     clock_gettime(CLOCK_MONOTONIC, &nanos);
//     srand(nanos.tv_nsec);//seed
//     for(int i=0; i<height; ++i){
//         for(int j=0; j<width; ++j){
//             //sets value
//             *matrix_at(mp,i,j) = rand_num(param);
//         }
//     }

//     //return
//     return mp;
// }

// //REQUIRES: 1 <= param <=4
// //EFFECTS:  returns a random double based on the given input
// //          1: rational number
// //          2: irrational number
// //          3: integer
// //          4: natural number
// double rand_num(int param){
//     double num;//to be returned

//     //sign
//     int plusmin = rand() % 2;
//     int times =1;
//     if(plusmin == 0) times *= -1;

//     switch (param)
//     {
//     case 1:
//         num = times * (double)(rand()%1025)/(double)(rand()%1025);
//         break;
//     case 2:
//         num = (M_PI * (rand()%1025));
//         break;
//     case 3:
//         num = times * (rand() % 1025);
//         break;
//     case 4:
//         num = rand() % 1025;
//     default:
//         //some sort of error handling idk
//         break;
//     }

//     return num;
// }
