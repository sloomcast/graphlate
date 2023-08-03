#include "io.h"
#include "src/main.h"

// Open the file for writing
int open_file(char* fname){
    fptr = fopen(fname,"w");
    if (fptr==NULL){
        return 1;
    }
    return 0;
}

// Close the file (we just assume fptr because lazy)
int close_file(char* fname){
    int c = fclose(fptr);
    return c;
}

// Print to thing in fptr. Need to actually print to a specific file by name ( or check against fptr)
int print_file(char* fname){
    char* temp = "happy happy happy";
    
    if (fptr==NULL){
        return -1;
    }
    return fputs(temp,fptr); // Handle this better you fuck (Lucas is the fuck, not Owen)
}

// command line print. Just nah
void print_to_system(){
    printf("/nTEST/n");
}

// Top level "print this matrix to this file" function
int print_to_file(char* fname){
    if(fname==NULL){
        //log an error
        printf("\nIT IS NULL\n");
        return 1;
    }

    // Do the actual printing but here we just do smiley face :0
    printf("\n:)\n");

    // Close out file
    if(close_file(fname)>0){
        return 2;
    }

    // Print out what we did
    print_file(fname);
    return 0;
}