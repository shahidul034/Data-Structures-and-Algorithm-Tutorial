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
![Adj matrix input](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/graph1.png/?raw=true)

#### Output Example
![Adj matrix output](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/graph2.png/?raw=true)

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
![adj list in graph](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/graph3.png/?raw=true)
#### Output Example
![adj list in graph](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/graph4.png/?raw=true)
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
![edge list in graph](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/graph5.png/?raw=true)
#### Output Example
![edge list in graph](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/graph6.png/?raw=true)
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
- `Visited Map`: Keeps track of the nodes that have been visited during the BFS.
Label 
- `Map`: Stores the distance (number of edges) from the start node to each node.
- `Queue`: Used to explore nodes level by level. BFS explores all neighbors of a node before moving on to the next level of nodes.
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

| ![Dijkstra's algorithm](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/dij.png/?raw=true) | 
|:--:| 
| *Courtesy: shafaetsplanet* |

Update the path
| ![Dijkstra's algorithm](http://www.shafaetsplanet.com/planetcoding/wp-content/uploads/2013/04/dijkstra26.png) | 
|:--:| 
| *Courtesy: shafaetsplanet* |

```c
if dis[u] + cost[u][v] < dis[v]:
dis[v] = dis[u] + cost[u][v]
```
#### Dijkstra implementation using BFS
```c
void dijkstra(int start,int node,vector<int>vec[],map<int, map<int,int>>cost)
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
    for (int i = 1; i <= node; i++)
    {
        cout << "Distance from node 1 to node "<<i<< " is " << dis[i] << endl;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int node;
    vector<int>vec[100];
    cin>>node;
    int a,b,c;
    map<int, map<int,int>>cost;
    while(cin>>a>>b>>c)
    {
        vec[a].push_back(b);
        vec[b].push_back(a);
        cost[a][b]=c;
    }
    dijkstra(1,node,vec,cost);
}
```
[Full code](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/code/dijkstra%20using%20bfs.cpp)
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
void dijkstra(int start,int node, vector<int>vec[],map<int,map<int,int>>cost)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> priorQ;
    map<int,int>dis;
    // Initialize all distances to infinity
    for (int i = 1; i <=node; i++)
        dis[i] = infinity;

    // Set the distance for the start node to 0
    dis[start] = 0;

    // Push the start node into the priority queue with a distance of 0
    priorQ.push(make_pair(start, dis[start]));

    while (!priorQ.empty())
    {
        // Extract the node with the smallest known distance
        int u = priorQ.top().first;
        priorQ.pop();

        // Traverse all neighbors of node 'u'
        for (int i = 0; i < vec[u].size(); i++)
        {
            int v = vec[u][i]; // Neighbor node

            // If a shorter path to node 'v' is found through 'u'
            if (cost[u][v] + dis[u] < dis[v])
            {
                dis[v] = cost[u][v] + dis[u];  // Update distance
                priorQ.push(make_pair(v, dis[v]));  // Push updated distance into the priority queue
            }
        }
    }
    for (int i = 1; i <= node; i++)
    {
        cout << "Distance from node 1 to node "<<i<< " is " << dis[i] << endl;
    }
}


int main()
{
    freopen("in_dij.txt","r",stdin);
    int node;
    vector<int>vec[100];
    cin>>node;
    int a,b,c;
    map<int, map<int,int>>cost;
    while(cin>>a>>b>>c)
    {
        vec[a].push_back(b);
        vec[b].push_back(a);
        cost[a][b]=c;
    }
    dijkstra(1,node,vec,cost);
}

```
[Full code](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/code/dijkstra%20using%20priority%20queue.cpp)

### Bellman-Ford algorithm
The Bellman-Ford algorithm is used to find the shortest paths from a source node to all other nodes in a weighted graph, even if the graph contains edges with negative weights. The algorithm also detects negative-weight cycles, where the total weight of a cycle is negative, which would imply the shortest path cannot be determined as the path could keep reducing indefinitely.

| ![Bellman-Ford algorithm](https://www.shafaetsplanet.com/planetcoding/wp-content/uploads/2014/10/bell1.jpg) | 
|:--:| 
| *Courtesy: shafaetsplanet* |

| ![Bellman-Ford algorithm](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/relax_order.png/?raw=true) | 
|:--:| 
| *Courtesy: shafaetsplanet* |

| ![Bellman-Ford algorithm](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/neg_cycle.png/?raw=true) | 
|:--:| 
| *Courtesy: shafaetsplanet* |

```c
void Bellmanford(int node,int source,vector<pair<int,pair<int,int>>>vec)
{
    map<int,int>dis;
    for(int i=1; i<=node; i++)
    {
        dis[i]=infinity;
    }
    dis[source]=0;
    for(int i=1; i<=node-1; i++)
    {
        vector<pair<int,pair<int,int>>>::iterator it=vec.begin();
        for( ; it!=vec.end(); it++)
        {
            int u=(it->second).first;
            int v=(it->second).second;
            cout<<u<<" "<<v<<endl;
            if((dis[u]+(it->first))<dis[v])
            {
                dis[v]=dis[u]+(it->first);
            }
        }
    }
    int flag=0;
    vector<pair<int,pair<int,int>>>::iterator it=vec.begin();
    for( ; it!=vec.end() ; it++  )
    {
        int u=(it->second).first;
        int v=(it->second).second;
        if((dis[u]+(it->first))<dis[v])
        {
            flag=1;
            dis[v]=dis[u]+(it->first);

        }
    }
    if(!flag)
    {
        cout<<"This graph has no cycle\n";
        for(int i=1; i<=node; i++)
            cout<<i<<": "<<dis[i]<<"\n";
    }

    else
        cout<<"This graph has cycle\n";
}
int main()
{
    freopen("in_bell.txt","r",stdin);
    vector<pair<int,pair<int,int>>>vec;
    int node,edges;
    cin>>node>>edges;
    for(int i=0; i<edges; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vec.push_back({c,{a,b}});
    }
    Bellmanford(node,1, vec);
}

```

[Full code](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/code/bellmanford.cpp)
### Floyd warshall algorithm
| ![floyd warshall algorithm](https://www.shafaetsplanet.com/planetcoding/wp-content/uploads/2014/07/floyed1.png) | 
|:--:| 
| *Courtesy: shafaetsplanet* |
The Floyd-Warshall algorithm computes the shortest paths between all pairs of nodes.
```c
int floyedwarshell(int n)
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                mat[i][j]=min((mat[i][k]+mat[k][j]),mat[i][j]);
            }
        }
    }
}
```

Initializes the mat array. If `i == j`, the distance from a node to itself is `0`. For `i != j`, the distance is set to infinity (`inf`), indicating no direct edge. 

```c
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
            if(i!=j)
                mat[i][j]=inf;
            else
                mat[i][j]=0;
    }
```
#### Main function
```c
int main()
{
    freopen("in_floyed_warshell.txt","r",stdin);
    int node;
    cin>>node;
    int a,b,c;
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
            if(i!=j)
                mat[i][j]=inf;
            else
                mat[i][j]=0;
    }

    while(cin>>a>>b>>c)
    {
        mat[a][b]=c;
    }
    cout<<"Initial Matrix: "<<endl;
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    floyedwarshell(node);
    cout<<"After applying floyed warshell: "<<endl;
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
```

[Full code](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/code/floyed_warshell.cpp)
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

| ![Bellman-Ford algorithm](https://www.shafaetsplanet.com/planetcoding/wp-content/uploads/2011/10/topsort5.png) | 
|:--:| 
| *Courtesy: shafaetsplanet* |
- Problem: Given a directed acyclic graph (DAG), find a topological ordering of its vertices.
- Input: Number of nodes `n` and edges `m`, followed by `m` directed edges.
- Output: Print one possible topological ordering of the graph.
- Hint: Use DFS to perform topological sorting by adding nodes to the result in post-order traversal (after all neighbors have been visited).

