# EX 09: Find the shortest path using all pairs shortest path algorithm

The All-Pairs Shortest Path (APSP) problem aims to find the shortest paths between all pairs of vertices in a weighted graph. The Floyd-Warshall algorithm is a well-known method to solve this problem efficiently.

### Algorithm (Floyd-Warshall Algorithm)

1. **Initialization**:
   - Create a distance matrix `dist` where `dist[i][j]` is initialized to the weight of the edge between vertices `i` and `j`. If there is no edge, set it to infinity (or a large number).
   - Set the diagonal `dist[i][i]` to 0, as the distance from any vertex to itself is zero.

2. **Relaxation**:
   - For each vertex `k`, update the distance matrix:
     - For each pair of vertices `(i, j)`, update `dist[i][j]` as follows:
       \[
       dist[i][j] = \min(dist[i][j], dist[i][k] + dist[k][j])
       \]
   - This step checks whether the path from vertex `i` to vertex `j` can be shortened by going through vertex `k`.

3. **Result**: After processing all vertices, `dist[i][j]` will contain the shortest distance from vertex `i` to vertex `j`.

### Code Implementation

Here’s a C++ implementation of the Floyd-Warshall algorithm:

```cpp
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1e9;

void floydWarshall(int V, vector<vector<int>>& dist) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void printSolution(int V, const vector<vector<int>>& dist) {
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << setw(3) << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }
    dist[0][1] = 5; 
    dist[0][3] = 10; 
    dist[1][2] = 3; 
    dist[2][3] = 1; 
    floydWarshall(V, dist);
    printSolution(V, dist);
    return 0;
}
```

### Output

```bash
Shortest distances between every pair of vertices:
  0   5   8   9 
INF   0   3   4 
INF INF   0   1 
INF INF INF   0 
```

### Explanation

- **Initialization**: The distance matrix is set up with infinite distances, except for the diagonal which is set to zero.
- **Floyd-Warshall Function**: This function iterates through each vertex `k` and checks every pair of vertices `(i, j)` to see if a shorter path exists through `k`. If a shorter path is found, it updates the distance matrix accordingly.
- **Print Solution**: This function formats and prints the distance matrix. It displays "INF" for unreachable pairs.
- **Time Complexity**: The algorithm runs in \(O(V^3)\), making it efficient for small to medium-sized graphs.

This implementation effectively computes the shortest paths between all pairs of vertices in a weighted graph using the Floyd-Warshall algorithm.
