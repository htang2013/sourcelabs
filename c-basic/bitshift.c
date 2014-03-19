#include<stdio.h>
#include<stdlib.h>

void intp(int s)
{
    int i;
    for (i = 0; i< 32; i ++)
    {
        if ((s <<i) & 0x80000000 )
            printf("%d", 1);
        else printf("%d",0);
    }
    printf("\n");
}


int main(void)
{
    int a = -10;
    printf("a = %x, size %d\n ", a, sizeof(int));
    intp(a);
    return 0;
}
