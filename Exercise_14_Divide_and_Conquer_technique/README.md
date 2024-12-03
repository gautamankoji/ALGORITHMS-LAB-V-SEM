# EX 14: Implement Heap Sort Technique

The **Heap Sort Technique** is a popular sorting algorithm that uses a binary heap data structure. It is an in-place, comparison-based algorithm with \(O(n \log n)\) time complexity.

## Algorithm (Heap Sort)

1. **Heapify**: Rearrange the array into a max-heap where the largest element is at the root.
2. **Extract Elements**: Swap the root of the heap with the last element and reduce the size of the heap. Reapply the heapify process to maintain the heap property.
3. **Repeat**: Continue extracting elements until the heap is empty.

### Code Implementation

Here’s a C++ implementation of the Heap Sort algorithm:

```cpp
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {9, 4, 3, 8, 10, 2, 5};
    heapSort(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}
```

### Output

```powershell
2 3 4 5 8 9 10
```

### Explanation

- **Heapify Function**:
  - This ensures the subtree rooted at any index maintains the max-heap property.
  - Recursively adjusts elements to position the largest at the root.
- **Heap Sort Function**:
  - First, the array is converted into a max-heap.
  - Then, the root (largest element) is swapped with the last element, and the heap size is reduced by one.
  - The heapify process is repeated to maintain the heap property after each extraction.
- **Final Sorted Array**: As elements are extracted from the heap, they are placed in sorted order from the end of the array to the beginning.

### Time Complexity

- **Heap Construction**: \(O(n)\)
- **Heapify Operations**: \(O(\log n)\) for each extraction.
- **Total**: \(O(n \log n)\)

### Space Complexity

- **In-place**: Requires \(O(1)\) auxiliary space.

### Applications

1. **Priority Queues**: Often used to implement priority queues.
2. **Job Scheduling**: Organizing tasks by priority.
3. **K Largest Elements**: Efficiently finding the largest \(k\) elements in an array.
