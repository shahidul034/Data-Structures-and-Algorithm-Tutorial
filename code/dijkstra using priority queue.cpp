#include<bits/stdc++.h>
#define infinity 1<<30
using namespace std;

class compare
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
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

