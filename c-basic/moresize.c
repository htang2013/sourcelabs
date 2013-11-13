#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee_st {
    char name[40];
    int id;
} Employee;

int main()
{
    int myInt;
    Employee john;

    printf("Size of int is %d\n",sizeof(myInt));
        /* The argument of sizeof is an object */
    printf("Size of int is %d\n",sizeof(int));
        /* The argument of sizeof is a data type */

    printf("Size of Employee is %d\n",sizeof(Employee));
        /* The argument of sizeof is a data type */
    printf("Size of john is %d\n",sizeof(john));
        /* The argument of sizeof is an object */

    printf("Size of char is %d\n",sizeof(char));
    printf("Size of short is %d\n",sizeof(short));
    printf("Size of int is %d\n",sizeof(int));
    printf("Size of long is %d\n",sizeof(long));
    printf("Size of float is %d\n",sizeof(float));
    printf("Size of double is %d\n",sizeof(double));

    return 0;

}
