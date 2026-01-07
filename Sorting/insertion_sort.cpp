#include <iostream>
using namespace std;

/*
======================= INSERTION SORT SUMMARY =======================

Insertion Sort works the same way we sort playing cards in our hands.

IDEA:
- Divide the array into:
  1) Sorted part (left)
  2) Unsorted part (right)
- Take one element from the unsorted part
- Insert it into its correct position in the sorted part
- Repeat until array is fully sorted

-------------------------------------------------------------------
TIME COMPLEXITY:
- Best Case:     O(n)      → already sorted array
- Average Case: O(n^2)
- Worst Case:    O(n^2)    → reverse sorted array

-------------------------------------------------------------------
SPACE COMPLEXITY:
- O(1) → in-place sorting

-------------------------------------------------------------------
IS IT STABLE?
- ✅ YES (relative order of equal elements is preserved)

-------------------------------------------------------------------
WHEN IS INSERTION SORT USEFUL?
- Small datasets
- Nearly sorted arrays
- As a helper algorithm in hybrid sorts (Tim Sort, Intro Sort)

-------------------------------------------------------------------
NUMBER OF SHIFTS:
- Worst case: O(n^2)
- Fewer swaps than Bubble Sort (uses shifting)

-------------------------------------------------------------------
HOW TO IMPROVE?
- Use Binary Insertion Sort (binary search for position)
- Combine with Quick / Merge Sort for small subarrays

-------------------------------------------------------------------
THIS IMPLEMENTATION:
- Classic Insertion Sort
- Very easy logic
- Commonly used in exams
===================================================================
*/

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // element to be inserted
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting:\n";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "After Sorting:\n";
    printArray(arr, n);

    return 0;
}
