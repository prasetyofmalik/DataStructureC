#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[25];
    int nim;
    int kuis;
    int uts;
    int uas;
    double akhir;

    printf("Input Data Nilai Mahasiswa\n");
    printf("Masukkan nama Anda: ");
    //fgets(name, 25, stdin);
    scanf("%[^\n]", &name);
    printf("Masukkan NIM Anda: ");
    scanf("%d", &nim);
    printf("Masukkan nilai kuis Anda: ");
    scanf("%d", &kuis);
    printf("Masukkan nilai UTS Anda: ");
    scanf("%d", &uts);
    printf("Masukkan nilai UAS Anda: ");
    scanf("%d", &uas);

    akhir = 0.2*kuis+0.3*uts+0.5*uas;

    printf("\nNilai Akhir Mahasiswa\n");
    printf("Nama        : %s\n", name);
    printf("NIM         : %d\n", nim);
    printf("Nilai kuis  : %d\n", kuis);
    printf("Nilai UTS   : %d\n", uts);
    printf("Nilai UAS   : %d\n", uas);
    printf("Nilai akhir : %f\n", akhir);

    return 0;
}
