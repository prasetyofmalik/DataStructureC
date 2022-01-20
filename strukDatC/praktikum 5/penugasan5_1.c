#include <stdio.h>
#include <stdlib.h>

// persiapan
struct node{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node *ptrnode;
ptrnode head, tail;
// fungsi untuk membuat simpul baru dengan deklarasi pointer
ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->prev = NULL;
    p->next = NULL;

    return p;
}
// insert kanan
void insert_tail(int nilai){
    ptrnode new_node = createNode(nilai);

    if(head==NULL){
        head = tail = new_node;
    } else{
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
// fungsi untuk membuat node dari kiri
void insert_head(int nilai){
    ptrnode new_node = createNode(nilai);

    if(head==NULL){
        head = tail = new_node;
    } else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
// delete kanan
void remove_last(){
    if(head==NULL) return;
    ptrnode last = tail;
    tail = tail->prev;
    tail->next = NULL;
    last->prev = NULL;
    free(last);
}
// menampilkan seluruh value pada node
void displayNodes(){
    ptrnode curr = head;
    printf("Simpul: ");

    while(curr){
        printf("%d  ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}
int main(){
    // pembuatan simpul awal
    ptrnode head = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    tail = head;
    insert_head(50);
    insert_head(40);
    insert_head(30);
    insert_head(20);
    insert_head(10);
    displayNodes();

    insert_tail(11); // insert kanan
    displayNodes();

    remove_last(); // delete kanan
    displayNodes();

    return 0;
}
