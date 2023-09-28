#include "matrix.h"
#include <string>
using namespace std;

// Testing functions
int print_mat();
int rands();
int mults();
int get_run(char* argv);

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
const char *TEST2_NAMES[TEST2_NUM_TESTS] = {"Rationals","Irrationals","Integers","Naturals","Meme","Complete"};

// Test 3 Parameters
const int TEST3_NUM_TESTS = 10;
const int TEST3_SIZES[TEST3_NUM_TESTS] = {1,2,3,4,5,6,7,8,9,10};

// Wrapper for try/catch
int try_get(char* argv,int def) {
    int num=def;
    try
    {
        num =stoi(argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return num;
}

// get the start point
int get_start(char* argv) {
    return try_get(argv,0);
}

// get the end point
int get_end(char* argv) {
    return try_get(argv,NUM_TESTS);
}

// Main function
int main(int argc, char** argv){
    int val;
    int run_start=0;            // Default the start of the run to be 0
    int run_end=NUM_TESTS;      // Default the end of the run to be 0

    if(argc > 3){
        return 0;
    } else if (argc == 2){
        run_start = get_end(argv[1]);
        run_end = run_start;
        run_start--;
    } else if (argc == 3){
        run_start=get_start(argv[1]);
        run_end=get_end(argv[2]);
        run_start--;
    }

    //printf("Start:\t%d\n",run_start);
    //printf("End:\t%d\n",run_end);

    // Run through the specified test cases
    for(int i=run_start; i<run_end; i++){
        if (i < NUM_TESTS) {
            printf("Test %d:\t%s\n\n",i+1,TEST_NAMES[i]); // Output the name of the test case
        } else {
            printf("Test %d:\t%s\n\n",i+1,MEME_ARRAY_2[ i % 10 ]);
        }
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

// Test 1: Build four matrices and print them out. NO BENCHMARK RIGHT NOW
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

// Test 2: Randomize 6 matrices and print them. NO BENCHMARK RIGHT NOW
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
    int time; //to store result of benchmark to

    for(int i=0; i<TEST3_NUM_TESTS; i++) {
        // Init matrices
        // START BENCHMARK HERE
        Matrix<int> matrix_1(TEST3_SIZES[i],4);
        Matrix<int> matrix_2(TEST3_SIZES[i],7); // Multiply against an identity for easy visual check
        Matrix<int> matrix_3 = matrix_1 * matrix_2;
        time=0; // OWEN THIS IS WHERE YOU INSERT THE RESULT OF THE BENCHMARK
        // END BENCHMARK

        printf("Case %d:\t%dX%d\n",i,i,i);
        try
        {
            print_eq(matrix_1,matrix_2,matrix_3);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        printf("End Case. Ran in %d\n\n",time); // OWEN THIS IS WHERE YOU INSERT THE RESULT OF BENCHMARKING
    }

    // exit with success
    //lol hi lucas
    return 0;
}
