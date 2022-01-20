#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node *ptrnode;
ptrnode head, tail;
// fungsi dalam ptrnode
ptrnode reverse_dll(ptrnode head){
    ptrnode temp = NULL;
    ptrnode current = head;

    while(current!=NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp!=NULL)
        head = temp->prev;

    return head;
}
// fungsi dalam void
void reverse_list(ptrnode *head_ref){
    ptrnode prev = NULL;
    ptrnode current = *head_ref;
    ptrnode next;

    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = prev;
    }
    *head_ref = prev;
}
ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->prev = NULL;
    p->next = NULL;

    return p;
}
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
    insert_tail(10);
    insert_tail(20);
    insert_tail(30);
    insert_tail(40);
    insert_tail(50);
    displayNodes();
    reverse_list(head);
    displayNodes();

    return 0;
}
