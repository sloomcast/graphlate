// AUTHOR:  LUCAS RIZZOLO
#include "maths.h"
#include "matrix.h"
#include <string>
#include <iostream>

//ftests as in "fuck these tests"
int find_seg_fault(); // yep

int main(int argc, char* argv[]) {
    /*if (argc == 2) {
        if(std::strlen(argv[1]) > 9) {
            printf("\nToo big :\(\n");
            return 0;
        }
        int i = std::stoi(argv[1]);
        printf("\nNumber:\t%d\n2^n:\t%d\n",i,twon(i));
    } */
    return find_seg_fault();
}

int find_seg_fault() {
    try
    {
        for(int i=2;i<MAX_DIMENSION;i++) {
            printf("====== Test %d ======\n",i);
            Matrix<int> matrix(i,6);
            matrix.print();
            std::cout << std::endl;

            if(i<MAX_DIMENSION / 2) {
                Matrix<int> result = matrix * matrix;
                result.print();
                std::cout << std:: endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    return 0;
}