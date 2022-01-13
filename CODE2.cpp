// for A,B,C--->THINK BRUTEFORCE APPROACH WITH SLIGHT OBSERVATION
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vll vector<ll>
#define vvll vector<vll>
#define pb push_back
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define vb vector<bool>
#define vvll vector<vll>
const int pi = 3.14159265358979323846;
vb primes(100007, false);
set<int> primes1;
void seive()
{
    primes[1] = true;
   for (int i = 2; i < 1000000; i++)
    {
       for (int j = 2 * i; j < 1000000; j += i)
        {
            primes[j] = true;
        }
    }
    for (int i = 1; i < 1000000; i++)
    {
        if (primes[i] == false)
        {
            primes1.insert(i);
        }
    }
}
ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2)
    {
        return a * power(a, b / 2 + 1);
    }
    else
        return a * power(a, b / 2);
}
ll inv(ll a, ll b)
{
    return power(a, mod - 1);
}
void solve()
{
    int n;
    cin>>n;
    cout<<n;
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
