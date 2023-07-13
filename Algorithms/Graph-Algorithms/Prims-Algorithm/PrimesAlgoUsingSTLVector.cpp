#include<bits/stdc++.h>
using namespace std;

#define INF 1000000 // Define a large value that will be used for initial key values and to find minimum value.

// Define an Edge structure to hold source and destination vertices and the weight between them.
struct Edge {
    int source;
    int destination;
    int weight;
};

// Function to convert adjacency matrix into a list of Edge structures.
vector<Edge> convertToEdges(int V, vector<vector<int>> graph) {
    vector<Edge> edges;

    // Traverse the adjacency matrix.
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0) {
                edges.push_back(Edge{i, j, graph[i][j]}); // Create an Edge structure for each non-zero cell.
            }
        }
    }
    return edges;
}

// Function to print the constructed Minimum Spanning Tree (MST) and return the total minimum cost.
int printMST(int V, vector<int> parent, vector<vector<int>> graph) {
    cout << "Edge \tWeight\n";
    int totalMinCost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
        totalMinCost += graph[i][parent[i]]; // Add the weight of the current edge to the total minimum cost.
    }
    return totalMinCost; // Return the total minimum cost.
}

// Prim's Algorithm function.
void primMST(int V, vector<vector<int>> graph) {
    vector<int> key(V, INF); // Initialize key values for all vertices as infinity.
    vector<int> parent(V, -1); // Initialize parent array as -1 for all vertices.
    vector<bool> inMST(V, false); // Initialize MST set as empty for all vertices.

    key[0] = 0; // Start with the first vertex, so its key is set to 0.

    // Iterate V-1 times to build the MST (V-1 because MST has V-1 edges).
    for (int count = 0; count < V; count++) {
        int min = INF, u; // Variables to store the minimum key value and corresponding vertex.

        // Find the vertex with the minimum key value that is not yet included in MST.
        for (int v = 0; v < V; v++)
            if (inMST[v] == false && key[v] < min)
                min = key[v], u = v;

        inMST[u] = true; // Add the selected vertex to the MST set.

        // Update the key value and parent index of the adjacent vertices of the selected vertex.
        for (int v = 0; v < V; v++)
            if (graph[u][v] && inMST[v] == false && graph[u][v] < key[v]) {
                parent[v] = u; // Update the parent of vertex v.
                key[v] = graph[u][v]; // Update the key value of vertex v to the weight of the edge.
            }
    }

    // Calculate total minimum cost and print the constructed MST.
    int totalMinCost = printMST(V, parent, graph);
    cout << "Total minimum cost: " << totalMinCost << "\n";
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

    vector<Edge> edges = convertToEdges(V, graph); // Convert adjacency matrix into edge list.

    // Display the converted edges.
    cout << "Converted Edges:\n";
    for (const Edge& edge : edges) {
        cout << edge.source << " - " << edge.destination << " \t" << edge.weight << "\n";
    }

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

Converted Edges:
0 - 1   2       
0 - 3   6       
1 - 0   2       
1 - 2   3       
1 - 3   8       
1 - 4   5       
2 - 1   3       
2 - 4   7       
3 - 0   6       
3 - 1   8       
3 - 4   9
4 - 1   5
4 - 2   7
4 - 3   9
Edge    Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5
Total minimum cost: 16

This represents the edges of the minimum spanning tree and their corresponding weights. For instance, the edge between node 0 and node 1 has a weight of 2, and so on. */