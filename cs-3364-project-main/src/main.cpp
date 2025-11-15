#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "insertion_sort.cpp"
#include "mergeSort.cpp"

std::vector<int> generate_array(int n);
void hybrid_sort(std::vector<int> *arr, int k, int start, int n);

const int TESTS_PER_K = 5;
const int N[] = {10000, 25000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000, 2000000, 4000000, 8000000, 10000000}; //Give this array values of n to test

int main() {
    std::ofstream unsorted("unsorted.csv");
    std::ofstream sorted("sorted.csv");

    unsorted << "N,Average Time (ms)" << std::endl;
    sorted << "N,Average Time (ms)" << std::endl;


    std::chrono::milliseconds total_unsorted_time = std::chrono::milliseconds::zero();
    std::chrono::milliseconds total_sorted_time = std::chrono::milliseconds::zero();

    for(int i = 0; i < 13; i++){ // Change i max value when array N length is changed
        for(int _ = 0; _ < TESTS_PER_K; _++) {
            auto arr = generate_array(N[i]);

            auto start = std::chrono::high_resolution_clock::now();
            hybrid_sort(&arr, 75, 0, N[i]); // Setting optimal K value (75)
            auto end = std::chrono::high_resolution_clock::now();

            // Make sure the array is sorted
            for (int i = 1; i < arr.size(); i++)
                if (arr[i - 1] > arr[i])
                    continue;

            total_unsorted_time += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            start = std::chrono::high_resolution_clock::now();
            hybrid_sort(&arr, 75, 0, N[i]); // Setting Optimal K value (75)
            end = std::chrono::high_resolution_clock::now();

            total_sorted_time += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        }
        auto unsorted_average = total_unsorted_time / TESTS_PER_K;
        auto sorted_average = total_sorted_time / TESTS_PER_K;

        unsorted << N[i] << "," << unsorted_average.count() << std::endl; // Setting Optimal K value (75)
        sorted << N[i] << "," << sorted_average.count() << std::endl; // Setting Optimal K value (75)
    }

    return 0;
}

std::vector<int> generate_array(int n) {
    std::vector<int> arr(n);
    std::iota(arr.begin(), arr.end(), 1);

    std::random_shuffle(arr.begin(), arr.end());

    return arr;
}

void hybrid_sort(std::vector<int> *arr, int k, int start, int end) {
    int n = end - start;

    if(n < k) {
        insertionSort(arr, n);
    } else {
        int mid = start + (end - start) / 2;
        hybrid_sort(arr, k, start, mid);
        hybrid_sort(arr, k, mid, end);
        merge(*arr, start, mid, end);
    }
}