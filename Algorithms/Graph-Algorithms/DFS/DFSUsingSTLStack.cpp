#include <iostream>
#include <stack>

using namespace std;

// Function to perform DFS on the graph
void DepthFirstSearch(int start_node, int adjacency_matrix[][8], int num_nodes) {
    // Initialize visit tracking array and stack
    bool visited_nodes[8] = {false}; // Array to keep track of visited nodes. Initialize all nodes as not visited.
    stack<int> node_stack; // Stack to keep track of nodes to visit
    node_stack.emplace(start_node); // Add the starting node to the stack
 
    // Visit start vertex start_node
    cout << start_node << ", " << flush; // Print the visited node
    visited_nodes[start_node] = true;  // Mark the node as visited
 
    // Initial Adjacent vertex
    int adjacent_node = 0; // Variable to iterate over all possible adjacent nodes
 
    // While there are nodes in the stack
    while (!node_stack.empty()){
        // Iterate over all possible adjacent nodes
        while (adjacent_node < num_nodes){
            // If there is an edge from start_node to adjacent_node and adjacent_node is not visited
            if (adjacency_matrix[start_node][adjacent_node] == 1 && !visited_nodes[adjacent_node]){
                node_stack.push(start_node); // Suspend exploring current vertex start_node and add it to the stack
                start_node = adjacent_node;  // Update current vertex as the next adjacent vertex
 
                // Visit current vertex start_node
                cout << start_node << ", " << flush; // Print the visited node
                visited_nodes[start_node] = true; // Mark the node as visited
                adjacent_node = -1;  // Set adjacent_node to -1 so that after incrementing it becomes 0
            }
            adjacent_node++; // Move to the next adjacent node
        }
        adjacent_node = start_node;  // Reset adjacent_node to the current node start_node
        start_node = node_stack.top();  // Return to previous suspended vertex
        node_stack.pop(); // Remove the top element from the stack
    }
}

// Simpler version of DFS
void SimpleDepthFirstSearch(int start_node, int adjacency_matrix[][8], int num_nodes){
    bool visited_nodes[8] = {false}; // Array to keep track of visited nodes. Initialize all nodes as not visited.
    stack<int> node_stack; // Stack to keep track of nodes to visit
    node_stack.emplace(start_node); // Add the starting node to the stack
 
    // While there are nodes in the stack
    while (!node_stack.empty()){
        start_node = node_stack.top(); // Get the top element from the stack
        node_stack.pop(); // Remove the top element from the stack
 
        // If the node is not visited
        if (!visited_nodes[start_node]){
            cout << start_node << ", " << flush; // Print the visited node
            visited_nodes[start_node] = true; // Mark the node as visited
 
            // Iterate over all possible adjacent nodes in reverse order
            for (int adjacent_node=num_nodes-1; adjacent_node>=0; adjacent_node--){
                // If there is an edge from start_node to adjacent_node and adjacent_node is not visited
                if (adjacency_matrix[start_node][adjacent_node] == 1 && !visited_nodes[adjacent_node]){
                    node_stack.emplace(adjacent_node); // Add the node to the stack
                }
            }
        }
    }
}

int main (){
    // Adjacency matrix representation of the graph
    int adjacency_matrix[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    int start_node = 5; // Starting node for DFS
    cout << "DFS Vertex: " << start_node << " -> " << flush;
    DepthFirstSearch(start_node, adjacency_matrix, 8); // Perform DFS
    cout << endl;
 
    cout << "dfs Vertex: " << start_node << " -> " << flush;
    SimpleDepthFirstSearch(start_node, adjacency_matrix, 8); // Perform DFS
    cout << endl;
 
    return 0;
}
