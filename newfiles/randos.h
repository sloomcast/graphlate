#ifndef RANDOS_H
#define RANDOS_H

#include <random>
#include <ctime>

// From https://cplusplus.com/forum/beginner/234722/
static int random_int()
{
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<int> dist(0, 999999999);

    return dist(m_mt);
}

static int random_int(int max)
{
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<int> dist(0, max);

    return dist(m_mt);
}

static int random_float() {
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<float> dist(0, 999999999);

    return dist(m_mt);
}

static int random_float(int max) {
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<float> dist(0, max);

    return dist(m_mt);
}

static int random_double()
{
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<double> dist(0, 999999999);

    return dist(m_mt);
}

static int random_double(int max)
{
    static std::mt19937 m_mt( std::time(nullptr) );
    static std::uniform_int_distribution<double> dist(0, max);

    return dist(m_mt);
}

#endif