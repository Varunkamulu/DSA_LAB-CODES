#include <bits/stdc++.h>
using namespace std;
class trees
{
public:
    trees *left;
    trees *right;
    int data;
    trees(int n)
    {
        data = n;
        *left = NULL;                                                                        s
        *right = NULL;
    }
};
void topveiw(trees *root)
{

    queue<pair<trees *, int>> q1;
    q1.push({root, 0});
    map<int, int> m;

    while (!q1.empty())
    {
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {
            trees* node = q1.front().first;
            int one = q1.front().second;
            q1.pop();
            m[one] = node->data;
            if (node->left)
                q1.push({root->left, one - 1});
            if (node->right)
                q1.push({root->right, one + 1});
        }
    }
    for (auto ma : m)
    {
        cout << ma.second << " ";
    }
}
void rightveiw(trees* root,vector<int>& v,int lim)
{
    if(root==NULL)return;
    if(v.size()==lim)v.push_back(root->data);
    if(root->right)rightveiw(root->right,v,lim+1);
    if(root->left)rightveiw(root->left,v,lim+1);

}
void postorder(trees *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(trees *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(trees *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void levelorder(trees *root)
{
    queue<trees *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            trees *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            cout << node->data << " ";
        }
        cout << endl;
    }
}
// vertical traversal of tree

map<int, multiset<pair<int, int>>> mp;

// void help(trees* root,int y,int x){

//     if(root == NULL) return;

//     mp[y].insert({x,root->val});
//     help(root->left ,  y-1 , x+1);
//     help(root->right,  y+1 , x+1);
//     return;

// }
int searchmin(trees* root)
{
    if(root->left==NULL)return root->data;
    searchmin(root->left);
}
int searchmax(trees* root)
{
    if(root->right==NULL)return root->data;
    searchmin(root->right);
}
int predeccessor(trees* root,int x)
{
    if(root==NULL)return -1;
    if(root->left&& root->left->data==x)return root->data;
    if(root->right && root->right->data==x)return root->data;
}
vector<vector<int>> verticalTraversal(trees *root)
{
    int i = 0;
    queue<pair<trees *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front().first;
        int x = q.front().second.first, y = q.front().second.second;
        q.pop();
        mp[x].insert({y, p->data});
        if (p->left)
            q.push({p->left, {x - 1, y + 1}});
        if (p->right)
            q.push({p->right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans(mp.size());
    for (auto a : mp)
    {
        for (auto s : a.second)
        {

            ans[i].push_back((s.second));
        }
        i++;
    }

    return ans;
}
void iterative_preorder(trees *root)
{
    stack<trees *> s;
    s.push(root);
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        trees *node = s.top();
        s.pop();
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}
void iterative_inorder(trees *root)
{
    stack<trees *> s;
    trees *node = root;
    while (true)
    {
        if (node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            if (s.empty())
                break;
            node = s.top();
            s.pop();
            cout << node->data << " ";
            // if(node->right)s.push(node->right);
            node = node->right;
        }
    }
}
void iterative_postorder(trees *root)
{
    stack<trees *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        trees *node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
        // auto it=s.top();s.pop();
        // if(it.second==3)
        // {
        //     cout<<it.first->data<<" ";
        // }
        // else if(it.second==1)
        // {
        //     it.second++;
        //     s.push(it);
        //     if(s.top().first->left){s.push({s.top().first->left,1});}

        // }
        // else
        // {
        //     it.second++;
        //     s.push(it);
        //     if(s.top().first->right){s.push({s.top().first->right,1});}

        // }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
void iterative_postorder_stack1(trees *root)
{
    stack<trees *> s;
    trees *curr = root;
    while (!s.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            trees *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                cout << temp->data << " ";
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    cout << temp->data << " ";
                }
            }
            else
                curr = temp;
        }
    }
}
void bfs(trees* root)
{
    queue<trees*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        auto p=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
           q.push(p->left);
           q.push(p->right);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    trees *root = new trees(5);
    root->left = new trees(3);
    root->right = new trees(8);
    // preorder(root);cout<<endl;
    // postorder(root);
    // cout<<endl;inorder(root);
    // cout<<endl;levelorder(root);cout<<endl;
    // iterative_preorder(root);cout<<endl;
    // iterative_inorder(root);
    // cout<<endl;iterative_postorder(root);
    // cout<<endl;iterative_postorder_stack1(root);
    // topveiw(root);
cout<<predeccessor(root,5);
    return 0;
}
/*
<---------------------------------------TREE DATA STRUCTURE----------------------------------------------------------->
1) TRAVERSALS
    i)DFS (uses stack ds)                                                                             ii)BFS (uses queue ds)
       i)PREORDER                                                                                         LEVELORDER
          ->print
          ->left
          ->right
       ii)INORDER
          ->left
          ->print
          ->right
       iii)POSTORDER
          ->left
          ->right
          ->print

-> BALANCED TREES: if the difference of the heights of the left node  and right node of the root node is not greater than 1
->DIAMETER OF TREES: the maximum sum of the height of the left node and right node is its diameter
->MAXIMUM DEPTH: is nothing but the height of the tree
->MAXIMUM PATH SUM: go left go right calculate max of r+l+rootval store it in a variable and then return rootval+max(l,r)
->CHECK IF TREES ARE SIMILIAR: if root1val==root2val and the left of both the trees should be equal and right should be equal
->ZIG ZAG TRAVERSAL: apply standerd dfs and put a bool variable and change its truthness after every level
->BOUNDARY TRAVERSAL: travel through the left nodes and then through leaf nodes and then through right nodes reversely
->VERTICAL TRAVERSAL: o.o
->TOP VEIW: standerd dfs and if its present in map then dont add it orelse add it to map
->BOTTOM VEIW: similiar to top veiw but add the element in map till the end of the prcess and print it at last
->RIGHT VEIW: standerd dfs and if the level should be equal to the vector size then go to right and then go to left
->LEFT VEIW: similiar to right veiw but go to left first and then right
->CHECK SYMMETRIC: if(root->left==root->right && root->right==root->left && root->val==root->val)
->always not underestimate the brute force method
*/