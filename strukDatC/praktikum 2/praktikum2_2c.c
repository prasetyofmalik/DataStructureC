#include <stdio.h>

void main()
{
    float pi = 22.0/7.0;
    printf("=== FLOAT ===\n");
    printf("%.15lf\n", pi);
    printf("%lf\n", pi);
}

void pidouble()
{
    double pi = 22.0/7.0;
    printf("=== DOUBLE ===\n");
    printf("%.15lf\n", pi);
    printf("%lf\n", pi);
}

int p22c()
{
    pifloat();
    printf("\n");
    pidouble();

    return 0;
}
