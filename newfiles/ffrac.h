#ifndef FFRAC_H
#define FFRAC_H

#include <fstream>
#include <iostream>

class ffrac{
    public:
    ffrac(){
        numerator = 1;
        denominator = 1;
        ratio = 1;
    }

    ffrac(int num, int denom = 1){
        //error handling
        if(denom == 0) throw std::invalid_argument("ERROR: Cannot divide by 0\n\n");

        //checks if we can reduce the fraction
        if(num % denom == 0){
            numerator = num / denom;
            denominator = 1;
        }
        else if(denom % num == 0){
            denominator = denom / num;
            numerator = 1;
        }
        else{
            numerator = num;
            denominator = denom;
        }

        ratio = num / denom;
    }

    ffrac operator*(ffrac &rhs){
        int num = this->numerator * rhs.numerator;
        int denom = this->denominator * rhs.denominator;

        return ffrac(num,denom);
    }

    ffrac operator*(int &rhs){
        ffrac mult(rhs);
        return (*this) * mult;
    }

    ffrac operator+(ffrac &rhs){
        return ffrac((this->numerator * rhs.denominator) + (rhs.numerator * this->denominator),this->denominator * rhs.denominator);
    }

    ffrac operator+(int &rhs){
        ffrac add(rhs);
        return (*this) + add;
    }

    ffrac operator/(ffrac &rhs){
        ffrac div(rhs.denominator,rhs.numerator);
        return (*this) * div;
    }

    ffrac operator/(int &rhs){
        ffrac div(1,rhs);
        return (*this) * div;
    }

    ffrac operator-(ffrac &rhs){
        int neg = -1;
        ffrac sub = rhs * neg;
        return (*this) + sub;
    }

    ffrac operator-(int &rhs){
        ffrac sub(-1 * rhs);
        return (*this) + sub;
    }

    friend std::ostream& operator<<(std::ostream &os, const ffrac &rhs){
        if(rhs.denominator == 1){
            os << " " << rhs.numerator << " ";
        }
        else{
            os << rhs.numerator << "/" << rhs.denominator;
        }

        return os;
    }

    bool operator==(ffrac &rhs){
        if(this->numerator == rhs.numerator && this->denominator == rhs.denominator) return true;
        return false;
    }

    bool operator!=(ffrac &rhs){
        return !(*this == rhs);
    }

    //overloaded casters
    operator int(){ return int(ratio); }
    operator double() { return ratio; }
    operator float() { return ratio; }

    private:
    int numerator;
    int denominator;
    double ratio;
};

#endif