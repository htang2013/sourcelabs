#include<stdio.h>

void main(void)
{
     int v = 0x1234;
     printf(" %x \n", *(char *)(&v));
     printf(" 12 is big endian, 34 is little endian");
}

