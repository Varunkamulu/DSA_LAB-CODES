/*int d;
int n1=n.size();
int n2=m.size();
int low=min(0,k-m);
int high=max(k,n);
while(left<=high)
{
    int cut1=(low+high)>>1;
    int cut2=(n1+n2)-cut1;
    int l1= cut1==0 ? INT_MIN:arr1[cut1-1];
    int l2= cut2==0?INT_MIN:arr2[cut2-1];
    int r1=cut1==0?INT_MAX:arr1[cut1];
    int r2=cut2==0?INT_MAX:arr2[cut2];
    if(l1<=r2 && l2<=r1)
    {
        return max(l1,l2);
    }
    else if(l1>r2)
    {
        high=cut1-1;
    }
    else if(l2>r1)
    {
        low=cut1+1;
    }
}*/
//#include <bits/stdc++.h>
//using namespace std;
/*
    void solve(string s,string op)
    {
        if(s.length()==0)
        {
            cout<<op<<" ";
            return;
        }
        if(isalpha(s[0]))
        {
        string op1=op;
        string op2=op;
        op1.push_back(tolower(s[0]));
         op2.push_back(toupper(s[0]));
            s=s.substr(1);
        solve(s,op1);
         solve(s,op2);
        }
        else
        {
            op.push_back(s[0]);
            s=s.substr(1);
             solve(s,op);
        }
        
       return;
    }
    */
/*
   void pushy(vector<int> &v,int i,vector<int> &s,int sum,int target)
   {
       
       if(  i==v.size())
       {
           if(sum==target)
           {
           for(int i=0;i<s.size();i++)
           {
               cout<<s[i]<<" ";
           }
           cout<<"\n";
           }
           return;
       }
       if(sum<target && v[i]<=target)
       {
           s.push_back(v[i]);
           pushy(v,i,s,sum+v[i],target);
           s.pop_back();
       }
    
    pushy(v,i+1,s,sum,target);
    return;

   }*/
/*
#include<iostream>
using namespace std;
int bubblesort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void duplicate(int arr[],int n){
    cout<<"Duplicate element is "<<endl;
    for(int i=0; i<n; i++){
        if(arr[i]==arr[i+1]){
            cout<<arr[i];
        }
    }
}
void sum(int arr[],int n){
    int sum=0;
    cout<<"Sum is "<<endl;
    for(int i=0; i<n ;i++){
        sum=sum+arr[i];
    }
    cout<<sum;
}
int main(){
int arr[]={5,4,3,2,2,1};
int size=sizeof(arr)/sizeof(arr[0]);
bubblesort(arr,size);

for(int i=0 ;i<size; i++){
    cout<<arr[i]<<" ";
}cout<<endl;
duplicate(arr,size);cout<<endl;
sum(arr,size);
return 0;
}*/
/*
      void addod(vector<int> &v,vector<int> &s,int i)
   {
       if(i<v.size())
    {
        if(i%2==1)
    {
    s.push_back(v[i]);
    }
    addod(v,s,i+1);
    }
    else return ;
   }
   void addeve(vector<int> &v,vector<int> &s,int i)
   {
       if(i<v.size())
    {
        if(i%2==0)
    {
    s.push_back(v[i]);
    }
    addeve(v,s,i+1);
    }
    else return ;
   }
vector<int> even(vector<int> &v, int i)
{
     vector<int> s;
    addeve(v,s,0);
    return s;    
}
vector<int> odd(vector<int> &v, int i)
{
    
    vector<int> s;
    addod(v,s,0);
    return s;

}
void solve(vector<int> &v)
{
    if (v.size() < 0)
    {
        return;
    }
    if (v.size() <= 2)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        return;
    }
    vector<int> a = even(v, 0);
    vector<int> b = odd(v, 0);
    solve(a);
    solve(b);
    return;
}
int main()
{
    vector<int> v = {1, 2, 3,4,5};
    solve(v);
    return 0;
}*/
/*
void solve(string a,string s)
{
    if(a.length()==0)
    {
        cout<<s<<" ";
        return;
    }
    
    for(int i=0;i<a.size();i++)
    {
    if(se.count(a[i])==0)
    {
        se.insert(a[i]);
        string ros=a.substr(0,i)+a.substr(i+1);
        solve(ros,s+a[i]);

    }
    }
    return;

}
int main()
{
    solve("AACC","");
    return 0;
}*/
/*
void solve(vector<int> &v,int ind,int target,vector<int> &s)
{
        if(target==0)
        {
            for(int i=0;i<s.size();i++)
            {
                cout<<s[i]<<" ";
            }
            cout<<endl;
            return;
        }
    for(int i=ind;i<v.size();i++)
    {
        if(i>ind && v[i]==v[i-1]) continue;
        if(target<v[i]) break;
        s.push_back(v[i]);
        solve(v,i+1,target-v[i],s);
        s.pop_back();
    }
    return;
}
int main()
{
    vector<int> v={1,1,1,2,2};
    vector<int> s;
    solve(v,0,4,s);
    return 0;
}
*/
/*
void insert(vector<int> &v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<temp)
    {
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
}
void solve(vector<int> &v)
{
    if(v.size()==1)
    {
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    solve(v);
    insert(v,temp);
}
int main()
{
    vector<int> v={1,0,5,2};
    solve(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}*/
