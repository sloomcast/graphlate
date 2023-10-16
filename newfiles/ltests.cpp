// AUTHOR:  LUCAS RIZZOLO
// EDITS:   OWEN ?

#include "matrix.h"
#include "benchmark.h"
#include <string>
using namespace std;

// Testing functions
int print_mat();
int rands();
int mults();
int appending_complete();
int appending_not_complete();
int matrix_funcs();

// For modular code
const int NUM_TESTS = 6;
const char *TEST_NAMES[NUM_TESTS] = {"Printing", "Constructors", "Multiplication", "Complete Matrix Union", "Not-Complete Matrix Union","Matrix Functions"};

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

// Test 4 Parameters
const int TEST4_NUM_TESTS = 3;
const int TEST4_SIZES[TEST4_NUM_TESTS] = {2,4,6};

// Test 5 Parameters
const int TEST5_NUM_TESTS = 3;
const int TEST5_SIZES[TEST5_NUM_TESTS] = {2,4,6};

// Test 6 Parameters
const int TEST6_NUM_TESTS = 4;
const int TEST6_SIZES[TEST6_NUM_TESTS] = {2,4,6,8};

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

    // Parse argc argument
    if(argc > 3){                       // Fail if more than 2 arguments
        return 0;
    } else if (argc == 2){              // If there is exactly 1 argument, only run that test
        run_start = get_end(argv[1]);
        run_end = run_start;
        run_start--;
    } else if (argc == 3){              // If there are exactly two arguments, only run the tests in that range
        run_start=get_start(argv[1]);
        run_end=get_end(argv[2]);
        run_start--;
    } else {
        return -1; // IDK what to do so just make it not happy right now
    }

    // Debug range
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
            case 1: val=print_mat();                //First test: can it print
                break;
            case 2: val=rands();                    //Second test: can it randomize
                break;
            case 3: val=mults();                    //Third test: can it multiply
                break;
            case 4: val=appending_complete();       //Fourth test: can it do complete matrices
                break;
            case 5: val=appending_not_complete();   //Fifth test: can it not do complete matrices    
                break;
            case 6: val=matrix_funcs();             //Sixth test: determinants and such
                break;
            default: val=-1;                        //Unimplemented
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
    int time=0;
    for(int size: TEST1_SIZES) {
        // non-specific try/catch because I'm lazy
        try
        {
            printf("Matrix %d: %dX%d\n",size,size,size);
            benchmark_start();
            Matrix<int> matrix(size,4);
            matrix.print();
            time=benchmark_mark();
            printf("Ran in %d\n",time);
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
    int time=0;

    // big try/catch because I'm lazy
    try
    {   
        // Build
        benchmark_start();
        Matrix<float> matrix_1(TEST2_SIZE,TEST2_RAND_PARAMS[0]);    //rats
        Matrix<float> matrix_2(TEST2_SIZE,TEST2_RAND_PARAMS[1]);    //irrats
        Matrix<int> matrix_3(TEST2_SIZE,TEST2_RAND_PARAMS[2]);      //ints
        Matrix<int> matrix_4(TEST2_SIZE,TEST2_RAND_PARAMS[3]);      //nats
        Matrix<int> matrix_5(TEST2_SIZE,TEST2_RAND_PARAMS[4]);      //meme
        Matrix<int> matrix_6(TEST2_SIZE,TEST2_RAND_PARAMS[5]);      //complete
        time=benchmark_mark();
        
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
    printf("Ran in %d\n",time);

    //Exit with success
    return 0;
}

// Test 3:  Build three matrices, multiply the first two and store to the third.
//          Print out the equation representation.
// RETURNS: 0 if succeeded, 1 if failed
// CHANGES: 10/15/23 LBR - Move benchmark to only mark time for the third matrix
int mults() {
    int time; //to store result of benchmark to

    for(int i=0; i<TEST3_NUM_TESTS; i++) {
        // Init matrices
        Matrix<int> matrix_1(TEST3_SIZES[i],4);
        Matrix<int> matrix_2(TEST3_SIZES[i],7); // Multiply against an identity for easy visual check
        
        // START BENCHMARK HERE: Dirty count the matrix_3 (not clean as we aren't only tracking the multiplication)
        benchmark_start();
        Matrix<int> matrix_3 = matrix_1 * matrix_2;
        time=benchmark_mark();
        // END BENCHMARK

        // small try/catch because I'm lazy
        printf("Case %d:\t%dX%d\n",i+1,i+1,i+1);
        try
        {
            print_eq(matrix_1,matrix_2,matrix_3,'X');
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        printf("End Case. Ran in %d\n\n",time);
    }

    // exit with success
    //lol hi lucas
    // Hi owen, how are you doing
    return 0;
}

// Test 4: Build two matrices of the same size and append them
// RETURNS: 0 if it succeeded and -1 if it didn't
int appending_complete() {
    for(int i=0; i<TEST4_NUM_TESTS; i++) {
        // init matrices of the right size
        printf("Case %d:\t%dX%d\n",i+1,i+1,i+1);
        Matrix<int> matrix_1(TEST4_SIZES[i],6);
        Matrix<int> matrix_2(TEST4_SIZES[i],6);
    }
    return 0;
}

// Test 5: Build two matrices of the same size and append them
// RETURNS: 0 if it succeeded and -1 if it didn't
int appending_not_complete() {
    // big try/catch because I'm lazy
    for(int i=0; i<TEST5_NUM_TESTS;i++) {
        // Init Matrices of the right sizes
        printf("Case %d:\t%dX%d\n",i+1,i+1,i+1);
        Matrix<int> matrix_1(TEST5_SIZES[i],4);
        Matrix<int> matrix_2(TEST5_SIZES[i],4);
    }
    return 0;
}

// Test 6: Build two matrices of the same size and append them
// RETURNS: 0 if it succeeded and -1 if it didn't
int matrix_funcs() {
    int time,res;
    // big try/catch because I'm lazy
    for(int i=0; i<TEST6_NUM_TESTS;i++) {
        time = 0 ;
        // Init Matrices of the right sizes
        printf("Case %d:\t%dX%d\n",i+1,i+1,i+1);
        Matrix<int> matrix_1(TEST6_SIZES[i],6);
        Matrix<int> matrix_2(TEST6_SIZES[i],4);
        Matrix<int> matrix_3(TEST6_SIZES[i]*2,8);
        printf("Matrix 1:\n");
        matrix_1.print();
        printf("Matrix 2:\n");
        matrix_2.print();

        // Simple determinant test
        benchmark_start();
        res=matrix_1.determinant();
        time=benchmark_mark();
        printf("Matrix 1 Determinant:\t%d\nFinished in:\t%d\n",matrix_1.determinant(),time);
        
        // Not simple determinant test
        benchmark_start();
        res=matrix_2.determinant();
        time=benchmark_mark();
        printf("Matrix 2 Determinant:\t%d\nFinished in:\t%d\n",matrix_2.determinant(),time);
        
        printf("Simple addendum:\n");
        benchmark_start();
        matrix_3 = addend_graphs(matrix_1,matrix_1);
        time=benchmark_mark();
        print_eq(matrix_1,matrix_1,matrix_3,'U');
        printf("Finished in:\t%d\n",time);

        printf("Fuck it up my guy:\n");
        benchmark_start();
        matrix_3 = addend_graphs(matrix_1,matrix_2);
        time=benchmark_mark();
        print_eq(matrix_1,matrix_2,matrix_3,'U');
        printf("Finished in:\t%d\n",time);
    }
    return 0;
}
