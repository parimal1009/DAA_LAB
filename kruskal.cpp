#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

// Compare edges by weight for sorting
bool compareEdge(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Union-Find Data Structure
class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find function with path compression
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union function with union by rank
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal’s algorithm function
vector<Edge> kruskalMST(int V, vector<Edge>& edges) {
    vector<Edge> result;  // To store the resultant MST
    UnionFind uf(V);

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdge);

    // Iterate through edges and add to the MST if they don’t form a cycle
    for (auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        // Check if including this edge creates a cycle
        if (uf.find(u) != uf.find(v)) {
            result.push_back(edge);  // Include this edge in MST
            uf.unionSets(u, v);      // Union the sets
        }
    }

    return result;
}

int main() {
    int V = 4;  // Number of vertices in graph
    vector<Edge> edges;

    // Add edges (src, dest, weight)
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    vector<Edge> mst = kruskalMST(V, edges);

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