/*
bool ispalindrome(string v,int ind,int end)
{
    while(ind<=end)
    {
        if(v[ind++]!=v[end--])
        {
            return false;
        }
    }
    return true;
}
void solve(int ind,string v,vector<string> &d)
{
    if(ind==v.size())
    {
        for(int i=0;i<d.size();i++)
        {
        cout<<d[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=ind;i<v.size();i++)
    {
        if(ispalindrome(v,ind,i))
        {
            d.push_back(v.substr(ind,i-ind+1));
            solve(i+1,v,d);
            d.pop_back();
        }
    }

}

void solve(int ind,vector<int> &v,int val)
{
    if(ind==v.size())
    {
        return;
    }
    for(int i=0;i<v.size();i++)
    {
    val=val*v[ind];
    solve(ind+1,v,val);
    cout<<val<<" ";
}
}
int main()
{
    vector<int> v={1,2,3,4,5};
    solve(0,v,1);
    return 0;
}
*/
/*
bool isSafe(int a,int b,vector<vector<int>> &ve,vector<vector<int>> &is)
{
     if(a>=0 && a<ve.size() && b>=0 && b<ve[0].size() && !is[a][b] && !ve[a][b])
     {
         return true;
     }
     return false;
}
int cnt=0;
bool solve(vector<vector<int>> &v,vector<vector<int>> &vis,int col,int row)
{
    if(!isSafe(row,col,vector<vector<int>> v,vector<vector<int>> vis))
    {
        return false;
    }
    else
    {
        v[row][col]=1;
        if(solve(v,vis,col,row+1) && solve(v,vis,col-1,row) && solve(v,vis,col,row-1) && solve(v,vis,col+1,row))
        {
            cnt++;
            return true;
        }
        return false;
    }
}*/
#include <bits/stdc++.h>
using namespace std;
/*
string solve(int n, int k)
{
    int fact = 1;
    vector<int> v;
    for (int i = 1; i < n; i++)
    {
        fact =fact*i;
        v.push_back(i);
    }
    v.push_back(n);
    k = k - 1;
    string s = "";
    while (true)
    {
        s =s + to_string(v[k / fact]);
        v.erase(v.begin() + (k / fact));
        if (v.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / v.size();
    }
    return s;
}
*/
/*
***is circle or not***
bool isrotatable(vector<int> &v)
{
    if(v.size()==1||v.size()==2||v.size()==3)
    {
        return true;
    }
    else{
    for(int i=1;i<v.size();i++)
    {
        if(!(abs(v[i]-v[i-1])==1)&&!(abs(v[i]-v[i-1])==v.size()-1))
        {
            return false;
        }
    }
    return true;
    
    }
}
*/
/*
 double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0,i=0;
        double avg=-1000.0,sum=0.0;
        while(j<n)
        {
            if(j-i+1<=k)
            {
                sum+=double(nums[j]);
            }            
            if(j-i+1>k)
            {
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k)
            {
                double ag=sum/k;
                if(avg<(ag))
                {
                    avg=ag;
                }
            }
            j++;
        }
        return avg;
    }
    */
/*
   int findLength(vector<int>& nums1, vector<int>& nums2) {
        long long cnt,ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    int k=1;
                    cnt=1;
                    while(nums1[i+k]==nums2[j+k] && (i+k)<nums1.size() && (j+k)<nums2.size())
                    {
                        k++;
                        cnt++;
                    }
                     ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
int main()
{
    /*vector<int> v={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> k={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   cout<< findLength(v,k);
   */
