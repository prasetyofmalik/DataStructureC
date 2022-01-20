#include <stdio.h>

int p38(){
    int a = 5;
    int *p;

    p = &a;
    *p = a + 64;
    printf("%d\n", *p);

    return 0;
}
