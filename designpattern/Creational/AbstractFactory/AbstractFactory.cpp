#include<iostream>
using namespace std;


class AbstractProductA
{
   public:
       virtual ~AbstractProductA(){};
   protected:
       AbstractProductA(){};
};


class AbstractProductB
{
   public:
       virtual ~AbstractProductB(){};
   protected:
       AbstractProductB(){};
};


class ProductA: public AbstractProductA
{
   public:
       ~ProductA(){};
       ProductA(){};
};



class ProductB: public AbstractProductB
{
   public:
       ~ProductB(){};
       ProductB(){};
};


class AbstractFactory
{
   public:
       virtual ~AbstractFactory(){};
       virtual AbstractProductA *CreateProductA() = 0;
       virtual AbstractProductB *CreateProductB() = 0;
       AbstractFactory(){}; 
};


class ConcreteFactory: public AbstractFactory
{
   public:
       ConcreteFactory(){};       
       virtual ~ConcreteFactory(){};
       AbstractProductA *CreateProductA() { return new ProductA(); };
       AbstractProductB *CreateProductB() { return new ProductB(); };
};



int main(void)
{
   AbstractFactory *cf1 = new ConcreteFactory();
   cf1 -> CreateProductA();
   cf1 -> CreateProductB();
   
   delete cf1;
   return 0;
}
