#include<iostream>

class base {
   public:
      base(int initialValue = 0): x(initialValue){}
   private:
     int x;
};

class derived: public base {
   public:
      derived(int initValue):base(initValue),y(initValue) {}
      derived &operator = ( const derived &rhs);
   private:
      int y;
};

derived &derived::operator = (const derived &rhs)
{
     if ( this == &rhs) return *this;
     base::operator=(rhs);
     y = rhs.y;
     return *this;
}

