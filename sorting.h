#pragma once

#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort (long long size, long long* arr);
void bubble_sort_optimized (long long size, long long* arr);
void selection_sort (long long size, long long* arr);
void insertion_sort (long long size, long long* arr);
void quick_sort (long long size, long long* arr);
void quick_advanced_sort (long long size, long long* arr);
void merge_sort (long long size, long long* arr);
void merge_recursion (long long first, long long last, long long size, long long* arr);
void merge (long long first, long long last, long long size, long long* arr);
void built_in_sort (long long size, long long* arr);
void built_in_stable_sort (long long size, long long* arr);
void heap_sort (long long size, long long* arr);
void heapify (long long size, long long* arr, long long i);
