#include<stdio.h>

int a[5][3] = { { 1,2,3}, {4,5,6}, {7,8,9}, {10,11,12},{13,14,15}};

int main(void)
{
    int i = 0, j = 0;
    int *p = a;
    for ( i = 0; i< 5; i++) {
       for ( j = 0; j< 3; j++)
           printf("%d ", a[i][j]);
       printf("\n");
    }
    
    printf("**********\n");
    
    for ( i = 0; i< 15; i++)
       printf("%d ", *p ++);
    printf("\n");

       
}


