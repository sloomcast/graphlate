#ifndef MATHS_H
#define MATHS_H
// AUTHOR:  LUCAS RIZZOLO
// because I'm too lazy to import a whole package, here's mine

// INPUT:   @param int a the first integer to compare
//          @param int b the second integer to compare
// RETURNS:  the largest input integer
static inline int max(int a, int b) {
    return(a>b ? a : b);
}

// https://stackoverflow.com/questions/8965603/how-to-find-the-closest-value-of-2n-to-a-given-input
unsigned twon(unsigned value) {
    unsigned above = (value - 1);
    above |= above >> 1;
    above |= above >> 2;
    above |= above >> 4;
    above |= above >> 8;
    above |= above >> 16;
    ++above;
    return above;
}

#endif