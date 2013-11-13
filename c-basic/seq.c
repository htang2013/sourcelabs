#include<stdio.h>

int main(void)
{
    int i = 8;
    printf("%d, %d, %d\n", i++, i++, i++);
    printf("%d, %d, %d\n", ++i, ++i, ++i);
    printf("%d\n", i);
    printf("%d, %d \n", -i++, -i--);
    printf("%d\n", i);
}
