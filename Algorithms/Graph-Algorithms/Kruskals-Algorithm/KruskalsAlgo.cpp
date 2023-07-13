#include<iostream>
using namespace std;

const int MAX = 1000;  // Maximum number of vertices or edges.

// Struct to represent a weighted edge in the graph.
struct Edge {
    int u, v, weight;  // u and v are the vertices, weight is the cost of the edge.
};

// Arrays to store the parent of each vertex and the rank of each set in the union-find data structure.
int parent[MAX], rankSet[MAX]; 

// Function to swap two edges.
void swapEdges(Edge& a, Edge& b) {
    Edge temp = a;
    a = b;
    b = temp;
}

// Function to create a singleton set for a vertex in the union-find data structure.
void make_set(int v) {
    parent[v] = v;  // Parent of v is v itself.
    rankSet[v] = 0;  // Since v is the only member of its set, its rank is 0.
}

// Function to find the representative of the set that a vertex belongs to (with path compression).
int find_set(int v) {
    if (v == parent[v])  // If v is the representative of its set.
        return v;
    // Otherwise, find the representative of v's parent, and store it as v's parent to implement path compression.
    return parent[v] = find_set(parent[v]);  
}

// Function to merge the sets that two vertices belong to (with union by rank).
void union_sets(int a, int b) {
    a = find_set(a);  // Find the representatives of the sets that a and b belong to.
    b = find_set(b);
    if (a != b) {  // If a and b are in different sets.
        // Make the representative of the smaller-ranked set point to the representative of the larger-ranked set.
        if (rankSet[a] < rankSet[b]) 
            swap(a, b);
        parent[b] = a;
        // If the sets that a and b belong to have the same rank, increment the rank of the new set.
        if (rankSet[a] == rankSet[b])
            rankSet[a]++;
    }
}

// Function to sort edges by weight in non-decreasing order using Bubble Sort.
void sort_edges(Edge edges[], int m) {
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < m-i-1; j++) {
            // If current edge is heavier than the next one, swap them.
            if (edges[j].weight > edges[j+1].weight)
                swapEdges(edges[j], edges[j+1]);
        }
    }
}

// Function to perform Kruskal's algorithm to find a minimum spanning tree.
void kruskal(Edge edges[], int n, int m, Edge result[]) {
    if(n <= 0 || m <= 0) { // If there are no vertices or edges, print an error message and exit.
        cout << "Invalid input!" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
        make_set(i);  // Create a singleton set for each vertex.

    sort_edges(edges, m);  // Sort the edges by weight.

    int cnt = 0;  // Counter for the number of edges included in the minimum spanning tree.
    for (int i = 0; i < m; i++) {
        Edge e = edges[i];  // Consider each edge in order of increasing weight.
        // If the vertices of the edge are in different sets (i.e., the edge doesn't form a cycle with the edges in the MST)...
        if (find_set(e.u) != find_set(e.v)) {
            // ...add the edge to the MST and merge the sets of its vertices.
            result[cnt++] = e;
            union_sets(e.u, e.v);
        }
    }
}

// Function to print the edges in a minimum spanning tree.
void printMST(Edge result[], int n) {
    if(n == 0) { // If the MST doesn't have any edges, print an error message and exit.
        cout << "No edges in the minimum spanning tree!" << endl;
        return;
    }

    // Print each edge in the MST.
    for (int i = 0; i < n; i++) {
        cout << result[i].u << " " << result[i].v << " " << result[i].weight << endl;
    }
}

// Main function
int main() {
    int n;  // Number of vertices
    cin >> n;

    int m;  // Number of edges
    cin >> m;

    // If the graph doesn't have enough edges to form a spanning tree, print an error message and exit.
    if(m < n-1) {
        cout << "Insufficient edges for creating a spanning tree!" << endl;
        return 1;
    }

    // Read the edges from the input.
    Edge edges[MAX];
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Array to store the edges in the minimum spanning tree.
    Edge result[MAX];

    // Perform Kruskal's algorithm to find the MST.
    kruskal(edges, n, m, result);

    // Print the edges in the MST.
    printMST(result, n-1);

    return 0;
}
