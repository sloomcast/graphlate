#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <typeinfo>
#include <cmath>
#include "randos.h"
#include "meme.h"
#include "maths.h"
#include "ffrac.h"

const int MAX_SIZE = 1024;
bool debug_flag = false;

template <typename T>
class Matrix{
    public:

    // Constructor to create a random matrix of specified flavor
    // Flavors: 1 - Random rationals
    //          2 - Random irrationals
    //          3 - Random integers
    //          4 - Random natural numbers
    //          5 - Meme
    //          6 - Complete graphs
    //          7 - Identity matrix
    Matrix(int size = 10, int flavor = 5) { //defaults to meme flavor
        //error handling
        if((flavor < 1 || flavor > 7) && flavor != 8)throw std::invalid_argument("ERROR: Please enter a matrix fill designation between 1-7");
        if(size > MAX_SIZE) throw std::invalid_argument("ERROR: Requested matrix size is too large, maximum size is 1024");

        dimensions = size;
        data = new T[size*size];
        this->fill_by_option(flavor);
    }

    Matrix(std::initializer_list<T> il){
        //add assert to make sure it's a square matrix
        double s1 = sqrt(il.size());
        int s2 = sqrt(il.size());
        if(double(s2) != s1) throw std::invalid_argument("ERROR: Initializer list must be a 1D square matrix");

        dimensions = sqrt(il.size());  //set size
        if(dimensions > MAX_SIZE) throw std::invalid_argument("ERROR: Requested matrix size is too large, maximum size is 1024");
        data = new T[dimensions*dimensions];

        for(int r=0; r<dimensions; ++r){
            for(int c=0; c<dimensions; ++c){
                *this->matrix_at(r,c) = *(il.begin() + r*dimensions + c);
            }
        }
    }

    //copy constructor
    Matrix(const Matrix& other){
        dimensions = other.matrix_dimension();
        if(dimensions > MAX_SIZE) throw std::invalid_argument("ERROR: Requested matrix size is too large, maximum size is 1024");
        data = new T[dimensions*dimensions];

        //copy values
        this->copy_mat(other);
    }

    //overloaded deep copy operator
    Matrix& operator=(const Matrix &other){
        if(this == &other){
            return *this;
        }

        //clears matrix
        this->clear_matrix();

        //copies new vals
        dimensions = other.matrix_dimension();
        data = new T[dimensions*dimensions];
        this->copy_mat(other);

        return *this;
    }

    //EFFECTS:  returns the width/height of the matrix
    int matrix_dimension() const{
        return dimensions;
    }

    //REQUIRES: 0 <= row <= dimensions
    //EFFECTS:  returns by reference the row at row
    std::list<T> return_row(int row) {
        //error handling
        if(row < 0 || row >= dimensions) throw std::invalid_argument("ERROR: Invalid row value");

        //make list
        std::list<T> to_return;

        //add to list
        for(int i=0; i<dimensions; ++i){
            to_return.push_back(*matrix_at(row, i));
        }

        return to_return;
    }

    //REQUIRES: 0 <= col <= dimensions
    //EFFECTS:  returns by reference the column at col
    std::list<T> return_col(int col) {
        //error handling
        if(col < 0 || col >= dimensions) throw std::invalid_argument("ERROR: Invalid column value");

        //make list
        std::list<T> to_return;

        //add to list
        for(int i=0; i<dimensions; ++i){
            to_return.push_back(*matrix_at(i,col));
        }

        return to_return;
    }

