#include <stdio.h>

int p3aop(){
    int var[] = {10, 20, 30, 40, 50};
    int i, *ptr[5];

    for(i=0; i<5; i++){
        ptr[i] = &var[i];
        printf("Value of var[%d] = %d\n", i, *ptr[i]);
    }

    return 0;
}
