//                               -----trie data structure------

// #include <bits/stdc++.h>
// using namespace std;
// class trieNode
// {
//     public:
//         trieNode *alpha[26];
//         char data;
//         trieNode(char c)
//         {
//             data=c;
//         for(int i=0;i<26;i++)
//         {
//             alpha[i]=NULL;
//         }
//         }
//         bool isEnd=false;
// };
// class trie
// {
//     trieNode *root;
//     trie()
//     {
//         root=new trieNode('\0');


        
//     }
//     void insertUtil(trieNode *root,string s)
//     {
//         if(s.length()==0)
//         {
//             root->isEnd=true;
//         }
//         int ch=s[0]-'A';
//         trieNode *child;
//         if(root->alpha[ch]!=NULL)
//         {
//             child=root->alpha[ch];
//         }
//         else
//         {
//             child = new trieNode(s[0]);
//             root->alpha[ch]=child;
//         }
//         insertUtil(child,s.substr(1));
//     }
//     void insert(string &c)
//     {
//         insertUtil(root,c);
//     }
// };
// int main()
// {

//     return 0;
// }

