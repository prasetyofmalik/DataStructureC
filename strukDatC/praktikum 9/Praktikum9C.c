#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
};
void displayPreorder(struct node* node){
    if(node == NULL)
        return;
    printf("%d ", node->data); // root
    displayPreorder(node->left); // subtree kiri
    displayPreorder(node->right); // subtree kanan
}
void displayInorder(struct node* node){
    if(node == NULL)
        return;
    displayInorder(node->left); // subtree kiri
    printf("%d ", node->data); // root
    displayInorder(node->right); // subtree kanan
}
void displayPostorder(struct node* node){
    if(node == NULL)
        return;
    displayPostorder(node->left); // subtree kiri
    displayPostorder(node->right); // subtree kanan
    printf("%d ", node->data); // root
}
struct node* insert(struct node* root, int newData){
    if(root == NULL){
        root = newNode(newData);
    } else{
        int is_left = 0;
        struct node* cursor = root;
        struct node* prev = NULL;
        while(cursor != NULL){
            prev = cursor;
            if(newData<=cursor->data){
                is_left = 1;
                cursor = cursor->left;
            } else if(newData>cursor->data){
                is_left = 0;
                cursor = cursor->right;
            }
        }
        if(is_left==1)
            prev->left = newNode(newData);
        else
            prev->right = newNode(newData);
    }
    return root;
};
void search_node(struct node* root, int data){
    struct node* cursor = root;

    while(cursor->data != data){
        if(cursor != NULL){
            if(data>cursor->data)
                cursor = cursor->right;
            else
                cursor = cursor->left;
            if(cursor == NULL){
                printf("Node %d tidak ditemukan\n\n", data);
                return;
            }
        }
    }
    printf("Node %d ditemukan\n\n", data);
    return;
}
struct node* delete_node(struct node* root, int deletedData){
    if(root == NULL)
        return root;
    else{
        struct node* cursor;
        if(deletedData > root->data)
            root->right = delete_node(root->right,deletedData);
        else if(deletedData < root->data)
            root->left = delete_node(root->left, deletedData);
        else{
            //1 CHILD
            if(root->left == NULL){
                cursor = root->right;
                free(root);
                root = cursor;
            }
            else if(root->right == NULL) {
                cursor = root->left;
                free(root);
                root = cursor;
            }
            //2 CHILDREN
            else{
                cursor = root->right;
                while(cursor->left != NULL){
                    cursor = cursor->left;
                }
                root->data = cursor->data;
                root->right = delete_node(root->right, cursor->data);
            }
        }
    }
    return root;
};
int addBT(struct node* root){
    if(root==NULL)
        return 0;
    return (root->data + addBT(root->left) + addBT(root->right));
}
int minValue(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL){
        current = current->left;
    }
    return(current->data);
}
int maxValue(struct node* node){
    struct node* current = node;
    while (current->right != NULL){
        current = current->right;
    }
    return(current->data);
}
int main(){
    struct node* root;
    int pilihan = 0;
    int sum, max, min;
    do{
        printf("Program Binary Tree\n1: Insert node\n2: Cari node\n3: Delete node");
        printf("\n4: Display nodes\n5: Jumlah data\n6: Minimum dan maksimum\n");
        printf("7: Exit\n\nMasukkan pilihan: ");
        scanf("%d", &pilihan);
        switch(pilihan){
        case 1:
            root = newNode(0);
            int add, i, jml;
            printf("Masukkan jumlah node: ");
            scanf("%d", &jml);
            for(i=0;i<jml;i++){
                printf("data ke-%d: ", i+1);
                scanf("%d", &add);
                root = insert(root, add);
            }
            root = delete_node(root, 0);
            printf("\n");
            break;
        case 2:
            printf("Cari data: ");
            int cari;
            scanf("%d", &cari);
            search_node(root, cari);
            break;
        case 3:
            printf("Hapus data: ");
            int del;
            scanf("%d", &del);
            root = delete_node(root, del);
            printf("\n");
            break;
        case 4:
            printf("Display Pre-Order\t: ");
            displayPreorder(root);
            printf("\nDisplay In-Order\t: ");
            displayInorder(root);
            printf("\nDisplay Post-Order\t: ");
            displayPostorder(root);
            printf("\n\n");
            break;
        case 5:
            sum = addBT(root);
            printf("Jumlah seluruh elemen: %d\n\n", sum);
            break;
        case 6:
            max = maxValue(root);
            min = minValue(root);
            printf("Nilai maksimum: %d\n", max);
            printf("Nilai minimum: %d\n\n", min);
            break;
        case 7:
            printf("\nKELUAR");
            break;
        default:
            printf("\nPilihan Tidak Valid");
        }
    }
    while(pilihan != 7);

    return 0;
}
