#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildBST(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = buildBST(root->right, d);
    }
    else
    {
        root->left = buildBST(root->left, d);
    }
    return root;
}
void takeinput(node* &root,int n)
{
   
    while (n--)
    {
        int d;
    cin >> d;
        root = buildBST(root, d);
        
    }
}

void inorderTraversal(node *root,vector<int> &ind)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left,ind);
    ind.push_back(root->data);
    inorderTraversal(root->right,ind);
}
int main()
{
    // 3 7 1 -1 -1 5 -1 -1 2 9 -1 -1 -1
    node *root = NULL;
    int n;
    cin>>n;
    takeinput(root ,n );
   
    int s,d,x;
    cin>>s>>d>>x ;
    vector<int> ind;
    inorderTraversal(root,ind);
    int count=0;
    for (int i = 0; i < ind.size(); i++)
    {
      if(ind[i]>=s)
      {
        if(ind[i]>=x && ind[i]<=d)
        count++;
      }
    }
    cout<<count<<endl;
    
    
    return 0;
}