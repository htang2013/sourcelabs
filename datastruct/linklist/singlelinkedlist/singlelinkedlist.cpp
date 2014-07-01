#include<iostream>
using namespace std;

struct Node{
     int data;
     Node *next;
     Node(int value): data(value){
        next = NULL;
     };
};

Node *headptr = NULL;

void Addition(int value)
{
     Node *ptr = new Node(value);
     if (headptr == NULL){
        headptr = ptr;
     }
     else{
        Node *tptr = headptr;
        while(tptr -> next){
            tptr = tptr->next;
        }
        // tptr -> next == NULL
        tptr -> next = ptr;
     } 
}

void Traverse(void)
{
    Node *tptr = headptr;
    while(tptr) {
         cout << "Content:" << tptr -> data << endl;
         tptr = tptr -> next;
    }
}

Node* Contain(int value)
{
     Node *tptr = headptr;
     while(tptr) {
         if(tptr -> data == value) {
             cout << " Data found:" << tptr-> data << endl;
             return tptr;
         } 
             tptr = tptr -> next;
     }
}

bool Remove( int value)
{
    if ( headptr == NULL) return false;

    Node *tptr = headptr;
    
    if (tptr -> data == value) {
       if (headptr -> next == NULL) {
           delete tptr; 
           headptr = NULL;
           return true;
       }
    }
    while(tptr->next != NULL && tptr-> next-> data != value)
        tptr = tptr -> next;
      
    if (tptr -> next == NULL) return false; 

    Node *tmp = tptr->next;
    tptr -> next = tmp->next;
    delete tmp;
    return true;  
}

TBD  XXXXXXXXXXXXX

void ReverseTraverse(void)
{
     Node *ptr = headptr;
     Node *tail = headptr;

     while(tail->next != NULL){
        tail = tail -> next;
     }
     cout << "Tail:" << tail->data << endl;  

     while() {
          
         while(ptr-> next == tail) cout << "Content:" << ptr->data << endl;
     }
         
      
      
     
    
}

int main(void)
{
     for (int i = 0; i < 10; i++) {
        Addition(i*10);
     }
     Remove(30);
     Traverse();
     return 0;
}
