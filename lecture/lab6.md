<h2><i>👉Lab 6 - Graphs</i></h2>
A graph consists of vertices (or nodes) connected by edges. Depending on how we want to represent and store the graph, different input methods come into play.

### ✅Inputting a Graph in C++ Using Different Methods
- Adjacency Matrix
- Adjacency List
- Edge List

### ✅Input Graph as an Adjacency Matrix
An adjacency matrix is a 2D array where each cell `(i, j)` represents an edge from node `i` to node `j`.
```c
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Create an n x n adjacency matrix and initialize to 0
    //  vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    int adjMatrix[n+1][n+1];

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (start end):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        // For undirected graph, set both (u,v) and (v,u) to 1
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Remove this line if directed graph
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

```
#### Input Example
![Adj matrix input](images/graph1.png)

#### Output Example
![Adj matrix output](images/graph2.png)

### ✅Input Graph as an Adjacency List
An adjacency list is a more space-efficient way to represent a sparse graph. Each vertex stores a list of all the vertices it is connected to.

```c
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Create an adjacency list of size n
    vector<vector<int>> adjList(n);

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (start end):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line for a directed graph
    }

    // Print the adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

```
#### Input Example
![adj list in graph](images/graph3.png)
#### Output Example
![adj list in graph](images/graph4.png)
### Input Graph as an Edge List
In an edge list, the graph is represented by a list of all edges, where each edge is a pair of vertices.
```c
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Create an edge list
    vector<pair<int, int>> edgeList;

    cout << "Enter the edges (start end):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }

    // Print the edge list
    cout << "Edge List:\n";
    for (auto edge : edgeList) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}

```
#### Input Example
![edge list in graph](images/graph5.png)
#### Output Example
![edge list in graph](images/graph6.png)
- `Adjacency Matrix`: Best for dense graphs where most vertices are connected.
- `Adjacency List`: Best for sparse graphs to save space.
- `Edge List:` Useful for specific algorithms where edge traversal is key.
### ✅Breadth-First Search (BFS)
Breadth-First Search (BFS) for an unweighted, undirected graph.
#### Graph Representation
The graph is represented as an adjacency list using a vector of vectors vec[100], where each vec[i] holds the neighbors (or adjacent nodes) of node i.
#### BFS Function
The BFS function takes a starting node start and traverses the graph layer by layer, visiting all nodes that are reachable from the start node. BFS uses a queue to explore nodes and a visited map to track which nodes have been visited to avoid revisiting them. A label map stores the distance of each node from the starting node.
```c
void bfs(int start)
{
    map<int, int> visited, label; // Maps to track visited nodes and their distances
    queue<int> q;                 // Queue for BFS traversal

    label[start] = 0;             // Starting node has a distance of 0
    q.push(start);                // Push the start node into the queue
    visited[start] = 1;           // Mark start node as visited

    while (!q.empty()) {          // Continue until the queue is empty
        int u = q.front();        // Get the front node from the queue
        q.pop();                  // Remove the front node from the queue

        for (int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i];    // Get the adjacent node v to node u
            if (!visited[v]) {    // If node v is not visited
                visited[v] = 1;   // Mark node v as visited
                label[v] = label[u] + 1; // Set the distance of v to be distance of u + 1
                q.push(v);        // Push v to the queue for further exploration
            }
        }
    }

    // Output the distance of each node from the start node
    for (int i = 1; i <= node; i++) {
        cout << "Node 1 --> " << i << " : " << label[i] << endl;
    }
}

```
- Visited Map: Keeps track of the nodes that have been visited during the BFS.
Label 
- Map: Stores the distance (number of edges) from the start node to each node.
- Queue: Used to explore nodes level by level. BFS explores all neighbors of a node before moving on to the next level of nodes.
#### Main Function
```c
int main()
{
    freopen("in.txt", "r", stdin);  // Open input file in.txt for reading

    cin >> node;                    // Input number of nodes
    int a, b;

    // Read the graph edges (pairs of nodes) and build the adjacency list
    while (cin >> a >> b) {
        vec[a].push_back(b);        // Add edge a --> b
        vec[b].push_back(a);        // Since the graph is undirected, also add b --> a
    }

    bfs(1);                         // Start BFS from node 1

    return 0;
```
- The BFS traverses the graph level by level, starting from node 1.
- The distance (label) of each node from node 1 is printed after the traversal.
### ✅Depth-First Search (DFS)
The DFS (Depth-First Search) algorithm explores a graph by going as deep as possible along each branch before backtracking. DFS can be implemented either recursively or iteratively, and the example provided uses a recursive implementation.

- `visited[u] = true`: Marks node u as visited so that it will not be visited again during the DFS.
- `for (int i = 0; i < vec[u].size(); i++)`: Loops through all the neighbors of node u.
- `if (!visited[v])`: If the neighbor v is not yet visited, the DFS function is called recursively for v.
- `Recursion`: DFS dives deeper into the graph by recursively visiting all unvisited neighbors until all nodes reachable from the starting node have been visited.

