#include "src/maths.h"
#include <string>
#include <iostream>

//ftests as in "fuck these tests"

int main(int argc, char* argv[]) {
    if (argc == 2) {
        if(std::strlen(argv[1]) > 9) {
            printf("\nToo big :\(\n");
            return 0;
        }
        int i = std::stoi(argv[1]);
        printf("\nNumber:\t%d\n2^n:\t%d\n",i,twon(i));
    }
    return 0;
}