#include<iostream>

using namespace std;

class Base {
    public:
      Base() { cout <<"Base" << endl; };
//      virtual ~Base() { cout <<"~Base" << endl; };
      ~Base() { cout <<"~Base" << endl; };
};

class Derive : public Base{
    public:
      Derive() { cout <<"Derive"<< endl; };
      ~Derive() { cout << "~Derive" << endl; };
};

int main(void)
{
     Base *b = new Derive();
     delete b;
     return 0;
}
      
   