/*
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        if(isrotatable(v))
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
};

vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
    solve(grid,vis,0,0);

    return 0;
}
*/
/*#include<bits/stdc++.h>
using namespace std;
int mini=INT_MAX;
void sets(int sr,int sc,int er,int ec,vector<vector<int>> &v,int cnt)
{
    if(sr>7 || sc>7 || sr<0 || sc<0)
    {
        return ;
    }
    if(sr==er && sc==ec)
    {
       mini=min(mini,cnt);
       return ;
    }
    
    if(v[sr][sc]==0 && cnt<=mini)
    {
        v[sr][sc]=1;
    sets(sr+2,sc+1,er,ec,v,cnt+1);
    sets(sr+2,sc-1,er,ec,v,cnt+1);
 sets(sr-2,sc+1,er,ec,v,cnt+1);
    sets(sr-2,sc-1,er,ec,v,cnt+1);
    sets(sr+1,sc+2,er,ec,v,cnt+1);
    sets(sr+1,sc-2,er,ec,v,cnt+1);
    sets(sr-1,sc+2,er,ec,v,cnt+1);
    sets(sr-1,sc-2,er,ec,v,cnt+1);
    }
    v[sr][sc]=0;
    return ;
}
int main()
{
    vector<int> s;
    vector<vector<int>> v(8,vector<int>(8,0));
    
    sets(7,0,0,5,v,0);
    cout<<mini;
    return 0;
}
#include<iostream>
using namespace std;

void rsprint(int a[5][5], int is, int js, int je){
    if(js<=je){
        cout<<a[is][js]<<" ";
        rsprint(a,is,js+1,je);
    }return;
}

void ceprint(int a[5][5], int is, int ie, int je){
    if(is<=ie){
        cout<<a[is][je]<<" ";
        ceprint(a,is+1,ie,je);
    }return;
}

void reprint(int a[5][5], int ie, int js, int je){
    if(js<=je){
        cout<<a[ie][je]<<" ";
        reprint(a,ie,js,je-1);
    }return;
}

void csprint(int a[5][5], int is, int ie, int js){
    if(is<=ie){
        cout<<a[ie][js]<<" ";
        csprint(a,is,ie-1,js);
    }return;
}

void spiral(int a[5][5], int rstart, int rend, int cstart, int cend){
    if(rstart>rend || cstart>cend){
        return;
    }
    if(rstart<=rend){
    rsprint(a,rstart,cstart,cend);
    rstart++;
    }
    if(cstart<=cend){
    ceprint(a,rstart,rend,cend);
    cend--;
    }
    if(rstart<=rend){
    reprint(a,rend,cstart,cend);
    rend--;
    }
    if(cstart<=cend){
    csprint(a,rstart,rend,cstart);
    cstart++;
    }
    spiral(a,rstart,rend,cstart,cend);
}

int main(){
    int matrix[5][5] = {
        {1,  2,  3,  4,  5},

        {16, 17, 18, 19, 6},

        {15, 24, 25, 20, 7},

        {14, 23, 22, 21, 8},

        {13, 12, 11, 10, 9}
    };
    spiral(matrix,0,4,0,4);
    return 0;
}*/
/*
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int target;
    cin>>target;
    int i=0,j=0,
    while()
  return 0;  
}*/

