#include<stdio.h>
#include<stdlib.h>

struct nodus{
    int n;
    struct nodus * next;
};
typedef struct nodus*box;

struct antri{
    box front;
    box rear;
};
typedef struct antri*line;

line initialize()
{
    line a= (line)malloc(sizeof(struct antri));
    a->front=NULL;a->rear=NULL;
    return(a);
}

box new_node(int* i)
{
    box a= (box)malloc(sizeof(struct nodus));
    (a)->n=*i; (a)->next=NULL;
    return(a);
}

line enq(int *urut,line* baru)
{
    printf("Nomor antrian anda = %d\n",*urut);
    box nod= new_node(urut); (*urut)++;
    if ((*baru)->rear!=NULL)
    {
        (*baru)->rear->next=nod;
        (*baru)->rear=(*baru)->rear->next;
    }
    else (*baru)->front=(*baru)->rear=nod;
    return(*baru);
}

line deq(line*baru)
{
    box temp = (*baru)->front;
    printf("Nomor antrian %d sudah selesai!",(*baru)->front->n);
    if((*baru)->front!=NULL){
    (*baru)->front=(*baru)->front->next;
    printf(" (nomor antrian saat ini = %d)\n",(*baru)->front->n);}
    free(temp); return(*baru);
}

void check_line(line*baru)
{
    int k; printf("Masukkan nomor antrian Anda = ");scanf("%d",&k);
    int l = k - (*baru)->front->n;
    if (k>=(*baru)->front->n && k<=(*baru)->rear->n){
    printf("Sisa antrian = "); line curs = (*baru);
    while(curs->front!=NULL)
    {
        printf("%d ",curs->front->n);
        curs->front = curs->front->next;
    }
    printf("\nSisa waktu antrean ");
    if (l == 0) printf("giliran anda saat ini!"); else printf("%d menit",l*15);}
    else printf("Nomor antrian sudah selesai atau belum diambil.");
}

int main(){
    int no;int urut = 1; line baru = initialize();

    label:printf("########### MENU PROGRAM ANTRIAN KLINIK ###########");
    printf("\n1.Ambil antrian\n2.Mengecek antrian\n3.Selesai berobat\n");
    printf("Pilihan anda = ");scanf("%d",&no);
    switch(no)
    {
        case 1: enq(&urut,&baru); break;
        case 2: check_line(&baru); break;
        case 3: deq(&baru); break;

    }
    printf("\n\nApakah ingin kembali ke menu?\nJika ya tekan 1 jika tidak tekan 0-> ");
    scanf("%d",&no);printf("\n"); if (no==1) goto label; else exit(0);
}
