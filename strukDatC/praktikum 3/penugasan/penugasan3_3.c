#include <stdio.h>

struct mahasiswa{
    char nama[25];
    char nim[10];
    int umur;
};

int pen3_3(){
    struct mahasiswa tio
        = {"Prasetyo", "222011325", 19};
    struct mahasiswa *ptio;
    ptio = &tio;

    printf("Nama: %s\n", ptio->nama);
    printf("NIM: %s\n", ptio->nim);
    printf("Umur: %d\n", ptio->umur);

    printf("\nPerbarui data diri\n");
    // ganti nama dan umur
    // 7 Januari 2022
    strcpy(ptio->nama, "Prasetyo Fajar Malik");
    ptio->umur++;

    printf("Nama Lengkap: %s\n", ptio->nama);
    printf("NIM: %s\n", ptio->nim);
    printf("Umur: %d\n", ptio->umur);

    return 0;
}
