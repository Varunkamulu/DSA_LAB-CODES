#include<iostream>
using namespace std;
void heapify(int a[],int n,int i)
{
    int maxi=i;
    int l=2*i+1;
    int r=2*i+2;
    if(a[l]>a[maxi]&&l<n)maxi=l;
    if(a[r]>a[maxi]&&r<n)maxi=r;
    if(maxi!=i)
    {
        swap(a[i],a[maxi]);
        heapify(a,n,maxi);
    }
}
void solve()
{
    int n;
    cout<<"enter the number of elements present : ";
    cin>>n;
    int a[n];
    cout<<"enter the elements in array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
    cout<<"elements after the sort are : ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main(){
int t;
cout<<"enter";
cin>>t;
 while(t--)
  solve();
return 0;
}