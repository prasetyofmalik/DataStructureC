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
    }
    else if(alp<(*head)->alpro){
        temp->next = *head;
        (*head) = temp;
    }
    else{
        mhs* start1 = (*head);
        mhs* start2 = NULL;
        while(start1->next!=NULL&&start1->next->alpro<=alp){
            start1 = start1->next;
        }
        temp->next = start1->next;
        start1->next = temp;
        if(alp==start1->alpro){
            if(kal<start1->kalkulus){
                start2 = start1;
                start1 = temp;
                start2->next = temp->next;
                temp->next = start2;

            }
        }
    }
    count++;
}
// print mhs
void display(mhs* head){
    if(head == NULL){
        printf("Daftar belum tersedia\n");
    }
    else{
        printf("Nama: %s\tAlpro: %d\tKalkulus: %d\n",
            head->nama, head->alpro, head->kalkulus);
        display(head->next);
    }
}
int main(){
    mhs* wakil = NULL;

    enqueue(&wakil, "2. Eko", 50, 20);
    enqueue(&wakil, "6. Budi", 70, 30);
    enqueue(&wakil, "4. Ame", 60, 25);
    enqueue(&wakil, "3. Bambang", 60, 20);
    enqueue(&wakil, "1. Eka", 20, 20);
    enqueue(&wakil, "5. Wawo", 60, 21);

    display(wakil);

    return 0;
}
