#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node* item;

struct queue{
    int count;
    item front;
    item rear;
};
typedef struct queue* antrean;

void initialize(antrean q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}
bool isempty(antrean q){
    return(q->rear == NULL);
}
void q_insert(antrean q, int value){
    item new_node;
    new_node = (item)malloc(sizeof(struct node));
    new_node->data = value;
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
void q_remove(antrean q){
    item tmp;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
}
void display(item head){
    if(head == NULL){
        printf("\n");
    } else{
        printf("%d ", head->data);
        display(head->next);
    }
}

int main(){
    antrean q;
    q = (antrean)malloc(sizeof(struct queue));
    initialize(q);

    q_insert(q,10);
    q_insert(q,20);
    q_insert(q,30);
    q_insert(q,40);
    printf("Queue sebelum dequeue\n");
    display(q->front);
    q_remove(q);
    printf("Queue setelah dequeue\n");
    display(q->front);

    return 0;
}
