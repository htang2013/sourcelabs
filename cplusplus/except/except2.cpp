#include<iostream>

using namespace std;

class Base{
     public:
        Base() { cout << "Base" << endl; }
        ~Base() { cout << "~Base" << endl; }
};         
   
class Derived : public Base {
    public:
       Derived() { cout << "Derived" << endl; }
       ~Derived() { cout << "~Derived" << endl; } 
};

int main(void) {

   Derived D;

   try
   {
      throw D;
   }
   catch (Derived &d)
   {
       cerr<<"Catch derived class" << endl;
   }
   catch (Base  &b)
   {
       cerr << "Catch base class" << endl; 
   }

   catch (Derived &d)
   {
       cerr<<"Catch derived class" << endl;
   }

   return 1;
}

