#include<iostream>

using namespace std;

namespace X {
     int a = 10;
     int b = 20;
     
     void function(void)
     {
	cout << a << ":"<< b << endl;
     }
}


int main(void)
{
    using namespace X;
    a = 30;
    b = 40;
    X::function();
    return 1;
}
