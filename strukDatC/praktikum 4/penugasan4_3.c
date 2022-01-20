#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSTRINGSIZE 50 // maximum allowed size of strings

struct student {
    int nim;
    char nama[MAXSTRINGSIZE]; // we need an array of char her, not a char
    struct student* next;
};
typedef struct student *mhsw;

void tambah_student(mhsw* head, int mhs_nim, char mhs_nama[]){
    mhsw new_student; // fungsi createNode()
    new_student = (mhsw)malloc(sizeof(struct student));// no cast is needed with malloc
    new_student->nim = mhs_nim;
    strcpy(new_student->nama, mhs_nama); // copy the string
    new_student->next = NULL;

    if(*head == NULL){
        *head = new_student;
    } else{
        mhsw tail = *head; // fungsi push() atau insert_tail()
        while(tail->next!=NULL)
            tail = tail->next;
        tail->next = new_student;
    }
}

void tampilkan_mahasiswa(mhsw head) {
    printf("\nDaftar Mahasiswa: \n");
    mhsw tmp= head;
    while (tmp != NULL) {
        printf("NIM: %d\n", tmp->nim);
        printf("Nama: %s\n\n", tmp->nama);
        tmp = tmp->next;
  }
  printf("selesai");
}

int main() {
    int n;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    int nim;
    char nama[MAXSTRINGSIZE];
    mhsw list_student = NULL;
    for (int i=0; i<n; i++) {
        printf("\nNama: ");
        scanf("%s", &nama);
        printf("\nNIM: ");
        scanf("%d", &nim);
        tambah_student(&list_student, nim, nama);
    }
    tampilkan_mahasiswa(list_student);

    return 0;
}
