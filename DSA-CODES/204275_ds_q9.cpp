#include<iostream>
using namespace std;
#define d 50
class stak
{
    int t;
    int a[d];

public:
    stak()
    {
        t = -1;
        for(int i=0;i<d;i++)
        {
            a[i]=0;
        }
    }
    bool isEmpty()
    {
        if (t == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (t == d - 1)
            return true;
        else
            return false;
    }
    void push(int n)
    {
        if (isFull())
            cout << "Stack is overflow. Can't add new member." << endl;
        else
        {
            t++;
            a[t] = n;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is underflow. Can't operate pop function." << endl;
            return 0;
        }
        else
        {
            int p = a[t];
            t--;
            return p;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is underflow. Can't operate peek function." << endl;
            return 0;
        }
        else
        {
            return a[t];
        }
    }
    int top()
    {
        return a[t];
    }
    void display()
    {
        for(int i=0;i<d;i++)
        {
            cout<<a[i]<<" ";
        }
    }
};
class que
{
      stak s1, s2;
public:
    void enqueue(int n)
    {
        //enqueue in constant linear complexity O(N)
        if(s1.isEmpty())
        {
            s1.push(n);
        }
        else{
            while (!s1.isEmpty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(n);
            while (!s2.isEmpty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        cout<<"the value : "<<n<<" enqueued successfully "<<endl;
     return ;
    }
    void dequeue()
    {
        //dequeue in constant time complexity O(1)
        if(s1.isEmpty())
        {
            cout<<"the queue is empty "<<endl;
            return ;
        }
        cout<<"the value : "<<s1.pop()<<" dequeued successfully "<<endl;
       return ;
    }
};

int main()
{
    que q1;
    q1.enqueue(5);
    q1.enqueue(63);
    q1.enqueue(25);
    q1.enqueue(53);
    q1.dequeue();
    q1.dequeue();
    return 0;
}