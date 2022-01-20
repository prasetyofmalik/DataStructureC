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
    int sisa_bagi, count, cneed, p;
    if(bil_desimal==0) printf("Hasil konversi ke biner = 0");
    else if(bil_desimal<0){
        int n;
        p = 1;
        bil_desimal = -bil_desimal-1;
        for(n=bil_desimal;n>0;n=n/2){
            sisa_bagi = n%2;
            sisa_bagi^=1;
            push(sisa_bagi);
            count++;
        }
        print(count, p);
    } else{
        int m;
        p = 0;
        for(m=bil_desimal;m>0;m=m/2){
            sisa_bagi = m%2;
            push(sisa_bagi);
            count++;
        }
        print(count, p);
    }
}
int print(int count, int p){
    int cneed;
    printf("jumlah digit biner (2^n): ");
    scanf("%d", &cneed);
    if(cneed>=count && cneed % 4 == 0){
        printf("Hasil konversi ke biner = ");
        int t=cneed-count;
        while(t>0){
            printf("%d", p);
            t--;
        }
        display(top);
    } else {
        printf("jumlah digit tidak memenuhi");
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
