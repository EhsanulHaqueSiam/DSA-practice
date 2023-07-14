#include <iostream>
#include <queue>
#include <vector>

// Function to perform BFS
void BFS(const std::vector<std::vector<int>>& graph, int start)
{
    int V = graph.size();
    std::vector<bool> visited(V, false);
    std::queue<int> queue;

    visited[start] = true;
    queue.push(start);

    while(!queue.empty())
    {
        start = queue.front();
        std::cout << start << " ";
        queue.pop();

        for(int i = 0; i < V; ++i)
        {
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
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
    };

    std::cout << "Following is Breadth First Traversal "
              << "(starting from vertex 2) \n";
    BFS(graph, 2);

    return 0;
}
