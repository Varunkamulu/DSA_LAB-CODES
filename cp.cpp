// for A,B,C--->THINK BRUTEFORCE APPROACH WITH SLIGHT OBSERVATION
/*
1)define a problem
2)see constraints and think of an algo
3)try to code 
4)orelse move on and upsolve it later
*/
#include <bits/stdc++.h>
using namespace std;
#define long long int;
int mod = 1e9 + 7;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vll vector<int>
#define vvll vector<vll>
#define pb push_back
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pll pair<int, int>
#define vll vector<int>
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
int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2)
    {
        return a * power(a, b / 2 )* power(a, b / 2 );
    }
    else
        return power(a, b / 2) * power(a, b / 2);
}
int inv(int a, int b)
{
    return power(a, mod - 1);
}
void solve()
{
     
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
   while (t--)
    {
        solve();
    }
    return 0;
}