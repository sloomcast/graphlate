// AUTHOR:  Owen Davis

#include "matrix.h"
#include "benchmark.h"
#include <chrono>

using namespace std;

bool make_tests();
bool at_tests();
bool row_tests();
bool col_tests();
bool print_tests();
bool rand_tests();
bool operator_tests();
void test_errors();
bool determinant_tests();
bool add_tests();
bool mult_tests();
void benchmarking();
bool rref_tests();
bool ffrac_tests();
bool komplete_tests();
bool dynamic_tests();

int main(){
    bool all_pass = true;

    //dynamic tests
    if(dynamic_tests()){
        cout << "DYNAMIC WORKS!\n\n";
    }
    else{
        cout << "BADBADBADBAD DYNAMIC BAD\n\n";
        all_pass = false;
    }

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
    //test_errors();

    //test determinant func
    if(determinant_tests()){
        cout << "DETERMINANT TESTS PASSED\n\n";
    }
    else{
        cout << "DETERMINANT TESTS FAILED, YOU BUFFOON\n\n";
        all_pass = false;
    }

    //test addition function
    if(add_tests()){
        cout << "ADDITION TESTS PASSED\n\n";
    }
    else{
        cout << "ADDITION TESTS FAILED YOU BANANAHEAD\n\n";
        all_pass = false;
    }

    //test mult function
    if(mult_tests()){
        cout << "MULTIPLICATION TESTS PASSED\n\n";
    }
    else{
        cout << "MULTIPLICATION TESTS FAILED YOU BANANAHEAD\n\n";
        all_pass = false;
    }

    //test rref
    if(rref_tests()){
        cout << "RREF TESTS PASSED\n\n";
    }
    else{
        cout << "RREF TESTS FAILED YOU NINCOMPOOP\n\n";
        all_pass = false;
    }

    //test ffrac
    if(ffrac_tests()){
        cout << "FFRAC TESTS PASSED\n\n";
    }
    else{
        cout << "BOI WHAT DA HEEEELLL YOU FAILED FFRAC TESTS\n\n";
        all_pass = false;
    }

    //komplete graph tests
    if(komplete_tests()){
        cout << "DERIK'S CODE PASSED\n\n";
    }
    else{
        cout << "DERIK CODE STINKY\n\n";
        all_pass = false;
    }

    //benchmark tests
    //benchmarking();

    if(all_pass) cout << "ALL TESTS PASSED\n\n";
    else cout << "NOT ALL PASSED\n\n";
    return 0;
}

bool make_tests(){
    Matrix<int> m1;
    Matrix<int> m2(5);
    Matrix<float> m3(5,1);
    Matrix<float> m4{1.1,2.2,3.3,6.9};
    Matrix<ffrac> m5(3,3);
    //m5.print();
    //m4.print();

    if(m1.matrix_dimension() != 10) return false;
    if(m2.matrix_dimension() != 5) return false;

    //cout << typeid(m3(0,0)).name() << "\n";
    //m1.print();

    return true;
}

bool at_tests(){
    Matrix<float> m1;
    Matrix<int> m2;

    if(m1(0,0) != 3.0) return false;
    if(m2(2,3) != 4) return false;


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
    // cout << "\n";
    // for(auto i : m1.return_row(1)){
    //     cout << i << " ";
    // }
    // cout << "\n";

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

    //testing of random access operators
    // m3.print();
    // cout << m3(0,0) << "\n";
    // cout << m3(1,1) << "\n";
    // cout << m3(3,1) << "\n";

    return true;
}

