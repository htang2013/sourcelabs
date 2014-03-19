#include<iostream>

using namespace std;

class VarEngConstant {
    public:
          static const int NUM;
          VarEngConstant(){};
};

const int VarEngConstant::NUM = 7;


int main(void) 
{
	VarEngConstant vc;
        cout << VarEngConstant::NUM << endl;
        return 1;
}



