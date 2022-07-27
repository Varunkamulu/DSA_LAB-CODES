#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
      int key;
      node* next;
      // node* prev;
      node()
      {
          key=0;
          next=NULL; 
      }    
      node(int k)
      {
          key=k;
          next=NULL;
      }
};
class linkedlist
{
    public:
    node* head;
    linkedlist()
    {
        head=NULL;
    }
    void insert(int v)
    {
        node* head1=head;
        if(head==NULL)
        {
            head=new node(v);
        }
        node *dummy=new node(-1);
        dummy->next=head;
        while(dummy->next && dummy->next->key<v)
        {
            dummy=dummy->next;
        }
        if(dummy->next==head)
        {
            node* newnode=new node(v);
            newnode->next=head;
            head=newnode;
        }
        else{
            node* newnode=new node(v);
            node* nextnode=dummy->next;
            dummy->next=newnode;
            newnode->next=nextnode;
        }
    }
    void find(int v)
    {
        node* head1=head;
        bool flag=false;
        while(head1)
        {
            if(head1->key==v)
            {
                flag=true;
                break;
            }
            head1=head1->next;
        }
        if(flag)
        {
            cout<<"element found"<<endl;
        }
        else
        {
            cout<<"element not found"<<endl;
        }
    }
    void print()
    {
        node* head1=head;
        while(head1)
        {
            cout<<head1->key<<" ";
            head1=head1->next;
        }
        cout<<endl;
    }
};
int main()
{

    return 0;
}