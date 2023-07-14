#include <iostream>
using namespace std;

// Function to perform DFS on the graph
void DepthFirstSearch(int current_node, int (&adjacency_matrix)[8][8], int num_nodes){
    // Static array to keep track of visited nodes. Initialize all nodes as not visited.
    // It's static because it should retain its value between function calls.
    static bool visited_nodes[8] = {false};
 
    // If the current node is not visited
    if (!visited_nodes[current_node]){
        cout << current_node << ", " << flush; // Print the visited node
        visited_nodes[current_node] = true; // Mark the node as visited

        // Iterate over all possible adjacent nodes
        for (int adjacent_node=1; adjacent_node<num_nodes; adjacent_node++){
            // If there is an edge from current_node to adjacent_node and adjacent_node is not visited
            if (adjacency_matrix[current_node][adjacent_node] == 1 && !visited_nodes[adjacent_node]){
                DepthFirstSearch(adjacent_node, adjacency_matrix, num_nodes); // Recursively call DFS for the adjacent node
            }
        }
    }
}
 
int main (){
    // Adjacency matrix representation of the graph
    int adjacency_matrix[8][8] = 
                  {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 4 -> " << flush;
    DepthFirstSearch(4, adjacency_matrix, 8); // Perform DFS starting from node 4
    cout << endl;
 
    return 0;
}
