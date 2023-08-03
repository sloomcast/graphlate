#include "io.h"


int open_file(char* fname){
    fptr = fopen(fname,"w");
    if (fptr==NULL){
        return 1;
    }
    return 0;
}

int close_file(char* fname){
    return 0;
}

int print_file(char* fname){
    if (fptr!=NULL){
        return -1;
    }
    return 0;
}

void print_to_system(){
    printf("/nTEST/n");
}
// I know it's kinda dumb to have to but I'm just writing quick code rn
int print_to_file(char* fname){
    if(fname==NULL){
        //log an error
        printf("\nIT IS NULL\n");
        return 1;
    }

    //

    // Close out file
    if(close_file>0){
        return 2;
    }

    // Print out what we did
    print_file(fname);
    return 0;
}