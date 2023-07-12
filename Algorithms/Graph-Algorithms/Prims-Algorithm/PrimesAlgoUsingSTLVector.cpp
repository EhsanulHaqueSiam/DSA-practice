#include<bits/stdc++.h>
using namespace std;

#define INF 1000000 // Define a large value that will be used for initial key values and to find minimum value.

// Function to print the constructed Minimum Spanning Tree (MST).
void printMST(int V, vector<int> parent, vector<vector<int>> graph) {
    // V is the number of vertices, parent vector stores the MST, and graph holds the weights.
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) // We start from 1 because the first vertex (0) doesn't have a parent.
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n"; // Print the edge and its weight.
}

// Prim's Algorithm function.
void primMST(int V, vector<vector<int>> graph) {
    // V is the number of vertices and graph is the adjacency matrix representation of the graph.
    vector<int> key(V, INF);  // Key values used to pick minimum weight edge in cut.
    vector<int> parent(V, -1);  // Stores constructed MST, with parent[i] representing the parent of vertex i in the MST.
    vector<bool> inMST(V, false);  // To keep track of vertices included in MST.

    key[0] = 0; // Always include first vertex in MST. Setting its key value to 0 ensures that vertex 0 is picked first.

    // The MST will have V vertices, therefore, the following process will be iterated V times.
    for (int count = 0; count < V; count++) {
        // Pick the vertex which is not in MST and has the smallest key.
        int min = INF, u;  // u is the index of the vertex with the smallest key.
        for (int v = 0; v < V; v++)
            if (inMST[v] == false && key[v] < min) // If v is not in MST and key[v] is smaller than current minimum, update min and u.
                min = key[v], u = v;

        // Add the picked vertex to the MST set.
        inMST[u] = true;

        // For every vertex v adjacent to u.
        for (int v = 0; v < V; v++)
            // If v is not in MST and weight of u-v is smaller than key value of v, then update key value and parent of v.
            if (graph[u][v] && inMST[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST.
    printMST(V, parent, graph);
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
    int V = 5; // Number of vertices in the graph.
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0},
                                }; // Representation of the graph as an adjacency matrix.

    // Execute Prim's Algorithm on the graph.
    primMST(V, graph);

    return 0;
}
/* 
1. `#define INF 1000000` : We set a large value as infinity for initial distance setting.
2. `vector<int> key(V, INF)`: The key vector will hold the minimum weight edge in the cut. Initially, all keys are set to infinity.
3. `vector<int> parent(V, -1)`: The parent vector will store the resultant Minimum Spanning Tree.
4. `vector<bool> inMST(V, false)`: The inMST vector will keep track of vertices included in the MST. Initially, no vertices are included, so all values are false.
5. `key[0] = 0` : Always include the first vertex in MST.
6. The first loop runs `V-1` times as MST includes `V-1` edges.
7. Inside the first loop, we pick the minimum key vertex from the set of vertices not yet included in MST.
8. Add the picked vertex to the MST set.
9. The inner loop updates the key value and parent index of the adjacent vertices of the picked vertex if they are not already included in MST and the edge weight is less than the key value.
10. Finally, we print the edges and their corresponding weights in the MST.

Here's the output of the code above:

Edge 	Weight
0 - 1 	2
1 - 2 	3
1 - 3 	8
2 - 4 	7

This represents the edges of the minimum spanning tree and their corresponding weights. For instance, the edge between node 0 and node 1 has a weight of 2, and so on. */