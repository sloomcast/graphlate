#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>
#include <stdbool.h>
// constants

// type definitions

// globals
extern bool file_opened; // true if file is open
extern bool file_closed; // true if file is closed
extern bool print_mode; // true for print to file
extern FILE *buffptr;   // pointer for the buffer
extern char buffer;

// function prototype for functions 
// file handling
void open_file(FILE *f);
void close_file(FILE *f);
void read(FILE *f);
void print();
void print_to_file(FILE *f);
void print_to_system();


// some error handling

#endif
