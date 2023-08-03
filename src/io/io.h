#ifndef __IO_H__
#define __IO_H__

#include "../main.h"
#include "../objs.h"
#include "string.h"
// constants
#define BUFFERSIZE 2000 // Read lines of 1000 with spaces in between

// type definitions

// globals
extern bool file_opened; // true if file is open
extern bool file_closed; // true if file is closed
extern bool print_mode; // true for print to file
extern FILE *fptr;   // pointer for file
extern char buffer;

// function prototype for functions 
// file handling
int open_file(char* fname);
int close_file(char* fname);
int read_file(char* fname);
int print_file(char* fname);
int print_to_file(char* fname);
void print_to_system();


// some error handling

#endif
