#include <iostream>
using namespace std;

/*
========================= RADIX SORT SUMMARY =========================

Radix Sort is a NON-comparison based sorting algorithm.

IDEA:
- Sort numbers digit by digit
- Start from the least significant digit (LSD)
- Use a stable sub-sorting algorithm (Counting Sort) for each digit

-------------------------------------------------------------------
TIME COMPLEXITY:
- O(d * (n + k))
  where:
    d = number of digits in the largest number
    n = number of elements
    k = base (10 for decimal)

For integers:
- Effectively O(n) when d is small

-------------------------------------------------------------------
SPACE COMPLEXITY:
- O(n + k)

-------------------------------------------------------------------
IS IT STABLE?
- ✅ YES (because counting sort is stable)

-------------------------------------------------------------------
WHEN IS RADIX SORT USEFUL?
- Sorting integers or fixed-length strings
- When numbers are not too large
- Large datasets with known digit length

-------------------------------------------------------------------
LIMITATIONS:
- ❌ Does NOT work directly for negative numbers
- ❌ Needs extra memory
- ❌ Not comparison-based (not general-purpose)

-------------------------------------------------------------------
THIS IMPLEMENTATION:
- LSD Radix Sort
- Uses Counting Sort as a subroutine
- Very common in exams
===================================================================
*/

// Get maximum element in array
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Counting sort according to a specific digit (exp)
void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert count to cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort main function
void radixSort(int arr[], int n)
{
    int mx = getMax(arr, n);

    // Apply counting sort for each digit
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
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
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting:\n";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "After Sorting:\n";
    printArray(arr, n);

    return 0;
}
