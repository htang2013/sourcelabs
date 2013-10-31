#include<stdlib.h>
#include<stdio.h>
#include<time.h>



int intcompare( const void * i, const void * j)
{
   if (* (const int*)(i) > * (const int *) (j)) return (-1);
   if (* (const int *) (i) < * (const int *)(j)) return (1);
   return 0;
}

int main(void)
{ 
   int ra[100];
   srand(time(NULL));
   for (int i= 0; i < 100; i++){
      ra[i] = (int)rand()%100;
      printf("%d,", ra[i]);
   }
   printf("**********************");
   
   qsort(ra,100, 4, intcompare);
   for (int i = 0; i< 100; i++) {
      printf("%d,", ra[i]);
   }
   return 1;  
}
