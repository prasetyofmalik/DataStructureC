#include <stdio.h>
#include <string.h>
#define MAX 100 //ukuran maksimum array

struct Mahasiswa{
    int nim;
    char nama[50];
    int nilai;
};
void fill_data(struct Mahasiswa mhsw[], int *size){ //mengisi data
    printf("\nInput Data Anda: \n");
    for(int i=0;i<*size;i++){
        printf("Nama mahasiswa: ");
        scanf(" %s", &mhsw[i].nama);
        printf("NIM: ");
        scanf("%d", &mhsw[i].nim);
        printf("Nilai: ");
        scanf("%d", &mhsw[i].nilai);
    }
}
void tampil_data(struct Mahasiswa mhsw[], int size){
    for(int i=0;i<size;i++){
        printf("\nNama mahasiswa: %s\n", mhsw[i].nama);
        printf("NIM: %d\n", mhsw[i].nim);
        printf("Nilai: %d\n", mhsw[i].nilai);
    }
    printf("\n");
}
void reverseArray(struct Mahasiswa mhsw[], int start, int end){
    while (start < end){
        struct Mahasiswa temp = mhsw[start];
        mhsw[start] = mhsw[end];
        mhsw[end] = temp;
        start++;
        end--;
    }
}
void swap(struct Mahasiswa *a, struct Mahasiswa *b){
    struct Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}
// pengurutan menggunakan algoritma bubble sort
void bubbleSortNIM(struct Mahasiswa mhsw[], int n){
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (mhsw[j].nim > mhsw[j+1].nim)
                swap(&mhsw[j], &mhsw[j+1]);
}
void bubbleSortNama(struct Mahasiswa mhsw[], int n){
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++){
            int z = strcmp(mhsw[j].nama, mhsw[j+1].nama);
            if (z>0)
                swap(&mhsw[j], &mhsw[j+1]);
        }
}
// pencarian dengan binary search
int binarySearchNIM(struct Mahasiswa mhsw[], int size, int x){
    int L = 0;
    int H = size-1;
    int M = -1;
    int index = -1;
    while (L<=H){
        M = (L + H)/2;
        if (mhsw[M].nim==x) return M;
        else {
            if (mhsw[M].nim<x) L = M + 1;
            else H = M - 1;
        }
    }
    return -1;
}
int binarySearchNama(struct Mahasiswa mhsw[], int size, char y[]){
    int L = 0;
    int H = size-1;
    int M = -1;
    int index = -1;
    while (L<=H){
        M = (L + H)/2;
        int z = strcmp(mhsw[M].nama, y);
        if (z==0) return M;
        else {
            if (z<0) L = M + 1;
            else H = M - 1;
        }
    }
    return -1;
}
void main(){
    struct Mahasiswa data[MAX];
    int size; //ukuran array yang dipakai
    char pengurutan, y[50];
    int pilih,pilih2, x;
    puts("###PROGRAM SORTING DAN SEARCHING DATA MAHASISWA###");
    printf("Input jumlah mahasiswa = ");
    scanf("%d", &size);
    // pengurutan
    puts("Pengurutan berdasarkan: ");
    printf(" 1. NIM\n 2. Nama\n Pilih (1/2): ");
    scanf("%d", &pilih);
    printf(" \nPilih pengurutan Naik/Turun (N/T): ");
    scanf(" %c", &pengurutan);
    fill_data(data,&size);
    if(pilih==1)
        bubbleSortNIM(data, size);
    else if(pilih==2)
        bubbleSortNama(data, size);
    if(pengurutan=='N'){
        puts("Pilihan pengurutan Naik");
        printf("\nData setelah diurutkan: ");
        tampil_data(data,size);
    }
    else if(pengurutan=='T'){
        puts("Pilihan pengurutan Turun");
        reverseArray(data, 0, size-1);
        printf("\nData setelah diurutkan: ");
        tampil_data(data,size);
    }
    else printf("\nPilihan tidak valid.\n");
    // pencarian
    puts("Pencarian berdasarkan: ");
    printf(" 1. NIM\n 2. Nama\n Pilih (1/2): ");
    scanf("%d", &pilih2);
    if(pilih2==1){
        printf("NIM yang ingin dicari: ");
        scanf("%d", &x);
        if(binarySearchNIM(data, size, x)==-1)
            printf("tidak ditemukan.");
        else 
            printf("ditemukan pada indeks ke-%d", 
            binarySearchNIM(data, size, x));
    }
    else if(pilih2==2){
        printf("Nama yang ingin dicari: ");
        scanf("%s", &y);
        if(binarySearchNama(data, size, y)==-1)
            printf("tidak ditemukan.");
        else 
            printf("ditemukan pada indeks ke-%d", 
            binarySearchNama(data, size, y));
    }
    else printf("\nPilihan tidak valid.\n");
}