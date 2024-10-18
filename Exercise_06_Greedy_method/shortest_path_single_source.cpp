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