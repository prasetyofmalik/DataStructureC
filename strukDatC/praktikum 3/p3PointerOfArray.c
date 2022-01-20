#include <stdio.h>

int p3poa() {
    int x[] = {10, 100, 1000};
    int *px, i;

    px = &x;

    for(i=0; i<3; i++){
        printf("Value of %d = %d\nAddress of %d = %p\n", i, *(px+i), i, (px+i));
    }

    return 0;
}