```c
#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> vec[100]; // Adjacency list to store the graph
map<int, bool> visited; // Map to track visited nodes
map<int,int>label;
int flag=0;
// DFS function starting from node 'u'
void dfs(int u) {
    if (flag==0){
        flag=1;
        label[u]=0;
    }
    visited[u] = true; // Mark the current node as visited
    cout << u << " "; // Print the node to see the DFS traversal order

    // Loop through all adjacent nodes (neighbors) of node 'u'
    for (int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i]; // Get the adjacent node
        if (!visited[v]) { // If the adjacent node is not visited
            label[v]=label[u]+1;
            dfs(v); // Recursively perform DFS on this node
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin); // Open input file for reading
    int node, edges; // Number of nodes and edges
    cin >> node >> edges;

    // Reading edges and building the adjacency list
    int a, b;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        vec[a].push_back(b); // Adding edge a --> b
        vec[b].push_back(a); // Adding edge b --> a (undirected graph)
    }

    // Perform DFS starting from node 1
    cout << "DFS Traversal starting from node 1:\n";
    dfs(1); // Start DFS from node 1

    return 0;
}

```
### Dijkstra's algorithm
![Dijkstra's algorithm](images/dij.png)
#### Simple implementation using BFS
```c
void dijkstra(int start,int node,vector<int>vec[100],map<int,int>cost,infinity)
{
    map<int, int> dis; // Maps to track visited nodes and their distances
    for(int i=1;i<=node;i++)dis[i]=infinity;
    queue<int> q;                 // Queue for BFS traversal
    dis[start]=0;

    q.push(start);                // Push the start node into the queue
    while (!q.empty()) {          // Continue until the queue is empty
        int u = q.front();        // Get the front node from the queue
        q.pop();                  // Remove the front node from the queue

        for (int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i];    // Get the adjacent node v to node u
            if (dis[u]+cost[u][v]<dis[v]) {    // If node v is not visited
                dis[v]=dis[u]+cost[u][v];//update the distance
                q.push(v);        // Push v to the queue for further exploration
            }
        }
    }

    // Output the distance of each node from the start node
    for (int i = 1; i <= node; i++) {
        cout << "Node --> " << i << " : " << dis[i] << endl;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int node;
    vector<int>vec[100];
    int maxInt = numeric_limits<int>::max();//#include<limits>
    cin>>node;
    int a,b,c;
    map<int,int>cost;
    while(cin>>a>>b>>c)
    {
        vec[a].push_back(b);
        cost[a][b]=c;
    }
    dijkstra(1,node,vec,cost,maxInt);
    
}

```
#### Dijkstra’s Algorithm using Priority Queue
##### Comparator Class for Priority Queue
```c
class compare {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

```
This is a custom comparator that is used to implement a min-heap using C++’s `priority_queue`. The `operator()` function defines that the priority queue should prioritize pairs based on the smallest distance (the second element of the pair).

##### Dijkstra’s Algorithm Implementation using priority queue
```c
void dijaktra(int start,int node, vector<int>vec[100],map<int,int>cost, int inf) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> priorQ;
    map<int,int>dis;
    // Initialize all distances to infinity
    for (int i = 1; i <=node; i++) 
        dis[i] = inf;
    
    // Set the distance for the start node to 0
    dis[start] = 0;
    
    // Push the start node into the priority queue with a distance of 0
    priorQ.push(make_pair(start, dis[start]));

    while (!priorQ.empty()) {
        // Extract the node with the smallest known distance
        int u = priorQ.top().first;
        priorQ.pop();

        // Traverse all neighbors of node 'u'
        for (int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i]; // Neighbor node

            // If a shorter path to node 'v' is found through 'u'
            if (cost[u][v] + dis[u] < dis[v]) {
                dis[v] = cost[u][v] + dis[u];  // Update distance
                priorQ.push(make_pair(v, dis[v]));  // Push updated distance into the priority queue
            }
        }
    }
    for(int i=1; i<=node; i++)
    {
        cout<<dis[i]<<" ";
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int node;
    int maxInt = numeric_limits<int>::max();//#include<limits>
    cin>>node;
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        vec[a].push_back(b);
        cost[a][b]=c;
    }
    dijaktra(1,node,vec,cost,maxInt);

}

```
<h2><i>🚩Questions</i></h2>

1. Connected Components (BFS/DFS)
- Problem: Given an undirected graph, find the number of connected components. Each component is a group of nodes where each node is reachable from any other node in the same component.
- Input: Number of nodes `n` and edges `m`, followed by `m` edges.
- Output: Print the number of connected components in the graph.
- Hint: You can use either BFS or DFS to explore each component, marking nodes as visited and counting how many separate DFS/BFS runs are needed.
2. Shortest Path in an Unweighted Graph (BFS)
- Problem: Given an undirected, unweighted graph, find the shortest path from a source node to all other nodes using BFS.
- Input: Number of nodes `n`, edges `m`, the source node, and `m` edges.
- Output: Print the shortest distance from the source node to every other node in the graph.
- Hint: BFS can be used to find the shortest path in an unweighted graph since it explores nodes in increasing order of distance.
3. Cycle Detection in an Undirected Graph (DFS)
- Problem: Given an undirected graph, determine if the graph contains a cycle.
- Input: Number of nodes `n` and edges `m`, followed by `m` edges.
- Output: Print `"Yes"` if there is a cycle, otherwise print `"No"`.
- Hint: Use DFS and track the parent of each node. If a visited node is encountered that is not the parent of the current node, a cycle is found.
4. Topological Sorting (DFS)
- Problem: Given a directed acyclic graph (DAG), find a topological ordering of its vertices.
- Input: Number of nodes `n` and edges `m`, followed by `m` directed edges.
- Output: Print one possible topological ordering of the graph.
- Hint: Use DFS to perform topological sorting by adding nodes to the result in post-order traversal (after all neighbors have been visited).

