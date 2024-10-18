# EX 01: Implement recursive binary search algorithm

### Algorithm

1. Set the low and high bounds of the search range.
2. Calculate the middle index.
3. Compare the middle element with the target:
   - If equal, return the index.
   - If less, search in the right half.
   - If greater, search in the left half.
4. If bounds cross, return -1 (element not found).

### Code

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return binarySearch(arr, mid + 1, high, target);
        else
            return binarySearch(arr, low, mid - 1, target);
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
```

### Output

```bash
Element found at index 4
```

### Explanation

- The function `binarySearch` takes an array, the low and high bounds, and the target value.
- It checks the middle element and recursively adjusts the search range until the target is found or the bounds cross.
