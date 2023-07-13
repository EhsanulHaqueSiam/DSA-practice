#include<bits/stdc++.h>
using namespace std;
 
// Structure to represent a graph
struct Graph {
    int V;
    vector< pair<int, pair<int, int>> > edges;
 
    // Constructor
    Graph(int V) {
        this->V = V;
    }
 
    // Utility function to add an edge
    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }
 
    // Function to perform Prim's algorithm
    void primMST() {
        // Create a priority queue to store vertices that
        // are being preprocessed. This is weird syntax in C++.
        // Refer below link for details of this syntax
        // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
        priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

        int src = 0; // Taking vertex 0 as source
 
        // Create a vector for keys and initialize all
        // keys as infinite (INT_MAX)
        vector<int> key(V, INT_MAX);
 
        // To store parent array which in turn store MST
        vector<int> parent(V, -1);
 
        // To keep track of vertices included in MST
        vector<bool> inMST(V, false);
 
        // Insert source itself in priority queue and initialize
        // its key as 0.
        pq.push({0, src});
        key[src] = 0;
 
        /* Looping till priority queue becomes empty */
        while (!pq.empty()) {
            // The first vertex in pair is the minimum key
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted key (key must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();
 
            inMST[u] = true;  // Include vertex in MST
 
            // 'i' is used to get all adjacent vertices of a vertex
            for (auto x : edges) {
                // Get vertex label and weight of current adjacent
                // of u.
                int v = x.second.second;
                int weight = x.first;

                //  If v is not in MST and weight of (u,v) is smaller
                // than current key of v
                if (inMST[v] == false && key[v] > weight) {
                    // Updating key of v
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }
 
        // Print edges of MST using parent array
        for (int i = 1; i < V; ++i)
            printf("%d - %d\n", parent[i], i);
    }
};
 
// Driver program to test methods of graph class
int main() {
    int V = 5;
    Graph g(V);
 
    // add edge 0-1
    g.addEdge(0, 1, 2);
    // add edge 0-3
    g.addEdge(0, 3, 6);
    // add edge 1-2
    g.addEdge(1, 2, 3);
    // add edge 1-3
    g.addEdge(1, 3, 8);
    // add edge 1-4
    g.addEdge(1, 4, 5);
    // add edge 2-4
    g.addEdge(2, 4, 7);
    // add edge 3-4
    g.addEdge(3, 4, 9);
 
    g.primMST();
 
    return 0;
}

/* 
In this version:

- We create a `Graph` structure with an adjacency list `edges` and the number of vertices `V`.
- The `addEdge` function adds an edge to the graph.
- `primMST` is the function that implements Prim's algorithm to find the MST.
- Inside `primMST`, we create a priority queue to store vertices, a vector to store keys and initialize them to `INT_MAX`, a vector to store the parent of each vertex, and a boolean vector to keep track of vertices included in MST.
- We start from vertex 0, so we insert it into the priority queue and set its key to 0.
- While the queue is not empty, we keep extracting the top element, which is the vertex with the smallest key. We then include this vertex in the MST.
- For each edge, if one endpoint is in the MST and the other is not, and if the weight of the edge is less than the current key of the endpoint not in the MST, we update the key of this endpoint and insert it into the queue.
- Finally, we print the MST by listing the edges.
- The `main` function creates the graph and calls `primMST` to find and print the MST. */