# EX 04: Implement randomized quick sort algorithm

### Algorithm

1. Select a random pivot element from the array.
2. Partition the array such that elements smaller than the pivot are on the left, and elements greater than the pivot are on the right.
3. Recursively apply the same process to the left and right sub-arrays.
4. Repeat until the array is fully sorted.

### Code

```cpp
#include <iostream>
#include <cstdlib>  
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;  
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}


int randomizedPartition(int arr[], int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);  
    swap(arr[randomPivot], arr[high]);  
    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);         
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array: ";
    printArray(arr, n);
    randomizedQuickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
```

### Output

```bash
Unsorted array: 10 7 8 9 1 5 
Sorted array: 1 5 7 8 9 10
```

### Explanation

- `randomizedPartition` selects a random pivot by swapping a randomly chosen element with the last element.
- The rest follows the typical quicksort process, where the array is partitioned around the pivot and recursively sorted.
- The random pivot selection helps avoid worst-case scenarios (like sorted arrays).
