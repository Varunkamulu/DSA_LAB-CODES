// for A,B,C--->THINK BRUTEFORCE APPROACH WITH SLIGHT OBSERVATION
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
        if(m[v[i]]==2)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
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