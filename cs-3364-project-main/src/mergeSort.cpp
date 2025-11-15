// Variable names might differ from the ones used in main and Insertion sort function

#include <iostream>
#include <vector>

void merge(std::vector<int> &anyArray, int start, int mid, int end);

// Function to sort the array using Merge Sort
void sortIt(std::vector<int> &anyArray, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Recursively sort the first and second halves
        sortIt(anyArray, start, mid);
        sortIt(anyArray, mid + 1, end);

        // Merge the sorted halves
        merge(anyArray, start, mid, end);
    }
}

// Function to merge two sorted subarrays
void merge(std::vector<int> &anyArray, int start, int mid, int end) {
    int n1 = mid - start + 1; // Size of left subarray
    int n2 = end - mid;       // Size of right subarray

    // Create temporary arrays
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = anyArray[start + i];
    for (int j = 0; j < n2; ++j)
        R[j] = anyArray[mid + 1 + j];

    // Merge the temporary arrays back into anyArray
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            anyArray[k] = L[i];
            i++;
        } else {
            anyArray[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        anyArray[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        anyArray[k] = R[j];
        j++;
        k++;
    }
}

// Function to print the array
void printArray(const std::vector<int> &arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

// Test function
// int main() {
//     std::vector<int> anyArray = {12, 11, 13, 5, 6, 7};
//     std::cout << "Original Array: ";
//     printArray(anyArray);

//     sortIt(anyArray, 0, anyArray.size() - 1);

//     std::cout << "Sorted Array: ";
//     printArray(anyArray);

//     return 0;
// }
