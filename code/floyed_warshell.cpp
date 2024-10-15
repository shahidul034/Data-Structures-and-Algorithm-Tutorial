#include<bits/stdc++.h>
#define inf 1<<28
using namespace std;
int mat[100][100];
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
