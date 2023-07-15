# [Kruskal's Algorithm: A Deep Dive](#kruskals-algorithm-a-deep-dive)

In the realm of computer science and algorithms, Kruskal's Algorithm carves its niche as an efficient procedure to solve one of the most common problems in graph theory – finding the Minimum Spanning Tree (MST) of a connected, undirected graph. Conceptualized and introduced by Joseph Kruskal in 1956, this algorithm provides a greedy solution to the MST problem, paving the way for more efficient network design and connectivity-related tasks.

# [Table of Contents](#table-of-contents)

- [Introduction](#kruskals-algorithm-a-deep-dive)
- [How Kruskal's Algorithm Works](#how-kruskals-algorithm-works)
- [Understanding Kruskal's Algorithm Through GIFs](#understanding-kruskals-algorithm-through-gifs)
    - [GIF 1: Basic Kruskal's Algorithm](#gif-1-basic-kruskals-algorithm)
    - [GIF 2: Detailed Kruskal's Algorithm](#gif-2-detailed-kruskals-algorithm)
    - [GIF 3: Kruskal's Algorithm with Animation](#gif-3-kruskals-algorithm-with-animation)
- [Detailed Explanation of Kruskal's Algorithm](#detailed-explanation-of-kruskals-algorithm)
- [Code Breakdown: Dissecting Kruskal's Algorithm in C++](#code-breakdown-dissecting-kruskals-algorithm-in-c)
  - [Edge Structure](#structural-entities-and-universal-variables)
  - [Union-Find Data Structure](#union-find-data-structure)
  - [Edge Sorting](#edge-sorting)
  - [Implementing Kruskal's Algorithm](#implementing-kruskals-algorithm)
  - [Outputting the Minimum Spanning Tree](#outputting-the-minimum-spanning-tree)
  - [Main Function](#main-function)
- [Optimizing Kruskal's Algorithm](#optimizing-kruskals-algorithm)
- [Related Algorithms](#related-algorithms)
- [Final Note](#final-note)
- [Useful Sites](#useful-sites)
  - [Articles](#articles)
  - [Visualizers](#visualizers)


# [How Kruskal's Algorithm Works](#table-of-contents)

At its core, Kruskal's algorithm revolves around a very logical and greedy strategy. The algorithm sorts all the graph's edges in non-decreasing order of their weights. It then traverses these sorted edges, iteratively adding the smallest edge that doesn't cause a cycle within the edges already included in the MST.

This procedure is continued until the MST has (V-1) edges, where V is the total number of vertices in the graph. While the algorithm functions assuming all the edges have distinct weights, it is versatile and can be modified to handle graphs where multiple edges share the same weight.

# [Understanding Kruskal's Algorithm Through GIFs](#table-of-contents)

Visual learning aids can significantly enhance understanding, and a series of GIFs illustrating the process of Kruskal's algorithm is no exception. This algorithm, named after its creator Joseph Kruskal, is a popular method used in computer science to find the minimum spanning tree (MST) for a connected weighted graph. This means it finds a tree (a subset of the graph's edges) that includes every vertex and has the smallest possible total weight.

### GIF 1: Basic Kruskal's Algorithm

![Kruskal Algorithm GIF](https://upload.wikimedia.org/wikipedia/commons/b/bb/KruskalDemo.gif)

The first GIF provides a basic demonstration of Kruskal's algorithm. The process begins with an empty spanning tree. The edges are analyzed one by one, following the sequence of their weights, ascending from lowest to highest. If a particular edge creates a cycle within the MST formed up to that point, it's excluded. Otherwise, it's added to the MST. The GIF shows this process in a clear and concise manner, making it easier to understand the algorithm's steps.

### GIF 2: Detailed Kruskal's Algorithm

![Kruskal Algorithm GIF](https://upload.wikimedia.org/wikipedia/commons/5/5c/MST_kruskal_en.gif)

The second GIF provides a more detailed view of the algorithm. It shows the same process as the first GIF but with additional information. Each step of the algorithm is clearly labeled, and the current state of the MST is shown after each step. This GIF is particularly useful for those who want a more in-depth understanding of the algorithm.

### GIF 3: Kruskal's Algorithm with Animation

![Kruskal Algorithm GIF](https://thealgoristsblob.blob.core.windows.net/thealgoristsimages/kruskals-algorithm-anim-1.gif)

The third GIF adds an animated element to the demonstration. It shows the algorithm in action, with each step animated to show the process of adding edges to the MST. This GIF is particularly useful for visual learners, as it provides a dynamic view of the algorithm in action.

In conclusion, these GIFs provide a comprehensive view of Kruskal's algorithm, from its basic steps to a more detailed and animated demonstration. By studying these GIFs, one can gain a deeper understanding of this important algorithm in computer science.

# [Detailed Explanation of Kruskal's Algorithm](#table-of-contents)

Kruskal's algorithm can be divided into three primary steps:

1. **Step 1: Sort the edges** - All edges are sorted in ascending order based on their weight.

2. **Step 2: Check for cycles** - Starting with the lowest weight edge, check if it forms a cycle with the current MST. If no cycle is formed, include this edge in the MST. If a cycle is formed, discard it.

3. **Step 3: Repeat** - Continue with Step 2 until there are (V-1) edges in the spanning tree, where V is the number of vertices.

The pivotal aspect of this algorithm is detecting cycles. The Disjoint Set Union (DSU), also known as Union-Find, is a data structure that can efficiently handle cycle detection in Kruskal's Algorithm. This structure supports 'union' and 'find' operations, enabling you to combine two subsets and find the representative of an element, respectively, in almost O(1) time.

![](https://media.geeksforgeeks.org/wp-content/uploads/20210727035309/UntitledDiagram92.png)

The graph contains 9 vertices and 14 edges. The minimum spanning tree formed will be having (9 – 1) = 8 edges. 

Here are the steps:

1. **Step 1**: Sort all the edges in non-decreasing order of their weight. 

   Sorted edges: 7-6, 8-2, 6-5, 0-1, 2-5, 8-6, 2-3, 7-8, 0-7, 1-2, 3-4

2. **Step 2**: Pick edge 7-6. No cycle is formed, include it.
   
![Step 2](https://media.geeksforgeeks.org/wp-content/uploads/20230306132726/img1drawio.png)

3. **Step 3**: Pick edge 8-2. No cycle is formed, include it. 

![Step 3](https://media.geeksforgeeks.org/wp-content/uploads/20230306132819/img2drawio.png)

4. **Step 4**: Pick edge 6-5. No cycle is formed, include it. 

![Step 4](https://media.geeksforgeeks.org/wp-content/uploads/20230306132901/img3drawio.png)

5. **Step 5**: Pick edge 0-1. No cycle is formed, include it.

![Step 5](https://media.geeksforgeeks.org/wp-content/uploads/20230306132939/img4drawio.png)

6. **Step 6**: Pick edge 2-5. No cycle is formed, include it.

![Step 6](https://media.geeksforgeeks.org/wp-content/uploads/20230306133028/img5drawio.png)

7. **Step 7**: Pick edge 8-6. Since including this edge results in the cycle, discard it. Pick edge 2-3: No cycle is formed, include it.

![Step 7](https://media.geeksforgeeks.org/wp-content/uploads/20230306133247/img6drawio.png)

8. **Step 8**: Pick edge 7-8. Since including this edge results in the cycle, discard it. Pick edge 0-7. No cycle is formed, include it.

![Step 8](https://media.geeksforgeeks.org/wp-content/uploads/20230306133618/img7drawio.png)

9. **Step 9**: Pick edge 1-2. Since including this edge results in the cycle, discard it. Pick edge 3-4. No cycle is formed, include it.

![Step 9](https://media.geeksforgeeks.org/wp-content/uploads/20230306133406/img8drawio.png)

At this point, all vertices are included in the MST, so the algorithm stops.

The minimum spanning tree formed by the edges {7-6, 8-2, 6-5, 0-1, 2-5, 2-3, 0-7, 3-4}.

The pictures are Collected from [here](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)


# [Code Breakdown: Dissecting Kruskal's Algorithm in C++](#table-of-contents)

This article delves into an implementation of Kruskal's Algorithm, which is utilized to determine the minimum spanning tree in a graph that's both connected and weighted. Here's a breakdown of each segment of the C++ code, providing an understanding of how each part contributes to the entire algorithm.

### Structural Entities and Universal Variables

```cpp
const int MAX = 1000;  // Maximum number of vertices or edges.

// Struct to represent a weighted edge in the graph.
struct Edge {
    int u, v, weight;  // u and v are the vertices, weight is the cost of the edge.
};

// Arrays to store the parent of each vertex and the rank of each set in the union-find data structure.
int parent[MAX], rankSet[MAX]; 
```
The `Edge` struct is a data structure that encapsulates the two endpoints (`u` and `v`) and the `weight` of an edge. The global arrays, `parent[MAX]` and `rank[MAX]`, are utilized to store the parent of every vertex and the rank of each set in the union-find data structure, respectively.

### Union-Find Data Structure

```cpp
void make_set(int v);
int find_set(int v);
void union_sets(int a, int b);
```
These three functions implement the union-find data structure. The `make_set` function is used for initializing a set for each vertex. The `find_set` function is responsible for identifying the representative of the set a vertex belongs to. The `union_sets` function takes two sets and merges them based on their rank.

### Edge Sorting

```cpp
void sort_edges(Edge edges[], int m) {
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < m-i-1; j++) {
            // If current edge is heavier than the next one, swap them.
            if (edges[j].weight > edges[j+1].weight)
                swapEdges(edges[j], edges[j+1]);
        }
    }
}
```
The function `sort_edges(Edge edges[], int m)` incorporates a simple bubble sort algorithm, sorting all edges according to their weights in a non-decreasing order. Edges are swapped if the weight of one is found to be greater than the one following it.

### Implementing Kruskal's Algorithm

```cpp
void kruskal(Edge edges[], int n, int m, Edge result[]) {
    if(n <= 0 || m <= 0) { // If there are no vertices or edges, print an error message and exit.
        cout << "Invalid input!" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
        make_set(i);  // Create a singleton set for each vertex.

    sort_edges(edges, m);  // Sort the edges by weight.

    int cnt = 0;  // Counter for the number of edges included in the minimum spanning tree.
    for (int i = 0; i < m; i++) {
        Edge e = edges[i];  // Consider each edge in order of increasing weight.
        // If the vertices of the edge are in different sets (i.e., the edge doesn't form a cycle with the edges in the MST)...
        if (find_set(e.u) != find_set(e.v)) {
            // ...add the edge to the MST and merge the sets of its vertices.
            result[cnt++] = e;
            union_sets(e.u, e.v);
        }
    }
}
```
This function, `kruskal(Edge edges[], int n, int m, Edge result[])`, is where the Kruskal's algorithm is brought to life. It begins with checking the validity of the inputs, initializes singleton sets for each vertex, and sorts the edges. After this, each edge is traversed in the order of increasing weight, and the algorithm checks if the current edge leads to a cycle. If it does not, the edge is added to the MST, and the sets of the two endpoints are merged.

### Outputting the Minimum Spanning Tree

```cpp
void printMST(Edge result[], int n) {
    if(n == 0) { // If the MST doesn't have any edges, print an error message and exit.
        cout << "No edges in the minimum spanning tree!" << endl;
        return;
    }

    // Print each edge in the MST.
    for (int i = 0; i < n; i++) {
        cout << result[i].u << " " << result[i].v << " " << result[i].weight << endl;
    }
}
```
The function `printMST(Edge result[], int n)` prints out the edges that are part of the MST. Each line of output corresponds to an edge, indicating the two vertices and the weight of the edge.

### Main Function

```cpp
int main() {
    int n;  // Number of vertices
    cin >> n;

    int m;  // Number of edges
    cin >> m;

    // If the graph doesn't have enough edges to form a spanning tree, print an error message and exit.
    if(m < n-1) {
        cout << "Insufficient edges for creating a spanning tree!" << endl;
        return 1;
    }

    // Read the edges from the input.
    Edge edges[MAX];
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Array to store the edges in the minimum spanning tree.
    Edge result[MAX];

    // Perform Kruskal's algorithm to find the MST.
    kruskal(edges, n, m, result);

    // Print the edges in the MST.
    printMST(result, n-1);

    return 0;
}
```
The `main()` function starts by obtaining the count of vertices (`n`) and edges (`m`) from the user. If the number of edges is not sufficient to form a spanning tree, the user sees an error message. Then, the user provides the edge information. The `kruskal` function is then called upon to find the MST, and `printMST` function prints out the edges of the MST.

By dissecting this C++ code implementation of Kruskal's Algorithm, you can gain a better understanding of the algorithm's functionality and learn how to implement it.

# [Optimizing Kruskal's Algorithm](#table-of-contents)

Kruskal's algorithm is an efficient method for finding the minimum spanning tree (MST) of a connected, undirected graph. However, like any algorithm, it can be further optimized for increased performance. The following points provide some insights on how this can be accomplished:

### 1. Sorting Algorithm:

The most time-consuming part of Kruskal's algorithm is sorting the edges based on their weights, which is done using the Bubble Sort algorithm in the provided code. Bubble Sort is known for its simplicity but it's not the most efficient sorting algorithm, having a time complexity of O(n^2). 

To improve this, more efficient sorting algorithms like QuickSort, MergeSort, or HeapSort could be used, all of which have a time complexity of O(n log n). Even more optimal would be to use a linear time complexity sorting algorithm like Counting Sort or Radix Sort, but these are applicable only when the range of edge weights is known and is reasonably small.

### 2. Union-Find Data Structure:

The Union-Find data structure is used in Kruskal's algorithm to determine if an edge forms a cycle with the spanning-tree formed so far. The current code uses path compression in `find_set` function to optimize this process. An additional optimization technique that could be employed is "union by rank". 

In union by rank, each set is given a rank, and when two sets are united, the set with the smaller rank is attached to the set with the larger rank. This reduces the time complexity of the algorithm to nearly O(m log*n), where m is the number of edges, n is the number of vertices, and log* is the iterated logarithm function which grows very slowly.

### 3. Data Structures for Graph Representation:

Another consideration for optimizing Kruskal's algorithm is how the graph is represented in memory. The code presented uses an edge list data structure. An edge list is easy to use and understand, but it's not the most efficient data structure for graph algorithms. 

An alternative graph representation, such as an adjacency list or an adjacency matrix, could potentially speed up the execution of Kruskal's algorithm. However, because Kruskal's algorithm must inspect every edge of the graph, the benefits of using these alternative data structures may be minimal.

### 4. Parallelization:

Since the examination of each edge during Kruskal's algorithm is an independent operation, there is a possibility for parallel processing. This can result in significant improvements in runtime, especially for very large graphs.

To conclude, Kruskal's algorithm is efficient, but several optimizations such as utilizing efficient sorting algorithms, improving the Union-Find structure, using optimized graph representation, and exploiting parallel processing can make it even faster. These enhancements, however, should be considered in light of the specific requirements and constraints of the problem at hand.

# [Related Algorithms](#table-of-contents)

Kruskal's algorithm is a popular method for finding the minimum spanning tree (MST) of a connected, undirected graph. However, it's not the only one. There are other algorithms that solve the same problem, each with their unique approaches and potential advantages depending on the specific properties of the graph. Here are some related algorithms:

### 1. Prim's Algorithm:

Like Kruskal's algorithm, Prim's algorithm is a greedy algorithm used for finding the MST of a weighted undirected graph. The difference lies in their approach. Prim's algorithm starts with an arbitrary vertex and builds the MST by adding the minimum weight edge from the graph that connects a vertex in the MST with a vertex outside the MST. 

Prim's algorithm performs better than Kruskal's when the graph is dense, i.e., the number of edges is high compared to the number of vertices, as it has a time complexity of O(E log V) using a binary heap, where E is the number of edges and V is the number of vertices.

### 2. Borůvka's Algorithm:

Also known as Sollin's algorithm, Borůvka's algorithm is another approach for finding the MST of a graph. Like Kruskal's algorithm, it works by examining edges of the graph and adding them to the MST if they don't form a cycle. However, unlike Kruskal's algorithm, which sorts all the edges first and then begins the MST construction, Borůvka's algorithm operates in phases. 

In each phase, it adds the shortest edge that connects each component (initially, each vertex is its own component) to the MST, then merges the connected components. This algorithm can be particularly efficient for solving large-scale problems due to its highly parallel nature.

### 3. Dijkstra's Algorithm:

While not used for finding the MST, Dijkstra's algorithm is closely related as it's another example of a greedy graph algorithm. Instead of finding the MST, Dijkstra's algorithm finds the shortest path from a given source vertex to all other vertices in the graph. 

It's worth noting that while the MST relates to the structure of the graph as a whole, the shortest path relates to specific paths between vertices. In certain contexts and graph structures, the shortest path between vertices might not be part of the MST, and vice versa.

Each of these algorithms offers a unique approach to solving specific graph-related problems. Depending on the properties and requirements of your graph, one may be more suitable than the others. It's also important to consider the time complexity of each algorithm, as this will also impact your choice depending on the size and complexity of your graph.

# [Final Note](#table-of-contents)

Kruskal's algorithm stands as a testament to the power and efficiency of greedy algorithms. The process of making the locally optimal choice at each decision point cumulatively leads to a globally optimal solution. Its applications are widespread and significant, especially in designing networks like computer networks, transportation networks, telecommunication networks, and distribution systems. 

Despite the passing of several decades since its introduction, Kruskal's algorithm remains highly effective and relevant, particularly when amalgamated with modern data structures and language features. As such, a solid understanding and mastery over this algorithm can be a game-changer for programmers and computer scientists worldwide.

# [Useful Sites](#table-of-contents)
### [Articles](#table-of-contents)
- [GeeksforGeeks - Kruskal’s Minimum Spanning Tree (MST) Algorithm | Greedy Algo](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)
- [CP-Algorithms - Minimum spanning tree - Kruskal's algorithm](https://cp-algorithms.com/graph/mst_kruskal.html)
- [Simplilearn - Kruskal's Algorithm Tutorial](https://www.simplilearn.com/tutorials/data-structure-tutorial/kruskal-algorithm)
- [Gate Vidyalay - Kruskal's Algorithm with an Example](https://www.gatevidyalay.com/kruskals-algorithm-kruskals-algorithm-example/)
- [Wikipedia - Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)

### [Visualizers](#table-of-contents)
- [Algorithm Visualizer - Kruskal's Minimum Spanning Tree](https://algorithm-visualizer.org/greedy/kruskals-minimum-spanning-tree)
- [USFCA - Kruskal MST Visualzation](https://www.cs.usfca.edu/~galles/visualization/Kruskal.html)
- [VisuAlgo - Minimum Spanning Tree (Kruskal's Algorithm)](https://visualgo.net/en/mst)
