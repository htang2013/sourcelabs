#include<iostream>

using namespace std;

class Singleton{
    public: 
        static Singleton *Instance();
        void display() { cout << " display" << endl; }
    private:
        Singleton() { cout <<"Singleton..." << endl; }
        static Singleton *_instance;
}; 


Singleton *Singleton::_instance = 0; 

Singleton *Singleton::Instance()
{
   if (_instance == 0)
   {
        _instance = new Singleton();
   }
   return _instance;
}


int main(void)
{
    Singleton *sgn = Singleton::Instance();
    sgn->display();
    return 0;
}

