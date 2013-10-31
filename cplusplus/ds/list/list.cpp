#include<iostream>

using namespace std;

struct Node{
     int data;
     Node *next;
};

Node *gHeadptr = NULL;

void addNodetoList(int d)
{
     Node *newnode = new Node;
     newnode-> data = d;
     newnode-> next = NULL;

     if (gHeadptr == NULL) {
         gHeadptr = newnode;
         return;   
     } 
     Node *cur = gHeadptr; 
     while( cur -> next != NULL) {
          cur = cur -> next;
     }
     cur-> next = newnode;
     return; 
}

void addHeadtoList(int d)
{
     Node *newnode = new Node;
     newnode-> data = d;
     newnode -> next = gHeadptr;
     gHeadptr = newnode;
}

void iterateList(void)
{
     Node *cur = gHeadptr;
     cout << "Start list:[ ";
     while(cur) {
         cout << cur -> data << ' '; 
         cur = cur -> next;
     }
     cout << "]" << endl; 
}

int lenList(void)
{
    int count = 0;
    Node *cur = gHeadptr;
    while(cur){
       cur = cur -> next;
       count ++;
    }
    return count; 
}

bool deleteNodefromList(int d)
{
      Node *cur = gHeadptr;
      while(cur->next) {
          if ( cur-> next -> data == d ) {
              Node *delNode = cur -> next;
              cur-> next = delNode -> next;
              delete delNode;
              return true;
           }
          cur = cur->next;
      }
      return false;
}

Node * searchList(int d)
{
    Node *cur = gHeadptr;
    while(cur){
        if (cur -> data == d) {
           return cur;
        }
        cur = cur -> next; 
    }
    return NULL;    
}


void reverseList(void)
{
     Node *prev = gHeadptr;
     Node *cur = gHeadptr -> next;
     Node *next = cur-> next;
     gHeadptr -> next = NULL;
     while(next->next) {
        cur -> next = prev;
        prev = cur;
        cur = next;
        next = next->next; 
     }
     cur -> next = prev;
     next -> next = cur;
     gHeadptr = next;
}


void transerval(void)
{
    Node *cur = gHeadptr->next;
    Node *nxt = cur -> next;
    Node *prv = gHeadptr;
    while(nxt -> next) {
        prv = cur;
        cur = nxt;
        nxt = nxt -> next;
        cout << "prv:" <<prv->data <<"cur:"<<cur->data <<"nxt:" << nxt->data << endl;
    }

}



bool hasLoop( Node *startNode)
{
    Node *slowNode = startNode;
    Node *fastNodeA = startNode;
    Node *fastNodeB = startNode;
    while( slowNode && fastNodeA ->next && fastNodeB -> next ) {
        fastNodeA = fastNodeB -> next;
        fastNodeB = fastNodeA -> next;  
        cout <<"s:" << slowNode <<" fA:" << fastNodeA <<" fB:" << fastNodeB << endl;
        if (slowNode == fastNodeA || slowNode == fastNodeB ) return true;
        slowNode = slowNode -> next;
    }
    return false;
}

Node *getListEnd(void)
{
    Node *cur = gHeadptr;
    while(cur->next) {
        cur =  cur -> next;
    }
    return cur;
}

int main(void)
{
     for ( int i = 100; i< 130; i ++ )
     addNodetoList(i);
     cout << "length is:" << lenList() << endl;
     iterateList();

//     addHeadtoList(1);
//     iterateList();

     Node *endptr = searchList(123);
     endptr->next = gHeadptr->next;
//     transerval();
     
     cout << "Begin:" << hasLoop(gHeadptr) << endl;
     cout << " End test " << endl;
}





