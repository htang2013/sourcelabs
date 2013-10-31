#include<iostream>

using namespace std;
 
template < class X >
class Node{
   public:
    Node ( const X & o = X(), Node *n = NULL): element(o), next(n) {};
    X element;
    Node *next;  
    friend ostream & operator << ( ostream &o, Node &rhs)
    {
         o << rhs.element << endl;
         return o;
    } 
};

class BaseX{
    public:
      BaseX(int x = 0, int y = 0): mx(x), my(y) {};
      int mx, my;
      friend ostream & operator << ( ostream &o, BaseX &rhs)
      {
          o << rhs.mx << "," << rhs.my << endl;
      }
};
     

int main(void)
{
    Node<BaseX> node(BaseX(10, 20));
    cout << node;
}





