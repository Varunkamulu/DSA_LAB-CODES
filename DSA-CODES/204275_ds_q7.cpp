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
          for(int i=cnt-1;i>=0;i--)
          {
              cout<<a[i]<<" ";
          }
      }
};
class stack
{
    queue q1,q2;
    public:
     void push(int n)
     {
         //push function in O(N)
         while(!q1.isEmpty())
         {
             int x=q1.dequeue();
             q2.enqueue(x);
         }

         q1.enqueue(n);

         while(!q2.isEmpty())
         {
             int x=q2.dequeue();
             q1.enqueue(x);
         }
     }

     int pop()
     {
         //pop function in O(1)
         q1.dequeue();
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
        if(a[i]==-1)break;
        s.push(a[i]);
        cnt++;
    }


    cout<<"\nDisplay Stack elements:\n";
    cout<<"Here the last element represents the top element of stack\n";
    s.print();
    cout<<"\nDequeue stack elements:\n";
    cout<<"Here the first element represents the first element poped out element of stack\n";
    for(int i=0; i<cnt; i++)
    {
        cout<<s.pop()<<" ";
    }
}