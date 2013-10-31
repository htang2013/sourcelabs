#include<iostream>

using namespace std;

class Base {
    public:
       Base(int a):mv(a){};
       void change(int a);
       void display(void) const;
       int mv;
       ~Base(void){ cout << "die of: " << mv <<endl; };
};

void Base::change( int a)
{
     mv = a;
}

void Base::display(void) const
{
    cout << mv << endl;
}

int main(void)
{
    Base b(1);
    Base c(2);
    return 0;
};

