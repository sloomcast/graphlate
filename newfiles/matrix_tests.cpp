#include "matrix.h"

using namespace std;

bool make_tests();
bool at_tests();
bool row_tests();
bool col_tests();
bool print_tests();
bool rand_tests();

int main(){
    cout << "hello bitch\n";

    //make a matrix
    if(make_tests()){
        cout << "MAKING TESTS PASSED\n";
    }
    else cout << "MAKING TESTS FAILED YOU IDIOT\n";

    //test matrix_at
    if(at_tests()){
        cout << "AT TESTS PASSED\n";
    }
    else cout << "AT TESTS FAILED YOU IDIOT\n";

    //test return row
    if(row_tests()){
        cout << "ROW TESTS PASSED\n";
    }
    else cout << "ROW TESTS FAILED YOU IDIOT\n";

    //test return column
    if(col_tests()){
        cout << "COL TESTS PASSED";
    }
    else cout << "COL TESTS FAILED YOU IDIOT\n";

    //test print
    if(print_tests()){
        cout << "PRINT TESTS PASSED\n";
    }
    else cout << "PRINT TESTS FAILED YOU IDIOT\n";

    //test random fill
    if(rand_tests()){
        cout << "RANDOM GENERATION TESTS PASSED\n";
    }
    else cout << "RANDOM GENERATION TESTS FAILED YOU IDIOT\n";
    return 0;
}

bool make_tests(){
    Matrix<int> m1;
    Matrix<int> m2(5);
    Matrix<float> m3;
    Matrix<string> lmfao;

    if(m1.matrix_dimension() != 10) return false;
    if(m2.matrix_dimension() != 5) return false;

    return true;
}

bool at_tests(){
    return true;
}

bool row_tests(){
    return true;
}

bool col_tests(){
    return true;
}

bool print_tests(){
    return true;
}

bool rand_tests(){
    return true;
}
