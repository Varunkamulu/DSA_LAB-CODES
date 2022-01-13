/*
   binary search 
   while(low<=high)
   {
       ll mid=low+(high-low)/2;
       if(mid==target)return;
       if(mid<target)low=mid-1;
       if(mid>target)high=mid+1;
   }
   the above one is the basic template for the binary search
   called as THE USUAL ONE
   while(low<high)
   {
       int mid=low+(high-low)/2;
       if(mid<=target)
       {
           low=mid;
       }
       else high=mid-1;
   }
   this is when you want to remove the 6th line of the code


**********************************************************************

generally binary search is used to find the target in the sorted array

recursive bs
*/
//for A,B,C--->THINK BRUTEFORCE APPROACH WITH SLIGHT OBSERVATION
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vll vector<ll>
#define vvll vector<vll>
int rec(int low,int high,int target,vector<ll> &v)
{
    if(low>high)return -1;
    int mid=low+(high-low)/2;
    if(v[mid]==target)return mid;
    if(v[mid]<target)return rec(low,mid-1,target,v);
    if(v[mid]>target)return rec(mid+1,high,target,v);
}
void solve(){
vector<ll> v;
for(int i=0;i<5;i++)
{
    int x;
    cin>>x;
    v.push_back(x);
}
int target=rec(0,v.size()-1,3,v);
ll a=upper_bound(v.begin(),v.end(),3)-v.begin();
cout<<a<<endl;
if(target==-1)
{
    cout<<"NO\n";
}
else cout<<"YES\n";
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
while(t--){
solve();
}
return 0;
}