// for A,B,C--->THINK BRUTEFORCE APPROACH WITH SLIGHT OBSERVATION
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool iscycleutilDG(vector<int> adj[], vector<bool> &vis, int it)
{
    if (vis[it] == true)
        return true;
    vis[it] = true;
    bool flag = false;
    for (auto i : adj[it])
    {
        flag = iscycleutilDG(adj, vis, i);
        if (flag)
            return true;
    }
    return false;
}
bool iscyclicDG(int v, vector<int> adj[])
{
    vector<bool> vis(v, false);
    bool flag = false;
    for (int i = 0; i < v; i++)
    {
        vis[i] = true;
        for (auto it : adj[i])
        {
            flag = iscycleutilDG(adj, vis, it);
            if (flag)
                return true;
        }
        vis[i] = false;
    }
    return false;
}
//dfs toposort

//bfs toposort
void kahnsalgo(vector<int> adj[])
{
    int n=adj->size();
    vector<int> in(n);
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            in[it]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(in[i]==0)q.push(i);
    }
    vector<int> v;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        v.push_back(a);
        for(auto it:adj[a])
        {
            in[it]--;
            if(in[it]==0)q.push(it);
        }
    }
}
bool bfsbip(vector<int> adj[],vector<int> &col,int i)
{
     if(col[i]==-1)
     {
         col[i]=0;
     }
     else return false;
     for(auto it:adj[i])
     {
         if(col[it]==-1)
         {
             col[it]=!col[i];
             if(!bfsbip(adj,col,it))
             {
                 return false;
             }
         }
     }
     return true;
}
bool isbipartite(int v,vector<int> adj[])
{
    vector<int> col(v,-1);
    for(int i=0;i<v;i++)
    {
        if(col[i]==-1)
        {
            if(!bfsbip(adj,col,i))
            {
                 cout<<"the graph is not bip";
                 return false;
            }
        }
    }
}
bool iscyclicUDG(int v, vector<int> adj[])
{
    vector<bool> vis(v, false);
    queue<pair<int, int>> q;
    for (int i = 0; i < v; i++)
    {
        vis[i] = true;
        q.push({i, -1});
        while (!q.empty())
        {
            auto p=q.front();
            q.pop();
            for (auto it : adj[p.first])
            {
                if(!vis[it])
                {
                    q.push({it,p.first});
                }
                if(it!=p.first)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
****************************************GRAPHS********************************************
1)directional graph   ->only one directional graph
2)undirectional graph  ->bi directional graph
3)cycle detection   ->detecting a cycle
4)topological sort  ->finding a topological sort
5)dijkstras algo   ->shortest path in a weighted graph
6)DFS  ->depth first traversal
7)BFS  ->level order traversal
8)union find   ->union of two or more graphs
9)bellman ford  ->for negetive dijkstras algo
10)kosaraju 
11)prims algo or kruskal algo  ->used for minimum spanning tree
12)ford fulkerson algo
13)hamiltonian cycle
14)euler cycle
15)floyd warshall algo  ->used for finding the minimum distance between all __pairs of graph




DONT WANT TO REPLY?
DONT CHAT THEN :)




)tarjans algo/articulation point
*/
