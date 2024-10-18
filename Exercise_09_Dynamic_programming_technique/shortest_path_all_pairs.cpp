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