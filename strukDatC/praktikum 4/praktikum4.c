#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};
typedef struct node *ptrnode;

// cara 3: agar tidak menulis program berulang-ulang,
// gunakan fungsi
ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;

    return(p);
}
ptrnode head;
// menampilkan seluruh value pada node
void displayNodes(ptrnode head){
    printf("Nodes: ");
    while (head!=NULL){
        printf("%d   ", head->value);
        head = head->next;
    }
    printf("\n");
}
// menambah node ke dalam linked list
// 1. insert kiri
ptrnode insert_head(ptrnode head, int nilai){
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head = new_node;

    return(head);
}
// 2. insert kanan
ptrnode insert_tail(ptrnode head, int nilai){
    // mencari node terakhir
    ptrnode tail = head;
    while(tail->next!=NULL)
        tail = tail->next;
    ptrnode new_node = createNode(nilai);
    tail->next = new_node;

    return(head);
}
// 3. setelah simpul tertentu
ptrnode insert_after(ptrnode head, int nilai, int prev_nilai){
    // mencari node sebelumnya
    ptrnode cursor = head;
    while(cursor->value!=prev_nilai)
        cursor = cursor->next;
    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next = new_node;

    return(head);
}
// 4. sebelum simpul tertentu
ptrnode insert_before(ptrnode head, int nilai, int next_nilai){
    if(head->value==next_nilai)
        head = insert_head(head, nilai);
    else{
        ptrnode cursor, prevcursor;
        cursor = head;
        do{
            prevcursor = cursor;
            cursor = cursor->next;
        }
        while(cursor->value!=next_nilai);
        ptrnode new_node = createNode(nilai);
        new_node->next = cursor;
        prevcursor->next = new_node;
    }
    return(head);
}
// menghapus node dari linked list
// 1. delete kiri
ptrnode remove_first(ptrnode head){
    if(head == NULL)
        return;
    ptrnode first = head;
    head = head->next;
    first->next = NULL;
    free(first);

    return(head);
}
// 2. delete kanan
ptrnode remove_last(ptrnode head){
    if(head == NULL)
        return;
    ptrnode tail = head;
    ptrnode prevtail = NULL;
    while(tail->next != NULL){
        prevtail = tail;
        tail = tail->next;
    }
    prevtail->next = NULL;
    free(tail);

    return(head);
}
// 3. delete tengah
ptrnode remove_middle(ptrnode head, int nilai){
    ptrnode cursor = head;
    while(cursor != NULL){
        if(cursor->next->value == nilai)
            break; //keluar dari iterasi
        cursor = cursor->next;
    }
    if(cursor != NULL){
        ptrnode tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }

    return(head);
}
// 4. delete semua
ptrnode dispose(ptrnode head){
    if(head == NULL)
        return;
    while(head != NULL){
        ptrnode tmp = head;
        head = head->next;

        tmp->next = NULL;
        free(tmp);
    }
    printf("semua node telah dihapus");

    return(head);
}

int main(){
    ptrnode head = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    head->value = 10;
    // cara membuat simpul baru
    // cara 1: deklarasikan node kemudian pointer
    struct node node_dua;
    ptrnode dua = &node_dua;
    dua->value = 20;
    head->next = dua;
    // cara 2: deklarasikan pointer kemudian struct
    // node sekaligus alokasi memori
    ptrnode tiga = NULL;
    ptrnode empat = NULL;

    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));

    dua->next = tiga;
    tiga->value = 30;
    tiga->next = empat;
    empat->value = 40;
    empat->next = NULL;
    // cara 3: panggil fungsi createNode
    ptrnode lima = createNode(50);
    empat->next = lima;

    displayNodes(head);

    // menambah node ke dalam linked list
    // 1. insert kiri
    head = insert_head(head, 9);
    // 2. insert kanan
    head = insert_tail(head, 99);
    // 3. setelah simpul tertentu
    head = insert_after(head, 60, 50);
    // 4. sebelum simpul tertentu
    head = insert_before(head, 35, 40);

    displayNodes(head);

    // menghapus node dari linked liks
    // 1. delete kiri
    head = remove_first(head);
    // 2. delete kanan
    head = remove_last(head);
    // 3. delete tengah
    head = remove_middle(head, 35);
    // 4. delete semua
    head = dispose(&head);

    return 0;
}
