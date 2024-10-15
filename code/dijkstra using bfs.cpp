#include<bits/stdc++.h>
#define infinity 1<<30
using namespace std;

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

