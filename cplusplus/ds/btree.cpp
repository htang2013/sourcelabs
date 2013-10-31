#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *right, *left;
};

Node * insert(Node *node, int d)
{
     if (node == NULL) {
        node = new Node;
        node -> data = d;
        node -> left = node -> right = NULL;
        return node;
     }
     if (d <= node -> data) node ->left = insert(node->left, d);
     else  node -> right = insert( node->right, d);
     return (node);
}

void printTree (Node *node) { 
    if (node == NULL) return;
    printTree(node->left); 
    cout <<":"<< node->data <<" "; 
    printTree(node->right); 
} 
 


Node *root = NULL;

int main(void)
{
    insert(root, 50);
    for (int i = 1;  i < 45; i++)
    root = insert(root,i);
   
    for (int i = 55;  i < 100; i++)
    root = insert(root,i);

    printTree(root);
	
}

