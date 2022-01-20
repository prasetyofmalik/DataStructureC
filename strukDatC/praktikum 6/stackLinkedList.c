#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node* ndpointer;
ndpointer top;

void initialize(){
    top = NULL;
}
void push(int value){
    ndpointer new_node;
    new_node = (ndpointer)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}
void pop(){
    ndpointer tmp;
    tmp = top;
    top = top->next;
    free(tmp);
}
void display(ndpointer head){
    if(head == NULL){
        printf("Stack kosong\n");
    } else{
        printf("%d\n", head->data);
        display(head->next);
    }
}
int DisplayTop(){
    return top->data;
}

int main(){
    initialize();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    printf("Top dari stack adalah %d\n", DisplayTop());
    pop();
    printf("Top dari stack setelah pop adalah %d\n", DisplayTop());
    display(top);

    return 0;
}
