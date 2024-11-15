#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/* The function `primsAlgorithm` implements Prim's algorithm for finding the Minimum Spanning Tree
(MST) of a graph. Here's a breakdown of what the function does: */
void primsAlgorithm(int V, vector<pair<int, int>> adj[], int src) {
    vector<int> key(V, INT_MAX);  // To store the minimum weight edge connected to a vertex
    vector<int> parent(V, -1);    // To store the MST
    vector<bool> inMST(V, false); // To track vertices included in the MST

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[src] = 0;
    pq.push({0, src}); // Starting with the source node

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true; // Include vertex in the MST

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            // If v is not in MST and the weight of (u,v) is smaller than the current key of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
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

    primsAlgorithm(V, adj, src);

    return 0;
}
// Enter the number of vertices: 5
// Enter the number of edges: 6
// Enter the edges (u v w) where u and v are vertices (0-indexed) and w is the weight:
// 0 1 9
// 0 2 6
// 0 3 5
// 0 4 3
// 2 1 2
// 2 3 4
// Enter the source vertex: 0
