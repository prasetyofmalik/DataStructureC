#include <stdio.h>

void p310(){
    // membuat variabel
    int umur = 19;
    float tinggi = 175.6;
    // membuat pointer
    int *pointer_umur = &umur;
    int *pointer2 = &umur;
    float *p_tinggi = &tinggi;
    // mencetak alamat memori pointer
    printf("alamat memori *pointer_umur = %d\n", &pointer_umur);
    printf("alamat memori *pointer2 = %d\n", &pointer2);
    printf("alamat memori *p_tinggi = %d\n", &p_tinggi);

    return 0;
}
