# EX 06: Find the shortest path using single source shortest path algorithm

To find the shortest path from a single source to all other vertices in a weighted graph, we can use Dijkstra's algorithm. This algorithm is particularly efficient for graphs with non-negative weights.

### Dijkstra's Algorithm Overview

1. **Initialization**:
   - Set the distance to the source node to 0 and all other nodes to infinity.
   - Create a priority queue (or a min-heap) to store vertices based on their current distance.

2. **Process the Graph**:
   - While the priority queue is not empty, extract the vertex with the smallest distance.
   - For each neighboring vertex, calculate the tentative distance through the current vertex.
   - If this tentative distance is less than the currently known distance, update the shortest distance and add the neighbor to the priority queue.

3. **Termination**:
   - When all vertices have been processed, the distances will represent the shortest paths from the source to each vertex.

### Code Implementation

Here's a C++ implementation of Dijkstra's algorithm:

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int source, const vector<vector<pii>>& graph, vector<int>& distances) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    distances[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        int currDistance = pq.top().first;
        int currVertex = pq.top().second;
        pq.pop();
        for (const auto& neighbor : graph[currVertex]) {
            int nextVertex = neighbor.first;
            int edgeWeight = neighbor.second;
            if (currDistance + edgeWeight < distances[nextVertex]) {
                distances[nextVertex] = currDistance + edgeWeight;
                pq.push({distances[nextVertex], nextVertex});
            }
        }
    }
}

int main() {
    int vertices = 5;
    vector<vector<pii>> graph(vertices);
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({0, 7});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});
    vector<int> distances(vertices, INT_MAX);
    int source = 0;
    dijkstra(source, graph, distances);
    cout << "Vertex Distance from Source (" << source << "):\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Distance to vertex " << i << " is " << distances[i] << endl;
    }
    return 0;
}
```

### Output

```bash
Vertex Distance from Source (0):
Distance to vertex 0 is 0
Distance to vertex 1 is 8
Distance to vertex 2 is 9
Distance to vertex 3 is 7
Distance to vertex 4 is 5
```

### Explanation

- The graph is represented using an adjacency list where each vertex points to a list of pairs representing its neighbors and the corresponding edge weights.
- The `dijkstra` function initializes the distance to the source as 0 and all other distances as infinity.
- It uses a priority queue to efficiently retrieve the next vertex with the smallest distance.
- The algorithm updates the shortest distances and outputs the final shortest distances from the source vertex to all other vertices.
