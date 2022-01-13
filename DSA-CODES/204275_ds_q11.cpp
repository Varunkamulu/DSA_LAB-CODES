#include<iostream>
using namespace std;  

class node
{
    public:
      int key;
      node* next;
      node()
      {
          key=0;
          next=NULL; 
      }    
      node(int k)
      {
          key=k;
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
      linkedlist(node* n)
      {
          head=n;
      }

      bool empty()
      {
          if(head==NULL)
            return true;
          else
            return false;
      }
      void add_end(node* n)
      {
          //pushing the element in O(1)
          if(head==NULL)
          {
              head=n;
          }
          else{
              node* ptr=head;
              head=n;
              n->next=ptr;
          }
      }

      int delete_end()
      {
          //poping in O(1)
          node* temp=head;
          head=head->next;
          return temp->key;
      }

      void display()
      {
          //printing the elements
          node* ptr=head;
          while(ptr!=NULL)
          {
              cout<<" <-> "<<ptr->key<<" <-> ";
              ptr=ptr->next;
          }
      }
};

class stack
{
    public:
      linkedlist l;

      void push(int n)
      {
          //pushing the elements in the stack
          node* n1=new node;
          n1->key=n;
          l.add_end(n1);
      }

      int pop()
      {
          //poping the elements of stack
          l.delete_end();
      }

      void print()
      {
          //printing the elements of stack
          l.display();
      }
};

int main()
{
    stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    cout<<"the poped value is : "<<s.pop()<<endl;
    s.print();
    return 0;
}