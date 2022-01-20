#include <stdio.h>

int p3pop(){
    int var = 789;
    int *ptr2, **ptr1;

    ptr2 = &var;
    ptr1 = &ptr2;

    printf("Value of var = %d\n", var);
    printf("Value of var using single pointer = %d\n", *ptr2);
    printf("value of var using double pointer = %d\n", **ptr1);

    return 0;
}
