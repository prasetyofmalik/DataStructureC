#include <stdio.h>

///declared after call
/*int total(int a, int b); // function prototype
int main(){
    int n1, n2, sum;
    printf("insert first number: ");
    scanf("%d", &n1);
    printf("insert second number: ");
    scanf("%d", &n2);

    sum = total(n1, n2); // function call
    printf("sum = %d", sum);

    return 0;
}
int total(int a, int b){ //function definition
    int result;
    result = a + b;

    return hasil; // return statement
}*/

///declared before call (recomended)
int total(int a, int b){ //function definition
    int result;
    result = a + b;

    return result; // return statement
}
int p3f(){
    int n1, n2, sum;
    printf("insert first number: ");
    scanf("%d", &n1);
    printf("insert second number: ");
    scanf("%d", &n2);

    sum = total(n1, n2); // function call
    printf("sum = %d", sum);

    return 0;
}
