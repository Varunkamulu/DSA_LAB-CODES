#include <bits/stdc++.h>
using namespace std;
int a[500];
class linear_hashing
{
  int cnt;
  public:
  linear_hashing()
  {
    for(int i=0;i<500;i++)
    {
      a[i]=-1;
    }
    cnt=0;
  }
  void push(int n,int d)
  {
    // pushes elements if there is valid empty space in the hash table
    if(cnt==d)
    {
      cout<<"cant add further elements"<<endl;
      return;
    }
    cnt++;
    if(a[n%d]==-1)
    {
       a[n%d]=n;
    }    
    else
    {
      
       int x=n;
       while(a[n%d]!=-1)
       {
         n=n+1;
       }
       a[n%d]=x;
    }
  }
    void delet(int n,int d)
  {
    //deletes element if exists
    for (int i = 0; i < d; i++)
        {
            if(a[i]==n)
            {
              cout<<a[i]<<"is deleted"<<endl;
              a[i]=-1;
              return;
            }
        }
        cout<<"element not found"<<endl;
  }
  void display(int d)
  {
    //displays elements
    for(int i=0;i<d;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
};
class quadratic_hashing
{
  int cnt;
  public:
  quadratic_hashing()
  {
    for(int i=0;i<500;i++)
    {
      a[i]=-1;
    }
    cnt=0;
  }
  void push(int n,int d)
  {
    // pushes elements if there is valid empty space in the hash table
    if(cnt==d)
    {
      cout<<"cant add further elements"<<endl;
      return;
    }
    cnt++;
    if(a[n%d]==-1)
    {
       a[n%d]=n;
    }    
    else
    {
      
       int x=n;
       int i=1;
       while(a[n%d]!=-1)
       {
         n=n+i*i;
         i++;
       }
       a[n%d]=x;
    }
  }
    void delet(int n,int d)
  {
    //deletes element if exists
    for (int i = 0; i < d; i++)
        {
            if(a[i]==n)
            {
              cout<<a[i]<<"is deleted"<<endl;
              a[i]=-1;
              return;
            }
        }
        cout<<"element not found"<<endl;
  }
  void display(int d)
  {
    //displays elements
    for(int i=0;i<d;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
};
class double_hashing
{
  int cnt;
  public:
  double_hashing()
  {
    for(int i=0;i<500;i++)
    {
      a[i]=-1;
    }
    cnt=0;
  }
  void push(int n,int d)
  {
    // pushes elements if there is valid empty space in the hash table
    if(cnt==d)
    {
      cout<<"cant add further elements"<<endl;
      return;
    }
    cnt++;
    if(a[n%d]==-1)
    {
       a[n%d]=n;
    }    
    else
    {
      
       int x=n;
       int i=1;
       while(a[n%d]!=-1)
       {
         n=(x+i*(7-x%7))%d;//here H1=x H2=(7-x%7)
         i++;
       }
       a[n%d]=x;
    }
  }
  void delet(int n,int d)
  {
//deletes element if exists
    for (int i = 0; i < d; i++)
        {
            if(a[i]==n)
            {
              cout<<a[i]<<"is deleted"<<endl;
              a[i]=-1;
              return;
            }
        }
        cout<<"element not found"<<endl;
  }
  void display(int d)
  {
    //displays elements
    for(int i=0;i<d;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
};
int main()
{
  int n,t;
  cout<<"for linear hashing\n";
  linear_hashing hashtable1;
  cout<<"enter the size of array : ";
  cin>>t;
  while (1)
  {
    cout<<"enter the element"<<endl;
    cin>>n;
    if(n==-1)break;
    hashtable1.push(n,t);
  }
  hashtable1.display(t);
  hashtable1.delet(3,t);//deletes 3 from the hashtable if it exists
  hashtable1.display(t);
  int p,q;
  cout<<"for quadratic hashing\n";
  quadratic_hashing hashtable2;
  cout<<"enter the size of array : ";
  cin>>q;
  while (1)
  {
    cout<<"enter the element"<<endl;
    cin>>p;
    if(p==-1)break;
    hashtable2.push(p,q);
  }
  hashtable2.display(q);
  hashtable2.delet(3,q);//deletes 3 from the hashtable if it exists
  hashtable2.display(q);
  int a,b;
  cout<<"for double hashing\n";
  double_hashing hashtable3;
  cout<<"enter the size of array : ";
  cin>>b;
  while (1)
  {
    cout<<"enter the element"<<endl;
    cin>>a;
    if(a==-1)break;
    hashtable3.push(a,b);
  }
  hashtable3.display(b);
  hashtable3.delet(3,b);//deletes 3 from the hashtable if it exists
  hashtable3.display(b);
  return 0;
}