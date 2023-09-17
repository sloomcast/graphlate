#include "matrix.h"

using namespace std;

// Testing functions
bool print_mat();
bool rands();
bool mults();

// Global matrices because I'm lazy

int main(){

    cout << "Test 1: Printing Functions" << endl;
    if(print_mat()){
        cout << "Printed matrices" << endl;
    } else{
        cout << "Failed to print matrices" << endl;
    }

    cout << "Test 2: Constructors" << endl;
    if(rands()) {
        cout << "Constructor tests passed." << endl;
    } else {
        cout << "Constructor tests failed." << endl;
    }

    cout << "Test 3: Multiplication" << endl;
    if(mults()) {
        cout << "Mults passed." << endl;
    } else {
        cout << "Mults failed." << endl;
    }
}

bool print_mat(){
    int arr[4] = {2,4,6,8};
    for(int size: arr) {
        try
        {
            printf("Matrix %d: %dX%d\n",size,size,size);
            Matrix<int> matrix(size,4);
            matrix.print();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
    }
    return true;
}

bool rands() {
    try
    {
        // Build
        Matrix<float> matrix_1(3,1);    // Matrix with random rationals
        Matrix<float> matrix_2(3,2);    // Matrix with random irrationals (hehe)
        Matrix<int> matrix_3(3,3);      // Matrix with random integers
        Matrix<int> matrix_4(3,4);      // Matrix with random natural numbers
        Matrix<int> matrix_5(3,5);      // Meme matrix
        Matrix<int> matrix_6(3,6);      // Complete graph adjaceny matrix

        cout << "Matrix 1: Rationals" << endl;
        matrix_1.print();
        cout << "Matrix 2: Irrationals" << endl;
        matrix_2.print();
        cout << "Matrix 3: Integers" << endl;
        matrix_3.print();
        cout << "Matrix 4: Naturals" << endl;
        matrix_4.print();
        cout << "Matrix 5: Meme" << endl;
        matrix_5.print();
        cout << "Matrix 6: Complete Graph Adjacency Matrices" << endl;
        matrix_6.print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

bool mults() {
    Matrix<int> matrix_1(3,1);
    Matrix<int> matrix_2(3,1);
    Matrix<int> matrix_3(3,1);

    try
    {
        print_eq(matrix_1,matrix_2,matrix_3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    
    return true;
}
