#include "matrix.h"

using namespace std;

// Testing functions
int print_mat();
int rands();
int mults();

// For modular code
const int NUM_TESTS = 5;
const char *TEST_NAMES[NUM_TESTS] = {"Printing", "Constructors", "Multiplication", "Menu", "Other"};

// Test 1 Parameters
const int TEST1_NUM_TESTS = 5;
const int TEST1_SIZES[TEST1_NUM_TESTS] = {2,4,6,8,10};

// Test 2 Parameters
const int TEST2_NUM_TESTS = 6;
const int TEST2_SIZE = 3;
const int TEST2_RAND_PARAMS[TEST2_NUM_TESTS] = {1,2,3,4,5,6}; // they could be diff so I'm doing it this way
const char *TEST2_NAMES[TEST2_NUM_TESTS] = {"Rationals","Irrationals (hehe)","Integers","Naturals","Meme","Complete"};
// Test 3 Parameters


// Main function
int main(){
    int val; // init int to store return values

    // Run through all test cases
    for(int i=0; i<NUM_TESTS; i++){
        printf("Test %d:\t%s\n\n",i+1,TEST_NAMES[i]); // Output the name of the test case
        switch(i+1){
            case 1: val=print_mat();    //First test: can it print
                break;
            case 2: val=rands();        //Second test: can it randomize
                break;
            case 3: val=mults();        //Third test: can it multiply
                break;
            case 4: val=-1;             //Unimplemented
                break;
            case 5: val=-1;             //Unimplemented
                break;
            default: val=-1;            //Unimplemented
                break;
        }
        if (val>0) {
            printf("\nFailed with exit code %d\n",val);
        } else if (val==0) {
            printf("\nPassed with exit code %d\n",val);
        }
        else if (val == -1) {
            printf("\nTest case not yet implemented.\n");
        }
    }

    // Exit
    return 0;
}

// Test 1: Build four matrices and print them out.
// RETURNS: 0 if succeeded, 1 if failed
int print_mat(){
    for(int size: TEST1_SIZES) {
        try
        {
            printf("Matrix %d: %dX%d\n",size,size,size);
            Matrix<int> matrix(size,4);
            matrix.print();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    return 0;
}

// Test 2: Randomize 6 matrices and print them.
// RETURNS: 0 if succeeded, 1 if failed
int rands() {
    try
    {   
        // Build
        Matrix<float> matrix_1(TEST2_SIZE,TEST2_RAND_PARAMS[0]);    //rats
        Matrix<float> matrix_2(TEST2_SIZE,TEST2_RAND_PARAMS[1]);    //irrats
        Matrix<int> matrix_3(TEST2_SIZE,TEST2_RAND_PARAMS[2]);      //ints
        Matrix<int> matrix_4(TEST2_SIZE,TEST2_RAND_PARAMS[3]);      //nats
        Matrix<int> matrix_5(TEST2_SIZE,TEST2_RAND_PARAMS[4]);      //meme
        Matrix<int> matrix_6(TEST2_SIZE,TEST2_RAND_PARAMS[5]);      //complete

        
        for (int i=1; i<TEST2_NUM_TESTS+1; i++) {
            // Mem leak like a mofo without deconstructor
            //matrix = new Matrix<float>(TEST2_SIZE,TEST2_RAND_PARAMS[i]);
            printf("Matrix %d: %s matrix\n",i+1,TEST2_NAMES[i-1]);
            switch(i) {
                case 1: matrix_1.print();
                    break;
                case 2: matrix_2.print();
                    break;
                case 3: matrix_3.print();
                    break;
                case 4: matrix_4.print();
                    break;
                case 5: matrix_5.print();
                    break;
                case 6: matrix_6.print();
                    break;
                default: printf("IDK How you got here bruh\n");
            }
            // when we have deconstructors
            // matrix.print();
            // delete matrix;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    //Exit with success
    return 0;
}

// Test 3:  Build three matrices, multiply the first two and store to the third.
//          Print out the equation representation.
// RETURNS: 0 if succeeded, 1 if failed
int mults() {
    //Init three matrices
    Matrix<int> matrix_1(3,1);
    Matrix<int> matrix_2(3,1);
    Matrix<int> matrix_3(3,1);

    // Multiply (unimplemented)

    //Try and print, catch failures
    try
    {
        print_eq(matrix_1,matrix_2,matrix_3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    // exit with success
    return 0;
}
