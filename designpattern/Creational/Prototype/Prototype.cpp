#include<iostream>

using namespace std;

class Prototype{
    public:
        virtual ~Prototype(){};
        virtual Prototype *Clone() const = 0;
        
    protected:
        Prototype(){};
};


class ConcretePrototype: public Prototype
{
     public:
        ConcretePrototype(){};
        ConcretePrototype( const ConcretePrototype &cp) { cout <<"Concrete Prototype copy ..." << endl; }
        ~ConcretePrototype(){};
        Prototype *Clone() const
        {
            return new ConcretePrototype(*this);
        }
};


int main(void)
{
     Prototype *p = new ConcretePrototype();
     Prototype *pl = p->Clone();
     return 0;
}



        
