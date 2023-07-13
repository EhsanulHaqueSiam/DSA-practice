#include<bits/stdc++.h>
using namespace std;

// structure to represent edges
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

// data structure to store union-find information
vector<int> parent, rank_vec; // renamed 'rank' to 'rank_vec'

// function to initialize union-find
void make_set(int v) {
    parent[v] = v;
    rank_vec[v] = 0; // use 'rank_vec'
}

// function to find the root of a set (with path compression)
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);  // path compression
}

// function to union two sets (with union by rank)
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_vec[a] < rank_vec[b]) // use 'rank_vec'
            swap(a, b);
        parent[b] = a;
        if (rank_vec[a] == rank_vec[b]) // use 'rank_vec'
            rank_vec[a]++; // use 'rank_vec'
    }
}

// function to perform Kruskal's algorithm
vector<Edge> kruskal(vector<Edge>& edges, int n) {
    if(n <= 0 || edges.empty()) {
        cout << "Invalid input!" << endl;
        return vector<Edge>();
    }

    // create set for each vertex
    for (int i = 0; i < n; i++)
        make_set(i);

    // sort edges by weight
    sort(edges.begin(), edges.end());

    // edges in minimum spanning tree
    vector<Edge> result;
    result.reserve(n);  // optimization: reserve space for n edges

    // for each edge, in increasing weight order...
    for (Edge e : edges) {
        // if the edge endpoints are not in the same connected component...
        if (find_set(e.u) != find_set(e.v)) {
            // ...add the edge to the MST
            result.push_back(e);
            // and merge the components
            union_sets(e.u, e.v);
        }
    }

    return result;
}

// function to print the minimum spanning tree
void printMST(const vector<Edge>& result) {
    if(result.empty()) {
        cout << "No edges in the minimum spanning tree!" << endl;
        return;
    }

    // print the edges in the minimum spanning tree
    for (Edge e : result) {
        cout << e.u << " " << e.v << " " << e.weight << endl;
    }
}

int main() {
    int n; // number of vertices
    cin >> n;

    // resize parent and rank_vec arrays
    parent.resize(n);
    rank_vec.resize(n); // use 'rank_vec'

    int m; // number of edges
    cin >> m;

    if(m < n-1) {
        cout << "Insufficient edges for creating a spanning tree!" << endl;
        return 1;  // error exit
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // get the edges in the minimum spanning tree
    vector<Edge> result = kruskal(edges, n);

    // print the minimum spanning tree
    printMST(result);

    return 0;
}
