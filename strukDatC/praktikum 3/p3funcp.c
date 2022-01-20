#include <stdio.h>

/*
 one of the functions of pointer is to swap numbers
 using pass by reference */
void swap_ref(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//example of using pass by value
void swap_val(int m, int n){
    int temp;
    temp = m;
    m = n;
    n = temp;
}
int p3fp(){
    int p = 2, q = 5;

    printf("before swap\np = %d\nq = %d\n\n", p, q);
    swap_val(p, q);
    printf("after swap by value\np = %d\nq = %d\n\n", p, q);
    swap_ref(&p, &q);
    printf("after swap by reference\np = %d\nq = %d\n", p, q);

    return 0;
}
