#include<iostream>
using namespace std;

int insertion(int a[], int n)
{
    int j,t,s;
    for(int i=1; i<n; i++)
    {
        s=a[i];
        j=i-1;
        while(a[j]>s && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=s;
    }
    cout<<"\nafter sorting ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n],i;

    cout<<"\nEnter array elements: ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    cout<<"\nArray elements: ";
    for(i=0; i<n; i++)
    {
        cout<<a[i]<< " ";
    }

    insertion(a,n);
}