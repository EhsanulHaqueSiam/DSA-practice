#include <iostream>
#include <queue>

using namespace std;

#define V 5  // Number of vertices

// Function to perform BFS
void BFS(int graph[V][V], int start)
{
    // Boolean array visited[] which stores whether
    // the vertex 'v' is visited or not
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push(start);

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        start = queue.front();
        cout << start << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex s.
        // If an adjacent vertex has not been visited,
        // then mark it visited and enqueue it
        for(int i = 0; i < V; ++i)
        {
            // Check for edge and if it is not visited
            if(graph[start][i] && !visited[i])
            {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}

// Driver program to test BFS function
int main()
{
    // Create a graph given in the form of adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
    };

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    BFS(graph, 2);

    return 0;
}
