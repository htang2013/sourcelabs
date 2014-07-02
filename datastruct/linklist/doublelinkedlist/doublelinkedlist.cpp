#include<iostream>
using namespace std;

struct Node {
     int data;
     Node *prev;
     Node *next;
     Node(int value): data(value), prev(NULL), next(NULL) {};
};

Node *headptr = NULL;

void Add(int value)
{
    Node *tptr = new Node(value);
    if (headptr == NULL) { 
        headptr = tptr;
        return;
    }
    Node *runptr = headptr;
    while(runptr->next){ runptr = runptr->next; }
    runptr -> next = tptr;
    tptr -> prev = runptr;
    
}

void Traversal(void)
{
     Node *ptr = headptr;
     while(ptr){
        cout << "Content: " << ptr->data << endl;
        ptr = ptr->next;
     }
}

void ReverseTraversal(void)
{
     Node *ptr = headptr;
     while(ptr->next){
         ptr = ptr ->next;
     }
     cout << "End to ptr" << endl;
     while(ptr->prev != headptr){
         cout << "Content: " << ptr->data << endl;
         ptr = ptr->prev;
     }
     cout << "Content: " << headptr->data << endl;
}


bool Remove(int value)
{
    Node *ptr = headptr;
    while(ptr){
       if (ptr->data == value) {
          Node *tmp = ptr;
          ptr->prev->next = ptr ->next;
          ptr->next->prev = ptr ->prev;
          delete tmp;
          return true;
       }
       ptr = ptr->next;
    }
    return false;
}


int main(void)
{
   for (int i = 0; i < 10; i++){
      Add(i);
   }
   Traversal();
   Remove(5);
   cout << "ReverseTraversal"<< endl;
   ReverseTraversal();
   return 0;
}



