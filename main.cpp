#include <iostream> 
#include <ctime>
#include <fstream>

#include "sorting.h"

using namespace std;

long long* generate_random(long long min, long long max)
    {
    long long size = rand() % max;
    if (size < min)
        size += min;

    long long* arr = new long long[size];

    for (long long i = 0; i < size; i++)
        arr[i] = rand();

    return arr;
    }

void get_time(long long size, long long* arr, void (*sort_arr)(long long size, long long* arr), const string type, const string name, ofstream& file)
    {
    long long* tmp = new long long[size];
    for (long long i = 0; i < size; i++)
        tmp[i] = arr[i];

    long double time_start = clock();
    sort_arr(size, tmp);
    long double time_used = (clock() - time_start) / (long double) CLOCKS_PER_SEC;

    file << type << '\t' << name << '\t' << size << '\t' << time_used << '\n';
    }

void get_time_random(ofstream& file)
    {
    file << "random\n";
    file << "type\tname\tsize\ttime\n";
    long long* arr_square = generate_random (1e3, 1e5);
    long long size_square = _msize (arr_square) / sizeof (arr_square[0]);

    long long* arr_fast = generate_random (1e5, 1e7);
    long long size_fast = _msize (arr_fast) / sizeof (arr_fast[0]);

    get_time (size_square, arr_square, bubble_sort          , "square", "bubble" , file);
    get_time (size_square, arr_square, bubble_sort_optimized, "square", "bubble+", file);
    get_time (size_square, arr_square, selection_sort       , "square", "select" , file);
    get_time (size_square, arr_square, insertion_sort       , "square", "insert" , file);
    get_time (size_fast  , arr_fast  , quick_sort           , "fast"  , "quick"  , file);
    get_time (size_fast  , arr_fast  , quick_advanced_sort  , "fast"  , "quick+" , file);
    get_time (size_fast  , arr_fast  , merge_sort           , "fast"  , "merge"  , file);
    get_time (size_fast  , arr_fast  , built_in_sort        , "fast"  , "default", file);
    get_time (size_fast  , arr_fast  , built_in_stable_sort , "fast"  , "stable" , file);
    get_time (size_fast  , arr_fast  , heap_sort            , "fast"  , "heap"   , file);
    
    file << '\n';
    }

void get_time_sorted(ofstream& file)
    {
    file << "sorted\n";
    file << "type\tname\tsize\ttime\n";
    long long* arr_square = generate_random (1e3, 1e5);
    long long size_square = _msize (arr_square) / sizeof (arr_square[0]);
    sort (arr_square, arr_square + size_square);

    long long* arr_fast = generate_random (1e5, 1e7);
    long long size_fast = _msize (arr_fast) / sizeof (arr_fast[0]);
    sort (arr_fast, arr_fast + size_fast);

    get_time (size_square, arr_square, bubble_sort          , "square", "bubble" , file);
    get_time (size_square, arr_square, bubble_sort_optimized, "square", "bubble+", file);
    get_time (size_square, arr_square, selection_sort       , "square", "select" , file);
    get_time (size_square, arr_square, insertion_sort       , "square", "insert" , file);
    get_time (size_fast  , arr_fast  , quick_sort           , "fast"  , "quick"  , file);
    get_time (size_fast  , arr_fast  , quick_advanced_sort  , "fast"  , "quick+" , file);
    get_time (size_fast  , arr_fast  , merge_sort           , "fast"  , "merge"  , file);
    get_time (size_fast  , arr_fast  , built_in_sort        , "fast"  , "default", file);
    get_time (size_fast  , arr_fast  , built_in_stable_sort , "fast"  , "stable" , file);
    get_time (size_fast  , arr_fast  , heap_sort            , "fast"  , "heap"   , file);

    file << '\n';
    }

void get_time_reversed(ofstream& file)
    {  
    file << "reversed\n";
    file << "type\tname\tsize\ttime\n";
    long long* arr_square = generate_random (1e3, 1e5);
    long long size_square = _msize (arr_square) / sizeof (arr_square[0]);
    sort (arr_square, arr_square + size_square);
    reverse (arr_square, arr_square + size_square);

    long long* arr_fast = generate_random (1e5, 1e7);
    long long size_fast = _msize (arr_fast) / sizeof (arr_fast[0]);
    sort (arr_fast, arr_fast + size_fast);
    reverse (arr_fast, arr_fast + size_fast);

    get_time (size_square, arr_square, bubble_sort          , "square", "bubble" , file);
    get_time (size_square, arr_square, bubble_sort_optimized, "square", "bubble+", file);
    get_time (size_square, arr_square, selection_sort       , "square", "select" , file);
    get_time (size_square, arr_square, insertion_sort       , "square", "insert" , file);
    get_time (size_fast  , arr_fast  , quick_sort           , "fast"  , "quick"  , file);
    get_time (size_fast  , arr_fast  , quick_advanced_sort  , "fast"  , "quick+" , file);
    get_time (size_fast  , arr_fast  , merge_sort           , "fast"  , "merge"  , file);
    get_time (size_fast  , arr_fast  , built_in_sort        , "fast"  , "default", file);
    get_time (size_fast  , arr_fast  , built_in_stable_sort , "fast"  , "stable" , file);
    get_time (size_fast  , arr_fast  , heap_sort            , "fast"  , "heap"   , file);

    file << '\n';
    }

void get_time_partially_sorted(ofstream& file)
    {  
    file << "partially sorted\n";
    file << "type\tname\tsize\ttime\n";
    long long* arr_square = generate_random (1e3, 1e5);
    long long size_square = _msize (arr_square) / sizeof (arr_square[0]);
    sort (arr_square, arr_square + size_square);
    for (long long i = 0; i < size_square / 20; i++)
        swap(arr_square[rand() % size_square], arr_square[rand() % size_square]);

    long long* arr_fast = generate_random (1e5, 1e7);
    long long size_fast = _msize (arr_fast) / sizeof (arr_fast[0]);
    sort (arr_fast, arr_fast + size_fast);
    for (long long i = 0; i < size_fast / 20; i++)
        swap(arr_fast[rand() % size_fast], arr_fast[rand() % size_fast]);

    get_time (size_square, arr_square, bubble_sort          , "square", "bubble" , file);
    get_time (size_square, arr_square, bubble_sort_optimized, "square", "bubble+", file);
    get_time (size_square, arr_square, selection_sort       , "square", "select" , file);
    get_time (size_square, arr_square, insertion_sort       , "square", "insert" , file);
    get_time (size_fast  , arr_fast  , quick_sort           , "fast"  , "quick"  , file);
    get_time (size_fast  , arr_fast  , quick_advanced_sort  , "fast"  , "quick+" , file);
    get_time (size_fast  , arr_fast  , merge_sort           , "fast"  , "merge"  , file);
    get_time (size_fast  , arr_fast  , built_in_sort        , "fast"  , "default", file);
    get_time (size_fast  , arr_fast  , built_in_stable_sort , "fast"  , "stable" , file);
    get_time (size_fast  , arr_fast  , heap_sort            , "fast"  , "heap"   , file);

    file << '\n';
    }

int main()
    {
    ofstream file;
    file.open ("results.txt");
    srand (time (0));

    get_time_random (file);
    get_time_sorted (file);
    get_time_reversed (file);
    get_time_partially_sorted (file);
    }