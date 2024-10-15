#include<bits/stdc++.h>
#define infinity  1<<30
using namespace std;
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
