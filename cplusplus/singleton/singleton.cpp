#include<iostream>

class singleton {
    public:
        static singleton & getInstance(void) { return _instance; };
    private:
        static singleton _instance;
        singleton(){}; //disallow create a instance in stack
        singleton(const singleton &);  //disallow use copy constructor
        singleton &operator = (singleton &);   //disallow to use assignment 
};

singleton singleton::_instance;

int main(void)
{
    singleton & st = singleton::getInstance();
    singleton t = singleton::getInstance();
    singleton c;
    c = t;
    return 1;
}

