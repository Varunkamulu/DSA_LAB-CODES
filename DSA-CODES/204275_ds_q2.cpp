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
int main()
{
    stak s;
    string a;
    cin>>a;
    string e[6][5];
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            s.push(a[i]-'0');
            e[i][0]=a[i];
        }
        else 
        {
            if(a[i]=='+')
            {
                //addition
                int op1=s.pop();
                e[i][1]=op1+'0';
                int op2=s.pop();
                e[i][2]=op1+'0';
                int op3=(op1)+(op2);
                e[i][3]=op3+'0';
                int o=op3;
                s.push(o);
            }
            if(a[i]=='-')
            {
                //subtraction
                int op1=s.pop();
                e[i][1]=op1+'0';
                int op2=s.pop();
                e[i][2]=op1+'0';
                int op3=(op2)-(op1);
                e[i][3]=op1+'0';
                int o=op3;
                s.push(o);
            }
            if(a[i]=='*')
            {
                //multiplication
                int op1=s.pop();
                e[i][1]=op1+'0';
                int op2=s.pop();
                e[i][2]=op1+'0';
                int op3=(op1)*(op2);
                e[i][3]=op1+'0';
                int o=op3;
                s.push(o);
            }
            if(a[i]=='/')
            {
                //division
                int op1=s.pop();
                e[i][1]=op1+'0';
                int op2=s.pop();
                e[i][2]=op1+'0';
                int op3=((op2)+0.5)/(op1);
                e[i][3]=op1+'0';
                int o=op3;
                s.push(o);
            }

        }
    }
    cout<<"the result is expected on "<<a.size()+1<<" th step"<<endl;
    cout<<"the result is : "<<s.top()<<" ";
    return 0;
}