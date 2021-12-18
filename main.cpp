#include <iostream> 
#include <ctime>
#include <fstream>

#include "sorting.h"
#include "arrayFactory.h"

using namespace std;

void get_time(long long* (*generator)(), void (*sort_arr)(long long size, long long* arr), ofstream& file)
    {
    long long* arr = generator();
    long long size = _msize(arr) / sizeof(arr[0]);
    
    cout << size << '\n';

    double time_start = clock();
    sort_arr(size, arr);
    double time_used = (clock() - time_start) / (double)CLOCKS_PER_SEC;

    file << size << "," << time_used << '\n';
    }

void get_time_random()
    {
    ofstream file;
    file.open("results.csv");
    get_time(generate_random, bubble_sort, file);
    }

int main()
    {
    
    }