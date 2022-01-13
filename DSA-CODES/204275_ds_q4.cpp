#include<iostream>
using namespace std;

class queue
{
    int front=-1,back=-1;
    int a[5];
    public:
    queue()
    {
       for(int i=0;i<5;i++)
       {
           a[i]=0;
       }
    }
    bool isempty()
    {
        if(front==-1 && back==-1)
        {
            return true;
        }
        else return false;
    }
    bool isfull()
    {
        if((back+1)%5==front)
        {
            return true;
        }
        else return false;
    }
    void enque(int n)
    {
        if(isfull())
        {
            cout<<"the queue is full"<<endl;
            return ;
        }
        if(isempty())
        {
            front=0,back=0;
            a[front]=a[back]=n;
        }
        else
        {
            back=(back+1)%5;
             a[back]=n;
        }
    }
    int dequeue()
    {
        int x;
        if(isempty())
        {
            cout<<"the queue is empty"<<endl;
            return -1;
        }
        if(front==back)
        {
            x=a[front];
            a[front]=0;
            front=-1,back=-1;
        }
        else
        {
            x=a[front];
            a[front]=0;
            front=(front+1)%5;
        }
    }
    void display()
    {
        if(isempty())
        {
            cout<<"the queue is empty"<<endl;
        }
        else
        {
        for(int i=0;i<5;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }}
    

};
int main()
{
    queue q;
    q.enque(1);
    q.enque(9);
    q.enque(3);
    q.enque(7);
    q.enque(4);
    q.dequeue();
    q.enque(3);
    q.display();
    return 0;
}