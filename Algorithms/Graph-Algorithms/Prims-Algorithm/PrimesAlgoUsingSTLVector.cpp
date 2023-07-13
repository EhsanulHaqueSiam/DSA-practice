#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(vector<int> key, vector<bool> mstSet) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < key.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(vector<int> parent, vector<vector<int>> graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(vector<vector<int>> graph) {
    // Create a vector for keys and initialize all keys as infinite (INT_MAX)
    vector<int> key(graph.size(), INT_MAX);

    // To store constructed MST
    vector<int> parent(graph.size(), -1);

    // mstSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    vector<bool> mstSet(graph.size(), false);

    // Always include first 1st vertex in MST.
    key[0] = 0;

    // The MST will have graph.size() vertices
    for (int count = 0; count < graph.size()-1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex. 
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < graph.size(); v++)
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, graph);
}

int main() {
    /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0}};

    // Print the solution
    primMST(graph);

    return 0;
}

/* 
In this code:

- `minKey` is a function that finds the vertex with the minimum key value from the vertices not yet included in the MST.
- `printMST` is a function to print the constructed MST.
- `primMST` is the function that constructs and prints the MST for a graph represented using the adjacency matrix.
- Inside `primMST`, we initialize a vector for keys and all keys as infinite (INT_MAX), a vector to store the constructed MST, and a boolean vector to keep track of vertices included in MST. We always include the first vertex in the MST, then for each vertex, we pick the minimum key vertex from the set of vertices not yet included in MST and update key value and parent index of the adjacent vertices of the picked vertex.
- Finally, the constructed MST is printed.
- The `main` function defines a graph as a 2D vector (adjacency matrix), and calls `primMST` to find and print the MST. */