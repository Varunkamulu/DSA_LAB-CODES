#include<iostream>
using namespace std;

void merge(int a[], int n, int m, int h)
{
    int i=n,j=m+1,k=n,t[10];
    
    while(i<=m && j<=h)
    {
        if(a[i]<=a[j])
        {
            t[k]=a[i];
            k++;
            i++;
        }
        else
        {
            t[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        t[k]=a[i];
        k++;i++;
    }
    while(j<=h)
    {
        t[k]=a[j];
            k++;
            j++;
    }

    for(int x=n; x<=h; x++)
    {
        a[x]=t[x];
    }

}

void mergesort(int a[], int n, int h)
{
    if(n<h)
    {
      int m=(n+h)/2;
      mergesort(a,n,m);
      mergesort(a,m+1,h);

      merge(a,n,m,h);
    }
}

int main()
{
  int i,j,s,n,a[10];
  cout<<"Enter number of array elements: ";
  cin>>n;
  
  cout<<"\nEnter array element: ";
  for(i=0; i<n; i++)
  {
    cin>>a[i];
  }

  cout<<"\nArray element: ";
  for(i=0; i<n; i++)
  {
    cout<<a[i]<<" ";
  }

  mergesort(a,0,n-1);
  cout<<"\n\nSorted array by MERGE SORT: ";

  for(i=0; i<n; i++)
  {
    cout<<a[i]<<" ";
  }

  return 0;
}