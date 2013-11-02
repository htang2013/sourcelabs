#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


void bubblesort(int a[], int size)
{
    int i, j, p, temp;
    for (i = 0; i < size; i++)
    {
        for ( j = i; j < size; j++)
        {
            if (a[j] <= a[i]) {
               temp = a[j];
               a[j] = a[i];
               a[i] = temp;
            }
        }

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
   bubblesort(rint, 10);
   for ( int i = 0; i < 10; i++) {
      cout << rint[i] << ",";
   }
   cout << endl;
   
}
