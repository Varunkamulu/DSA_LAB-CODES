#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// cout<<"varun";
map<char,int> m;
vector<vector<int>> v;
map<vector<int>,int> n; 
string s;
cin>>s;
for(int i=0;i<s.size();i++)
{
    m[s[i]]++;
}
// sort(m.begin(),m.end());
for(auto a:m)
{
    // low->high
    // m[1]->0
    // map initialize with 0
    // int ans=INT_MAX
    // if(m[i]<ans)
    // cout<<a.first;
    // 
    // 
}
return 0;
}

/*
<-------------------------------MAPS------------------------------------------------------------>
generally stored in increasing order and sorted order and stored only unique keys 
->multi map is used to store multiple keys 
->map is based on self balancing trees()
->.first is used for accessing the key
->.second is used for accessing value
->
1=2
*/