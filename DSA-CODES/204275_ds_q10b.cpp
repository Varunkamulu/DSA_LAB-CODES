
#include <iostream>
#include <cstring>
/*
   VARUN KAMULU
   204275
   SECTION-B
   INTUITION:
     just wrote the DLL code and stored input according to the priority queue (max heap) to make code simple
*/
using namespace std;
int cnt = 0;
class node
{
public:
  char data;
  node *next;
  node *prev;
  node()
  {
    data = '#';
    next = NULL;
    prev = NULL;
  }
  node(char d)
  {
    data = d;
  }
};
class doublylinkedlist
{
public:
  node *head;
  doublylinkedlist()
  {
    head = NULL;
  }
  doublylinkedlist(node *n)
  {
    head = n;
  }
  void enqueue(node* n)
  {
    node* ptr=head;
    if(head==NULL)
    {
      head=n;
      return;
    }
    if(head->data-'0'<n->data-'0')
    {
      n->next=head;
      head->prev=n;
      head=n;
    }
    while(ptr && ((ptr->data-'0') > (n->data-'0')))
    {
      ptr=ptr->next;
    }
    if(ptr)
    {
      ptr->prev->next=n;
      n->prev=ptr->prev;
      n->next=ptr;
      ptr->prev=n;
    }
    else{
      ptr->prev->next=n;
      n->prev=ptr->prev;
      n->next=ptr;
    }
  }
  char delete_node_at_beginning()
  {
    if (head)
    {
      char p=head->data;
      head = head->next;
      if(head)head->prev = NULL;
      return p;
    }
    else
    {
      cout << "the linked list is empty\n";
      return '#';
    }
  }
  // 4. Display nodes.
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
        cout << ptr->data << " -> ";
        ptr = ptr->next;
      }
    }
  }

  // 8. Empty status
  bool isEmpty()
  {
    if (head == NULL)
      return true;
    else
      return false;
  }
};

int main()
{
  doublylinkedlist s;

  cout << "1. Enqueue : 2. Dequeue : 3. Exit : 4.Display\n";

  int choice, k1, x;
  char d1;
  do
  {
    cout << "\nChoose operation which you want to perform: ";
    cin >> choice;
    node *n1 = new node();
    switch (choice)
    {
    case 1:
      cout << "Enter data: ";
      cin >> d1;
      n1->data = d1;
      s.enqueue(n1);
      cout << "Appending done.\n";
      break;
    case 2:
      cout << s.delete_node_at_beginning()<<endl;
      break;
    case 3:
      break;
    case 4:
      cout << "Display data:\n";
      s.display();
      break;
    default:
      cout << "Choose proper option.\n";
    }
  } while (choice != 3);
}