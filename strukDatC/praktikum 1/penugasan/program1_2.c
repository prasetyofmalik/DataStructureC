#include <stdio.h>
#include <stdlib.h>

int persegipanjang()
{
    int p;
    int l;
    int L;
    int K;

    printf("Program Menghitung Luas dan Keliling Persegi Panjang\n");
    printf("Masukkan panjang: ");
    scanf("%d", &p);
    printf("Masukkan lebar: ");
    scanf("%d", &l);

    L = p*l;
    K = 2*(p+l);

    printf("\nLuas Persegi Panjang: %d\n", L);
    printf("Keliling Persegi Panjang: %d\n", K);

    return 0;
}
