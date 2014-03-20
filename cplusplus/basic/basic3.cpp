#include<iostream>
#include<cassert>
#include<new>

using namespace std;


class X { 
     public:
       static int status;
       static void outOfMemory(void)
       {
           cerr << "Unable to satisfy request for class X object\n";
           assert(0);
       };
       static void SetNewHandler(void)
       {
           if( !X::status ) {
              set_new_handler(X::outOfMemory);
              X::status = 1;
           }
       };
};

class Y {
     public:
       static int status;
       static void outOfMemory(void)
       {
           cerr << "Unable to satisfy request for class Y object\n";
           assert(0);
       };
       static void SetNewHandler(void)
       {
           if( !Y::status ) {
              set_new_handler(Y::outOfMemory);
              Y::status = 1;
             }
       };
};


int X::status = 0;
int Y::status = 0;

int main(void)
{

    X::SetNewHandler();
    Y::SetNewHandler();

    X *px = new X[111000000000000000];
    Y *py = new Y[111000000000000000];
    return 0;

}
