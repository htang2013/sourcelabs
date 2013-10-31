#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <class X>
void swaps( X &a, X &b)
{
    X temp = a;
    a = b;
    b = temp;
}

class Base {
   private:
      int m;
   public:
      explicit Base(int);
      Base( Base &);
      void print(void) const
      {
          cout << m << endl;
      }
};

Base::Base(int a)
{
    cout << "Base(int)" << endl;
    m = a;
}

Base::Base( Base &b)
{
    cout << "Base(&b)"<< endl;
    m = b.m;
}

int main(void)
{
    Base a(10);
    Base b(20);

    swaps(a,b);

    a.print();
    b.print();
    
    return 1;

}
