#include<iostream>

using namespace std;

class DivideByZero
{
    public:
        double divisor;
        DivideByZero(double x);
};

DivideByZero::DivideByZero(double x) : divisor(x) {}

int divide(int x, int y)
{
    if(y==0)
    {
        throw DivideByZero(x);
    }
}


int fun(void) {
   try
   {
       divide(12, 0);
   }
   catch (DivideByZero divZero)
   {
       cerr<<"Attempted to divide "<<divZero.divisor<<" by zero" <<endl;
       throw; 
   }
   return 1;
}


int main(void)
{
    try{
    fun();
    }
    catch(...)
    {
        cerr << "All ....."<< endl;
    }
}

