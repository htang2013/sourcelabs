#include<iostream>
#include<new>
#include<cstdlib>
using namespace std;

class location{
    int longtitude, latitude;
    public:
        location(){longtitude = 1; latitude = 1;}
        location(int lg, int la):longtitude(lg),latitude(la){}
/*
        location operator + (location op2)
        {
            location temp;
            temp.longtitude = op2.longtitude + longtitude;
            temp.latitude = op2.latitude + latitude;
            return temp;
        }
*/
        void show(void){
            cout << "long: " << longtitude << "att: " << latitude << endl;
        } 
        location &operator++ ()
        {
             longtitude ++;
             latitude ++;
             return *this;
        }

        location &operator++ (int)
        {
	     longtitude ++;
             latitude ++;
             return *this;
        }
        
        friend location operator+( location op1, location op2)
        {
            location temp;
            temp.longtitude = op1.longtitude + op2.longtitude;
            temp.latitude = op1.latitude + op2.latitude;
            return temp;
        }
        
        void *operator new (size_t size)
        {
              void *p;
              cout << "In overloaded new" << endl;
              p = malloc(size);
              if(!p) { 
                   bad_alloc ba;
                   throw ba;
              }
              return p;

        }

        void operator delete(void *p)
        {
 	     cout << " In overloaded delete" << endl;
             free(p); 
            
        }
        
        
        void *operator new[] (size_t size)
        {
              void *p;
              cout << "In overloaded new[]" << endl;
              p = malloc(size);
              if(!p) { 
                   bad_alloc ba;
                   throw ba;
              }
              return p;

        }

        void operator delete[](void *p)
        {
 	     cout << " In overloaded delete[]" << endl;
             free(p); 
            
        }
/*
        location &operator[] (int i)
        {
            //  return this    
        }
*/
        location operator() ( int i, int j)
        {
            longtitude = i;
            latitude = j;
            return *this;
        }   
   
        location *operator->()
        {
            return this;
        } 
         

};

int mainf(void)
{
       location la(1,2), lb(3,4);
       la.show();
       lb.show();
       location lt = la + lb;
       lt.show();
       lt++;
       lt.show();
}

int maing(void)
{
      location *p1, *p2;
      p1 = new location[10];
      for ( int i = 0; i < 10; i++)
          p1[i].show();
      delete []p1;
}

int main(void)
{
     location la(1,2), lb(3,4);
     la.show();
     lb(4,5);
     lb.show();
    
}
