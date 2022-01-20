#include <stdio.h>

struct tubuh{
    int tinggi;
    float berat;
};
int main(){
    struct tubuh *ptubuh, tubuh1;
    ptubuh = &tubuh1;

    printf("Masukkan tinggi: ");
    scanf("%d", &ptubuh->tinggi);

    printf("Masukkan berat: ");
    scanf("%f", &ptubuh->berat);
    printf("\n");

    printf("Tinggi dan berat tubuh\n");
    printf("Tinggi: %d cm\n", ptubuh->tinggi);
    printf("Berat: %.2f kg\n", ptubuh->berat);

    return 0;
}
