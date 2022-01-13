#include<iostream>
using namespace std;  
int cnt=0;
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
      }
};


class linkedlist
{
    public:
      node* head,*head1;
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
          //pushing the element 
        cnt++;
          if(head==NULL)
          {
              head=head1=n;
          }
          else{
                head->next=n;
                head=n;
              if(cnt==2)
              {
                  //this is the condition to only give the link btw first node and the next one because the rest are automatically linked from the above lines(50,51)
                head1->next=head;
              }
          }
      }
      int delete_end()
      {
          //deleting in O(1)
          node* temp=head1;
          head1=head1->next;
          return temp->key;
      }
      void display()
      {
          node* ptr=head1;
          while(ptr!=NULL)
          {
              cout<<ptr->key<<" -> ";
              ptr=ptr->next;
          }
      }
};
class queue
{
    public:
      linkedlist q;

      void push(int n)
      {
          //pushing the element into the queue
          node* n1=new node();
          n1->key=n;
          q.add_end(n1);
      }
      int pop()
      {//poping the element 
          q.delete_end();
      }

      void print()
      {
          //displaying the elements
          q.display();
      }
};

int main()
{
    queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(8);
    q.push(8);
    q.push(8);
    cout<<"the poped element is "<<q.pop()<<endl;
    q.print();
}