/*
   VARUN KAMULU
   204275
   SECTION-B
*/
#include <iostream>
#include <cstring>
using namespace std;
int cnt = 0;
class node
{
public:
  string name;
  node *next;
  node()
  {
    name = "";
    next = NULL;
  }
  node(string d)
  {
    name = d;
  }
};
bool compare(string s,string a)
{
    return s<a; 
}
class singlylinkedlist
{
public:
  node *head;
  singlylinkedlist()
  {
    head = NULL;
  }
  singlylinkedlist(node *n)
  {
    cnt++;
    head = n;
  }
  // 3. Adding element at begin by a node.
  void Add_at_beginning(node *n)
  {
    cnt++;
    n->next = head;
    head = n;
  }
  void addnode_at_pos(node *n)
  {
    cnt++;
    node *ptr = head;
    if (head==NULL || head->name>n->name)
    {
      Add_at_beginning(n);
    }
    else
    {
      while (ptr->next!=NULL && compare((ptr->next->name),(n->name)))
      {
        ptr = ptr->next;
      }
      n->next = ptr->next;
      ptr->next = n;
    }
  }
  void display()
  {
    if (head == NULL)
    {
      cout << "List is empty.";
    }
    else
    {
      node *ptr = head;
      while (ptr != NULL)
      {
        cout << ptr->name << " -> ";
        ptr = ptr->next;
      }
    }
  }
  void isEmpty()
  {
    if (head == NULL)
    {
      cout << "the list is empty" << endl;
      return;
    }
    else
    {
      cout << "the list is not empty" << endl;
      return;
    }
  }
  friend node* mergelists(node* ,node*);
};
//merge two sorted lists in a sorted order using recursion 
node* mergelists(node *n1,node* n2)
{
    //  if(!n1)return n2;
    //  if(!n2)return n1;
    //  if(n1->name<n2->name)
    //  {
    //      n1->next=mergelists(n1->next,n2);
    //      return n1;
    //  }
    //  else 
    //  {
    //      n2->next=mergelists(n1,n2->next);
    //      return n2;
    //  }
    node* ptr=n1;
    node* ptr1=n2;
    node* dum=new node();
    node* dummi=dum;
    while(ptr && ptr1)
    {
          if(ptr->name<ptr1->name)
          {
            dum->next=ptr;
            ptr=ptr->next;
          }
          else 
          {
            dum->next=ptr1;
            ptr1=ptr1->next;
          }
          dum=dum->next;
    }
    while(ptr)
    {
      dum->next=ptr;
      ptr=ptr->next;
      dum=dum->next;
    }
    while(ptr1)
    {
      dum->next=ptr1;
      ptr1=ptr1->next;
      dum=dum->next;
    }
return dummi;
}

int main()
{
  singlylinkedlist s1,s2;
  cout<<"enter the list-1 : "<<endl;
  cout<<"enter exit to finish"<<endl;
  string s;
  while(1)
  {
    cin>>s;
    if(s=="exit" || s=="Exit")break;
    node* n=new node();
    n->name=s;
    s1.addnode_at_pos(n);
  }
  s1.display();
  cout<<endl;
  cout<<"enter the list-2 : "<<endl;
  cout<<"enter exit to finish"<<endl;
  string str;
  while(1)
  {
    cin>>str;
    if(str=="exit" || str=="Exit")break;
    node* n=new node();
    n->name=str;
    s2.addnode_at_pos(n);
  }
  s2.display();
    cout<<endl;
  node* n12=mergelists(s1.head,s2.head);
  cout<<"after merging of two sorted lists"<<endl;
  while(n12!=NULL)
  {
      cout<<n12->name<<"->";
      n12=n12->next;
  }
}