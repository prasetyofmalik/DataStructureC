// doubly linked list adalah linked list yang memiliki
// dua pointer, yaitu pointer yang menyimpan alamat nilai
// selanjutnya dan pointer yang menyimpan alamat nilai
// sebelumnya.
#include <stdio.h>
#include <stdlib.h>

// buat struct node dengan pointer mengarah ke nilai
// selanjutnya dan sebelumnya
struct node{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node* ptrnode;
// inisialisasi node head dan tail
ptrnode head = NULL, tail = NULL;
//fungsi untuk membuat node baru
ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL; // pointer ke nilai selanjutnya
    p->prev = NULL; // pointer ke nilai sebelumnya

    return p;
}
// fungsi untuk membuat node dari kanan
void insertHead(int value){
    ptrnode p = createNode(value);

    if(head==NULL){
        head = tail = p;
    } else{
        head->next = p;
        p->prev = head;
        head = p;
    }
}
//fungsi untuk membuat node dari kiri
void insertTail(int value){
    ptrnode p = createNode(value);

    if(head==NULL){
        head = tail = p;
    } else{
        tail->prev = p;
        p->next = tail;
        tail = p;
    }
}
// fungsi untuk menghapus node dari kanan
void removeHead(){
    ptrnode curr;

    if(head==tail){
        curr = head;
        head = tail = NULL;
        free(curr);
    } else{
        curr = head;
        head = head->prev;
        head->next = NULL;
        free(curr);
    }
}
// fungsi untuk menghapus node dari kiri
void removeTail(){
    ptrnode curr;

    if(head==tail){
        curr = head;
        head = tail = NULL;
        free(curr);
    } else{
        curr = tail;
        tail = tail->next;
        tail->prev = NULL;
        free(curr);
    }
}
//fungsi untuk menampilkan node
void displayNodes(){
    ptrnode curr = tail;
    printf("head->tail: ");

    while(curr){
        printf("%d  ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}
//fungsi untuk menampilkan node
void displayNodesRev(){
    ptrnode curr = head;
    printf("tail->head: ");

    while(curr){
        printf("%d  ", curr->value);
        curr = curr->prev;
    }
    printf("\n");
}
int main(){
    insertHead(10);
    insertHead(20);
    insertHead(30);
    insertHead(40);
    insertHead(50);
    insertHead(11);
    insertTail(99);
    // 99  10  20  30  40  50  11

    displayNodes();
    displayNodesRev();

    removeHead();
    removeTail();
    // 10  20  30  40  50

    displayNodes();

    return 0;
}
