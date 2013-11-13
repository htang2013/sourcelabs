#include<stdio.h>

union comb{
   unsigned long A;
   struct {
       unsigned  BA: 8;
       unsigned  BB: 8;
   } B; 
};

int main(void)
{
    union comb C;
    C.A = 0x123456789abcdef0;
    C.B.BB = 0xAB;
    
    printf("ptr A, B is: %lx , %lx\n", &(C.A), &(C.B));
    printf("C.A = %lx, C.B = %lx\n", C.A, C.B.BB);
    printf("size of union comb %d\n", sizeof(union comb));
    printf("size of unsigned long: %d, sizeof unsigned int: %d\n", sizeof(unsigned long), sizeof(unsigned int));
  
}
