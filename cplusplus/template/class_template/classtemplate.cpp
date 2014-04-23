#include<iostream>
using namespace std;

template<class T>
class Test {
    public:
         Test();
         ~Test();
         T Data(T);
};


template<class T>
Test<T>::Test()
{
    cout << "constructor ,alloc..."<< endl; 
}

template<class T>
Test<T>::~Test()
{
    cout <<"destructor , dealloc ..."<< endl;
}

template<class T>
T Test<T>::Data( T t)
{
    return t;
}
   
int main(void)
{
    Test<int> var1;
    Test<double> var2;
    cout << var1.Data(100)<< endl;
    cout << var2.Data(1.23)<< endl;
    return 1;

}  
        
