#include<iostream>

using namespace std;

class BaseX {
};

class DeriveX {
};

int main(void)
{
     int a = 10;
     BaseX b;
     DeriveX d;
     

     cout << typeid(int).name() << endl; 
     cout << typeid(BaseX).name() << endl; 
     cout << typeid(DeriveX).name() << endl; 

     cout << typeid(a).name() << endl; 
     cout << typeid(b).name() << endl; 
     cout << typeid(d).name() << endl; 

}

//./a.out | c++filt -t

