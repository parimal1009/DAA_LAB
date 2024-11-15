#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/* The function `dijkstraAlgorithm` implements Dijkstra's algorithm for finding the shortest paths
from a source vertex to all other vertices in a graph with non-negative weights. */
void dijkstraAlgorithm(int V, vector<pair<int, int>> adj[], int src) {
    vector<int> dist(V, INT_MAX);  // To store the shortest distance from the source to each vertex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src}); // Starting with the source node

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Explore all adjacent vertices of u
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            // If the path through u offers a shorter path to v, update dist[v]
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source to each vertex
    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int V, E;
    
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<pair<int, int>> adj[V];

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v w) where u and v are vertices (0-indexed) and w is the weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstraAlgorithm(V, adj, src);

    return 0;
}


// Enter the number of vertices: 5
// Enter the number of edges: 6
// Enter the edges (u v w) where u and v are vertices (0-indexed) and w is the weight:
// 0 1 4
// 0 2 1
// 1 2 2
// 1 3 5
// 2 3 8
// 3 4 3
// Enter the source vertex: 0
