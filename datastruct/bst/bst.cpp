#include<iostream>

using namespace std;


struct Node {
     int value;
     Node *left;
     Node *right;
     Node( int val)
     {
          vale = val;
          left = NULL;
          right = NULL;
     }
};


Node *root = NULL;

void Insert(value)
{
     if ( root == NULL) {
        root = new Node(value);
        return;
     }
     
     insertNode(root,value);
}

void insertNode(Node *root, int value)
{
    if (value < root->value)
    {
        if (root->left == NULL)  root->left = new Node(value);
        else insertNode(root->left, value);
    }else{
        if (root->right == NULL) root ->right = new Node(value);
        else insertNode(root->right, value);
    }
}


void searchNode(Node *root, int value)
{
    if (root == NULL) return false;
    if (root->value == value ) return true;
    
    if (value < root-> value) return searchNode(root->left, value);
    return searchNode(root->right, value); 
}



void deleteNode(Node *root, int value)
{
    
     
        
}






