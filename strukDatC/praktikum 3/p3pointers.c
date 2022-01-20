#include <stdio.h>

int p3p(){
    float *ptr, q;

    q = 50.5;
    ptr = &q; //get address of q

    printf("Value: %g\n", *ptr); //shows value of q, *ptr=*&q=q
    printf("Address: %p\n", ptr); //shows address of q

    *ptr = *ptr + 10;

    printf("value: %g\n", q);

    return 0;
}
