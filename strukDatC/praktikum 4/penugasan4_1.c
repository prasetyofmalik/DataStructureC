#include <stdio.h>
#include <stdlib.h>

//linked list node structure
struct node{
    int value;
    struct node *next;
};
typedef struct node *ptrnode;

// membuat node baru
ptrnode makeNode(int nilai){
    // alokasi memori
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;

    return(p);
}
// menampilkan seluruh value pada node
void displayNodes(ptrnode head){
    printf("Nodes: ");
    while (head!=NULL){
        printf("%d   ", head->value);
        head = head->next;
    }
    printf("\n");
}
ptrnode head = NULL;
// menampilkan jumlah pada node
void countNode(ptrnode head){
    ptrnode p = head;
    int count=0;
    while(p != NULL){
       p = p->next;
       count++;
    }
    printf("Jumlah nodenya ada %d.\n",count);
}
int main(){
    //ptrnode head = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    head->value = 10;
    ptrnode dua = makeNode(20);
    ptrnode tiga = makeNode(30);
    ptrnode empat = makeNode(40);
    ptrnode lima = makeNode(50);

    head->next = dua;
    dua->next = tiga;
    tiga->next = empat;
    empat->next = lima;
    displayNodes(head);
    // memanggil fungsi countNode function untuk print jumlah node.
    countNode(head);

    return 0;
}