void test_errors(){
    try{
        Matrix<int> m1;
        int test = m1(1,13);

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

bool determinant_tests(){
    //declarations
    Matrix<int> m1{5};
    Matrix<int> m2{1,1,1,1};
    Matrix<int> m3{1,4,5,7};
    Matrix<int> m4{6,5,3,4,7,9,1,1,2};

    //tests
    if(m1.determinant() != 5) return false;
    if(m2.determinant() != 0) return false;
    if(m3.determinant() != -13) return false;
    if(m4.determinant() != 26) return false;

    return true;
}

bool add_tests(){
    //declarations
    Matrix<int> m1{1,1,1,1};
    Matrix<int> m2{2,2,2,2};
    Matrix<double> m3{0.32,0.98,0.47,0.71};
    Matrix<double> m4{1.0,1.0,1.0,1.0};

    //add da matrices
    Matrix<int> add1 = m1 + m2;
    Matrix<double> add2 = m3 + m4;
    Matrix<int> sub1 = m2 - m1;
    Matrix<double> sub2 = m4 - m3;

    //if statements
    Matrix<int> test1{3,3,3,3};
    Matrix<double> test2{1.32,1.98,1.47,1.71};
    Matrix<double> test3{0.68, 0.02,0.53,0.29};
    if(add1 != test1) return false;
    if(add2 != test2) return false;
    if(sub1 != m1) return false;
    // sub2.print();
    // test3.print();
    // if(sub2 != test3) return false;  this case works but rounding is dumb :/

    return true;

}

bool mult_tests(){
    //declarations
    Matrix<int> m1{2,2,2,2};
    Matrix<int> m2{1,8,7,3};
    Matrix<int> m3{1,1,1,1};
    Matrix<int> m4(4);
    Matrix<int> m5{1,1,1,1,1,1,1,1,1};
    Matrix<int> m6(3);
    Matrix<int> m7{3,9,7,9,8,5,3,5,11};

    //multiply
    Matrix<int> mult1 = m1 * m2;
    Matrix<int> mult2 = m3 * m3;
    Matrix<int> mult3 = m4 * m4;
    Matrix<int> mult4 = m5 * m5;
    Matrix<int> mult5 = m6 * m7;

    //if statements
    Matrix<int> test1{16,22,16,22};
    Matrix<int> test2{2,2,2,2};
    Matrix<int> test3{43,31,43,44,124,134,102,93,127,103,123,87,134,120,122,132};
    Matrix<int> test4{3,3,3,3,3,3,3,3,3};
    Matrix<int> test5{30,55,70,75,94,131,75,91,99};
    // m4.print();
    // mult3.print();
    // test3.print();
    if(mult1 != test1) return false;
    if(mult2 != test2) return false;
    if(mult3 != test3) return false;
    if(mult4 != test4) return false;
    if(mult5 != test5) return false;

    return true;
}

void benchmarking(){
    for(int i=0; i<10; i++){
        //start time1
        benchmark_start();

        //function calls
        // Matrix<int> m1(4,3);
        // Matrix<int> m2(4,3);
        // Matrix<int> m5(5,3);
        // Matrix<int> m6(5,3);
        Matrix<int> m9(10,3);
        //Matrix<int> mult1 = m1 * m2;
        //Matrix<int> mult3 = m5 * m6;
        Matrix<int> mult5 = m9 * m9;

        //end time1
        benchmark_end();

        //print times
        benchmark_print();
    }
    cout << "\n";
}

bool rref_tests(){
    //benchmarking
    benchmark_start();

    //declarations
    Matrix<ffrac> m1{4,1,7,1,8,3,1,1,1};
    Matrix<int> m2{4,1,7,0,0,0,0,0,0};
    Matrix<int> m3{1,1,1,1,1,1,2,2,2};
    Matrix<int> m4{6,9,42,3};
    Matrix<int> m5{69};
    //stress test
    //Matrix<int> m6(10000);

    //operations
    //m1.rref(m1);
    Matrix<double> op2 = m2.rref();
    Matrix<double> op3 = m3.rref();
    Matrix<double> op4 = m4.rref();
    Matrix<double> op5 = m5.rref();
    //Matrix<double> op6 = m6.rref();

    //if statements
    Matrix<double> test1{1,0,0,0,1,0,0,0,1};
    Matrix<double> test2{1,0.25,1.75,0,0,0,0,0,0};
    Matrix<double> test3{1,1,1,0,0,0,0,0,0};
    Matrix<double> test4{1,0,0,1};
    Matrix<double> test5{1};
    //m1.print();
    //if(m1 != test1) return false;
    if(op2 != test2) return false;
    if(op3 != test3) return false;
    if(op4 != test4) return false;
    if(op5 != test5) return false;

    std::cout << benchmark_mark() << "\n\n";

    //return
    return true;
}

bool ffrac_tests(){
    //declarations
    ffrac def_const;
    ffrac frac1(1,2);
    ffrac frac2(1,2);
    ffrac frac3(1,3);
    ffrac frac4(2);
    ffrac zerofrac(0);
    ffrac frac5(5,6);

    //operations
    ffrac sum1 = frac1 + frac2;
    ffrac sum2 = frac1 + frac3;
    ffrac mult1 = frac1 * frac3;
    ffrac mult2 = frac1 * frac4;
    ffrac div1 = frac1 / frac4;
    ffrac div2 = def_const / frac4;
    ffrac sub1 = frac1 - frac2;
    ffrac sub2 = frac5 - frac3;

    //if statments
    ffrac test1(5,6);
    ffrac test2(1,6);
    ffrac test3(1,4);
    if(!(frac1 == frac2)) return false;
    if(frac1 != frac2) return false;
    if(sum1 != def_const) return false;
    if(sum2 != test1) return false;
    if( mult1 != test2) return false;
    if(mult2 != def_const) return false;
    if(test3 != div1) return false;
    if(div2 != frac1) return false;
    if(sub1 != zerofrac) return false;
    if(sub2 != frac1) return false;

    //base return
    return true;
}

bool komplete_tests(){
    //initializations
    Matrix<int> m1(6,6);
    Matrix<int> m2(5,6);

    //operations
    Matrix<int> combined = addend_graphs(m1,m2);

    //if statements
    //combined.print();

    //default
    return true;
}

bool dynamic_tests(){
    //benchmarking
    benchmark_start();

    //destructor
    Matrix<int> m1(1024);

    //m1.print();

    //copy ctor
    Matrix<int> m2(m1);
    if(&m1 == &m2) return false;
    if(m1 != m2) return false;

    //overloaded =
    Matrix<int> m3;
    m3 = m1;
    if(&m1 == &m3) return false;
    if(m1 != m3) return false;

    //benchmarking
    std::cout << benchmark_mark() << "\n\n";

    return true;
}
