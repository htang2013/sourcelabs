#include<iostream>

using namespace std;

class Base{
      int _a;
    public:
      Base():_a(0) { cout << "Base" <<endl; }
      Base(int x):_a(x) { cout << "Convert Base" <<_a<<endl; }
      Base(const Base &b):_a(b._a) { cout <<" Base copy" << endl;};
      void display(void) { cout << "display" << _a << endl; }
      Base & operator=( const Base & b)
      {
	 cout << "operator =" <<endl;
         _a = b._a;
         return *this;
      }

      friend ostream & operator <<(ostream &os, const Base &b)
      {
          os << "(" << b._a <<")";
          return os;
      }


};

int main()
{
    Base a(1);
    Base b(2);
    b = a;
    cout << b;
    cout <<"Here" <<endl;
    Base &c = a;
    Base d(3);
    cout << c;
    c = d;
    cout << a;    
}

