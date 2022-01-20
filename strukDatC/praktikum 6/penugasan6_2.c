#include <stdio.h>

struct node{
    int item;
    struct node *next;
};
typedef struct node* ndpointer;
ndpointer top;
// menyiapkan tumpukan kosong
void initializestack(){
    top = NULL;
}
void push(int value){
    ndpointer new_node;
    new_node = (ndpointer)malloc(sizeof(struct node));
    new_node->item = value;
    new_node->next = top;
    top = new_node;
}
void display(ndpointer head){
    if(head == NULL){
        printf("\n");
    } else{
        printf("%d", head->item);
        display(head->next);
    }
}
void konversi(bil_desimal){
    int sisa_bagi;
    if(bil_desimal==0) printf("Hasil konversi ke biner = 0");
    else{
        int n;
        for(n=bil_desimal;n>0;n=n/2){
            sisa_bagi = n%2;
            push(sisa_bagi);
        }
        printf("Hasil konversi ke biner = ");
        display(top);
    }
}
int main(){
    int desimal;

    printf("Program Konversi Desimal ke Biner\n\n");
    initializestack();
    printf("Masukkan bilangan desimal : ");
    scanf("%d", &desimal);
    konversi(desimal);

    return 0;
}
