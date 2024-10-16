#include<bits/stdc++.h>
typedef long long int ll;//1507034
using namespace std;
int finishingtime[10000];
vector<int>vec[100];
map<int,string>color;
int visited[1000];
vector<int>v;
int startingtime[1000];
int time_cnt=0,n;
int DFS_VISIT(int);
void DFS(int n)
{
	for(int i=1;i<=n;i++)
	{
		color[i]="white";
	}
	for(int i=0;i<n;i++)
	{
		if(color[i]=="white")
		{
			DFS_VISIT(i);
		}
	}
}
int DFS_VISIT(int node)
{
	color[node]="gray";
	time_cnt++;
	startingtime[node]=time_cnt;
	for(int i=0;i<vec[node].size();i++)
	{
		if(color[vec[node][i]]=="white")DFS_VISIT(vec[node][i]);
	}
	v.push_back(node);
	color[node]="black";
	time_cnt++;
	finishingtime[node]=time_cnt;
}
int main()
{
	freopen("in_bfs_dfs.txt","r",stdin);

	int m;cin>>m;
	int a,b;
	while(cin>>a>>b)
	{
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	DFS(m);
	cout<<"Topological sort: "<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}
