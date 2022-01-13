#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int value;
  TreeNode *left;
  TreeNode *right;

  TreeNode()
  {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v)
  {
    value = v;
    left = NULL;
    right = NULL;
  }
};
class node
{
public:
  int data;
  node *next;
  node()
  {
    data = 0;
    next = NULL;
  }
  node(int d)
  {
    data = d;
  }
};

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
    head = n;
  }

  // 2. Adding element at end by a node node.
  void add_at_end(node *n)
  {
    if (head == NULL)
    {
      head = n;
    }
    else
    {
      node *ptr = head;
      while (ptr->next != NULL)
      {
        ptr = ptr->next;
      }
      ptr->next = n;
    }
  }
  int get()
  {
    node* ptr=head;
    head=head->next;
    return ptr->data;
  }
  // 7. Display nodes.
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
};
vector<pair<int, int>> children_count;
vector<pair<int, int>> sibling_count;
class bst
{
public:
  TreeNode *root;
  bst()
  {
    root=NULL;
  }
  TreeNode *insert(TreeNode *root,node* s)
  {
    if (root == NULL)
    {
      TreeNode* n=new TreeNode();
      n->value=s->data;
      root=n;
      s=s->next;
      return root;
    }
    if (s->data < root->value)
    {
      root->left = insert(root->left, s);
    }
    else if (s->data > root->value)
    {
      root->right = insert(root->right, s);
    }
    return root;
  }
  void display_Nodes(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
        cout << node->value << " ";
      }
      cout << endl;
    }
  }
  int count_children(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        int cnt = 0;
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
          q.push(node->left);
          cnt++;
        }
        if (node->right)
        {
          q.push(node->right);
          cnt++;
        }
        children_count.push_back({node->value, cnt});
      }
      cout << endl;
    }
  }
  void count_siblings(TreeNode *root)
  {
    queue<pair<TreeNode *, TreeNode *>> q;
    q.push({root, root});
    sibling_count.push_back({root->value, 0});
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        int cnt = 0;
        TreeNode *node = q.front().first;
        TreeNode *par = q.front().second;
        q.pop();
        if (node->left)
        {
          q.push({node->left, par});
          if (par->right)
            cnt++;
          sibling_count.push_back({node->value, cnt});
        }
        else
        {
          sibling_count.push_back({node->value, cnt});
        }
        if (node->right)
        {
          q.push({node->right, par});
          if (par->left)
          {
            cnt++;
          }
          sibling_count.push_back({node->value, cnt});
        }
        else
        {
          sibling_count.push_back({node->value, cnt});
        }
      }
      cout << endl;
    }
  }
};
int main()
{
  singlylinkedlist s;

  while(1)
  {
    int n;
    cin>>n;
    if(n==-1)break;
    node* nodes=new node();
    nodes->data=n;
    s.add_at_end(nodes);
  }
  s.display();
  cout<<endl;
  bst tree1;
  tree1.root = tree1.insert(tree1.root, s.head);
  tree1.display_Nodes(tree1.root);
  cout<<endl;
  tree1.count_children(tree1.root);
  tree1.count_siblings(tree1.root);
  cout<<"children count of each node represented level wise is : "<<endl;
  for(auto it:children_count)
  {
    cout<<it.first<<" "<<it.second<<endl;
  }
  cout<<"sibling count of each node represented level wise is : "<<endl;

  for(auto it:sibling_count)
  {
    cout<<it.first<<" "<<it.second<<endl;
  }
}