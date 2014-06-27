#include<iostream>

using namespace std;

class Product {
    public:
       Product();
       ~Product();
       void ProductPart();
};

class ProductPart {
    public:
       ProductPart();
       ~ProductPart();
       ProductPart *BuildPart();
};

class Component {
    public:
       void Add( const Component & com) {} 
       Component *GetChild(int index) { return 0; }
       void Component::Remove( const Component & com) {}

class Builder {
    public:
         virtual ~Builder();
         virtual void BuildPartA(const string &buildPara) = 0;
         virtual void BuildPartB(const string &buildPara) = 0;
         virtual void BuildPartC(const string &buildPara) = 0;
         virtual Product *GetProduct() = 0;
   protected:
         Builder(); 
};

class ConcreteBuilder: public Builder
{
   public:
         ConcreteBuilder();
         ~ConcreteBuilder();
         void BuildPartA(const string & buildPara) { cout << "Build PartA" << endl; }
         void BuildPartB(const string & buildPara) { cout << "Build PartB" << endl; }
         void BuildPartC(const string & buildPara) { cout << "Build PartC" << endl; }
         Product *GetProduct()
         {
             BuildPartA("pre-defined");
             BuildPartB("pre-defined");
             BuildPartC("pre-defined");
             return new Product();
         };
};
       
    

