#include<iostream>
using namespace std;


template < class ST >
class SStack {
       ST stck[10];
       int tos;
    public:
       SStack() { tos = 0; }
       void push(ST ob);
       ST pop(void);
};

template <class ST >
void SStack<ST>:: push(ST ob)
{
    if (tos == 10) return;
    stck[tos] = ob;
    tos ++;
}

template <class ST>
ST SStack<ST>::pop(void)
{
    if (tos == 0) return 0;
    tos --;
    return stck[tos];
}


int main(void)
{ 
   SStack <int> Sa, Sb;
   Sa.push(1);
   Sb.push(2);
   cout << Sa.pop() << endl;
   cout << Sb.pop() << endl;

 
   SStack <double> Ta, Tb;
   Ta.push(10.1);
   Tb.push(20.2);
   cout << Ta.pop() << endl;
   cout << Tb.pop() << endl;
   
   return 1;
}


