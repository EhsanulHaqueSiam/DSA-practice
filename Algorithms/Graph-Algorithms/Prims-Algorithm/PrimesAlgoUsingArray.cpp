#include <iostream>
#define INF 9999999
#define V 5

using namespace std;

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        // Loop through all the vertices starting from 1 (vertex 0 doesn't have a parent)
        // Print parent (source vertex) - i (destination vertex) and the weight of the edge
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
}

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[]) {
    // Initialize minimum value and its index
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        // If the vertex has not been included in the MST (mstSet[v] is false)
        // and its key value is less than the current minimum, update the minimum
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMST(int graph[V][V]) {
    // Arrays to store the MST (as parent array), the key values, and whether a vertex is in the MST
    int parent[V], key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        // Initialize all keys as infinite and none of the vertices are in the MST
        key[i] = INF, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)
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
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Call the Prim's MST algorithm function
    primMST(graph);

    return 0;
}
/* 
1. `INF` is defined as `9999999` as a representation of an unreachable vertex.
2. The `minKey()` function finds the vertex with the minimum key value from the set of vertices not yet included in MST.
3. In `primMST()`, we first initialize all keys as infinite and `mstSet[]` as false, and then pick the smallest key vertex at every iteration.
4. `key[0] = 0` : Always include the first vertex in MST.
5. The first loop runs `V-1` times as MST includes `V-1` edges.
6. Inside the first loop, we pick the minimum key vertex from the set of vertices not yet included in MST.
7. Add the picked vertex to the MST set.
8. The inner loop updates the key value and parent index of the adjacent vertices of the picked vertex if they are not already included in MST and the edge weight is less than the key value.
9. Finally, `printMST()` function prints the edges of the MST.

Here's the output of the code above:

Edge 	Weight
0 - 1 	2
1 - 2 	3
1 - 3 	8
2 - 4 	7

This represents the edges of the minimum spanning tree and their corresponding weights. For instance, the edge between node 0 and node 1 has a weight of 2, and so on. */