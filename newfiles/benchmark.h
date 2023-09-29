#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "matrix.h"
#include <chrono>

static std::chrono::high_resolution_clock::time_point start;
static std::chrono::high_resolution_clock::time_point end;

//benchmark that mf!
//starts da clock
void benchmark_start(){ 
    start = std::chrono::high_resolution_clock::now();
}

//ends da clock
void benchmark_end(){
    end = std::chrono::high_resolution_clock::now();
}

int benchmark_mark() {
    benchmark_end();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

//print our benchmark times
void benchmark_print(){
    std::cout << "Time between start and end: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
}

#endif
