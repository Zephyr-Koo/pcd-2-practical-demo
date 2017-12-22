#include <stdio.h>

/* Parameter/argument name is optional for function declaration/prototype */
void demoPointer(),
     demoSwap1(),
     demoSwap2(),
     swap1(int, int),
     swap2(int *, int *);

int main()
{
    demoPointer();
    demoSwap1();
    demoSwap2();

    return 0;
}

void demoPointer()
{
    int num      = 42;
    int *numAddr = &num;

    /* NOTE:
       (1) numAddr stores the address of num
       (2) *numAddr refers to the reference (pointer) which store at its
           corresponding address
    */

    printf("Value %d was stored in address %d. \n", num, numAddr);
    printf("The address %d contains the value %d. \n\n", numAddr, *numAddr);
}

void demoSwap1()
{
    int num1 = 11, num2 = 22;

    printf("Before  (1) : num1 = %d | num2 = %d\n", num1, num2);

    swap1(num1, num2);

    printf("After   (1) : num1 = %d | num2 = %d\n\n", num1, num2);
}

void demoSwap2()
{
    int num1 = 33, num2 = 44;

    printf("Before  (2) : num1 = %d | num2 = %d\n", num1, num2);

    swap2(&num1, &num2);

    printf("After   (2) : num1 = %d | num2 = %d\n\n", num1, num2);
}

/* Carry out swapping but only applies within the function scope ONLY */
void swap1(int num1, int num2)
{
    int temp;

    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("Swapped (1) : num1 = %d | num2 = %d\n", num1, num2);
}

/* Carry out swapping with reference to the corresponding address */
void swap2(int *num1, int *num2)
{
    int temp;

    temp  = *num1;
    *num1 = *num2;
    *num2 = temp;

    printf("Swapped (2) : num1 = %d | num2 = %d\n", *num1, *num2);
}
