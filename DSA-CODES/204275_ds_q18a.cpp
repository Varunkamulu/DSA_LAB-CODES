// prims algo
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of vertices :";
    cin >> n;
    vector<pair<int, int>> v[n];
    cout<<"enter the edges : "<<endl;
    while (1)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (x == -1 || y == -1)
            break;
        v[y].push_back({x, w});
        v[x].push_back({y, w});
    }
    vector<int> dis(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> par(n, -1);
    dis[0]=0;
    par[0]=-1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int x = p.first, y = p.second;
        mst[x] = true;
        for (auto it : v[x])
        {
            if (mst[it.first] == false && it.second < dis[it.first])
            {
                par[it.first] = x;
                dis[it.first] = it.second;
                pq.push({it.first, dis[it.first]});
            }
        }
    }
    cout<<"the mst in prims algo is : "<<endl;
    //here the parent of 0 is set as -1 because it has no parents
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" "<<par[i] << " " << dis[i] << endl;
    }
    return 0;
}