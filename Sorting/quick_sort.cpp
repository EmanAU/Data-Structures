#include <iostream>
using namespace std;

/*
======================== QUICK SORT SUMMARY ========================

Quick Sort is a divide-and-conquer sorting algorithm.

STEPS:
1. Pick a pivot element (here we choose the LAST element).
2. Rearrange the array so that:
   - Elements smaller than pivot go to the left
   - Elements greater than pivot go to the right
3. Recursively apply Quick Sort on left and right subarrays.

-------------------------------------------------------------------
TIME COMPLEXITY:
- Best Case:     O(n log n)  → balanced partitions
- Average Case: O(n log n)
- Worst Case:    O(n^2)      → already sorted array (bad pivot choice)

-------------------------------------------------------------------
SPACE COMPLEXITY:
- O(log n)  (recursive stack, in best/average case)
- O(n)      (worst case recursion)

-------------------------------------------------------------------
IS IT STABLE?
- ❌ NO (equal elements may change order)

-------------------------------------------------------------------
WHEN QUICK SORT IS FAST?
- When pivot divides array roughly in half
- Random or unsorted data

-------------------------------------------------------------------
HOW TO IMPROVE PERFORMANCE?
1. Choose better pivot:
   - Middle element
   - Random element
   - Median of three (first, middle, last)

2. Switch to Insertion Sort for small subarrays

3. Use Tail Recursion optimization

-------------------------------------------------------------------
THIS IMPLEMENTATION:
- Uses Lomuto Partition
- Very easy to understand
- Good for learning and exams
===================================================================
*/

// Partition function (Lomuto partition scheme)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // place pivot at its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        // sort elements before and after partition
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Utility function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting:\n";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "After Sorting:\n";
    printArray(arr, n);

    return 0;
}
