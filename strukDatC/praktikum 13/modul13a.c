#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size){ //mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data: ");
    for(int i=0;i<*size;i++){
        scanf("%d",&data[i]);
    }
}

void tampil_data(int data[], int size){
    for(int i=0;i<size;i++) printf("%d ",data[i]);
    printf("\n");
}

void insertionSortAsc(int arr[], int n){
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
void insertionSortDesc(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void main(){
    int data[MAX];
    int size; //ukuran array yang dipakai
    fill_data(data,&size);
    insertionSortAsc(data,size);
    printf("data setelah diurutkan ascending:\n");
    tampil_data(data,size);

    insertionSortDesc(data, size);
    printf("data setelah diurutkan descending:\n");
    tampil_data(data,size);
}