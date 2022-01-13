#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int> v[n];
vector<int> va;
while(1)
{
    set<int> s;
    s.end
    int x,y;
    cin>>x>>y;
    if(x==-1||y==-1)break;

    v[y].push_back(x);
    v[x].push_back(y);

}
queue<int> q;
int src;
cin>>src;
q.push(src);
vector<bool> vis(n,false);
vis[src]=true;
while(!q.empty())
{
    int temp=q.front();
    q.pop();
    va.push_back(temp);
    for(auto it:v[temp])
    {
         if(!vis[it])
         {
             vis[it]=true;
             q.push(it);
         }
    }
}
for(int it: va)cout<<it<<" ";
return 0;
}