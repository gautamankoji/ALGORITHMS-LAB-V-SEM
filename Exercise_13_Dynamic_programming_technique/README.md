# EX 13: Implement Longest Common Subsequence Problem

The **Longest Common Subsequence (LCS) Problem** is a fundamental problem in computer science and bioinformatics. It involves finding the longest sequence that appears in the same relative order in both input strings, though not necessarily contiguously.

## Algorithm (Dynamic Programming Approach)

1. **Define a DP Table**: Create a 2D array `dp` where `dp[i][j]` represents the length of the LCS of the first `i` characters of the first string and the first `j` characters of the second string.
2. **Initialization**:
   - Set `dp[0][j] = 0` for all `j` since an empty string has no common subsequence.
   - Set `dp[i][0] = 0` for all `i` for the same reason.
3. **Filling the Table**:
   - If the characters of both strings match, update `dp[i][j] = dp[i-1][j-1] + 1`.
   - If the characters do not match, set `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
4. **Result**: The value of `dp[m][n]` gives the length of the LCS, where `m` and `n` are the lengths of the two strings.

### Code Implementation

Here’s a C++ implementation to solve the LCS problem:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int lcs(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << "Length of LCS: " << lcs(s1, s2) << endl;
    return 0;
}
```

### Output

```powershell
Length of LCS: 4
```

### Explanation

- **Initialization**: The `dp` array is initialized with zeros. Its size is `(m+1) x (n+1)` to accommodate base cases.
- **Filling the Table**:
  - When characters from both strings match (`s1[i-1] == s2[j-1]`), the length of the LCS up to that point increases by 1, using the value from `dp[i-1][j-1]`.
  - When characters do not match, the value at `dp[i][j]` is the maximum of excluding either character (`dp[i-1][j]` or `dp[i][j-1]`).
- **Result Extraction**: The final cell `dp[m][n]` contains the length of the LCS.

### Time Complexity

- **Time**: \(O(m \cdot n)\), where \(m\) and \(n\) are the lengths of the two strings.
- **Space**: \(O(m \cdot n)\), for the DP table.

### Applications

1. **DNA Sequence Analysis**: Finding similarities between gene sequences.
2. **Version Control Systems**: Comparing text files for changes.
3. **Plagiarism Detection**: Identifying common patterns in documents.
