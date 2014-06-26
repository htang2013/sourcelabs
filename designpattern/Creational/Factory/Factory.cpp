#include<iostream>
using namespace std;

class Product{
    public:
      virtual void Usage() = 0;
};

class ConcreteProduct: public Product{
    public:
      void Usage() { cout <<" Concrete Product Usage" << endl; }; 
};
   

class Factory {
    public:
       virtual ~Factory() {};
       virtual Product *CreateProduct() = 0;
    protected:
       Factory(){};
};


class ConcreteFactory: public Factory {
    public:
       ConcreteFactory() { cout <<" Concrete Factory" << endl; };
       Product *CreateProduct()
       {
            return new ConcreteProduct();
       }; 
       ~ConcreteFactory() {};
};



int main(void)
{
     Factory * fac = new ConcreteFactory();
     Product * p = fac->CreateProduct();
     p -> Usage();
     delete p;
     delete fac;
}

       
