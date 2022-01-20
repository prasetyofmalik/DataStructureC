#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size){ //mengisi data
    printf("Input Data Anda: ");
    for(int i=0;i<*size;i++){
        scanf("%d",&data[i]);
    }
}
void tampil_data(int data[], int size){
    for(int i=0;i<size;i++) printf("%d ",data[i]);
    printf("\n");
}
void reverseArray(int arr[], int start, int end){
    while (start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}  
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// insertion sort
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// selection sort
void selectionSort(int data[], int size){
    for(int step = 0; step < size - 1; step++){
        int min_idx = step;
        for(int i = step +1;i<size;i++)
            if(data[i]<data[min_idx])
                min_idx = i;
        swap(&data[min_idx],&data[step]);
    }
}
// merge sort
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// bubble sort
void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
void main(){
    int data[MAX];
    int size; //ukuran array yang dipakai
    int pilih;
    char pengurutan;
    puts("###PROGRAM SORTING DATA###");
    printf("Input jumlah data = ");
    scanf("%d", &size);
    puts("Metode Sorting yang tersedia");
    printf("1. Insertion Sort\n"
           "2. Selection Sort\n"
           "3. Merge Sort\n"
           "4. Bubble Sort\n");
    printf("Pilih Metode Sorting (1/2/3/4): ");
    scanf("%d", &pilih);
    printf("Pilih pengurutan Naik/Turun (N/T): ");
    scanf(" %c", &pengurutan);
    fill_data(data,&size);
    switch(pilih){
        case 1:
            puts("Menjalankan sorting dengan metode Insertion Sort");
            insertionSort(data,size);
            break;
        case 2:
            puts("Menjalankan sorting dengan metode Selection Sort");
            selectionSort(data,size);
            break;
        case 3:
            puts("Menjalankan sorting dengan metode Merge Sort");
            mergeSort(data,0,size-1);
            break;
        case 4:
            puts("Menjalankan sorting dengan metode Bubble Sort");
            bubbleSort(data,size);
            break;
        default:
            printf("\nPilihan tidak valid.\n");
    }
    if(pengurutan=='N'){
        puts("Pilihan pengurutan Naik");
        printf("Data setelah diurutkan: ");
        tampil_data(data,size);
    }
    else if(pengurutan=='T'){
        puts("Pilihan pengurutan Turun");
        reverseArray(data, 0, size-1);
        printf("Data setelah diurutkan: ");
        tampil_data(data,size);
    }
    else printf("\nPilihan tidak valid.\n");
}