    //REQUIRES: os is a valid output stream capable of being written to
    //MODIFIES: the file specified in os
    //EFFECTS:  prints the matrix object to os
    //NOTE:     if the ofstream passed to the print function is not in append mode
    //          the function WILL OVERWRITE any existing contents in the corresponding file
    void print(std::ofstream &os) {
        //error handling
        if(!os.is_open()) throw std::invalid_argument("ERROR: Please input a valid ofstream to print to");

        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                os << *matrix_at(i,j) << " ";
            }
            os << "\n";
        }
        os << "\n" << "\n";
    }

    //REQUIRES: f_out is the name of an existing file or a file to be created
    //MODIFIES: the file specified in f_out
    //EFFECTS:  opens the file f_out or creates a new file and prints the matrix to it
    void print(std::string f_out) {
        //error handling
        if(f_out == "") throw std::invalid_argument("ERROR: Please input a valid filename");

        //creates stream
        std::ofstream of;
        of.open(f_out, std::ios::app);
        if(!of.is_open()) throw std::invalid_argument("ERROR: Encountered an issue opening file" + f_out);

        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                of << *matrix_at(i,j) << " ";
            }
            of << "\n";
        }
        of << "\n" << "\n";

        of.close();
    }

    //EFFECTS:  prints the matrix to stdout
    void print() {
        for(int i=0; i<dimensions; ++i){
            for(int j=0; j<dimensions; ++j){
                std::cout << *matrix_at(i,j) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n" << "\n";
    }

    //operators
    bool operator==(Matrix<T> rhs){
        if(rhs.matrix_dimension() != this->matrix_dimension()) return false;    //has to be the same size

        for(int r=0; r<rhs.matrix_dimension(); ++r){
            for(int c=0; c<rhs.matrix_dimension(); ++c){
                T left = *(this->matrix_at(r,c));
                T right = *rhs.matrix_at(r,c);
                if(left != right) return false;
            }
        }

        return true;
    }

    bool operator!=(Matrix<T> rhs){    
        return !(*this == rhs);
    }

    T operator()(int num1, int num2) const{
        //error handling
        if(num1 < 0 || num1 >= dimensions) throw std::invalid_argument("ERROR: Invalid row value");
        if(num2 < 0 || num2 >= dimensions) throw std::invalid_argument("ERROR: Invalid column value");

        return this->get(num1,num2);
    }

    Matrix<T> operator+(Matrix<T> &rhs){
        //create new matrix
        Matrix<T> m1(this->matrix_dimension(), 8);

        try{
            //error handling
            if(this->matrix_dimension() != rhs.matrix_dimension()) throw std::invalid_argument("ERROR: Matrices must be the same size to perform addition");

            //fills new matrix by adding values
            for(int i=0; i<this->matrix_dimension(); ++i){
                for(int j=0; j<this->matrix_dimension(); ++j){
                    m1.set(i,j,(*this)(i,j) + rhs(i,j));
                }
            }
            
        }
        catch(std::exception &e){
            std::cerr << e.what() << "\n";
        }
        return m1;
    }

    Matrix<T> operator-(Matrix<T> &rhs){
        Matrix<T> to_add = rhs.make_neg();
        return (*this)+to_add;
    }

    Matrix<T> operator*(Matrix<T> &rhs){
        //error handling
        if(this->matrix_dimension() != rhs.matrix_dimension()) throw std::invalid_argument("ERROR: Matrix dimension must match");

        //base case, matrices are 1x1
        if(rhs.matrix_dimension() == 1){
            Matrix<T> base(1,8);
            base.set(0,0,(*this)(0,0) * rhs(0,0));
            return base;
        }

        //make the matrices size 2^n x 2^n
        int new_size = rhs.next_size(rhs.matrix_dimension());
        Matrix<T> mult1(new_size, 8);
        Matrix<T> mult2(new_size, 8);

        //fill new matrices
        for(int i=0; i<new_size; ++i){
            for(int j=0; j<new_size; ++j){
                if(i < rhs.matrix_dimension() && j < rhs.matrix_dimension()){
                    mult1.set(i,j,(*this)(i,j));
                    mult2.set(i,j,rhs(i,j));
                }
                else{
                    mult1.set(i,j,0);
                    mult2.set(i,j,0);
                }
            }
        }

        //divide each matrix into 4 blocks
        //this blocks
        Matrix<T> topleft1(new_size/2,8);
        Matrix<T> topright1(new_size/2,8);
        Matrix<T> bottomleft1(new_size/2,8);
        Matrix<T> bottomright1(new_size/2,8);
        //rhs blocks
        Matrix<T> topleft2(new_size/2,8);
        Matrix<T> topright2(new_size/2,8);
        Matrix<T> bottomleft2(new_size/2,8);
        Matrix<T> bottomright2(new_size/2,8);
        //fill blocks
        for(int i=0; i<new_size; ++i){
            for(int j=0; j<new_size; ++j){
                if(i < new_size/2 && j < new_size/2){   //top left quadrant
                    topleft1.set(i,j,mult1(i,j));
                    topleft2.set(i,j,mult2(i,j));
                }
                else if(i < new_size/2 && j >= new_size/2){ //top right quadrant
                    topright1.set(i,j-(new_size/2),mult1(i,j));
                    topright2.set(i,j-(new_size/2),mult2(i,j));
                }
                else if(i >= new_size/2 && j < new_size/2){ //bottom left quadrant
                    bottomleft1.set(i-(new_size/2),j,mult1(i,j));
                    bottomleft2.set(i-(new_size/2),j,mult2(i,j));
                }
                else if(i >= new_size/2 && j >= new_size/2){    //bottom right quadrant
                    bottomright1.set(i-(new_size/2),j-(new_size/2),mult1(i,j));
                    bottomright2.set(i-(new_size/2),j-(new_size/2),mult2(i,j));
                }
            }
        }

        //the seven new matrices based on the Strassen algorithm, see link below
        //https://en.wikipedia.org/wiki/Strassen_algorithm
        //m1
        Matrix<T> left = topleft1 + bottomright1;
        Matrix<T> right = topleft2 + bottomright2;
        Matrix<T> m1 = left * right;
        //m2
        left = bottomleft1 + bottomright1;
        Matrix<T> m2 = left * topleft2;
        //m3
        right = topright2 - bottomright2;
        Matrix<T> m3 = topleft1 * right;
        //m4
        right = bottomleft2 - topleft2;
        Matrix<T> m4 = bottomright1 * right;
        //m5
        left = topleft1 + topright1;
        Matrix<T> m5 = left * bottomright2;
        //m6
        left = bottomleft1 - topleft1; right = topleft2 + topright2;
        Matrix<T> m6 = left * right;
        //m7
        left = topright1 - bottomright1; right = bottomleft2 + bottomright2;
        Matrix<T> m7 = left * right;

        //reassigns the blocks
        //top left
        left = m1 + m4; left = left - m5;
        topleft1 = left + m7;
        //top right
        topright1 = m3 + m5;
        //bottom left
        bottomleft1 = m2 + m4;
        //bottom right
        left = m1 - m2; left = left + m3;
        bottomright1 = left + m6;

        //copies the quadrants into the matrix to be returned
        Matrix<T> to_return(rhs.matrix_dimension(),8);
        for(int i=0; i<rhs.matrix_dimension(); ++i){
            for(int j=0; j<rhs.matrix_dimension(); ++j){
                if(i < new_size/2 && j < new_size/2){   //top left quadrant
                    to_return.set(i,j,topleft1(i,j));
                }
                else if(i < new_size/2 && j >= new_size/2){ //top right quadrant
                    to_return.set(i,j,topright1(i,j-(new_size/2)));
                }
                else if(i >= new_size/2 && j < new_size/2){ //bottom left quadrant
                    to_return.set(i,j,bottomleft1(i-(new_size/2),j));
                }
                else if(i >= new_size/2 && j >= new_size/2){    //bottom right quadrant
                    to_return.set(i,j,bottomright1(i-(new_size/2),j-(new_size/2)));
                }
            }
        }

        //return final matrix
        return to_return;
    }

    //REQUIRES: option is an integer 1-7 corresponding to the desired fill type
    //MODIFIES: the matrix object the method is called on
    //EFFECTS:  fills the matrix with the specified flavor of fill
    //          1: random rational number
    //          2: random irrational number
    //          3: random integer
    //          4: random natural number
    //          5: meme
    //          6: make a complete graph
    //          7: make an identity matrix
    //          default: meme
    //          8: leave the matrix unfilled
    void fill_by_option(int option){
        //error handling
        if(option < 1 || option > 8)throw std::invalid_argument("ERROR: Please specify an integer in the range 1-8 to fill with");

        //skips the fill
        if(option == 8) return;

        for (int column=0; column<dimensions; column++){
            for (int row=0; row<dimensions; row++) {
                switch (option){                    // Switching to funcs for readability, could inline if wanted
                    case 1: data[column*dimensions+row]= random_float(200) - (float) 100;
                        break;
                    case 2: data[column*dimensions+row]= (double) 3.14 * (random_int(1023)+1);
                        break;
                    case 3: data[column*dimensions+row]= random_int(2) - 1;
                        break;
                    case 4: data[column*dimensions+row]= random_int() % 10;
                        break;
                    case 5: data[column*dimensions+row]=meme_array[(column*dimensions+row) % 50];
                        break;
                    case 6: data[column*dimensions+row]= column==row ? 0 : 1;
                        break;
                    case 7: data[column*dimensions+row]= column==row ? 1 : 0;
                        break;
                    default: data[column*dimensions+row]= 0;
                        break;
                }
            }
        }
    }

    //EFFECTS:  returns the determinant of the matrix the method is called on
    T determinant(){
        T det = 0;

        //checks for size 1
        if(dimensions == 1){
            return (*this)(0,0);
        }
        else if(dimensions == 2){   //size 2
            return (*this)(0,0) * (*this)(1,1) - (*this)(0,1) * (*this)(1,0);
        }
        else{   //da otha sizes
            for(int i=0; i<dimensions; ++i){
                Matrix<T> temp(dimensions-1);
                for(int j=1; j<dimensions; ++j){
                    for(int k=0; k<dimensions; ++k){
                        if(k<i){
                            *temp.matrix_at(j-1,k) = *(this->matrix_at(j,k));
                        }
                        else if(k > i){
                            *temp.matrix_at(j-1,k-1) = *(this->matrix_at(j,k));
                        }
                    }
                }
                det += (*this)(0,i) * pow(-1,i) * temp.determinant();
            }
        }
        return det;
    }

    //EFFECTS:  checks if the matrix object is invertible, calls determinant
    bool invertible(){
        if(this->determinant() == 0){
            return false;
        }
        else return true;
    }

    //REQUIRES: 0 <= row, col < dimensions
    //MODIFIES: the matrix object pointed to by this
    //EFFECTS:  sets the value at (row,col) to val
    void set(int row, int col, T val){
        //error handling
        if(row < 0 || row >= dimensions) throw std::invalid_argument("ERROR: Invalid row value");
        if(col < 0 || col >= dimensions) throw std::invalid_argument("ERROR: Invalid column value");

        *(this->matrix_at(row,col)) = val;
    }

    //REQUIRES: 0 <= row, col < dimensions
    //EFFECTS:  gets the value at (row,col)
    T get(int row, int col) const{
        //error handling
        if(row < 0 || row >= dimensions) throw std::invalid_argument("ERROR: Invalid row value");
        if(col < 0 || col >= dimensions) throw std::invalid_argument("ERROR: Invalid column value");

        int index = row*dimensions + col;
        return data[index];
    }

    //REQUIRES: node1, node2 are valid location on the matrix
    //MODIFIES: the matrix pointed to by this
    //EFFECTS:  creates a connection in a graph between node1 and node2
    void create_connection(int node1, int node2){
        //error handling
        if(node1 <= 0 || node1 > dimensions) throw std::invalid_argument("ERROR: Invalid row value");
        if(node2 <= 0 || node2 > dimensions) throw std::invalid_argument("ERROR: Invalid column value");

        //size and setting the node indices
        int size = node1 + node2;
        node1--;
        node2--;

        //creates the connection in the graph
        for(int i=0; i<size; ++i){
            for(int j=0; j<size; ++j){
                if(i == node1 && j == node2){
                    this->set(i,j,1);
                }
                else if(i == node2 && j == node1){
                    this->set(i,j,1);
                }
            }
        }
    }

    //EFFECTS:  Returns a reduced row echelon form matrix of the matrix pointed to by this
    Matrix<double> rref(){
        Matrix<double> to_return(this->matrix_dimension(),8);
        to_return.copy_vals(*this);

        //forward elimination
        for(int i=0; i<this->matrix_dimension()-1; i++){
            if(!is_nonzero(to_return.return_row(i))) continue;
            for(int j=i+1; j<this->matrix_dimension(); j++){
                //gets ratio
                double ratio = (double)to_return(j,i) / to_return(i,i);
                for(int k=i; k<this->matrix_dimension(); k++){
                    //does operations
                    to_return.set(j,k,round(to_return(j,k) - ratio * to_return(i,k)));
                }
            }
        }

        //backward operations
        for(int i=to_return.matrix_dimension()-1; i>0; i--){
            if(!is_nonzero(to_return.return_row(i))) continue;

            //gets position of lead
            int pos = pivot(to_return.return_row(i));

            //divide row to get a 1
            to_return.divide_row_by(i, to_return(i,pos));

            //do subtractions
            for(int j=i-1; j>=0; j--){
                double ratio = to_return(j, pos) / to_return(i,pos);

                for(int k=pos; k<to_return.matrix_dimension(); k++){
                    to_return.set(j,k,to_return(j,k) - ratio * to_return(i,k));
                }
            }
        }
        //top row
        to_return.divide_row_by(0,to_return(0,0));

        return to_return;
    }

    //EFFECTS: copies the contents of the parameter into the matrix
    template <typename J>
    void copy_vals(Matrix<J> &from){
        for(int i=0; i<this->matrix_dimension(); i++){
            for(int j=0; j<this->matrix_dimension(); j++){
                (*this).set(i,j,from(i,j));
            }
        }
    }

    //MODIFIES: this matrix
    //EFFECTS:  divides each element in row by ratio
    void divide_row_by(int row, double ratio){
        for(int i=0; i<this->matrix_dimension(); i++){
            this->set(row,i,0.0 + (*this)(row,i) / ratio);
        }
    }

    ~Matrix(){
        clear_matrix();
    }

    private:
    int dimensions;
    T* data;

    void clear_matrix(){
        delete[] data;
    }

    void copy_mat(const Matrix &other){
        for(int i=0; i<other.matrix_dimension(); i++){
            for(int j=0; j<other.matrix_dimension(); j++){
                this->set(i,j,other(i,j));
            }
        }
    }

    //REQUIRES: 0 <= row,col <= dimensions
    //EFFECTS:  returns by reference the value stored at row,col
    T* matrix_at(int row, int col){
        //error handling
        if(row < 0 || row >= dimensions) throw std::invalid_argument("ERROR: Invalid row value");
        if(col < 0 || col >= dimensions) throw std::invalid_argument("ERROR: Invalid column value");

        int index = row*dimensions + col;
        return &data[index];
    }

    //EFFECTS:  returns the next 2^n size to expand a matrix to
    int next_size(int size){
        for(int i=0; i<11; ++i){
            if(pow(2,i) >= size) return pow(2,i);
        }

        return -1;
    }

    //EFFECTS:  returns a matrix with the same values but negative for subtraction purposes
    Matrix<T> make_neg(){
        //new mat
        Matrix<T> m1(this->matrix_dimension(),8);

        for(int i=0; i<m1.matrix_dimension(); ++i){
            for(int j=0; j<m1.matrix_dimension(); ++j){
                m1.set(i,j,(*this)(i,j) * -1);
            }
        }
        return m1;
    }

    //REQUIRES: l1 is a valid non-empty list
    //EFFECTS:  returns true if the column (list) passed to it is non-zero
    bool is_nonzero(std::list<double> l1){
        for(auto i=l1.begin(); i != l1.end(); i++){
            if(*i != 0) return true;
        }
        return false;
    }

    int pivot(std::list<double> l1){
        int index = 0;
        for(auto i=l1.begin(); i != l1.end(); i++){
            if(*i != 0){
                break;
            }
            index++;
        }
        return index;
    }

    double round(double d){
        double val = (int)(d * 1000 + 0.5);
        return (double) val / 1000;
    }
};

// BASIC, BAD, TYPE-SPECIFIC
void print_eq(Matrix<int> matrix_1, Matrix<int> matrix_2, Matrix<int> result, char oper) {
    int size1 = matrix_1.matrix_dimension();
    int size2 = matrix_2.matrix_dimension();
    int size3 = result.matrix_dimension();

    int largest = max(max(size1,size2),size3);
    int smallest = min(min(size1,size2),size3);

    // Print each line top to bottom
    for (int j=0; j<largest; j++) {                    
        for(int k=0; k<size1; k++)//Print each value in the jth row for Matrix 1
        {
            if (j<size1) {
                printf(" %d ",matrix_1(j,k));
            } else{
                printf("   ");
            }
        }
        
        //If it's in the right spot, print a multiplication symbol
        if(j == smallest/2)
        {
            printf("\t%c\t",oper);
        }
        else //Else, don't
        {
            printf("\t\t");
        }
    
        //Print each value in the jth row for for Matrix 2
        for(int k=0; k<size2; k++)
        {
            if(j<size2) {
                printf(" %d ",matrix_2(j,k));
            } else {
                printf("   ");
            }
        }
    
        //If it's in the right spot, print the equals symbol
        if(j == smallest/2)
        {
            printf("\t=\t");
        }
        else//Otherwise, don't
        {
            printf("\t\t");
        }

        //Print each value in the jth row for the result matrix
        for(int k=0; k<size3; k++)
        {
            if (j<size3) {
                printf(" %d ",result(j,k));
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
};

//REQUIRES: size < MAX_DIMENSIONS
//EFFECTS:  returns by value a complete graph matrix of the designated size
Matrix<int> complete_graph(int size){
    //declare new matrix
    Matrix<int> new_mat(size,6);

    //return matrix
    return new_mat;
}

//REQUIRES: size < MAX_DIMENSTIONS and the two matrices are complete graphs
template <typename T>
Matrix<T> addend_graphs(Matrix<T> &m1, Matrix<T> &m2){
    //new size and new matrix
    int new_size = m1.matrix_dimension() + m2.matrix_dimension();
    Matrix<T> new_mat(new_size);

    //combines the graphs
    for(int i=0; i<new_size; ++i){
        for(int j=0; j<new_size; ++j){
            if(i == j){
                new_mat.set(i,j,0);
            }
            else if(i < m1.matrix_dimension() && j < m1.matrix_dimension()){
                if(i != j) new_mat.set(i,j,1);
            }
            else if(i >= m1.matrix_dimension() && j >= m1.matrix_dimension()){
                if(i != j) new_mat.set(i,j,1);
            }
            else{
                new_mat.set(i,j,0);
            }
        }
    }
    return new_mat;
}

#endif
