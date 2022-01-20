#include <stdio.h>

int p2_1(){
    printf("Char     :%d\n",sizeof(char));//1
    printf("Integer  :%d\n",sizeof(int));//4
    printf("Float    :%d\n",sizeof(float));//4
    printf("Double   :%d\n",sizeof(double));//8

    int arr[] = {1, 2, 3, 5, 84};//tergantung isi dalam array
    printf("Jumlah elemen array:%lu ", sizeof(arr) / sizeof(arr[0]));

    return 0;
}
