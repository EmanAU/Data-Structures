#include <iostream>
using namespace std;

/*
======================= SELECTION SORT SUMMARY =======================

Selection Sort is a simple comparison-based sorting algorithm.

IDEA:
- Divide the array into two parts:
  1) Sorted part (left side)
  2) Unsorted part (right side)
- Repeatedly find the MINIMUM element from the unsorted part
- Swap it with the first element of the unsorted part
- Move the boundary of the sorted part one step right

-------------------------------------------------------------------
TIME COMPLEXITY:
- Best Case:     O(n^2)
- Average Case: O(n^2)
- Worst Case:    O(n^2)

(Note: Time complexity is ALWAYS O(n^2) because selection is done
 even if the array is already sorted.)

-------------------------------------------------------------------
SPACE COMPLEXITY:
- O(1) → in-place sorting (no extra memory)

-------------------------------------------------------------------
IS IT STABLE?
- ❌ NO (swapping can change order of equal elements)

-------------------------------------------------------------------
WHEN IS SELECTION SORT USEFUL?
- When memory writes are costly (minimum swaps)
- Very small datasets
- Educational and exam purposes

-------------------------------------------------------------------
NUMBER OF SWAPS:
- At most (n - 1) swaps → better than Bubble Sort in this aspect

-------------------------------------------------------------------
HOW TO IMPROVE?
- Use Stable Selection Sort (extra shifting, more code)
- Use Insertion Sort for slightly better performance
- Use Quick / Merge Sort for large data

-------------------------------------------------------------------
THIS IMPLEMENTATION:
- Classic Selection Sort
- Very easy logic
- Frequently asked in exams
===================================================================
*/

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // Find minimum element in remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap minimum with first unsorted element
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting:\n";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "After Sorting:\n";
    printArray(arr, n);

    return 0;
}
