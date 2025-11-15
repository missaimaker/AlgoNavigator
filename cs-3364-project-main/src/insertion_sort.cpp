#include <iostream>
#include <vector>

// Function to perform Insertion Sort
void insertionSort(std::vector<int> *arr, int n)
{

    for (int i = 1; i < n; ++i)
    {
        // Save the current element to insert it in the sorted portion
        int key = (*arr)[i];

        // Find the correct position for the key in the sorted portion of the array
        int j = i - 1;
        while (j >= 0 && (*arr)[j] > key)
        {
            (*arr)[j + 1] = (*arr)[j];
            j--;
        }

        // Insert the key in the correct position
        (*arr)[j + 1] = key;
    }
}