#include<bits/stdc++.h>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Prim's Algorithm function
void primMST(vector<pair<int,int>> adj[], int V) {
    // Create a priority queue to store vertices that
    // are being preprocessed.
    priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;

    // Create a vector for keys and initialize all
    // keys as infinite (INT_MAX)
    vector<int> key(V, INT_MAX);

    // To store parent array which in turn store MST
    vector<int> parent(V, -1);

    // Insert source itself in priority queue and initialize
    // its key as 0.
    key[0] = 0;
    pq.push(make_pair(0, 0)); // Insert vertex 0 as source with weight 0

    /* Looping till priority queue becomes empty */
    while (!pq.empty()) {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        int u = pq.top().second;
        pq.pop();

        // Include extracted vertex to MST
        for (auto x : adj[u]) {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = x.first;
            int weight = x.second;

            // If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (key[v] > weight) {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Print edges of MST
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

// Driver code
int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    // Adding edges
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);

    // Call the Prim's Algorithm
    primMST(adj, V);

    return 0;
}
/* 
In this implementation:

- `addEdge` is a function that adds an edge to the adjacency list representation of the graph.
- `primMST` is the function that implements Prim's algorithm to find the MST.
- Inside `primMST`, a priority queue is used to select the next vertex to add to the MST. The priority queue orders its elements by their weights, which allows us to efficiently select the smallest edge to add to the MST.
- We start from vertex 0, so we push it to the priority queue with a weight of 0.
- While the queue is not empty, we keep removing the top element, getting the vertex number from the second part of the pair. We then go through all the adjacent vertices of the extracted vertex, and for every adjacent vertex v, if its weight is less than the current key value, we update the key value and add it to the priority queue.
- Finally, we print the MST by listing the edges.
- The `main` function creates the adjacency list representation of the graph and calls `primMST` to find and print the MST. */