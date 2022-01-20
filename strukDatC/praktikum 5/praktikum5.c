#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node *ptrnode;
// fungsi untuk membuat simpul baru dengan deklarasi pointer
ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->prev = NULL;
    p->next = NULL;

    return p;
}
// fungsi untuk menambahkan simpul baru
// 1. insert head
ptrnode insert_head(ptrnode head, int nilai){
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;

    return head;
}
// 2. insert tail
ptrnode insert_tail(ptrnode head, int nilai){
    // mencari letak tail
    ptrnode tail = head;
    while(tail->next!=NULL)
        tail = tail->next;
    ptrnode new_node = createNode(nilai);
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;

    return head;
}
// 3. insert after
ptrnode insert_after(ptrnode head, int nilai, int nilai_dicari){
    // cari letak nilai yang dicari
    ptrnode cursor = head;
    while(cursor->value!=nilai_dicari)
        cursor = cursor->next;
    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next->prev = new_node;
    new_node->prev = cursor;
    cursor->next = new_node;

    return head;
}
// 4. insert before
ptrnode insert_before(ptrnode head, int nilai, int next_nilai){
    if (head->value == next_nilai)
        head = insert_head(head, nilai);
    else{
        // pencarian nilai sama seperti insert after,
        // tidak perlu 2 cursor
        ptrnode cursor = head;
        while(cursor->value != next_nilai)
            cursor = cursor->next;
        ptrnode new_node = createNode(nilai);
        new_node->prev = cursor->prev;
        cursor->prev->next = new_node;
        new_node->next = cursor;
        cursor->prev = new_node;
    }
    return(head);
}
// fungsi untuk menghapus simpul
// 1. remove first
ptrnode remove_first(ptrnode head){
    if(head == NULL) return;

    ptrnode first = head;
    head = head->next;
    head->prev = NULL;
    first->next = NULL;

    free(first);

    return head;
}
// 2. remove last
ptrnode remove_last(ptrnode head){
    if(head == NULL) return;
    //cursor bantuan satu lagi (prev_tail) tidak dibutuhkan
    ptrnode tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    ptrnode last = tail;
    tail = tail->prev;
    tail->next = NULL;
    last->prev = NULL;

    free(last);

    return head;
}
// 3. remove middle
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
        tmp->next->prev = cursor;
        tmp->next = NULL;
        tmp->prev = NULL;
        free(tmp);
    }

    return(head);
}
// menampilkan seluruh value pada node
void displayNodes(ptrnode head){
    // printf("simpul: ");
    while (head!=NULL){
        printf("%d   ", head->value);
        head = head->next;
    }
    printf("\n");
}
int main(){
    // pembuatan simpul awal
    ptrnode head = NULL;
    ptrnode tail = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    tail = head;
    head->value = 10;
    head->next = NULL;
    head->prev = NULL;
    // pembuatan sebuah simpul
    struct node node_dua;
    // struct node *dua = &node_dua;
    ptrnode dua = &node_dua;
    dua->value = 20;
    dua->prev = head;
    dua->next = NULL;
    head->next = dua;
    // pembuatan simpul dengan deklarasi pointer
    ptrnode tiga = NULL;
    ptrnode empat = NULL;
    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));
    dua->next = tiga;
    tiga->value = 30;
    tiga->prev = dua;
    tiga->next = empat;
    empat->value = 40;
    empat->prev = tiga;
    empat->next = NULL;
    // pembuatan simpul dengan fungsi createNode
    ptrnode lima = createNode(50);
    empat->next = lima;
    lima->prev = empat;
    printf("Simpul awal   : ");
    displayNodes(head);
    // insert
    head = insert_head(head, 99);
    head = insert_tail(head, 11);
    head = insert_after(head, 60, 50);
    head = insert_before(head, 35, 40);
    printf("Setelah insert: ");
    displayNodes(head);
    // remove
    head = remove_first(head);
    head = remove_last(head);
    head = remove_middle(head, 35);
    // display
    printf("Setelah remove: ");
    displayNodes(head);

    return 0;
}
