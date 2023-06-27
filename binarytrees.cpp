/**
 * The above code builds a binary tree by taking input from the user and returns the root node of the
 * tree.
 *
 * @param root A pointer to the root node of the binary tree.
 *
 * @return The function `buildTrees` returns a pointer to a `node` object, which represents the root of
 * the binary tree that is being built.
 */
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
node *buildTrees(node *root)
{
    cout << "enter data(-1 means null)" << endl;
    int x;
    cin >> x;
    root = new node(x);
    if (x == -1)
    {
        return NULL;
    }
    cout << "enter data to left" << root->data << endl;
    root->left = buildTrees(root->left);
    cout << "enter data to right" << root->data << endl;
    root->right = buildTrees(root->right);
    return root;
}
void levelordertraversal(node* root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
void reverselvlOrder(node* root)
{
stack <node*> S;
    queue <node*> Q;
    Q.push(root);
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        
        S.push(root);
 
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
 
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
 
    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}
void inorderTraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data<<" ";
    inorderTraversal(root->right);
}
void preorderTraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
     cout << root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
     
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data<<" ";
}
int main()
{
    // 3 7 1 -1 -1 5 -1 -1 2 9 -1 -1 -1
    node *root = NULL;
    root = buildTrees(root);
    cout<<"level order traversal"<<endl;
    levelordertraversal(root);
    cout<<"reverse level order traversal"<<endl;
    reverselvlOrder(root);
    cout<<endl;
    cout<<"inorder Traversal:"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"preorder TraversaL:"<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"postorder Traversal:"<<endl;
    postorderTraversal(root);
    cout<<endl;
    return 0;
}