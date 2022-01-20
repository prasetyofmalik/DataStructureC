#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};
typedef struct node *ptrnode;
ptrnode head = NULL;
int jumnode; // jumlah node
ptrnode insert(int nilai){
    ptrnode p,q;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    if (head==NULL){
        head = p;
    }
    else {
        q = head;
        while (q->next!=NULL){
            q = q->next;
        }
        q->next = p;
    }
    return (head);
}
void isi_data(){
    int data;
    printf("Input jumlah node: ");
    scanf("%d", &jumnode);
    for (int j=0; j<jumnode; j++){
        printf("input data ke-%d: ", j+1);
        scanf("%d", &data);
        head = insert(data);
    }
}
int search(int x){ // x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp = head;
    while (tmp!=NULL){
        if(x==tmp->value)
            return j;
        else {
            tmp = tmp->next;
            j++;
        }
    }
    return -1; // jika tidak ada yang dicari return -1
}
void bersihkan_memori(){
    while (head!=NULL){
        ptrnode tmp = head;
        head = head->next;
        tmp->next = NULL;
        free(tmp);
    }
}
void main(){
    int x;
    isi_data();

    printf("\nInput nilai yang ingin dicari: ");
    scanf("%d", &x);
    if (search(x)==-1)
        printf(" data tidak ditemukan.");
    else
        printf(" data ditemukan di node ke-%d.", search(x));
    bersihkan_memori();
}
