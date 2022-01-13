#include<bits/stdc++.h>
using namespace std;
void floydwarshall(vector<vector<int>> &v,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(v[j][i]!=INT_MAX && v[i][k]!=INT_MAX)
                {
                    v[j][k]=min(v[j][k],v[j][i]+v[i][k]);
                }
            }
        }
    }
}
int main()
{
    int n;
    cout<<"enter number of vertices : ";
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n,INT_MAX));
    cout<<"enter the edges : "<<endl;
    while(1)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==-1||y==-1||z==-1)break;
        v[x][y]=z;
        // v[y][x]=z;
    }
    for(int i=0;i<n;i++)v[i][i]=0;
    floydwarshall(v,n);
    cout<<"the all pair shortest path weight using floyd warshall's algo : "<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}