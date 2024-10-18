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