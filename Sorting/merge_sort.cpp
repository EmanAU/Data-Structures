#include <iostream>
using namespace std;

/*
========================
MERGE SORT (OVERVIEW)
========================
Merge Sort is a DIVIDE AND CONQUER sorting algorithm.

Steps:
1. Divide the array into two halves
2. Recursively sort both halves
3. Merge the two sorted halves

Key Idea:
- Division continues until subarrays have size 1
- Merging combines sorted parts in linear time
*/

/*
========================
MERGE FUNCTION
========================
Merges two sorted subarrays into one sorted array

Left subarray:  arr[left ... mid]
Right subarray: arr[mid+1 ... right]
*/
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // size of left subarray
    int n2 = right - mid;    // size of right subarray

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data into temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temp arrays back into arr[]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements (if any)
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

/*
========================
MERGE SORT FUNCTION
========================
Recursively divides the array and merges it
*/
void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return; // Base case: single element

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);      // sort left half
    mergeSort(arr, mid + 1, right); // sort right half
    merge(arr, left, mid, right);   // merge both halves
}

/*
========================
MAIN FUNCTION
========================
*/
int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\n\nAfter sorting:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

/*
================================================
TIME & SPACE COMPLEXITY SUMMARY
================================================

TIME COMPLEXITY:
----------------
At each level of recursion:
- The array is merged in O(n) time

Number of levels:
- Array is divided into 2 parts each time
- Height of recursion tree = log₂(n)

Total Time:
= O(n) * O(log₂ n)
= O(n log n)

Best Case:    O(n log n)
Average Case: O(n log n)
Worst Case:   O(n log n)

------------------------------------------------

SPACE COMPLEXITY:
-----------------
- Extra arrays used during merging
- O(n) auxiliary space

------------------------------------------------

STABILITY:
----------
- Merge Sort is STABLE
- Equal elements maintain relative order

------------------------------------------------

CAN WE CHANGE log BASE?
-----------------------
You may see:
- log₂ n
- log₄ n
- log₈ n

Important Rule:
log₄ n = log₂ n / log₂ 4 = (1/2) log₂ n

So:
O(n log₄ n) == O(n log₂ n)

➡️ Changing the base of log DOES NOT change Big-O complexity.

------------------------------------------------

HOW WOULD WE *ACTUALLY* CHANGE THE BASE?
---------------------------------------
Instead of dividing array into 2 parts,
divide into 4 parts each time.

Example idea (not recommended in practice):
- Split array into 4 equal parts
- Recursively sort all 4
- Merge all 4 parts

Height becomes:
log₄ n instead of log₂ n

BUT:
- Merge step becomes more complex
- Total complexity still O(n log n)

------------------------------------------------

WHY MERGE SORT IS ALWAYS O(n log n)?
-----------------------------------
Because:
1. It always divides fully (no shortcuts)
2. It always merges full arrays
3. Input order does NOT matter

------------------------------------------------

WHEN TO USE MERGE SORT?
----------------------
✔ Large datasets
✔ Linked lists
✔ Stable sorting required
❌ When memory is limited

================================================
END OF SUMMARY
================================================
*/
