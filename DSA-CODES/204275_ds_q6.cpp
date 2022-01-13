#include <iostream>
using namespace std;  
#define d 500
int cnt=0;
class queue
{
    int front,rear,a[d];
    public:
      queue()
      {
          front=rear=-1;
      }
      bool isEmpty()
      {
          if(front==-1 && rear==-1)
             return true;
          else
             return false;
      }
      void enqueue(int n)
      {
          if(isEmpty())
          {
              front=rear=0;
              a[rear]=n;
          }
          else
          {
              rear++;
              a[rear]=n;
          }
      }
      int dequeue()
      {
          int x;
          if(isEmpty())
          {
              cout<<"Stack is empty.";
              return 0;
          }
          else if(rear==front)
          {
              x=a[front];
              a[front]=0;
              rear=front=-1;
          }
          else
          {
              x=a[front];
              a[front]=0;
              front++;
          }
          return x;
      }
      void display()
      {
          cout<<"Stack members:\n";
          for(int i=0;i<cnt;i++)
          {
              cout<<a[i]<<" ";
          }
      }
      int size()
      {
        return (rear-front+1);
      }
};
class stack
{
    queue q1,q2;
    public:
     void push(int n)
     {
         q1.enqueue(n);
     }

     int pop()
     {
         int k=q1.size();
        for(int i=0; i<k-1; i++)
        {
            q2.enqueue(q1.dequeue());
        }
        int x=q1.dequeue();
        while(!q2.isEmpty())
        {
            q1.enqueue(q2.dequeue());
        }
        return x;
     }

     void print()
     {
         q1.display();
     }
};

int main()
{
    stack s;int a[d];
    cout<<"Enter element into stack:\npress -1 to exit\n";

    int i=0;
    while(1)
    {
        cin>>a[i];
        if(a[i]==-1)
        {
            break;
        }
        s.push(a[i]);
        cnt++;
    }


    cout<<"\nDisplay Stack elements:\nthe top is the last element\n";
    s.print();

    cout<<"\nDequeue stack elements:\nthe top is the first element\n";
    for(int i=0; i<cnt; i++)
    {
        cout<<s.pop()<<" ";
    }
}