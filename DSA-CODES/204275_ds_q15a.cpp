//chain hashing by varun kamulu
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
class array1
{
    node *arr[508];

public:
    array1()
    {
        for (int i = 0; i < 500; i++)
        {
            arr[i] = NULL;
        }
    }
    void push(node *n,int d)
    {
        if (arr[(n->data) % d] == NULL)
        {
            arr[(n->data) % d] = n;
            arr[(n->data) % d]->next = NULL;
        }
        else
        {
            node *c = arr[(n->data) % d];
            while (c->next != NULL)
            {
                c = c->next;
            }
            c->next = n;
            n->next = NULL;
        }
    }
    bool search(int n,int d)
    {
        for (int i = 0; i < d; i++)
        {
            node *c = arr[i];
            if (c == NULL)
                return false;
            else
            {
                while (c != NULL)
                {
                    if(c->data==n)
                    {
                        return true;
                    }
                    c = c->next;
                }
            }
        }
        return false;
    }
    void delet(int n,int d)
    {
        //deletes elements if it exists in hashtable
        node *s = arr[n % d];
        if (!search(n,d))
        {
            cout << "no such element" << endl;
        }
        else
        {
            if (s->next == NULL)
            {
                arr[n % d] = NULL;
            }
            else
            {
                while (s->next->data != n && s->next != NULL)
                {
                    s = s->next;
                }
                s->next = s->next->next;
            }
        }
    }
    void display(int d)
    {
        //displays the elements
        for (int i = 0; i < d; i++)
        {
            node *c = arr[i];
            if (c == NULL)
                cout << "NA" << endl;
            else
            {
                while (c != NULL)
                {
                    cout << c->data << "->";
                    c = c->next;
                }
                cout << endl;
            }
        }
    }
};
int main()
{
    array1 hashtable;
    int n,d;
    cout<<"enter the size of hashtable : ";
    cin>>d;
    while (1)
    {
        node *b = new node;
        cout<<"enter the node value"<<endl;
        cin >> n;
        if (n == -1)
            break;
        b->data = n;
        hashtable.push(b,d);
    }
    cout<<"here I've hardcoded the size of hashtable to make things simple"<<endl;
    cout<<"before deletion"<<endl;
    hashtable.display(d);
    int del;
    cout<<"enter the value which is to be deleted : ";
    cin>>del;
    hashtable.delet(del,d);//deleting 9 from the hashtable if it exists
    cout<<"after deletion"<<endl;
    hashtable.display(d);
    return 0;
}