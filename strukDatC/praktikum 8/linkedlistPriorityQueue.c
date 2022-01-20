#include <stdio.h>
#include <stdlib.h>
// operasi priority queue dengan linked list
// diasumsikan nilai lebih rendah menunjukkan prioritas lebih tinggi
struct node{
    int data;
    int priority;
    struct node* next;
};
typedef struct node* Node;
// create node baru
Node newNode(int d, int p){
    Node temp = (Node)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}
// operasi insert atau enqueue
void insert_pq(Node* head, int d, int p){
    Node temp = newNode(d, p); // node baru: data=d, priority=p
    if((*head)==NULL){
        (*head) = temp;
    }
    else if((*head)->priority>p){
        temp->next = *head; // jika lebih prioritas, jadikan head
        (*head) = temp;
    } else{
        Node start = (*head);
        while(start->next!=NULL&&start->next->priority<=p){
            start = start->next; // sesuaikan posisi elemen baru
        }
        temp->next = start->next;
        start->next = temp;
    }
}
// operasi remove atau dequeue
void remove_pq(Node* head){
    Node temp = *head;
    (*head) = (*head)->next;
    free(temp); // hapus node head (prioritas tertinggi)
}
// tampilkan isi nodes
void display(Node head){
    if(head==NULL){
        printf("-\n");
    } else{
        printf("%d\n", head->data);
        display(head->next);
    }
}
int main(){
    Node pq = newNode(4, 1);
    insert_pq(&pq, 5, 2);
    insert_pq(&pq, 6, 3);
    insert_pq(&pq, 69, 3);
    insert_pq(&pq, 52, 2);
    insert_pq(&pq, 7, 0);

    display(pq);

    remove_pq(&pq);

    display(pq);

    return 0;
}
