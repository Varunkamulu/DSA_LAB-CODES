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
bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

string InfixToPostfix(stak s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z')
		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.isEmpty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if(isOperator(infix[i]))
		{
			if(s.isEmpty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}	
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.isEmpty())&&( precedence(infix[i])<=precedence(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.isEmpty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}
int main()
{
    string infix_exp, postfix_exp;
  	cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix_exp;
  	stak s;
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	postfix_exp = InfixToPostfix(s, infix_exp);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
	  return 0;
    return 0;
}