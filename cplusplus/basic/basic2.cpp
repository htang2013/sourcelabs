#include<iostream>

using namespace std;

class IntComplex {
     public:
        int real;
        int img;
        IntComplex(int rl = 0, int ig = 0):real(rl),img(ig){};
        friend ostream & operator << (ostream &os, const IntComplex &ic);
};


ostream & operator << (ostream &os, const IntComplex &ic)
{
     os << ic.real << '+' << ic.img << 'i';
     return os;
}

int main(void)
{
	IntComplex cmplx(1,2);
        cout << cmplx << endl;
        
        return 0;
}


 



     
