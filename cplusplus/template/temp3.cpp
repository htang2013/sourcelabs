#include<iostream>
using namespace std;

template<class X>
void swaps ( X & a, X & b)
{
     X temp = a;
     a = b;
     b = temp;
}

template <class X>
bool ge( X&a, X&b)
{
    return a > b;
}

class Base {
    private:
      int m;
    public:
      Base(int a):m(a){};
      friend ostream & operator << (ostream &stream, Base o)
      {
          stream << o.m;
          return stream;
      };
      int getValue() const
      {
          return m;
      }
      bool operator > ( const Base &b)
      {
           return m > b.m;
      }
};


int main(void)
{
     int a = 10; 
     int b = 20;
     Base bA(100);
     Base bB(200);

     cout << a << ":" <<b <<endl;
     swaps(a,b);
     cout << a << ":" << b <<endl;

     cout <<bA << ":" << bB <<endl;
     swaps(bA,bB);
     cout <<bA << ":" << bB <<endl;

     cout << ge(bA,bB) << endl;
    
     return 0;
}