#include <iostream>
using namespace std;
#define d 5
class stak
{
    int t;
    int a[d];

public:
    stak()
    {
        t = -1;
        for(int i=0;i<d;i++)
        {
            a[i]=0;
        }
    }
    bool isEmpty()
    {
        if (t == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (t == d - 1)
            return true;
        else
            return false;
    }
    void push(int n)
    {
        if (isFull())
            cout << "Stack is overflow. Can't add new member." << endl;
        else
        {
            t++;
            a[t] = n;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is underflow. Can't operate pop function." << endl;
            return 0;
        }
        else
        {
            int p = a[t];
            t--;
            return p;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is underflow. Can't operate peek function." << endl;
            return 0;
        }
        else
        {
            return a[t];
        }
    }
    void display()
    {
        for(int i=0;i<d;i++)
        {
            cout<<a[i]<<" ";
        }
    }
};
/*
#include <iostream>
using namespace std;
#define d 5
class stak
{
    int t;
    int a[d];

public:
    stak()
    {
        t = -1;
        for(int i=0;i<d;i++)
        {
            a[i]=0;
        }
    }
    bool isEmpty()
    {
        if (t == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (t == d - 1)
            return true;
        else
            return false;
    }
    void push(int n)
    {
        if (isFull())
            cout << "Stack is overflow. Can't add new member." << endl;
        else
        {
            t++;
            a[t] = n;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is underflow. Can't operate pop function." << endl;
            return 0;
        }
        else
        {
            int p = a[t];
            t--;
            return p;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is underflow. Can't operate peek function." << endl;
            return 0;
        }
        else
        {
            return a[t];
        }
    }
    void display()
    {
        for(int i=0;i<d;i++)
        {
            cout<<a[i]<<" ";
        }
    }
};
*/
int main()
{
    stak s;
    int value,pos,choice;
    do{
        cout<<"1. Empty status:\n";
        cout<<"2. Full status:\n";
        cout<<"3. Push function:\n";
        cout<<"4. Pop fuction:\n";
        cout<<"5. Peek functin:\n";
        cout<<"6. Display function:\n";
        cout<<"Enter proper number according to your work:\n";
        cin>>choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
           if(s.isEmpty())
           {
            cout<<"Stack is empty."<<endl;
           }
          else{
            cout<<"Stack is not empty."<<endl;
          }
            break;
        case 2:
           if(s.isFull()){
             cout<<"Stack is full."<<endl;}
           else{
             cout<<"Stack is not full."<<endl;}
             break;
        case 3:
            cout<<"Enter the value to push in stack: ";
            cin>>value;
            s.push(value);
            break;
        case 4:
            cout<<"Pop value: "<<s.pop()<<endl;
            break;
        case 5:
            cout<<"Peek value at top position is: "<<s.peek()<<endl;
            break;
        case 6:
            cout<<"Display Stack members:\n";
            s.display();
            cout<<endl;
            break;
        default:
            cout<<"Enter proper choice."<<endl;
        }
    }while(choice!=0);
     /*string infix_exp, postfix_exp;
  	cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix_exp;
  	stak s;
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	postfix_exp = InfixToPostfix(s, infix_exp);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
	  return 0;
      */
   
}

    
/* evaluate postfix expression****
    stak s;
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            s.push(a[i]-'0');
        }
        else 
        {
            if(a[i]=='+')
            {
                int op1=s.pop();
                int op2=s.pop();
                int op3=(op1)+(op2);
                int o=op3;
                s.push(o);
            }
            if(a[i]=='-')
            {
                int op1=s.pop();
                int op2=s.pop();
                int op3=(op2)-(op1);
                int o=op3;
                s.push(o);
            }
            if(a[i]=='*')
            {
                int op1=s.pop();
                int op2=s.pop();
                int op3=(op1)*(op2);
                int o=op3;
                s.push(o);
            }
            if(a[i]=='/')
            {
                int op1=s.pop();
                int op2=s.pop();
                int op3=((op2)+0.5)/(op1);
                int o=op3;
                s.push(o);
            }

        }
    }
    cout<<s.top()<<" ";
    */
/*
int value,pos,choice;
    do{
        cout<<"1. Empty status:\n";
        cout<<"2. Full status:\n";
        cout<<"3. Push function:\n";
        cout<<"4. Pop fuction:\n";
        cout<<"5. Peek functin:\n";
        cout<<"6. Display function:\n";
        cout<<"Enter proper number according to your work:\n";
        cin>>choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
           if(s.isEmpty())
           {
            cout<<"Stack is empty."<<endl;
           }
          else{
            cout<<"Stack is not empty."<<endl;
          }
            break;
        case 2:
           if(s.isFull()){
             cout<<"Stack is full."<<endl;}
           else{
             cout<<"Stack is not full."<<endl;}
             break;
        case 3:
            cout<<"Enter the value to push in stack: ";
            cin>>value;
            s.push(value);
            break;
        case 4:
            cout<<"Pop value: "<<s.pop()<<endl;
            break;
        case 5:
            cout<<"Peek value at top position is: "<<s.peek()<<endl;
            break;
        case 6:
            cout<<"Display Stack members:\n";
            s.display();
            cout<<endl;
            break;
        default:
            cout<<"Enter proper choice."<<endl;
        }
    }while(choice!=0);
    */