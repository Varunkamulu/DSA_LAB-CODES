//for A,B,C--->THINK BRUTEFORCE APPROACH WITH SLIGHT OBSERVATION
#include<bits/stdc++.h>
using namespace std;
vector<int> va;
void dfs(int src,vector<bool>& vis,vector<int> v[])
{
    vis[src]=1;
    va.push_back(src);
    for(int it:v[src])
    {
        if(!vis[it])
        {
            dfs(it,vis,v);
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int> v[n];
while(1)
{
    int x,y;
    cin>>x>>y;
    if(x==-1||y==-1)break;

    v[y].push_back(x);
    v[x].push_back(y);

}
vector<bool> vis(n,false);
dfs(0,vis,v);
for(int it:va)cout<<it<<" ";
return 0;
}