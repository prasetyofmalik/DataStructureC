#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node
typedef struct node{
    char nama[20];
    int alpro;
    int kalkulus;
    struct node* next;
} mhs;
int count = 0;
// function to create a new node
mhs* newmhs(char a[], int alp, int kal){
    mhs* temp = (mhs*)malloc(sizeof(mhs));
    strcpy(temp->nama, a);
    temp->alpro = alp;
    temp->kalkulus = kal;
    temp->next = NULL;

    return temp;
}
// delete mhs
void dequeue(mhs** head){
    if((*head)!=NULL){
        mhs* temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}
// insert mhs
void enqueue(mhs** head, char n[], int alp, int kal){
    mhs* temp = newmhs(n, alp, kal);
    if((*head)==NULL){
        (*head) = temp;
    } else if(alp>(*head)->alpro){
        temp->next = *head;
        (*head) = temp;
    } else{
        if(kal>(*head)->kalkulus){
            temp->next = *head;
            (*head) = temp;
        } else{
            mhs* start = (*head);
            while(start->next!=NULL && start->next->kalkulus>kal){
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
        }
    }
    count++;
}
// print mhs
void display(mhs* head){
    if(head == NULL){
        printf("Daftar belum tersedia\n");
    } else{
        printf("Nama: %s\tAlpro: %d\tKalkulus: %d\n",
            head->nama, head->alpro, head->kalkulus);
        display(head->next);
    }
}
int main(){
    mhs* wakil = NULL;

    enqueue(&wakil, "Eko", 50, 20);
    enqueue(&wakil, "Budi", 50, 20);
    enqueue(&wakil, "Bambang", 60, 20);
    enqueue(&wakil, "Eka", 60, 20);
    enqueue(&wakil, "Wawo", 60, 20);
    enqueue(&wakil, "Ame", 60, 30);

    display(wakil);

    return 0;
}
