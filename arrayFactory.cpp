#include "arrayFactory.h"

long long* generate_random()
    {
    srand (time(0));
    long long size = rand() % 10000;
    long long* arr = new long long[size];

    for (long long i = 0; i < size; i++)
        {
        arr[i] = rand();
        }

    return arr;
    }