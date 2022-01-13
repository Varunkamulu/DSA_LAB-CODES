// krushkals algo
#include <bits/stdc++.h>
using namespace std;
vector<int> par(100);
vector<int> rankk(100);
class v
{
   public:
   int a,b,c;
   v(int x,int y,int z)
   {
       a=x;
       b=y;
       c=z;
   }
};
int findpar(int u)
{
    if(u==par[u])
    {
          return u;
    }
    return par[u]=findpar(par[u]);
}
void unionn(int u,int v)
{
    u=findpar(u);
    v=findpar(v);
    if(rankk[u]<rankk[v])
    {
        par[u]=v;
    }
    else if(rankk[u]>rankk[v])
    {
        par[v]=u;
    }
    else 
    {
        par[u]=v;
        rankk[v]++;
    }
}
static bool cmp(v a,v u)
{
    return a.c<u.c;
}
int main()
{
    int n;
    cout<<"enter number of vertices :";
    cin >> n;
    for(int i=0;i<n;i++){par[i]=i;rankk[i]=0;}
    vector<v> va;
    cout<<"enter the edges : "<<endl;
    while (1)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (x == -1 || y == -1)
            break;
        va.push_back(v(x,y,w));
    }
    vector<pair<int,pair<int,int>>> mst;
    sort(va.begin(),va.end(),cmp);
    for(auto it:va)
    {
        if(findpar(it.a)!=findpar(it.b))
        {
            mst.push_back({it.a,{it.b,it.c}});
            unionn(it.a,it.b);
        }
    }
    cout<<"the mst after krushkals algo is : "<<endl;
    for (auto it:mst)
    {
        cout <<it.first<<" "<<it.second.first<<" "<<it.second.second<< endl;
    }
    return 0;
}