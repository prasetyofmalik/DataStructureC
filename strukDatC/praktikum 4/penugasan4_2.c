#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct node{
    int value;
    struct node *next;
};
typedef struct node *ptrnode;

/* Function to reverse the linked list */
void reverse(ptrnode* head_ref)
{
    ptrnode prev = NULL;
    ptrnode current = *head_ref;
    ptrnode next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

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
    //printf("Nodes: ");
    while (head!=NULL){
        printf("%d   ", head->value);
        head = head->next;
    }
    printf("\n");
}
/* Driver code*/
int main()
{
    ptrnode head = NULL;
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

    printf("singly linked list sebelumnya:\n");
    displayNodes(head);
    reverse(&head);
    printf("\nsingly linked list setelahnya:\n");
    displayNodes(head);

    return 0;
}
