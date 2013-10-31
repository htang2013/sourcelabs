#include<iostream>
using namespace std;

class A{
   public:
      A(){ cout << "A()" <<endl; }
      ~A(){ cout << "~A()" <<endl; }
};

class B{
   public:
      B(){ cout << "B()" <<endl; }
      ~B(){ cout << "~B()" <<endl; }
};


class C: public A, public B{
//class C: public A, virtual public B{
   public:
      C(){ cout << "C()" <<endl; }
      ~C(){ cout << "~C()" <<endl; }
};


//class D: virtual public C{
class D: public C{
   public:
      D(){ cout << "D()" <<endl; }
      ~D(){ cout << "~D()" <<endl; }
};

int main(void)
{
    D d;
}





