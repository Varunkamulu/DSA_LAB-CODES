#include<bits/stdc++.h>
using namespace std;
#define SP 5
class tree
{
    public:
      tree *left, *right;
      int data;
      tree()
      {
          left=NULL;
          right=NULL;
          data=0;
      }
      tree(int d)
      {
          data=d;
          left=NULL;
          right=NULL;
      }
};

class bst
{
    public:
      tree* root;
      bst()
      {
          root=NULL;
      }
      void insert(tree* n)
      {
          if(root==NULL)
          {
              root=n;
          }
          else{
              tree* t=root;
              while(t!=NULL)
              {
                  if(n->data==t->data)
                  {
                      cout<<"Node already exists. Duplicates are not allowed.\n";
                      break;
                  }
                  else if(n->data<t->data && t->left==NULL)
                  {
                      t->left=n;
                      break;
                  }
                  else if(n->data>t->data && t->right==NULL)
                  {
                      t->right=n;
                      break;
                  }
                  else if(n->data<t->data)
                  {
                      t=t->left;
                  }
                  else if(n->data>t->data){
                      t=t->right;
                  }
              }
          }
      }
     void printTree(tree* n, int sp)
     {
         if(n==NULL)
         {
             return;
         }
         sp+=SP;
         printTree(n->right,sp);
         cout<<endl;
         for(int i=SP; i<sp; i++)
         {
             cout<<" ";
         }
         cout<<n->data<<endl;
         printTree(n->left,sp);
     }
     void printInord(tree* n)
     {
         if(n==NULL)
           return;
        printInord(n->left);
        cout<<n->data<<" ";
        printInord(n->right);
     }
     tree* searchnode(int v)
     {
         if(root==NULL)
         {
             return root;
         }
         else{
             tree* t=root;
             while(t!=NULL)
             {
                 if(t->data==v)
                 {
                     return t;
                 }
                 else{
                     if(v<t->data)
                     {
                         t=t->left;
                     }
                     else{
                         t=t->right;
                     }
                 }
             
            }
         }
         return NULL;
     }
     int height(tree* n)
     {
         int l,r;
         if(root==NULL)
         {
             return -1;
         }
         else{
             l=height(n->left);
             r=height(n->right);
         }
         if(l>r)
         {
             return (l+1);
         }
         else{
             return (r+1);
         }
     }
     tree* minvalNode(tree* n)
     {
         tree* t=n;
         while(t->left!=NULL)
         {
             t=t->left;
         }
         return t;
     }
     tree* deletenode(tree* n, int v)
     {
         if(n==NULL)
         {
             return NULL;
         }
         else{
             if(v<n->data)
             {
                 n->left=deletenode(n->left,v);
             }
             else if(v>n->data)
             {
                 n->right=deletenode(n->right,v);
             }
             else{
                 if(n->left==NULL)
                 {
                     tree* t=n->right;
                     delete n;
                     return t;
                 }
                 else if(n->right==NULL)
                 {
                     tree* t=n->left;
                     delete n;
                     return t;
                 }
                 else{
                     tree* k=minvalNode(n->right);
                     n->data=k->data;
                     n->right=deletenode(n->right, k->data);
                 }
             }
             return n;
         }
     }
     int maxVal(tree* n)
     {
         if(n==NULL) return 0;
         tree* t=n;
         while(t->right!=NULL)
         {
             t=t->right;
         }
         return t->data;
     }
     int minVal(tree* n)
     {
         if(n==NULL) return 0;
         tree* t=n;
         while(t->left!=NULL)
         {
             t=t->left;
         }
         return t->data;
     }
     int pre,suc;
     void PreSuc(tree* n, tree* pres, tree* sucs, int v)
     {
         if(n==NULL) return;
         if(n->data==v)
         {
             if(n->left!=NULL){
                tree* t=n->left;
                while(t->right!=NULL)
                {
                    t=t->right;
                }
                pres=t;
                pre=pres->data;
             }
             if(n->right!=NULL)
             {
                 tree* t=n->right;
                 while(t->left!=NULL)
                 {
                     t=t->left;
                 }
                 sucs=t;
                 suc=sucs->data;
             }
             return;
         }
         else if(n->data>v)
         {
             sucs=n;
             suc=sucs->data;
             PreSuc(n->left, pres, sucs, v);
         }
         else{
             pres=n;
             pre=pres->data;
             PreSuc(n->right, pres, sucs, v);
         }
     }
};
int main()
{
    bst tree1;
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)break;
        tree *node=new tree();
        node->data=n;
        tree1.insert(node);
    }
   cout<<"the tree is : "; tree1.printInord(tree1.root);
    cout<<endl;
    cout<<"the max val of key in bst is : "<<tree1.maxVal(tree1.root)<<endl;
    cout<<"the min val of key in bst is : "<<tree1.minVal(tree1.root)<<endl;
    int a;cout<<"enter the value to be searched : ";
    cin>>a;
   if(tree1.searchnode(a)!=NULL){cout<<"the node exists"<<endl;}
   else cout<<"there is no such node"<<endl;
   int val;cout<<"enter the value to be deleted in tree : ";cin>>val;
   cout<<"the tree after deletion of "<<val<<"is : ";
   tree1.printInord(tree1.deletenode(tree1.root,val));
   cout<<endl;
   int value;cout<<"enter the value of the node in the tree for which predecessor and successor need to be calculated : ";cin>>value;
   tree1.PreSuc(tree1.root,NULL,NULL,value);

   if(tree1.pre<tree1.maxVal(tree1.root)&&tree1.pre>tree1.minVal(tree1.root))cout<<"the predecessor is : "<<tree1.pre<<endl;
   else cout<<"no predecessor"<<endl;
   if(tree1.suc<tree1.maxVal(tree1.root)&&tree1.suc>tree1.minVal(tree1.root))cout<<"the successor is : "<<tree1.suc<<endl;
   else cout<<"no successor"<<endl;
    return 0;
}