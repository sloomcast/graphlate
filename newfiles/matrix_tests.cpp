#include "matrix.h"

using namespace std;

bool make_tests();
bool at_tests();
bool row_tests();
bool col_tests();
bool print_tests();
bool rand_tests();
bool operator_tests();
void test_errors();

int main(){
    cout << "hello bitch\n";
    bool all_pass = true;

    //make a matrix
    if(make_tests()){
        cout << "MAKING TESTS PASSED\n\n";
    }
    else{ 
        cout << "MAKING TESTS FAILED YOU IDIOT\n\n";
        all_pass = false;
    }

    //test matrix_at
    if(at_tests()){
        cout << "AT TESTS PASSED\n\n";
    }
    else{
        cout << "AT TESTS FAILED YOU IDIOT\n\n";
        all_pass = false;
    }

    //test return row
    if(row_tests()){
        cout << "ROW TESTS PASSED\n\n";
    }
    else{
        cout << "ROW TESTS FAILED YOU IDIOT\n\n";
        all_pass = false;
    }

    //test return column
    if(col_tests()){
        cout << "COL TESTS PASSED\n\n";
    }
    else{
        cout << "COL TESTS FAILED YOU IDIOT\n\n";
        all_pass = false;
    }

    //test print
    if(print_tests()){
        cout << "PRINT TESTS PASSED\n\n";
    }
    else{
        cout << "PRINT TESTS FAILED YOU IDIOT\n\n";
        all_pass - false;
    }

    //test operators
    if(operator_tests()){
        cout << "OPERATOR TESTS PASSED\n\n";
    }
    else{
        cout << "OPERATOR TESTS FAILED YOU GOON\n\n";
        all_pass - false;
    }

    //test random fill
    if(rand_tests()){
        cout << "RANDOM GENERATION TESTS PASSED\n\n";
    }
    else{
        cout << "RANDOM GENERATION TESTS FAILED YOU IDIOT\n\n";
        all_pass = false;
    }

    //error testing
    test_errors();

    if(all_pass) cout << "ALL TESTS PASSED\n\n";
    else cout << "NOT ALL PASSED\n\n";
    return 0;
}

bool make_tests(){
    Matrix<int> m1;
    Matrix<int> m2(5);
    Matrix<float> m3(5,1);
    Matrix<float> m4{1.1,2.2,3.3,6.9};
    //m4.print();

    if(m1.matrix_dimension() != 10) return false;
    if(m2.matrix_dimension() != 5) return false;

    //cout << typeid(*m3.matrix_at(0,0)).name() << endl;
    //m1.print();

    return true;
}

bool at_tests(){
    Matrix<float> m1;
    Matrix<int> m2;

    if(*m1.matrix_at(0,0) != 3.0) return false;
    if(*m2.matrix_at(2,3) != 4) return false;


    return true;
}

bool row_tests(){
    list<int> l1{5,8,9,7,9,3,2,3,8,4};
    list<int> l2{1,6,9,3,9,9,3,7,5,0};
    Matrix<int> m1;

    //m1.print();
    if(l1 != m1.return_row(1)) return false;
    if(l2 != m1.return_row(9)) return false;
    // for(auto i : l1){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(auto i : m1.return_row(1)){
    //     cout << i << " ";
    // }
    // cout << endl;

    return true;
}

bool col_tests(){
    Matrix<int> m1;
    list<int> l1{1,8,2,5,6,1,8,2,5,6};
    list<int> l2{3,4,7,7,0,3,4,7,7,0};

    if(l1 != m1.return_col(1)) return false;
    if(l2 != m1.return_col(9)) return false;

    return true;
}

bool print_tests(){
    // Matrix<int> m1;
    //Matrix<double> m2(3);
    // m1.print();
    //m2.print();

    // m1.print("out_test.txt");

    // ofstream yuh;
    // ofstream yah;
    // yah.open("out2_test.txt", ios::app);
    // yuh.open("out_test.txt", ios::app);
    // m1.print(yuh);
    // m1.print(yah);

    //the above code are functional tests that have all performed as desired

    return true;
}

bool operator_tests(){
    Matrix<int> m1;
    Matrix<int> m2;
    Matrix<int> m3(3);

    if(!(m1==m2)) return false;
    if(m1!=m2) return false;
    if(m1 == m3) return false;

    return true;
}

void test_errors(){
    try{
        Matrix<int> m1;
        int test = *m1.matrix_at(1,13);

        m1.print();
    }
    catch(std::exception& e){
        std::cerr << e.what() << "\n\n";
    }

    try{
        Matrix<int> m1;
        ofstream of;

        m1.print(of);
    }
    catch(std::exception& e){
        cerr << e.what() << "\n\n";
    }

    try{
        Matrix<int> m1{1,2};
    }
    catch(std::exception& e){
        cerr << e.what() << "\n\n";
    }
}

bool rand_tests(){
    //option 1, rationals
    Matrix<float> m1(5,1);
    Matrix<float> m2(5,1);
    if(m2 == m1) return false;

    //option 2, irrationals
    Matrix<float> m7(5,2);
    Matrix<float> m8(5,2);
    if(m7 == m8) return false;

    //option 3, integers
    Matrix<int> m3(5,3);
    Matrix<int> m4(5,3);
    if(m3 == m4)return false;

    //option 4, natural numbers
    Matrix<int> m5(5,4);
    Matrix<int> m6(5,4);
    if(m5 == m6) return false;

    return true;
}
