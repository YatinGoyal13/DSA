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
void takeinput(node* &root)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        root = buildBST(root, d);
        cin >> d;
    }
}
void levelordertraversal(node *root)
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
void reverselvlOrder(node *root)
{
    stack<node *> S;
    queue<node *> Q;
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
void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    // 3 7 1 -1 -1 5 -1 -1 2 9 -1 -1 -1
    node *root = NULL;
    takeinput(root);
    cout << "level order traversal" << endl;
    levelordertraversal(root);
    cout << "reverse level order traversal" << endl;
    reverselvlOrder(root);
    cout << endl;
    cout << "inorder Traversal:" << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "preorder TraversaL:" << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "postorder Traversal:" << endl;
    postorderTraversal(root);
    cout << endl;
    return 0;
}