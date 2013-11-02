#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


void selectionsort(int a[], int size)
{
    int i;
    for (i = 0; i < size - 1; ++i)
    {
        int j, min, temp;
        min = i; 
        for ( j = i + 1; j < size; ++j)
        {
            if ( a[j] < a[min] ) min = j;
        }
         
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        for ( int p = 0; p < size; p++)
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
   selectionsort(rint, 10);
   for ( int i = 0; i < 10; i++) {
      cout << rint[i] << ",";
   }
   cout << endl;
   
}
