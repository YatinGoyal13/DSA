/**
 * The above function builds a linked list by taking input from the user and displays the values in the
 * linked list.
 * 
 * @param root The root parameter is a pointer to the head node of the linked list. It is initially set
 * to NULL and is later updated as nodes are added to the linked list.
 * 
 * @return The function `bui_linked` returns a pointer to the root node of the linked list.
 */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node{
    public:
       int val;
       node* next;
    node(int d)
    {
        this->val = d;
        this->next = NULL;
    }
};
node* bui_linked(node* root)
{
    cout<<"enter data (-1 means null)"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    {
        return NULL;
    }
    
    root->next=bui_linked(root->next);
    return root;
}
int main() {
    node* root=NULL;
    root=bui_linked(root);
    cout<<"values in linked list are:"<<endl;
    node* temp = root;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}