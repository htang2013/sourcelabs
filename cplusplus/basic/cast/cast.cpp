#include<iostream>


using namespace std;

// This file illustrate several casts:
// static_cast, dynamic_cast, const_cast, reinterpret_cast and regular c style cast


class Base {
    public:
//    void display(void)
    virtual void display(void)
    {
         cout << "This is Base class object." << endl;
    }
};

class Derived: public Base {
    public:
    void display(void)
    {
         cout <<" This is Derived class object." << endl;
    }
    void show(void)
    {
         cout << "Derived class show function" <<endl;
    }
};

class Inherit: public Base {
     public:
     void display(void)
     {
         cout << "This is Inherit class object. "<< endl;
     }
     void show(void)
     {
         cout << "Inherit class show function" << endl;
     }
};

void func1(Base *pB)
{
    Derived *pC = static_cast<Derived*> (pB);
    pC->display();
    pC->show();
}

void func2(Base *pB)
{
    Derived *pC = dynamic_cast<Derived*> (pB);
    pC->display();
    pC->show();
}
    


void func3(void)
{
   //const_cast 
    const Derived D;
    Derived &rD = const_cast <Derived &> (D);
    rD.display();
}




int main(void)
{
    Derived *pD = new Derived;
    Inherit *pI = new Inherit;
    Base *pB = new Base;
    
    func1(pB);
    func1(pD);
    func2(pI);   // this will cause Segmentation fault,  
     
    func3();

    delete pB;
    delete pD;
    delete pI;

    return 0;
}





