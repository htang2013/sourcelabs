#include<stdio.h>
#include<string.h>

void main(void)
{
    
     char str[] = "hello";
     char *p = str;
     printf("str : length %d, size %d\n",strlen(str), sizeof(str));
     printf("p : length %d, size %d, content %x\n", strlen(p), sizeof(p), p);
     printf("sizeof char is: %d\n", sizeof(char));
     
     
}
