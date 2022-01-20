#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 36
#define MAX_CHARS 16
// struct untuk menyimpan data pasien
struct node{
    int urutan;
    char data[MAX_CHARS];
    int data2;
    char data3[2];
    struct node* next;
};
typedef struct node* item;
// struct untuk menyimpan data queue
struct queue{
    int count;
    item front;
    item rear;
};
typedef struct queue* antrean;
antrean q;
// inisialisasi queue
void initialize(antrean q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}
// fungsi untuk melihat apabila antrean kosong
bool isempty(antrean q){
    return(q->rear == NULL);
}
// fungsi enqueue
void enqueue(antrean q, int nomor, char nama[], int umur, char jk[]){
    item new_node; // node baru untuk menyimpan data tiap pasien
    new_node = (item)malloc(sizeof(struct node));
    new_node->urutan = nomor;
    strcpy(new_node->data, nama);
    new_node->data2 = umur;
    strcpy(new_node->data3, jk);
    new_node->next = NULL;
    if(!isempty(q)){
        q->rear->next = new_node;
        q->rear = new_node;
    }
    else {
        q->front = q->rear = new_node;
    }
    q->count++;
}
// fungsi pendaftaran pasien
void daftar(antrean q, int n){
    int nomor=n;
    char nama[MAX_CHARS], jk[2];
    int umur;
    if(n==MAX){
        printf("Mohon maaf, antrean penuh.\n");
        // jika nomor antrean mencapai MAX-1 (35),
        // klinik tidak menerima antrean lagi pada hari itu
    } else{
        puts("Formulir Pendaftaran Pasien Klinik COI19-VD");
        puts("-------------------------------------------");
        printf("Nomor antrean: %d\n", n);
        printf("Masukkan nama: "); scanf("%s", nama);
        printf("Masukkan umur: "); scanf("%d", &umur);
        printf("Masukkan jenis kelamin (L/P): "); scanf("%s", jk);
        puts("-------------------------------------------");
        enqueue(q, nomor, nama, umur, jk);
    }
}
// fungsi dequeue
void dequeue(antrean q){
    if(!isempty(q)){
        item tmp;
        tmp = q->front; // data paling depan sebelum di-dequeue ditampilkan terlebih dahulu
        puts("-----------------------------------------------------------------------");
        printf("!! Antrean nomor %d atas nama Sdr. %s silakan memasuki ruangan. !!\n", tmp->urutan, tmp->data);
        puts("-----------------------------------------------------------------------\n");
        q->front = q->front->next;
        q->count--;
        free(tmp);
    } else{
        printf("Antrean telah kosong.");
    }
}
// fungsi display
// fungsi display ketiga yang memunculkan baris kedua tabel dan seterusnya
void q_display2(item head){
    printf("|%i                |%*s          |   %3d     |     %s         |\n",
    head->urutan, -MAX_CHARS, head->data, head->data2, head->data3);
    if(head->next!=NULL) q_display2(head->next);
}
// fungsi display kedua yang hanya memunculkan header dan baris pertama tabel
void q_display(item head){
    puts("Daftar Antrean Tersisa\n");
    puts("|No. Antrean      |Nama                      |  Umur     | Jenis Kelamin |");
    puts("|-----------------|--------------------------|-----------|---------------|");
    printf("|%i                |%*s          |   %3d     |     %s         |\n",
    head->urutan, -MAX_CHARS, head->data, head->data2, head->data3);
    if(head->next!=NULL) q_display2(head->next);
}
// fungsi display pertama apabila antrean kosong akan langsung ditampilkan tanpa tabel
void display(item head){
    if(head!=NULL){
        q_display(head);
    }
    else if(head==NULL){
        printf("Antrean kosong.\n");
        head->next = head;
    }
    printf("\n");
}

int main(){
    int n = 1;
    int pilihan;
    antrean q = (antrean)malloc(sizeof(struct queue));
    initialize(q);

    do{
        puts("\n               Program Antrean Klinik COI19-VD");
        puts("               ===============================\n");
        puts("   MENU");
        puts("1. Ambil Nomor Antrean");
        puts("2. Lihat Antrean Tersisa");
        puts("3. Perkiraan Waktu Tunggu");
        puts("4. Panggil Antrean");
        puts("5. Keluar");
        printf("Silakan masukkan pilihan (1-5): "); scanf("%d", &pilihan);
        printf("\n");
        switch(pilihan){
        case 1 :
            daftar(q, n);
            n++;
            break;
        case 2 :
            display(q->front);
            break;
        case 3 :
            if(q->front!=NULL){
                printf("Perkiraan waktu tunggu untuk pasien Sdr.%s dengan nomor antrean %d", q->rear->data, q->rear->urutan);
                printf(" adalah %d menit.\n\n", 15 * (q->rear->urutan - q->front->urutan + 1));
                // 15 menit * (nomor pasien saat ini - nomor pasien paling depan -1)
            } else{
                printf("Mohon maaf, antrean kosong.\n");
            }
            break;
        case 4 :
            dequeue(q);
            break;
        case 5 :
            printf("Terima kasih dan semoga lekas sembuh.\n");
            break;
        default :
            puts("Pilihan tidak valid.\n");
            break;
        }
    }
    while(pilihan!=5);

    return 0;
}
