#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50
#define MAX_CHARS 16
struct node{
    int urutan;
    char data[MAX_CHARS];
    int data2;
    char data3[MAX_CHARS];
    struct node* next;
};
typedef struct node* item;

struct queue{
    int count;
    item front;
    item rear;
};
typedef struct queue* antrean;
antrean q;
void initialize(antrean q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}
bool isempty(antrean q){
    return(q->rear == NULL);
}
// fungsi enqueue
void enqueue(antrean q, int nomor, char nama[], int umur, char jk[]){
    item new_node;
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
// fungsi dequeue
void dequeue(antrean q){
    item tmp;
    tmp = q->front;
    puts("-----------------------------------------------------------------------");
    printf("!! Antrean nomor %d atas nama Sdr. %s silakan memasuki ruangan. !!\n", tmp->urutan, tmp->data);
    puts("-----------------------------------------------------------------------\n");
    q->front = q->front->next;
    q->count--;
    free(tmp);
}
// fungsi display
void q_display2(item head){
    printf("|%i                |%*s          |%3d        |   %s           |\n\n",
    head->urutan, -MAX_CHARS, head->data, head->data2, head->data3);
    if(head->next!=NULL) q_display2(head->next);
}
void q_display(item head){
    puts("Daftar Antrean Tersisa\n");
    puts("|No. Antrean      |Nama                      |  Umur     | Jenis Kelamin |");
    puts("|-----------------|--------------------------|-----------|---------------|");
    printf("|%i                |%*s          |%3d        |   %s           |\n",
    head->urutan, -MAX_CHARS, head->data, head->data2, head->data3);
    if(head->next!=NULL) q_display2(head->next);
}
void display(item head){
    if(head!=NULL){
        q_display(head);
    }
    else if(head==NULL){
        printf("Antrean kosong\n");
        head->next = head;
    }
}

int main(){
    int n = 1;
    int nomor, pilihan, umur, no;
    char nama[MAX_CHARS];
    char jk[MAX_CHARS];
    antrean q = (antrean)malloc(sizeof(struct queue));
    initialize(q);

    do{
        puts("\n               Program Antrean Klinik COI19-VD");
        puts("               ===============================\n");
        puts("   MENU");
        puts("1. Ambil nomor antrean");
        puts("2. Lihat antrean tersisa");
        puts("3. Perkiraan waktu tunggu");
        puts("4. Panggil antrean");
        puts("5. Keluar");
        printf("Silakan masukkan pilihan (1-5) : "); scanf("%d", &pilihan);
        printf("\n");
        switch(pilihan){
        case 1 :
            nomor=n;
            if(n==MAX){
                printf("Mohon maaf, antrean penuh.\n");
                break;
            }
            printf("Nomor antrean: %d\n", n);
            printf("Masukkan nama: "); scanf("%s", nama);
            printf("Masukkan umur: "); scanf("%d", &umur);
            printf("Masukkan jenis kelamin (L/P): "); scanf("%s", jk);
            enqueue(q, nomor, nama, umur, jk);
            no = n;
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
            printf("Terima kasih dan semoga lekas sembuh.");
            break;
        default :
            puts("Pilihan tidak valid.\n");
            break;
        }
    }
    while(pilihan!=5);

    return 0;
}
