#include <stdio.h>
#include <stdlib.h>
// program konversi bilangan desimal (basis 10) ke biner (basis 2)
// dan oktal (basis 8) menggunakan stack dan linked list
struct node{
    int item;
    struct node *next;
};
typedef struct node* ndpointer;
// menyiapkan node awal
ndpointer top;
// menyiapkan stack kosong
void initializestack(){
    top = NULL;
}
// fungsi push untuk memasukkan nilai ke dalam linked list
void push(int value){
    ndpointer new_node;
    new_node = (ndpointer)malloc(sizeof(struct node));
    new_node->item = value;
    new_node->next = top;
    top = new_node;
}
// fungsi display untuk menampilkan nilai linked list
void display(ndpointer head){
    if(head == NULL){
        printf("\n");
    } else{
        printf("%d", head->item);
        display(head->next);
    }
}
// fungsi tampilkan untuk menampilkan bilangan biner dengan
// jumlah digit 2^n
int tampilkan(int count, int p){
    int cneed;
    // variabel cneed untuk menentukan jumlah digit
    // yang akan ditampilkan
    printf("jumlah digit biner (2^n): ");
    scanf("%d", &cneed);
    if(cneed>=count && cneed % 4 == 0){
        printf("Hasil konversi ke biner = ");
        int t=cneed-count;
        while(t>0){
            printf("%d", p);
            t--;
        }
        display(top);
    } else {
        printf("Jumlah digit tidak memenuhi.\n");
        tampilkan(count, p);
        // ditampilkan jika jumlah digit yang dimasukkan
        // kurang dari jumlah digit yang seharusnya atau
        // bukan kelipatan 2^n
    }
    top = NULL;
}
// fungsi untuk mengubah desimal ke biner atau oktal
void konversi(int bil_desimal, int basis){
    printf("Masukkan bilangan desimal : ");
    scanf("%d", &bil_desimal);
    int sisa_bagi, p;
    // variabel p untuk membedakan bilangan biner positif dan negatif
    int count = 0;
    if(bil_desimal==0) printf("Hasil konversi = 0\n");
    else{
        if(basis == 2){ // konversi desimal ke biner
            int n;
            p = 0;
            if(bil_desimal<0) bil_desimal++;
            for(n=bil_desimal;n!=0;n=n/basis){
                sisa_bagi = abs(n%basis);
                if(bil_desimal<0){
                    sisa_bagi^=1;
                    p = 1;
                }
                push(sisa_bagi);
                count++;
            }
            tampilkan(count, p);
        } else if (basis == 8){ // konversi desimal ke oktal
            int m;
            for(m=bil_desimal;m!=0;m=m/basis){
                sisa_bagi = abs(m%basis);
                if(m/basis==0)sisa_bagi = m%basis;
                push(sisa_bagi);
            }
            printf("Hasil konversi ke oktal = ");
            display(top);
            top = NULL; // kosongkan kembali nilai linked list
        }
    }
}
int main(){
    int desimal;
    int basis;
    // biner = basis 2, oktal = basis 8
    int choice = 0;

    printf("Program Konversi Desimal ke Biner dan Oktal\n\n");
    initializestack();

    do{
        printf("\nMasukkan pilihan konversi (1: biner, 2: oktal, 3: keluar): ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("\n---------------------------");
            printf("\nKonversi Desimal ke Biner\n\n");
            basis = 2;
            konversi(desimal, basis);
            printf("---------------------------\n");
            break;
        case 2:
            printf("\n---------------------------");
            printf("\nKonversi Desimal ke Oktal\n\n");
            basis = 8;
            konversi(desimal, basis);
            printf("---------------------------\n");
            break;
        case 3:
            printf("\nKELUAR");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    }
    while(choice!=3);

    return 0;
}
