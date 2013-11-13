#include<stdio.h>

union comb{
   unsigned int A;
   struct BT {
       unsigned short int BA;
       unsigned char BB;
       unsigned char BC;
   } B;
};


void main(void)
{
    int i;
    union comb c;
    c.A = 0x01234567;
    printf("CA = %0x, c.B.BA = %0x, c.B.BB = %0x, c.B.BC = %0x \n", c.A, c.B.BA, c.B.BB, c.B.BC);
    
}
