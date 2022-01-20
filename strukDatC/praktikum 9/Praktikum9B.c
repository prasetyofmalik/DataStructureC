#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct node{
    char nama[30];
    struct node *left;
    struct node *right;
} mhs;
mhs* newMhs(char a[]){
    mhs* temp = (mhs*)malloc(sizeof(mhs));
    strcpy(temp->nama, a);
    temp->left = NULL;
    temp->right = NULL;

    return temp;
};
mhs* insert(mhs* root, char n[]){
    mhs* temp = newMhs(n);
    if (root == NULL) {
        root = temp;
    } else {
        int is_left = 0;
        mhs* cursor = root;
        mhs* prev = NULL;
        while(cursor != NULL){
            prev = cursor;
            int z = strcmp(n, cursor->nama);
            if(z<=0){
                is_left = 1;
                cursor = cursor->left;
            } else if(z>0){
                is_left = 0;
                cursor = cursor->right;
            }
        }
        if(is_left==1)
            prev->left = temp;
        else
            prev->right = temp;
    }
    return root;
};
mhs* delete_node(struct node* root, char deletedNama[]){
    if(root == NULL)
        return root;
    else{
        mhs* cursor;
        int z = strcmp(deletedNama, root->nama);
        if (z>0)
            root->right = delete_node(root->right,deletedNama);
        else if (z<0)
            root->left = delete_node(root->left, deletedNama);
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
                strcpy(root->nama, cursor->nama);
                root->right = delete_node(root->right, cursor->nama);
            }
        }
    }
    return root;
};
void displayPreorder(mhs* node){
    if (node==NULL)
        return;
    printf(" %s\n", node->nama); // root
    displayPreorder(node->left); // subtree kiri
    displayPreorder(node->right); // subtree kanan
}
void displayInorder(mhs* node){
    if (node==NULL)
        return;
    displayInorder(node->left); // subtree kiri
    printf(" %s\n", node->nama); // root
    displayInorder(node->right); // subtree kanan
}
void displayPostorder(mhs* node){
    if (node==NULL)
        return;
    displayPostorder(node->left); // subtree kiri
    displayPostorder(node->right); // subtree kanan
    printf(" %s\n", node->nama); // root
}
void search_node(struct node* root, char nama[]){
    struct node* cursor = root;
    printf(" %s\t-> ", nama);
    int z = strcmp(nama, cursor->nama);
    while (z!=0){
        if (cursor != NULL){
            if (z>0)
                cursor = cursor->right;
            else
                cursor = cursor->left;
            if (cursor == NULL){
                printf("Nama \"%s\" tidak ditemukan\n", nama);
                return;
            }
            z = strcmp(nama, cursor->nama);
        }
    }
    printf("Nama \"%s\" ditemukan\n", nama);
    return;
}
int main(){
    mhs* root = newMhs("Walter");

    root = insert(root, "Alexander");
    root = insert(root, "Skyler");
    root = insert(root, "Peter");
    root = insert(root, "Lester");
    root = insert(root, "Cooper");
    root = insert(root, "Roger");
    root = insert(root, "Fisher");
    root = insert(root, "Oliver");

    printf("Display Pre-Order: \n");
    displayPreorder(root);
    printf("\nDisplay In-Order: \n");
    displayInorder(root);
    printf("\nDisplay Post-Order: \n");
    displayPostorder(root);

    printf("\nCari node: \n");
    search_node(root, "Miller");
    search_node(root, "Fisher");

    printf("\nSetelah Delete Node\n");
    root = delete_node(root, "Alexander");
    root = delete_node(root, "Walter");

    printf("Display Pre-Order: \n");
    displayPreorder(root);
    printf("\nDisplay In-Order: \n");
    displayInorder(root);
    printf("\nDisplay Post-Order: \n");
    displayPostorder(root);

    return 0;
}
