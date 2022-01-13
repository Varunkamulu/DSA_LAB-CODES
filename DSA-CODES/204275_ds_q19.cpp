//DIJKSTRA ALGO
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of edges : ";
    cin>>n;
   vector<pair<int,int>> v[n];
   cout<<"enter the edges : "<<endl;
   while(true)
   {
       int x,y,z;
       cin>>x>>y>>z;
       if(x==-1||y==-1 || z==-1)break;
       v[y].push_back({x,z});
       v[x].push_back({y,z});
   }
   priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > q;
   q.push({0,0});
   vector<int> va(n,0);
   vector<int> dis(n,INT_MAX);
   dis[0]=0;
   while(!q.empty())
   {
       auto it=q.top();
       q.pop();
       va[it.first]=1;
       for(auto i:v[it.first])
       {
           int wt=i.second;
           if(!va[i.first])
           {
               if(dis[it.first]+wt<dis[i.first] && dis[it.first]!=INT_MAX)
               {
                   dis[i.first]=dis[it.first]+wt;
                   q.push({i.first,dis[i.first]});
               }
           }
       }
   }
   cout<<"the minimum distances from source node to each node : "<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<"distance from 0 to "<<i+1<<" is : "<<dis[i]<<"\n";
   }
return 0;
}