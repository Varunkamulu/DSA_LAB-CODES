#include <iostream>
using namespace std;
typedef long long ll;
#define d 500
class stak
{
    int t;
    double a[d];

public:
    stak()
    {
        t = -1;
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
    void push(double n)
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
    double pop()
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
    double top()
    {
        return a[t];
    }
    double peek()
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
bool isnumber(char ch)
{
    if((ch-'0')>=0 && (ch-'0')<=9)return true;
    else return false;
}
/*
    algo in breif: 
     ->reversely iterated the prefix expression
     ->and did the same kind of evaluation of postfix
     ->no result means invalid expression
*/
int main()
{
    stak s;
    string str;
    cin>>str;
    //reverse iteration of the given string
    for(int i=str.length()-1;i>=0;i--)
    {
        if(isnumber(str[i]))
        {
            s.push(str[i]-'0');
        }
        else 
        {
             if(s.isEmpty()){cout<<"no result"<<endl;return 0;}
            double op1=s.top();s.pop();
            if(s.isEmpty()){cout<<"no result"<<endl;return 0;}
            double op2=s.top();s.pop();
            if(str[i]=='+')
            {
                s.push(op1+op2);
            }
            if(str[i]=='-')
            {
                s.push(op1-op2);
            }
            if(str[i]=='*')
            {
                s.push(op1*op2);
            }
            if(str[i]=='/')
            {
                s.push(op1/op2);
            }
        }
    }
    double op=s.top();
    s.pop();
    if(s.isEmpty())cout<<"the string is valid postfix expression and the result is : "<<op<<endl;
    if(!s.isEmpty())cout<<"the string is invalid postfix expression "<<endl;
    return 0;
}