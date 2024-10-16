#include<bits/stdc++.h>
#define inf 1<<28
using namespace std;
void bfs(int start,int node, vector<int>vec[])
{
    map<int, int> visited, label; // Maps to track visited nodes and their distances
    queue<int> q;                 // Queue for BFS traversal

    label[start] = 0;             // Starting node has a distance of 0
    q.push(start);                // Push the start node into the queue
    visited[start] = 1;           // Mark start node as visited

    while (!q.empty())            // Continue until the queue is empty
    {
        int u = q.front();        // Get the front node from the queue
        q.pop();                  // Remove the front node from the queue

        for (int i = 0; i < vec[u].size(); i++)
        {
            int v = vec[u][i];    // Get the adjacent node v to node u
            if (!visited[v])      // If node v is not visited
            {
                visited[v] = 1;   // Mark node v as visited
                label[v] = label[u] + 1; // Set the distance of v to be distance of u + 1
                q.push(v);        // Push v to the queue for further exploration
            }
        }
    }

    // Output the distance of each node from the start node
    for (int i = 1; i <= node; i++)
    {
        cout << "Distance from node 1 to " << i << " is " << label[i] << endl;
    }
}
int main()
{
    freopen("in_bfs_dfs.txt", "r", stdin);  // Open input file in.txt for reading
    int a, b,node;
    vector<int>vec[100];
    cin >> node;                    // Input number of nodes
    // Read the graph edges (pairs of nodes) and build the adjacency list
    while (cin >> a >> b)
    {
        vec[a].push_back(b);        // Add edge a --> b
        vec[b].push_back(a);        // Since the graph is undirected, also add b --> a
    }

    bfs(1,node,vec);                         // Start BFS from node 1

    return 0;
}
