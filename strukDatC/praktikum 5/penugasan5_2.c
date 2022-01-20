#include <stdio.h>
#include <stdlib.h>

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
// fungsi untuk menambahkan simpul baru
// 1. insert head
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
// 2. insert tail
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
// menampilkan seluruh value pada node
void display_list(){
    ptrnode curr = head;
    int i = 1;

    while(curr){
        printf("node %d: ",i);
        printf("%d  \n", curr->value);
        curr = curr->next;
        i++;
    }
    printf("\n");
}
int main(){
    ptrnode head = NULL;
    ptrnode tail = NULL;
    tail = head;

    int jmlnode;
    printf("Input the number of nodes : ");
    scanf("%d", &jmlnode);

    int i, nilai;
    for(i=1; i<=jmlnode; i++){
        printf("Input data for node %d : ", i);
        scanf("%d", &nilai);
        insert_tail(nilai);
    }
    printf("\nData entered in the list are : \n");
    display_list();

    int new_head;
    printf("\nInput data for the first node : ");
    scanf("%d", &new_head);
    insert_head(new_head);

    printf("\nAfter insertion the new list are : \n");
    display_list();

    return 0;
}
