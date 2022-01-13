#include<bits/stdc++.h>
using namespace std;
                         
int partition(int a[],int l, int h)
{
    int i=l+1,j=h-1;
    int p=a[l];

    while(i<=j)
    {
        while(a[i]<p)
        {
            i++;
        }
        while(a[j]>p)
        {
            j--;
        }
        if(i<j)
        {
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int k=a[l];
    a[l]=a[j];
    a[j]=k;

    return j;
}

void quick(int a[], int l, int h)
{
    if(l<h)
    {
        int x=partition(a,l,h);
        quick(a,0,x);
        quick(a,(x+1),h);
    }
}

int main()
{
  int i,l,a[10];
  cout<<"\nEnter size of array: ";
  cin>>l;
  
  cout<<"\nEnter Array elements: ";
  for(i=0; i<l; i++)
  {
    cin>>a[i];
  }

  cout<<"\nArray elements: ";
  for(i=0; i<l; i++)
  {
    cout<<a[i]<<" ";
  }

  quick(a,0,l);
  cout<<"\nafter sorting: ";

  for(i=0; i<l; i++)
  {
    cout<<a[i]<<" ";
  }
}