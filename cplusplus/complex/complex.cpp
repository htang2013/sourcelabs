#include<iostream>



using namespace std;


class complex{
    private:
           double re,im;
    public:
           complex(double r=0, double i=0):re{r},im(i){}
           double real() const { return re; }
           double image() const { return im; }
           complex & operator +=( complex &z ) { re+=z.re, im+=z.im; return *this; }
           friend complex operator + (complex & a, complex &b) 
           { 
                return complex(a.re+b.re,a.im+ b.im); 
           }
           friend ostream & operator << (ostream &ostr , const complex &z)
           {
               ostr << z.re << "+" << z.im << "i"; 
           }
};


int main(void)
{
    complex cpx(1,2), cpy(3,4);
    cout << cpx << endl;
    cout << cpy << endl;
    cpx+= cpy;
    complex cps = cpx + cpy;
    cout << cpx << endl;
    cout << cps << endl;
    
    
}
 
            



