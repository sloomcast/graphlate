//matrix tests to ensure compilation and smooth functioning

#include "src/matrix/matrix.h"
#include <stdio.h>
#include <assert.h>

int main(){
    printf("Hello!\n");
    struct matrix mat1;
    struct matrix *mp = &mat1;
    matrix_init(mp,10,10);
    matrix_fill_empty(mp);
    assert(mp->data[0] == mp->data[1]);
    assert(mp->data[0] == 0);
    printf("Pass!\n");


    return 0;
}
