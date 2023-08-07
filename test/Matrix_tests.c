//matrix tests to ensure compilation and smooth functioning

#include "src/matrix/matrix.h"
#include <stdio.h>
#include <assert.h>

int main(){
    //tests making and empty filling
    printf("Hello!\n");
    struct matrix mat1;
    struct matrix *mp = &mat1;
    matrix_init(mp,10,10);
    matrix_fill_empty(mp);
    assert(mp->data[0] == mp->data[1]);
    assert(mp->data[0] == 0);

    //tests random matrix (run a couple o times to prove it)
    struct matrix *mp1 = random_matrix(5,5,2);
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            printf("%f ",*matrix_at(mp1,i,j));
        }
        printf("\n");
    }
    printf("\n");
    struct matrix *mp2 = random_matrix(5,5,4);
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            printf("%f ",*matrix_at(mp2,i,j));
        }
        printf("\n");
    }

    printf("Pass!\n");

    return 0;
}
