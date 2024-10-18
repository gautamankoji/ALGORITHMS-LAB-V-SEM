# EX 11: Implement sum of subsets

The **Subset Sum Problem** is a classic problem in computer science and combinatorial optimization. It involves finding all subsets of a given set of integers that sum to a specific target value. The problem can be solved using recursion and backtracking or dynamic programming.

### Algorithm (Backtracking Approach)

1. **Recursive Function**: Define a recursive function that explores including or excluding each number in the current subset.
2. **Base Cases**:
   - If the sum of the current subset equals the target, store the subset.
   - If the sum exceeds the target or if there are no more numbers to consider, return.
3. **Recursion**:
   - Include the current number in the subset and recurse with the remaining numbers.
   - Exclude the current number and recurse with the remaining numbers.

### Code Implementation

Here’s a C++ implementation to find all subsets of a given set that sum up to a target value:

```cpp
#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int>& arr, int target, vector<int>& current, int index) {
    if (target == 0) {
        cout << "{ ";
        for (int num : current) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }
    if (target < 0 || index == arr.size()) {
        return;
    }
    current.push_back(arr[index]);
    findSubsets(arr, target - arr[index], current, index + 1);
    current.pop_back();
    findSubsets(arr, target, current, index + 1);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    vector<int> current;

    cout << "Subsets with sum " << target << " are:\n";
    findSubsets(arr, target, current, 0);

    return 0;
}
```

### Output

```powershell
Subsets with sum 9 are:
{ 3 4 2 }
{ 4 5 }
```

### Explanation

- **Initialization**: The array `arr` contains the elements for which we want to find subsets. The `target` variable holds the desired sum.
- **findSubsets Function**:
  - This function takes the array, the remaining target sum, the current subset being built, and the current index.
  - **Base Case**: If the remaining target is 0, it means the current subset sums up to the original target. The subset is printed.
  - If the target becomes negative or the end of the array is reached, the function returns.
  - **Including/Excluding Logic**: The function first includes the current element in the subset and recurses, then backtracks by removing the element. It also recurses by excluding the current element to explore other combinations.
- **Time Complexity**: The time complexity is \(O(2^n)\) in the worst case since each element can either be included or excluded, leading to all possible subsets.

This implementation effectively finds all subsets of a given set that sum to a specified target, using a recursive backtracking approach.
