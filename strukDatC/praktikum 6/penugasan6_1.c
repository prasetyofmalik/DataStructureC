#include <stdio.h>

typedef struct{
    int item[50];
    int jml_item;
} stack;
// menyiapkan tumpukan kosong
void initializestack(stack *s){
    s->jml_item = 0;
}
// jika tumpukan kosong, nilai fungsinya 1 (true)
// jika tidak 0 (false)
int isEmpty(stack *s){
    return (s->jml_item == 0);
}
// jika tumpukan sudah full (dalam deklarasi stack, field
// item adalah array sejumlah 50), nilai fungsinya = 1,
// jika tidak, nilai fungsinya = 0.
int isFull(stack *s){
    return (s->jml_item == 50);
}
void push(int x, stack *s){
    if(isFull(&s))
        printf("Bilangan terlalu besar!\n");
    else{
        s->item[s->jml_item]=x; ++(s->jml_item);
    }
}
int pop(stack *s){
    if(isEmpty(&s)) return 0;
    else {
        --(s->jml_item);
        return (s->item[s->jml_item]);
    }
}
// fungsi konversi
void konversi(stack tumpuk, int desimal){
    int sisa;
    if(desimal==0) printf("Hasil konversi ke biner = 0");
    else{
        int n;
        for(n=desimal;n>0;n=n/2){
            sisa = n%2;
            push(sisa, &tumpuk);
        }
        int i;
        printf("Hasil konversi ke biner = ");
        for(i=tumpuk.jml_item;i>0;i--){
            printf("%d", pop(&tumpuk));
        }
    }
}
int main(){
    stack tumpukan;
    int bil_desimal;

    printf("Program Konversi Desimal ke Biner\n\n");
    initializestack(&tumpukan);
    printf("Masukkan bilangan desimal : ");
    scanf("%d", &bil_desimal);
    konversi(tumpukan, bil_desimal);

    return 0;
}
