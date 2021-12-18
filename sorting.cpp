#include "sorting.h"

void bubble_sort (long long size, long long* arr)
    {
    for (long long i = 0; i < size; i++)
        for (long long j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap (arr[j], arr[j + 1]);
    }

void bubble_sort_optimized (long long size, long long* arr)
    {
    for (long long i = 0; i < size; i++)
        {
        bool swapped = false;
        for (long long j = 0; j < size - i - 1; j++)
            {
            if (arr[j] > arr[j + 1])
                {
                swap (arr[j], arr[j + 1]);
                swapped = true;
                }
            }
        if (swapped == false)
            break;
        }
    }

void selection_sort (long long size, long long* arr)
    {
    for (long long i = 0; i < size; i++)
        {
        long long min_ind = i;
        for (long long j = i + 1; j < size; j++)
			if (arr[j] < arr[min_ind])
				min_ind = j;
        swap (arr[i], arr[min_ind]);
        }
    }

void insertion_sort (long long size, long long* arr)
    {
    for (long long i = 1; i < size; i++)
        for (long long j = i; (j > 0) && (arr[j - 1] > arr[j]); j--)
            swap (arr[j - 1], arr[j]);  
    }

void quick_sort (long long size, long long* arr)
    {
    long long i = 0, j = size - 1;
    long long mid = arr[size / 2];

    while (i <= j)
        {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;

        if (i <= j)
            swap (arr[i++], arr[j--]);
        }

    if (j > 0) quick_sort (j + 1, arr);
    if (size - 1 > i) quick_sort (size - i, arr + i);
    }

void quick_advanced_sort (long long size, long long* arr)
    {
    long long i = 0, j = size - 1;
    long long mid = arr[size / 2];
    if (size > 2)
        {
        long long tmp[3] = {arr[0], arr[size / 2], arr[size - 1]};
        sort(tmp, tmp + 2);
        mid = arr[tmp[1]];
        }

    while (i <= j)
        {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;

        if (i <= j)
            swap (arr[i++], arr[j--]);
        }

    if (j > 0) quick_sort (j + 1, arr);
    if (size - 1 > i) quick_sort (size - i, arr + i);
    }

void merge (long long first, long long last, long long size, long long* arr)
    {
    long long mid = (first + last) / 2;
    long long* tmp_arr = new long long[size];
    long long start = first;
    long long finish = mid + 1;

    for (int i = first; i <= last; i++)
        {
        if ((start <= mid) && ((finish > last) || (arr[start] < arr[finish])))
            tmp_arr[i] = arr[start++];
        else
            tmp_arr[i] = arr[finish++];    
        }

    for (int i = first; i <= last; i++)
        arr[i] = tmp_arr[i];

    delete[] tmp_arr;    
    } 

void merge_recursion (long long first, long long last, long long size, long long* arr)
    {
    if (first < last)
        {
        merge_recursion (first, (first + last) / 2, size, arr);
        merge_recursion ((first + last) / 2 + 1, last, size, arr);
        merge (first, last, size, arr);
        }
    }

void merge_sort (long long size, long long* arr)
    {
    merge_recursion (0, size - 1, size, arr);
    }

void built_in_sort (long long size, long long* arr)
    {
    sort (arr, arr + size);
    }

void built_in_stable_sort (long long size, long long* arr)
    {
    stable_sort (arr, arr + size);
    }

void heapify (long long size, long long* arr, long long i)
    {
    int max = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < size && arr[l] > arr[max])
        max = l;

    if (r < size && arr[r] > arr[max])
        max = r;

    
    if (max != i)
        {
        swap(arr[i], arr[max]);
        heapify(size, arr, max);
        }
    }

void heap_sort (long long size, long long* arr)
    {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(size, arr, i);

    for (int i = size - 1; i >= 0; i--)
        { 
        swap(arr[0], arr[i]);
        heapify(i, arr, 0);
        }
    }
