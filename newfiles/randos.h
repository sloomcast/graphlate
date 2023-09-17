#ifndef RANDOS_H
#define RANDOS_H

#include <random>   // for []
#include <ctime>    // for time

// Adapted from https://cplusplus.com/forum/beginner/234722/,
// uses the Mersenne Twister PRNG (using prime 199737) to generate
// pseudorandom numbers

// OUTPUT: a pseudo-random integer between the range 0 and 999999999
static int random_int()
{
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<int> dist(0, 999999999);

    return dist(m_mt);
}

// INPUT: a maximum bound to the range used to generate a pseudorandom integer
// OUTPUT: a pseudorandom integer between 0 and max
static int random_int(int max)
{
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<int> dist(0, max);

    return dist(m_mt);
}

// OUTPUT: a pseudo-random float between the range 0 and 999999999
static int random_float() {
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<float> dist(0, 999999999);

    return dist(m_mt);
}

// INPUT: a maximum bound to the range used to generate a pseudorandom float
// OUTPUT: a pseudorandom float between 0 and max
static int random_float(int max) {
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<float> dist(0, max);

    return dist(m_mt);
}

// OUTPUT: a pseudo-random double between the range 0 and 999999999
static int random_double()
{
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<double> dist(0, 999999999);

    return dist(m_mt);
}

// INPUT: a maximum bound to the range used to generate a pseudorandom double
// OUTPUT: a pseudorandom double between 0 and max
static int random_double(int max)
{
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<double> dist(0, max);

    return dist(m_mt);
}

#endif