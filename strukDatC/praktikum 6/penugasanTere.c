#include<stdio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};

typedef struct node* nodeku;
nodeku top;

void initializestack()
{
    top = NULL;
}

void push(int x){
    nodeku new_node;
    new_node = (nodeku)malloc(sizeof(struct node));
    new_node->item = x;
    new_node->next = top;
    top = new_node;
}
int pop()
{
    nodeku cursor;
    cursor = top;
    top=top->next;
    free(cursor);
}
void display(nodeku head){
    if(head == NULL){
        printf("\n");
    } else{
        printf("%d", head->item);
        display(head->next);
    }
}
void keBiner(int n){
    int sisa_bagi, i;
    printf("n = %d\n", n);
    if (n==0) printf("Hasil konversi ke biner = 0");
    else{
        for(i=n;i>0;i=i/2){
            sisa_bagi=i%2;
            push(sisa_bagi);
        }
        printf("Hasil konversi ke biner = ");
        display(top);
    }
}
void main(){
    int bil_desimal, opt;
    printf("Program Konversi Desimal \n\n");
    initializestack();
    printf("Masukan bilangan desimal = ");
    scanf("%d", &bil_desimal);

    printf("\n---MENU---\n");
    printf("1. Konversi ke Biner\n");
    printf("2. Konversi ke Oktal\n");
    printf("3. Keluar");

 	printf("\n\nNomor yang Anda Pilih :  ");
 	scanf("%d",&opt);

 	if (opt==1) keBiner(bil_desimal);
 	//else if (opt==2) keOktal(top, bil_desimal);
 	else printf("\nTekan Enter untuk Keluar\n");
}
