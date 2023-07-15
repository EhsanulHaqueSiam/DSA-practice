# [Prim's Algorithm: A Deep Dive](#prims-algorithm-a-deep-dive)

Prim's algorithm, named after its creator Robert C. Prim, is an efficient algorithm for finding the minimum spanning tree (MST) of a weighted undirected graph. The minimum spanning tree of a graph is a tree composed of all the vertices of the graph such that the total weight of the edges is minimized. Prim's algorithm is widely used in network design, where it helps to minimize the total cost of laying out networks.

# [Table of Contents](#prims-algorithm-a-deep-dive)

- [Prim's Algorithm: A Deep Dive](#prims-algorithm-a-deep-dive)
  - [How Prim's Algorithm Works](#how-prims-algorithm-works)
  - [Understanding Prim's Algorithm Through a GIF](#understanding-prims-algorithm-through-a-gif)
  - [Detailed Explanation of Prim's Algorithm](#detailed-explanation-of-prims-algorithm)
  - [Code Breakdown](#code-breakdown)
  - [Optimizing Prim's Algorithm](#optimizing-prims-algorithm)
  - [Related Algorithms](#related-algorithms)
  - [Final Note](#final-note)
- [Useful Sites](#useful-sites)
  - [Articles](#articles)
  - [Visualizers](#visualizers)

## [How Prim's Algorithm Works](#table-of-contents)

Prim's algorithm operates by continuously adding the nearest unvisited vertex to the already visited vertices, gradually growing the MST. This is a classic example of a greedy algorithm, where the optimum solution is built by making the optimal choice at each stage. Here's a step-by-step breakdown of the algorithm:

1. **Initialization:** Select an arbitrary vertex from the graph to be the starting point. Initialize a tree with this single vertex.

2. **Growing the Tree:** Out of the edges that connect the vertices already in the tree to vertices outside the tree, select the edge with the smallest weight and add it to the tree.

3. **Repeating the Process:** Repeat step 2 until all vertices are included in the tree.

## [Understanding Prim's Algorithm Through a GIF](#table-of-contents)

![Prim's Algorithm](https://upload.wikimedia.org/wikipedia/en/9/96/Prim-animation.gif)

Prim's algorithm is a greedy algorithm used to find the minimum spanning tree for a weighted, undirected graph. This means it constructs a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

The provided GIF is an excellent visual representation of how Prim's algorithm works. The algorithm starts from a single node, colored red, and grows the spanning tree by adding the smallest edge that connects the tree to a node not yet in the tree. This process is repeated until all nodes are included in the tree, resulting in a tree with the minimum total edge weight possible.

The GIF uses different colors to represent different states of nodes and edges:

- **Red**: The starting node.
- **Blue**: Nodes that have been added to the tree.
- **Green**: The current edge being considered.
- **Yellow**: Nodes that are connected to the tree but not yet included in it.
- **White**: Nodes that are not yet connected to the tree.

The numbers on the edges represent their weights. The algorithm always picks the edge with the smallest weight that doesn't form a cycle. Through this process, Prim's algorithm ensures the creation of a minimum spanning tree for a given graph.

## [Detailed Explanation of Prim's Algorithm](#table-of-contents)

To understand Prim's algorithm's process, let's break it down into several detailed steps using a sample graph:

![sample graph](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c9/Multiple_minimum_spanning_trees.svg/300px-Multiple_minimum_spanning_trees.svg.png)

Starting at any arbitrary node (let's choose 'A'), we perform the following:

1. **Step 1:** At the beginning, we only have one node (A) in our MST. The available edges from this node are {A-B, A-C, A-D}. The minimum weight among these edges is 1 (A-B), so we select this edge and add it to our MST. Now our MST has nodes {A, B}.

2. **Step 2:** Next, we have additional edges {B-C, B-D, B-E} to consider, in addition to the original edges from node A {A-C, A-D}. The smallest edge now is 2 (B-C), which we add to the MST. Our MST now has nodes {A, B, C}.

3. **Step 3:** The cycle continues. We now consider the following edges: {B-D, B-E, A-D, C-E, C-F}. The smallest weight is 3 (C-E). So, we select the edge C-E and add it to our MST. Now, the MST has nodes {A, B, C, E}.

4. **Step 4:** The process repeats until all the nodes are included in the MST. The resulting MST will be the tree that connects all nodes with the minimum total weight.

Through this detailed example, we see how Prim's algorithm gradually constructs the MST by continuously choosing the smallest edge connected to the existing MST.

Let's visualize this process with a simple example:

Consider the following weighted graph:

```
        1
    A ---- B
    | \    |
  2 |  \1  | 3
    |    \ |
    C ---- D
        4
```

Here's how Prim's algorithm would create the MST:

- Start at vertex `A`.
- The smallest edge connected to `A` is `A-D`. Add `A-D` to the MST.
- The smallest edge connected to `A` or `D` is `A-B`. Add `A-B` to the MST.
- The smallest edge connected to `A`, `B`, or `D` is `A-C`. Add `A-C` to the MST.
- All vertices are now included in the MST. The MST is `A-D`, `A-B`, `A-C`.

## [Code Breakdown](#table-of-contents)

Here's a high-level overview of the code for Prim's algorithm using an adjacency matrix representation of the graph.

```cpp

#define INF 9999999
#define V 5

void printMST(int parent[], int graph[V][V]);
int minKey(int key[], bool mstSet[]);

void primMST(int graph[V][V]) {
    // Arrays to store the MST (as parent array), the key values, and whether a vertex is in the MST
    int parent[V], key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        // Initialize all keys as infinite and none of the vertices are in the MST
        key[i] = INF;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST.
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        // Pick the vertex with the minimum key value from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        // Loop through all the vertices starting from 1 (vertex 0 doesn't have a parent)
        // Print parent (source vertex) - i (destination vertex) and the weight of the edge
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
    }
}

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    // Initialize the minimum value and its index
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        // If the vertex has not been included in the MST (mstSet[v] is false)
        // and its key value is less than the current minimum, update the minimum
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}
```

This code has a time complexity of O(V^2), where V is the number of vertices.

## [Optimizing Prim's Algorithm](#table-of-contents)

The time complexity of Prim's algorithm can be improved to O(E log V), where E is the number of edges, by using an adjacency list representation of the graph along with a binary heap or Fibonacci heap.

1. **Priority Queue:** A priority queue is an abstract data type that operates similar to a queue and every element has some priority value associated with it. The priority of the elements in a priority queue determines the deletion order. The element with the highest priority is deleted first. Thus, we can use a priority queue to quickly extract the vertex with the minimum key value.

2. **Binary Heap:** Instead of using an adjacency matrix, we can use an adjacency list and binary heap. In each step, we don't have to traverse all vertices to find the minimum key value, but we can extract the minimum value from the binary heap in O(log V) time. When a key value is decreased, we can decrease the key in the binary heap in O(log V) time using decrease-key operation. So the overall time complexity becomes O(E log V).

3. **Fibonacci Heap:** We can further optimize the algorithm by using a Fibonacci heap instead of a binary heap. The time complexity of extract-min operation in Fibonacci heap is O(log V), but the time complexity of decrease-key operation is O(1). So, the overall time complexity using adjacency list representation and Fibonacci heap becomes O(E + V log V).

## [Related Algorithms](#table-of-contents)

Prim's algorithm is not the only algorithm to find the MST of a graph. Some related algorithms include:

1. **Kruskal's Algorithm:** In Kruskal’s algorithm, we sort all the edges from low weight to high and iteratively add edges to the MST, but we skip those edges which create a cycle in MST. This is different from Prim's because it doesn't start from a specific vertex. Instead, it can start by picking the smallest weight edge first.

2. **Boruvka’s Algorithm:** In Boruvka’s algorithm, we start by treating each vertex as a separate component of the MST. We then iterate over all edges and for each edge connecting two components, we add the edge with the minimum weight to the MST and merge the two components. This process continues until we have a single component that is the MST.

3. **Dijkstra's Algorithm:** Dijkstra's algorithm is similar to Prim's algorithm in the sense that they both form a tree, but Dijkstra's algorithm forms a shortest-path tree from a single source node, meaning it finds the shortest path from the given source node to all other nodes in the graph. In contrast, Prim’s algorithm constructs an MST, which means it finds a subset of the edges that form a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

Each of these algorithms, including Prim's, have their use cases. The choice of which algorithm to use depends on the nature of the problem and the specific characteristics of the graph.

## [Final Note](#table-of-contents)

Prim's algorithm is a robust and intuitive method for finding the minimum spanning tree of a weighted undirected graph. It's a powerful tool in fields such as computer networking, network design, civil engineering, computer graphics, and more, where minimal connection strategies are crucial for efficiency. By understanding its mechanism and how to optimize it, one can significantly improve the speed and performance of network-related tasks.

## [Useful Sites](#table-of-contents)
### [Articles](#table-of-contents)
- [GeeksforGeeks - Prim's Minimum Spanning Tree (MST) | Greedy Algo](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)
- [CP-Algorithms - MST: Prim's Algorithm](https://cp-algorithms.com/graph/mst_prim.html#sparse-graphs-om-log-n)
- [JavaTpoint - Prim's Algorithm](https://www.javatpoint.com/prim-algorithm)
- [Simplilearn - Prim's Algorithm Tutorial](https://www.simplilearn.com/tutorials/data-structure-tutorial/prims-algorithm)
- [Gate Vidyalay - Prim's Algorithm with an Example](https://www.gatevidyalay.com/prims-algorithm-prim-algorithm-example/)
- [Scanftree - Prim's Algorithm](https://scanftree.com/Data_Structure/prim's-algorithm)
- [Wikipedia - Prim's algorithm](https://en.wikipedia.org/wiki/Prim%27s_algorithm)

### [Visualizers](#table-of-contents)
- [Algorithm Visualizer - Prim's Minimum Spanning Tree](https://algorithm-visualizer.org/greedy/prims-minimum-spanning-tree)
- [USFCA - Prim's Algorithm Visualization](https://www.cs.usfca.edu/~galles/visualization/Prim.html)
- [VisuAlgo - Minimum Spanning Tree (Prim's Algorithm)](https://visualgo.net/en/mst)
