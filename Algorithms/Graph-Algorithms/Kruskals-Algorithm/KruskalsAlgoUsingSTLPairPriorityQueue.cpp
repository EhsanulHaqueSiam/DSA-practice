#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a union-find set.
struct UnionFind {
    vector<int> parent, rank;

    // Constructor to create a singleton set for each vertex.
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Function to find the representative of a set (with path compression).
    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    // Function to merge two sets (with union by rank).
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }

    // Sort the edges in non-decreasing order of weights.
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    int total_weight = 0;
    vector<pair<int, int>> mst;

    for (int i = 0; i < m; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        // If u and v belong to different sets...
        if (uf.find_set(u) != uf.find_set(v)) {
            // Add the edge to the MST.
            mst.push_back({u, v});
            total_weight += w;

            // Merge the sets of u and v.
            uf.union_sets(u, v);
        }
    }

    cout << "Total weight of MST: " << total_weight << '\n';
    cout << "Edges in the MST:\n";
    for (auto edge : mst) {
        cout << edge.first << " " << edge.second << '\n';
    }

    return 0;
}
/* 
This program reads the number of vertices and edges, then reads each edge as a pair of vertices and a weight. It then sorts the edges, initializes the union-find data structure, and applies Kruskal's algorithm, keeping track of the total weight of the minimum spanning tree and its edges.

Here's an example of input/output:

Input:
```
6
9
0 1 4
0 2 4
1 2 2
1 3 1
2 3 3
2 4 2
3 4 4
3 5 2
4 5 1
```

Output:
```
Total weight of MST: 10
Edges in the MST:
1 3
4 5
1 2
2 4
0 1
```

This means that the total weight of the minimum spanning tree is 8, and it consists of the edges (1-3), (4-5), (1-2), (2-4), and (0-1). */