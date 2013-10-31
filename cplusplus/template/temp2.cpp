#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Base {
   private:
      int m;
   public:
      explicit Base(int a):m(a)
      {
          cout <<"Base (int)" << endl;
          m = a;
      }
      int GetValue() const
      {
         return m;
      }
};


void DoBar(Base ob)
{
     int i = ob.GetValue();
     cout << i << endl;
}

int main(void)
{
    DoBar(23);
    return 1;
}
