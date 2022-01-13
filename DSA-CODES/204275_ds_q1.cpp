#include <iostream>
using namespace std;
#define d 5
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
        //returns true if stack is empty else returns false
        if (t == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {  
        //returns true if stack is full else returns false
        if (t == d - 1)
            return true;
        else
            return false;
    }
    void push(int n)
    {
        //push element in stack
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
        //pop element from stack
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
        //returns the top element of the stack
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
    void display()
    {
        //displays all elements of stack
        for(int i=0;i<d;i++)
        {
            cout<<a[i]<<" ";
        }
    }
};
int main()
{
    stak s;
    int value,pos,choice;
    do{
        cout<<"1. Empty status:\n";
        cout<<"2. Full status:\n";
        cout<<"3. Push function:\n";
        cout<<"4. Pop fuction:\n";
        cout<<"5. Peek functin:\n";
        cout<<"6. Display function:\n";
        cout<<"Enter proper number according to your work:\n";
        cin>>choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
           if(s.isEmpty())
           {
            cout<<"Stack is empty."<<endl;
           }
          else{
            cout<<"Stack is not empty."<<endl;
          }
            break;
        case 2:
           if(s.isFull()){
             cout<<"Stack is full."<<endl;}
           else{
             cout<<"Stack is not full."<<endl;}
             break;
        case 3:
            cout<<"Enter the value to push in stack: ";
            cin>>value;
            s.push(value);
            break;
        case 4:
            cout<<"Pop value: "<<s.pop()<<endl;
            break;
        case 5:
            cout<<"Peek value at top position is: "<<s.peek()<<endl;
            break;
        case 6:
            cout<<"Display Stack members:\n";
            s.display();
            cout<<endl;
            break;
        default:
            cout<<"Enter proper choice."<<endl;
        }
    }while(choice!=0);
    return 0;
}