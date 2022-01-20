#include <stdio.h>

int *getMax(int *m, int *n){
    if(*m>*n){
        return m;
    }
    else{
        return n;
    }
}
int p3fr(){
    int x = 6900;
    int y = 200;
    int *max;

    max = getMax(&x, &y);
    printf("max value: %d\n", *max);

    return 0;
}
