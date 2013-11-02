#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


void insertionsort(int a[], int size)
{
    int i, j, index , p;
    for (i = 1; i < size; i++)
    {
        index = a[i]; 
        for ( j = i; j > 0 && a[j-1] > index; j--)
            a[j] = a[j-1];
        a[j] = index;

        for ( p = 0; p < size; p++)
          cout << a[p] << " ";
        cout << "pass: " << i << endl;
    }
}


int main(void)
{
   srand((unsigned)time(0));
   int rint[10];
   for( int i = 0 ; i < 10; i++ ){
       rint[i] = (rand() % 100) +1;
       cout << rint[i] << ",";
   }
   cout << endl <<"********************" << endl;
   insertionsort(rint, 10);
   for ( int i = 0; i < 10; i++) {
      cout << rint[i] << ",";
   }
   cout << endl;
   
}
