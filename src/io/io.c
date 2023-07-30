#include "io.h"


void open_file(FILE *f){

};

void close_file(FILE *f){

};

void print_to_file(FILE *f){

}

void print_to_system(){
    printf("/nTEST/n");
}

void print(FILE *f){
    if(f==NULL){
        //log an error
        printf("\nIT IS NULL\n");
    } else if (f==stdin){
        print_to_system();
    } else {
        print_to_file(f);
    }
}