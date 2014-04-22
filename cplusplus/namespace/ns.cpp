#include<iostream>

using namespace std;

namespace X {
     int a = 10;
     int b = 20;
     
     void function(void)
     {
	cout << a << ":"<< b << endl;
     }
     
     class T {
        private:
          int ts;
        public:
          T(int t){ ts = t; }
          void display(void) { cout << ts << endl; }
          ~T(void){};
     };   
}


int main(void)
{
    using namespace X;
    a = 30;
    b = 40;
    X::function();
    X::T t(1);;
    t.display();
    return 1;
}
